#include "cachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3

template<> BCS_SHARED void byteswap_inplace<halo3::xbox360::s_cache_file_header>(halo3::xbox360::s_cache_file_header& header)
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
	byteswap_inplace(header.padding);
	byteswap_inplace(header.footer_signature);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_section& section)
{
	byteswap_inplace(section.count);
	byteswap_inplace(section.address);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_tag_group& tag_group)
{
	byteswap_inplace(tag_group.group_tag);
	byteswap_inplace(tag_group.parent_group_tags);
	byteswap_inplace(tag_group.name);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_tag_instance& tag_instance)
{
	byteswap_inplace(tag_instance.group_index);
	byteswap_inplace(tag_instance.tag_index_datum_header);
	byteswap_inplace(tag_instance.base_address);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_global_tag_index& tag_global_instance)
{
	byteswap_inplace(tag_global_instance.group_tag);
	byteswap_inplace(tag_global_instance.tag_index);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_tag_interop_type_fixup& tag_interop)
{
	byteswap_inplace(tag_interop.interop_address);
	byteswap_inplace(tag_interop.cache_file_interop_type);
}

template<> BCS_SHARED void byteswap_inplace(::halo3::pc::s_cache_file_tags_header& tags_header)
{
	byteswap_inplace(tags_header.tag_groups);
	byteswap_inplace(tags_header.tag_instances);
	byteswap_inplace(tags_header.global_tag_indices);
	byteswap_inplace(tags_header.tag_interop_fixups);
	byteswap_inplace(tags_header.unknown20);
	byteswap_inplace(tags_header.tags_checksum);
	byteswap_inplace(tags_header.signature);
}

template<> BCS_SHARED void byteswap_inplace(::halo3::xbox360::s_cache_file_tags_header& tags_header)
{
	byteswap_inplace(tags_header.tag_groups);
	byteswap_inplace(tags_header.tag_instances);
	byteswap_inplace(tags_header.global_tag_indices);
	byteswap_inplace(tags_header.tag_interop_fixups);
	byteswap_inplace(tags_header.checksum);
	byteswap_inplace(tags_header.tags_signature);
}

#endif
