#include "cachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO4

template<> BCS_SHARED void byteswap_inplace(halo4::pc::s_cache_file_header& header) 
{
	byteswap_inplace(header.header_signature);
	byteswap_inplace(header.version);
	byteswap_inplace(header.size);
	byteswap_inplace(header.compressed_file_padding);
	byteswap_inplace(header.tags_offset);
	byteswap_inplace(header.total_tags_size);
	byteswap_inplace(header.scenario_type);
	byteswap_inplace(header.shared_cache_file_type);
	byteswap_inplace(header.uncompressed);
	byteswap_inplace(header.tracked);
	byteswap_inplace(header.valid_shared_resource_usage);
	byteswap_inplace(header.header_flags);
	byteswap_inplace(header.debug_tag_name_count);
	byteswap_inplace(header.debug_tag_name_data_offset);
	byteswap_inplace(header.debug_tag_name_data_size);
	byteswap_inplace(header.debug_tag_name_index_offset);
	byteswap_inplace(header.string_id_count);
	byteswap_inplace(header.string_id_data_count);
	byteswap_inplace(header.string_id_index_offset);
	byteswap_inplace(header.string_id_data_offset);
	byteswap_inplace(header.string_id_namespace_count);
	byteswap_inplace(header.string_id_namespace_offset);
	byteswap_inplace(header.shared_creation_date);
	byteswap_inplace(header.unknown1);
	byteswap_inplace(header.creator_name);
	byteswap_inplace(header.build_number);
	byteswap_inplace(header.name);
	byteswap_inplace(header.tag_path);
	byteswap_inplace(header.path);
	byteswap_inplace(header.expected_base_address);
	byteswap_inplace(header.tags_header_when_loaded);
	byteswap_inplace(header.unknown2);
	byteswap_inplace(header.tag_post_link_buffer);
	byteswap_inplace(header.tag_language_dependent_read_only_buffer);
	byteswap_inplace(header.tag_language_dependent_read_write_buffer);
	byteswap_inplace(header.tag_language_neutral_read_write_buffer);
	byteswap_inplace(header.tag_language_neutral_write_combined_buffer);
	byteswap_inplace(header.tag_language_neutral_read_only_buffer);
	byteswap_inplace(header.realtime_checksum);
	byteswap_inplace(header.content_hash_mask);
	byteswap_inplace(header.signature_marker);
	byteswap_inplace(header.content_hashes);
	byteswap_inplace(header.rsa_key_blob_hash);
	byteswap_inplace(header.rsa_signature);
	byteswap_inplace(header.section_offsets);
	byteswap_inplace(header.original_section_bounds);
	byteswap_inplace(header.shared_resource_usage);
	byteswap_inplace(header.unknown1D728);
	byteswap_inplace(header.late_binding_tag_reference_fixup_info_count);
	byteswap_inplace(header.late_binding_tag_reference_fixup_info_address);
	byteswap_inplace(header.cache_file_fixups_count);
	byteswap_inplace(header.cache_file_fixups_address);
	byteswap_inplace(header.unknown1D738);
	byteswap_inplace(header.unknown1D73C);
	byteswap_inplace(header.unknown1D740);
	byteswap_inplace(header.unknown1D744);
	byteswap_inplace(header.unknown1D748);
	byteswap_inplace(header.unknown1D74C);
	byteswap_inplace(header.unknown1D768);
	byteswap_inplace(header.unknown1D76C);
	byteswap_inplace(header.padding);
	byteswap_inplace(header.footer_signature);
}

template<> BCS_SHARED void byteswap_inplace(halo4::xbox360::s_cache_file_header& header)
{
	byteswap_inplace(header.header_signature);
	byteswap_inplace(header.version);
	byteswap_inplace(header.size);
	byteswap_inplace(header.compressed_file_padding);
	byteswap_inplace(header.tags_header_when_loaded);
	byteswap_inplace(header.tags_offset);
	byteswap_inplace(header.total_tags_size);
	byteswap_inplace(header.path);
	byteswap_inplace(header.build_number);
	byteswap_inplace(header.scenario_type);
	byteswap_inplace(header.shared_cache_file_type);
	byteswap_inplace(header.uncompressed);
	byteswap_inplace(header.tracked);
	byteswap_inplace(header.valid_shared_resource_usage);
	byteswap_inplace(header.header_flags);
	byteswap_inplace(header.slot_modification_date);
	byteswap_inplace(header.low_detail_texture_number);
	byteswap_inplace(header.low_detail_texture_offset);
	byteswap_inplace(header.low_detail_texture_byte_count);
	byteswap_inplace(header.string_id_count);
	byteswap_inplace(header.string_id_data_count);
	byteswap_inplace(header.string_id_index_offset);
	byteswap_inplace(header.string_id_data_offset);
	byteswap_inplace(header.shared_map_usage);
	byteswap_inplace(header.creation_date);
	byteswap_inplace(header.shared_creation_date);
	byteswap_inplace(header.name);
	byteswap_inplace(header.language);
	byteswap_inplace(header.tag_path);
	byteswap_inplace(header.minor_version_number);
	byteswap_inplace(header.debug_tag_name_count);
	byteswap_inplace(header.debug_tag_name_data_offset);
	byteswap_inplace(header.debug_tag_name_data_size);
	byteswap_inplace(header.debug_tag_name_index_offset);
	byteswap_inplace(header.tag_remap_count);
	byteswap_inplace(header.tag_remap_address);
	byteswap_inplace(header.dlc_tag_remap_count);
	byteswap_inplace(header.dlc_tag_remap_address);
	byteswap_inplace(header.realtime_checksum);
	byteswap_inplace(header.creator_name);
	byteswap_inplace(header.expected_base_address);
	byteswap_inplace(header.xdk_version);
	byteswap_inplace(header.tag_post_link_buffer);
	byteswap_inplace(header.tag_language_dependent_read_only_buffer);
	byteswap_inplace(header.tag_language_dependent_read_write_buffer);
	byteswap_inplace(header.tag_language_neutral_read_write_buffer);
	byteswap_inplace(header.tag_language_neutral_write_combined_buffer);
	byteswap_inplace(header.tag_language_neutral_read_only_buffer);
	byteswap_inplace(header.content_hash_mask);
	byteswap_inplace(header.pad2);
	byteswap_inplace(header.signature_marker);
	byteswap_inplace(header.content_hashes);
	byteswap_inplace(header.rsa_signature);
	byteswap_inplace(header.section_offsets);
	byteswap_inplace(header.original_section_bounds);
	byteswap_inplace(header.shared_resource_usage);
	byteswap_inplace(header.unknown1D728);
	byteswap_inplace(header.late_binding_tag_reference_fixup_info_count);
	byteswap_inplace(header.late_binding_tag_reference_fixup_info_address);
	byteswap_inplace(header.cache_file_fixups_count);
	byteswap_inplace(header.cache_file_fixups_address);
	byteswap_inplace(header.unknown1D738);
	byteswap_inplace(header.unknown1D73C);
	byteswap_inplace(header.unknown1D740);
	byteswap_inplace(header.unknown1D744);
	byteswap_inplace(header.unknown1D748);
	byteswap_inplace(header.unknown1D74C);
	byteswap_inplace(header.unknown1D768);
	byteswap_inplace(header.unknown1D76C);
	byteswap_inplace(header.padding);
	byteswap_inplace(header.footer_signature);
}

