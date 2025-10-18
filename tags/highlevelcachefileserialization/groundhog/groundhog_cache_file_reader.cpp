#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG

c_groundhog_cache_file_reader::c_groundhog_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build) :
	filepath(filepath),
	engine_platform_build(engine_platform_build),
	file(nullptr),
	file_info(),
	cache_cluster(nullptr),
	cache_file_header()
{
	BCS_RESULT rs;
	if (BCS_FAILED(rs = create_memory_mapped_file(filepath, true, file)))
	{
		throw(rs);
	}
	if (BCS_FAILED(rs = get_memory_mapped_file_info(file, file_info)))
	{
		throw(rs);
	}

	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		pc_cache_file_header = *reinterpret_cast<halo4::pc::s_cache_file_header*>(file_info.file_view_begin);
	}
	break;
	default: throw BCS_E_UNSUPPORTED;
	}
}

c_groundhog_cache_file_reader::~c_groundhog_cache_file_reader()
{
	ASSERT_NO_THROW(BCS_SUCCEEDED(destroy_memory_mapped_file(file)));
}

BCS_RESULT c_groundhog_cache_file_reader::get_build_info(s_cache_file_build_info& build_info) const
{
	build_info.version = cache_file_header.version;
	build_info.size = cache_file_header.size;
	build_info.compressed_file_padding = cache_file_header.compressed_file_padding;

	BCS_RESULT rs = BCS_S_OK;

	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		build_info.path = pc_cache_file_header.path;
		build_info.build_number = pc_cache_file_header.build_number;
		if (BCS_FAILED(rs = halo4::halo4_scenario_type_to_base_scenario_type(pc_cache_file_header.scenario_type, build_info.scenario_type)))
		{
			return rs;
		}
		if (BCS_FAILED(rs = halo4::halo4_cache_file_shared_file_type_to_base_cache_file_shared_file_type(pc_cache_file_header.shared_cache_file_type, build_info.shared_cache_file_type)))
		{
			return rs;
		}
		if (BCS_FAILED(rs = halo4::halo4_cache_file_header_flags_to_base_cache_file_header_flags(pc_cache_file_header.header_flags, build_info.header_flags)))
		{
			return rs;
		}
		build_info.shared_map_usage.clear(); // #TODO: Handle build info shared_map_usage
		build_info.creation_date = pc_cache_file_header.shared_creation_date[0]; // #TODO: Handle creation_date
		build_info.name = pc_cache_file_header.name;
		build_info.tag_path = pc_cache_file_header.tag_path;
		build_info.expected_base_address = pc_cache_file_header.expected_base_address;
		build_info.xdk_version = 0; // pc_cache_file_header.xdk_version; // TODO: Handle xdk_version
		build_info.content_hashes[0] = pc_cache_file_header.content_hashes[0];
		build_info.content_hashes[1] = pc_cache_file_header.content_hashes[1];
		build_info.content_hashes[2] = pc_cache_file_header.content_hashes[2];
		build_info.rsa_signature = pc_cache_file_header.rsa_signature;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}

	return BCS_S_OK;
}

BCS_RESULT c_groundhog_cache_file_reader::get_debug_info(s_cache_file_debug_info& debug_info) const
{

	return BCS_S_OK;
}

BCS_RESULT c_groundhog_cache_file_reader::get_section_buffer(e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
{
	int32_t section_size = 0;
	int32_t section_offset_mask = 0;
	int32_t section_offset = 0;

	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		section_size = pc_cache_file_header.original_section_bounds[section_index].size;
		section_offset_mask = pc_cache_file_header.section_offsets[section_index];
		section_offset = pc_cache_file_header.original_section_bounds[section_index].offset;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}

	if (section_size == 0)
	{
		return BCS_E_UNSUPPORTED;
	}

	const char* section_begin = file_info.file_view_begin + section_offset + section_offset_mask;
	const char* section_end = section_begin + section_size;

	buffer_info.begin = section_begin;
	buffer_info.end = section_end;
	buffer_info.size = section_size;
	buffer_info.offset = section_offset;
	buffer_info.offset_mask = section_offset_mask;

	return BCS_S_OK;
}

