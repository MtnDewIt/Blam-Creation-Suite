#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO2

c_halo2_cache_file_reader::c_halo2_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build) :
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
	case _platform_type_xbox: 
	{
		// #TODO: Handle Alpha/Beta Header
		xbox_cache_file_header = *reinterpret_cast<halo2::xbox::s_cache_file_header*>(file_info.file_view_begin);
	}
	break;
	case _platform_type_pc_32bit:
	{
		pc32_cache_file_header = *reinterpret_cast<halo2::pc32::s_cache_file_header*>(file_info.file_view_begin);
	}
	break;
	case _platform_type_pc_64bit: 
	{
		pc64_cache_file_header = *reinterpret_cast<halo2::pc64::s_cache_file_header*>(file_info.file_view_begin);
	}
	break;
	default: throw BCS_E_UNSUPPORTED;
	}
}

c_halo2_cache_file_reader::~c_halo2_cache_file_reader()
{
	ASSERT_NO_THROW(BCS_SUCCEEDED(destroy_memory_mapped_file(file)));
}

BCS_RESULT c_halo2_cache_file_reader::get_build_info(s_cache_file_build_info& build_info) const
{
	build_info.version = cache_file_header.version;
	build_info.size = cache_file_header.size;
	build_info.compressed_file_padding = cache_file_header.compressed_file_padding;

	BCS_RESULT rs = BCS_S_OK;

	switch (engine_platform_build.platform_type) 
	{
	case _platform_type_xbox:
	{
		build_info.path = xbox_cache_file_header.path;
		build_info.build_number = xbox_cache_file_header.build_number;
		//build_info.scenario_type.clear(); // #TODO: Handle build info scenario_type
		//build_info.shared_cache_file_type.clear(); // #TODO: Handle build info shared_cache_file_type
		build_info.header_flags.clear(); // #TODO: Handle build info header_flags
		build_info.shared_map_usage.clear(); // #TODO: Handle build info shared_map_usage
		build_info.creation_date = xbox_cache_file_header.creation_date;
		build_info.name = xbox_cache_file_header.name;
		build_info.tag_path = xbox_cache_file_header.tag_path;
	}
	break;
	case _platform_type_pc_32bit:
	{
		build_info.path = pc32_cache_file_header.path;
		build_info.build_number = pc32_cache_file_header.build_number;
		//build_info.scenario_type.clear(); // #TODO: Handle build info scenario_type
		//build_info.shared_cache_file_type.clear(); // #TODO: Handle build info shared_cache_file_type
		build_info.header_flags.clear(); // #TODO: Handle build info header_flags
		build_info.shared_map_usage.clear(); // #TODO: Handle build info shared_map_usage
		build_info.creation_date = pc32_cache_file_header.creation_date;
		build_info.name = pc32_cache_file_header.name;
		build_info.tag_path = pc32_cache_file_header.tag_path;
	}
	break;
	case _platform_type_pc_64bit:
	{
		build_info.path = pc64_cache_file_header.path;
		build_info.build_number = pc64_cache_file_header.build_number;
		//build_info.scenario_type.clear(); // #TODO: Handle build info scenario_type
		//build_info.shared_cache_file_type.clear(); // #TODO: Handle build info shared_cache_file_type
		build_info.header_flags.clear(); // #TODO: Handle build info header_flags
		build_info.shared_map_usage.clear(); // #TODO: Handle build info shared_map_usage
		build_info.creation_date = pc64_cache_file_header.shared_creation_date[0]; // #TODO: Handle creation_date
		build_info.name = pc64_cache_file_header.name;
		build_info.tag_path = pc64_cache_file_header.tag_path;
	}
	break;
	default: throw BCS_E_UNSUPPORTED;
	}

	return BCS_S_OK;
}

BCS_RESULT c_halo2_cache_file_reader::get_debug_info(s_cache_file_debug_info& debug_info) const
{

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_halo2_cache_file_reader::get_section_buffer(e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
{
	if (section_index == _cache_file_tag_section || section_index == _cache_file_debug_section)
	{
		const char* section_begin = nullptr;
		const char* section_end = nullptr;
		int32_t section_size = 0;

		switch (engine_platform_build.platform_type) 
		{
		case _platform_type_xbox:
		{
			section_begin = file_info.file_view_begin + xbox_cache_file_header.tags_offset;
			section_end = buffer_info.begin + xbox_cache_file_header.tags_instances_size;
			section_size = xbox_cache_file_header.tags_instances_size;
		}
		break;
		case _platform_type_pc_32bit:
		{
			section_begin = file_info.file_view_begin + pc32_cache_file_header.tags_offset;
			section_end = buffer_info.begin + pc32_cache_file_header.tags_instances_size;
			section_size = pc32_cache_file_header.tags_instances_size;
		}
		break;
		case _platform_type_pc_64bit:
		{
			section_begin = file_info.file_view_begin + pc64_cache_file_header.tags_header_when_loaded;
			section_end = buffer_info.begin + pc64_cache_file_header.tags_instances_size;
			section_size = pc64_cache_file_header.tags_instances_size;
		}
		break;
		default: throw BCS_E_UNSUPPORTED;
		}

		if (section_size == 0)
		{
			return BCS_E_UNSUPPORTED;
		}

		buffer_info.begin = section_begin;
		buffer_info.end = section_end;
		buffer_info.size = section_size;
		buffer_info.offset = 0;
		buffer_info.offset_mask = 0;

		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo2_cache_file_reader::get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const
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
	case _tag_section_buffer:
		return get_section_buffer(_cache_file_tag_section, buffer_info);
	case _resources_section_buffer:
		return get_section_buffer(_cache_file_resource_section, buffer_info);
	default:
		return BCS_E_UNSUPPORTED;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo2_cache_file_reader::get_buffers(s_cache_file_buffers_info& buffers_info) const
{
	for (int cache_file_buffer_index = 0; cache_file_buffer_index < k_num_cache_file_buffers; cache_file_buffer_index++)
	{
		get_buffer(static_cast<e_cache_file_buffer_index>(cache_file_buffer_index), buffers_info.buffer_infos[cache_file_buffer_index]);
	}

	return BCS_S_OK;
}

BCS_RESULT c_halo2_cache_file_reader::associate_cache_cluster(c_cache_cluster& target_cache_cluster)
{
	if (c_halo2_cache_cluster* halo2_cache_cluster = dynamic_cast<c_halo2_cache_cluster*>(&target_cache_cluster))
	{
		return associate_cache_cluster(*halo2_cache_cluster);
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_halo2_cache_file_reader::associate_cache_cluster(c_halo2_cache_cluster& target_cache_cluster)
{
	if (cache_cluster == nullptr)
	{
		cache_cluster = &target_cache_cluster;
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT c_halo2_cache_file_reader::virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const
{
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info buffer_info;
	if (BCS_FAILED(rs = get_buffer(_tag_section_buffer, buffer_info)))
	{
		return rs;
	}

	// #TODO: Handle Alpha/Beta Header
	halo2::s_cache_file_tags_header tags_header = *reinterpret_cast<const halo2::s_cache_file_tags_header*>(buffer_info.begin);

	relative_offset = static_cast<long>(virtual_address - tags_header.tag_instances + sizeof(halo2::s_cache_file_tags_header));

	return rs;
}

BCS_RESULT c_halo2_cache_file_reader::page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const
{
	virtual_address = page_offset; // -cache_file_header->expected_base_address;

	return BCS_S_OK;
	//return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_halo2_cache_file_reader::get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const
{
	return blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups);
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO2