template<> BCS_SHARED void byteswap_inplace(halo4::s_section& section)
{
	byteswap_inplace(section.count);
	byteswap_inplace(section.address);
}

template<> BCS_SHARED void byteswap_inplace(halo4::s_cache_file_tag_group& tag_group)
{
	byteswap_inplace(tag_group.group_tag);
	byteswap_inplace(tag_group.name);
}

template<> BCS_SHARED void byteswap_inplace(halo4::s_cache_file_tag_instance& tag_instance)
{
	byteswap_inplace(tag_instance.group_index);
	byteswap_inplace(tag_instance.tag_index_datum_header);
	byteswap_inplace(tag_instance.base_address);
}

template<> BCS_SHARED void byteswap_inplace(halo4::s_cache_file_global_tag_index& tag_global_instance)
{
	byteswap_inplace(tag_global_instance.group_tag);
	byteswap_inplace(tag_global_instance.tag_index);
}

template<> BCS_SHARED void byteswap_inplace(halo4::s_cache_file_tag_interop_type_fixup& tag_interop)
{
	byteswap_inplace(tag_interop.interop_address);
	byteswap_inplace(tag_interop.cache_file_interop_type);
}

template<> BCS_SHARED void byteswap_inplace(halo4::pc::s_cache_file_tags_header& tags_header)
{
	byteswap_inplace(tags_header.tag_groups);
	byteswap_inplace(tags_header.tag_instances);
	byteswap_inplace(tags_header.global_tag_indices);
	byteswap_inplace(tags_header.tag_interop_fixups);
	byteswap_inplace(tags_header.tags_checksum);
	byteswap_inplace(tags_header.unknown20);
	byteswap_inplace(tags_header.signature);
}

template<> BCS_SHARED void byteswap_inplace(halo4::xbox360::s_cache_file_tags_header& tags_header)
{
	byteswap_inplace(tags_header.tag_groups);
	byteswap_inplace(tags_header.tag_instances);
	byteswap_inplace(tags_header.global_tag_indices);
	byteswap_inplace(tags_header.tag_interop_fixups);
	byteswap_inplace(tags_header.tags_checksum);
	byteswap_inplace(tags_header.signature);
}

uint32_t cache_file_get_absolute_maximum_size()
{
	return 0x7FFFFFFF;
}

bool shell_build_string_is_compatible(const char* build_string)
{
	return true; // #todo
}

bool halo4::xbox360::cache_file_header_verify(halo4::xbox360::s_cache_file_header& header)
{
	constexpr uint32_t k_tag_cache_minimum_address = 0xA0000000;
	constexpr uint32_t k_tag_cache_maximum_address = 0xBFC00000;

	if (header.header_signature != k_cache_header_signature)
	{
		console_write_line("does not have a valid header signature (is %08x, should be %08x)", header.header_signature, k_cache_header_signature);
		return false;
	}

	if (header.version != 12)
	{
		console_write_line("does not have a valid header signature (is %08x, should be %08x)", header.version, 12);
		return false;
	}

	if (header.footer_signature != k_cache_footer_signature)
	{
		console_write_line("does not have a valid footer signature (is %08x, should be %08x)", header.footer_signature, k_cache_footer_signature);
		return false;
	}

	if (header.xdk_version != 21119)
	{
		console_write_line("mismatch in xdk versions (cache file is %d, code is %d)", header.xdk_version, 21119);
		return false;
	}

	if (!shell_build_string_is_compatible(header.build_number.get_string()))
	{
		console_write_line("the cache file '%s' belongs to an incompatible build (%s)", header.name, header.build_number);
		return false;
	}

	return true;
}


#endif