BCS_RESULT c_groundhog_cache_file_reader::get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const
{
	switch (buffer_index)
	{
	case _cache_file_buffer:
		buffer_info.begin = file_info.file_view_begin;
		buffer_info.end = file_info.file_view_end;
		buffer_info.size = static_cast<unsigned long>(file_info.file_size);
		return BCS_S_OK;
	case _debug_section_buffer:
		return get_section_buffer(_cache_file_debug_section, buffer_info);
	case _resources_section_buffer:
		return get_section_buffer(_cache_file_resource_section, buffer_info);
	case _tag_section_buffer:
		return get_section_buffer(_cache_file_tag_section, buffer_info);
	case _localization_section_buffer:
		return get_section_buffer(_cache_file_language_pack_section, buffer_info);
	case _tag_post_link_buffer:
		buffer_info = {};
		break;
	case _tag_language_dependent_read_only_buffer:
		buffer_info = {};
		break;
	case _tag_language_dependent_read_write_buffer:
		buffer_info = {};
		break;
	case _tag_language_neutral_read_write_buffer:
		buffer_info = {};
		break;
	case _tag_language_neutral_write_combined_buffer:
		buffer_info = {};
		break;
	case _tag_language_neutral_read_only_buffer:
		buffer_info = {};
		break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_buffers(s_cache_file_buffers_info& buffers_info) const
{
	for (int cache_file_buffer_index = 0; cache_file_buffer_index < k_num_cache_file_buffers; cache_file_buffer_index++)
	{
		get_buffer(static_cast<e_cache_file_buffer_index>(cache_file_buffer_index), buffers_info.buffer_infos[cache_file_buffer_index]);
	}

	return BCS_S_OK;
}

BCS_RESULT c_groundhog_cache_file_reader::associate_cache_cluster(c_cache_cluster& target_cache_cluster)
{
	if (c_groundhog_cache_cluster* groundhog_cache_cluster = dynamic_cast<c_groundhog_cache_cluster*>(&target_cache_cluster))
	{
		return associate_cache_cluster(*groundhog_cache_cluster);
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_groundhog_cache_file_reader::associate_cache_cluster(c_groundhog_cache_cluster& target_cache_cluster)
{
	if (cache_cluster == nullptr)
	{
		cache_cluster = &target_cache_cluster;
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT c_groundhog_cache_file_reader::virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		relative_offset = static_cast<long>(virtual_address - pc_cache_file_header.expected_base_address);
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const
{
	virtual_address = page_offset; // -cache_file_header.expected_base_address;

	return BCS_S_OK;
	//return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_groundhog_cache_file_reader::get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const
{
	return blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups);
}

BCS_RESULT c_groundhog_cache_file_reader::get_tags_header_relative_offset(int32_t& tags_header_relative_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		BCS_FAIL_RETURN(virtual_address_to_relative_offset(pc_cache_file_header.tags_header_when_loaded, tags_header_relative_offset));
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_string_id_count(int32_t& string_id_count) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		string_id_count = pc_cache_file_header.string_id_count;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_string_id_index_offset(int32_t& string_id_index_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		string_id_index_offset = pc_cache_file_header.string_id_index_offset;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_string_id_data_offset(int32_t& string_id_data_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		string_id_data_offset = pc_cache_file_header.string_id_data_offset;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_string_id_data_count(int32_t& string_id_data_count) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		string_id_data_count = pc_cache_file_header.string_id_data_count;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_debug_tag_name_count(int32_t& debug_tag_name_count) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		debug_tag_name_count = pc_cache_file_header.debug_tag_name_count;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_debug_tag_name_index_offset(int32_t& debug_tag_name_index_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		debug_tag_name_index_offset = pc_cache_file_header.debug_tag_name_index_offset;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_debug_tag_name_data_offset(int32_t& debug_tag_name_data_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		debug_tag_name_data_offset = pc_cache_file_header.debug_tag_name_data_offset;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT c_groundhog_cache_file_reader::get_debug_tag_name_data_size(int32_t& debug_tag_name_data_size) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_64bit:
	{
		debug_tag_name_data_size = pc_cache_file_header.debug_tag_name_data_size;
		return BCS_S_OK;
	}
	break;
	default: return BCS_E_UNSUPPORTED;
	}
}

#endif // BCS_BUILD_HIGH_LEVEL_GROUNDHOG
