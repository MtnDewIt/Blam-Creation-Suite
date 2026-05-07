#include "definitiondumper-private-pch.h"

c_definition_dumper::c_definition_dumper() :
	engine_platform_build(),
	runtime_tag_definitions(nullptr),
	regex(),
	candidates()
{
	// #TODO: Pull this from the command line arguments
	engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit };

	runtime_tag_definitions = new() c_runtime_tag_definitions();
	regex.clear();
	candidates.clear();
}

c_definition_dumper::~c_definition_dumper()
{
	// #TODO: Destory Everything Here
}

BCS_RESULT c_definition_dumper::dump_definitions()
{
	BCS_RESULT rs = BCS_S_OK;

	const wchar_t* tags_directory = nullptr;
	if (BCS_FAILED(rs = command_line_get_argument(L"filepath", tags_directory)))
	{
		return rs;
	}

	BCS_RESULT tag_definition_registry_init_result = blofeld::tag_definition_registry_init();
	ASSERT(BCS_SUCCEEDED(tag_definition_registry_init_result));

	BCS_RESULT tag_definitions_register_result = blofeld::tag_definitions_register();
	ASSERT(BCS_SUCCEEDED(tag_definitions_register_result));

	blofeld::t_tag_group_collection tag_groups;
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups)))
	{
		return rs;
	}

	for (blofeld::t_tag_group_iterator tag_group_iterator = tag_groups; *tag_group_iterator; tag_group_iterator++)
	{
		blofeld::s_tag_group const& tag_group = **tag_group_iterator;

		const wchar_t* file_path = nullptr;

		size_t buffer_length = strlen(tag_group.name);
		wchar_t* buffer = new(_alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
		mbstowcs(buffer, tag_group.name, buffer_length + 1);

		regex.format(L"*.%s", buffer);

		filesystem_traverse_directory_folders(
			tags_directory,
			[](void* userdata_pointer, const wchar_t* directory, const wchar_t* relative_directory)
			{
				struct s_traverse_directory_userdata
				{
					c_definition_dumper& dumper;
					const wchar_t* directory;
					const wchar_t* relative_directory;
				};
				s_traverse_directory_userdata userdata = { *static_cast<c_definition_dumper*>(userdata_pointer), directory, relative_directory };
				filesystem_traverse_directory_files(
					directory,
					userdata.dumper.regex.c_str(),
					[](void* userdata_pointer, const wchar_t* path, const wchar_t* relative_path)
					{
						s_traverse_directory_userdata& userdata = *static_cast<s_traverse_directory_userdata*>(userdata_pointer);

						userdata.dumper.candidates.push_back(_wcsdup(path));

						return true;
					},
					&userdata);
				return true;
			},
			this);

		const blofeld::s_tag_group* blofeld_tag_group;
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_get_tag_group_by_engine_platform_build(engine_platform_build, tag_group.group_tag, blofeld_tag_group)))
		{
			return rs;
		}

		runtime_tag_definitions->enqueue_tag_group_definition(engine_platform_build, *blofeld_tag_group);

		// #TODO: Make this not ass :/
		if (!candidates.empty())
		{
			// #TODO: Handle fail over so that if the first reference in the collection fails to validate, we try the next candidate
			file_path = candidates.front();

			void* tag_file_data = nullptr;
			uint64_t tag_file_data_size = 0;
			if (BCS_FAILED(rs = filesystem_read_file_to_memory(file_path, tag_file_data, tag_file_data_size)))
			{
				return rs;
			}

			if (tag_file_data_size < (static_cast<uint64_t>(sizeof(s_tag_file_header)) + sizeof(tag)))
			{
				return BCS_E_FAIL;
			}

			s_tag_file_header* tag_file_header = static_cast<s_tag_file_header*>(tag_file_data);

			if (engine_platform_build.platform_type == _platform_type_xbox_360) 
			{
				byteswap_inplace(tag_file_header->unknown0);
				byteswap_inplace(tag_file_header->unknown4);
				byteswap_inplace(tag_file_header->unknown8);
				byteswap_inplace(tag_file_header->unknownC);
				byteswap_inplace(tag_file_header->unknown10);
				byteswap_inplace(tag_file_header->unknown14);
				byteswap_inplace(tag_file_header->unknown18);
				byteswap_inplace(tag_file_header->unknown1C);
				byteswap_inplace(tag_file_header->unknown20);
				byteswap_inplace(tag_file_header->unknown24);
				byteswap_inplace(tag_file_header->unknown28);
				byteswap_inplace(tag_file_header->unknown2C);
				byteswap_inplace(tag_file_header->group_tag);
				byteswap_inplace(tag_file_header->group_version);
				byteswap_inplace(tag_file_header->crc32);
				byteswap_inplace(tag_file_header->blam);
			}

			if (tag_file_header->blam != 'BLAM')
			{
				return BCS_E_FAIL;
			}

			c_tag_file_reader* tag_file_reader = new() c_tag_file_reader(tag_file_data);

			if (engine_platform_build.platform_type == _platform_type_xbox_360)
			{
				tag_file_reader->is_big_endian = true;
			}

			unsigned int struct_definition_count = tag_file_reader->get_struct_definition_count();
			for (unsigned int struct_definition_index = 0; struct_definition_index < struct_definition_count; struct_definition_index++)
			{
				s_tag_persist_struct_definition& tag_persist_struct_definition = tag_file_reader->get_struct_definition_by_index(struct_definition_index);

				runtime_tag_definitions->enqueue_tag_struct_definition(*tag_file_reader, tag_persist_struct_definition);
			}

			candidates.clear();
		}

		regex.clear();
	}

	const wchar_t* tag_definitions_output_directory = nullptr;
	if (BCS_SUCCEEDED(command_line_get_argument(L"tag-definitions-output-directory", tag_definitions_output_directory)))
	{
		const wchar_t* tag_groups_output_directory = nullptr;
		if (BCS_SUCCEEDED(command_line_get_argument(L"tag-groups-output-directory", tag_groups_output_directory)))
		{
			const char* engine_namespace = nullptr;
			const char* platform_namespace = nullptr;
			const char* build_namespace = nullptr;
			ASSERT(BCS_SUCCEEDED(get_engine_type_namespace(engine_platform_build.engine_type, engine_namespace)));
			ASSERT(BCS_SUCCEEDED(get_platform_type_namespace(engine_platform_build.platform_type, platform_namespace)));
			ASSERT(BCS_SUCCEEDED(get_build_namespace(engine_platform_build.build, build_namespace)));
			blamtoozle_generate_source(
				*runtime_tag_definitions,
				tag_definitions_output_directory,
				tag_groups_output_directory,
				engine_namespace,
				platform_namespace,
				build_namespace,
				nullptr);
		}
	}

	return rs;
}