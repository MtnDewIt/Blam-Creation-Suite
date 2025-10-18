#include "cachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_section_file_bounds& value)
{
	byteswap_inplace(value.offset);
	byteswap_inplace(value.size);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_local_resource_location& value)
{
	// #TODO: Handle byteswapping bitfields
	//byteswap_inplace(value.flags);
	//byteswap_inplace(value.file_size);

	byteswap_inplace(value.flags_and_file_size);
	byteswap_inplace(value.memory_size);
	byteswap_inplace(value.entire_checksum);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_insertion_point_resource_usage& value)
{
	byteswap_inplace(value.initial_zone_set_index);
	byteswap_inplace(value.pad);
	byteswap_inplace(value.shared_required_locations);
	byteswap_inplace(value.local_required_locations);
}

template<> BCS_SHARED void byteswap_inplace(halo3::s_cache_file_shared_resource_usage& value)
{
	byteswap_inplace(value.shared_layout_identifier);
	byteswap_inplace(value.shared_location_count);
	byteswap_inplace(value.local_location_count);
	byteswap_inplace(value.first_file_offset);
	byteswap_inplace(value.codec_identifier);
	byteswap_inplace(value.local_locations);
	byteswap_inplace(value.insertion_point_usage_count);
	byteswap_inplace(value.pad);
}

template<> BCS_SHARED void byteswap_inplace(halo3::xbox360::beta::s_cache_file_header& header) 
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
	byteswap_inplace(header.checksum);
	byteswap_inplace(header.uncompressed);
	byteswap_inplace(header.tracked);
	byteswap_inplace(header.valid_shared_resource_usage);
	byteswap_inplace(header.header_flags);
	byteswap_inplace(header.slot_modification_date);
	byteswap_inplace(header.low_detail_texture_number);
	byteswap_inplace(header.low_detail_texture_offset);
	byteswap_inplace(header.low_detail_texture_byte_count);
	byteswap_inplace(header.string_id_offset);
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
	byteswap_inplace(header.padding);
	byteswap_inplace(header.footer_signature);
}

template<> BCS_SHARED void byteswap_inplace(halo3::xbox360::s_cache_file_header& header)
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

template<> BCS_SHARED void byteswap_inplace(halo3::xbox360::s_cache_file_tag_interop_type_fixup& tag_interop)
{
	byteswap_inplace(tag_interop.interop_address);
	byteswap_inplace(tag_interop.cache_file_interop_type);
}

template<> BCS_SHARED void byteswap_inplace(halo3::xbox360::s_section& section)
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

template<> BCS_SHARED void byteswap_inplace(halo3::xbox360::s_cache_file_tags_header& tags_header)
{
	byteswap_inplace(tags_header.tag_groups);
	byteswap_inplace(tags_header.tag_instances);
	byteswap_inplace(tags_header.global_tag_indices);
	byteswap_inplace(tags_header.tag_interop_fixups);
	byteswap_inplace(tags_header.tags_checksum);
	byteswap_inplace(tags_header.signature);
}

#endif

namespace halo3 
{
	BCS_SHARED BCS_RESULT halo3_scenario_type_to_base_scenario_type(e_scenario_type halo3_scenario_type, ::e_scenario_type& base_scenario_type)
	{
		switch (halo3_scenario_type)
		{
		case halo3::_scenario_type_invalid:
			base_scenario_type = ::_scenario_type_invalid;
			return BCS_S_OK;
		case halo3::_scenario_type_solo:
			base_scenario_type = ::_scenario_type_solo;
			return BCS_S_OK;
		case halo3::_scenario_type_multiplayer:
			base_scenario_type = ::_scenario_type_multiplayer;
			return BCS_S_OK;
		case halo3::_scenario_type_main_menu:
			base_scenario_type = ::_scenario_type_main_menu;
			return BCS_S_OK;
		case halo3::_scenario_type_multiplayer_shared:
			base_scenario_type = ::_scenario_type_multiplayer_shared;
			return BCS_S_OK;
		case halo3::_scenario_type_single_player_shared:
			base_scenario_type = ::_scenario_type_single_player_shared;
			return BCS_S_OK;
		case halo3::_scenario_type_sounds_shared:
			base_scenario_type = ::_scenario_type_sounds_shared;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_scenario_type_to_halo3_scenario_type(::e_scenario_type base_scenario_type, e_scenario_type& halo3_scenario_type)
	{
		switch (base_scenario_type)
		{
		case ::_scenario_type_invalid:
			halo3_scenario_type = halo3::_scenario_type_invalid;
			return BCS_S_OK;
		case ::_scenario_type_solo:
			halo3_scenario_type = halo3::_scenario_type_solo;
			return BCS_S_OK;
		case ::_scenario_type_multiplayer:
			halo3_scenario_type = halo3::_scenario_type_multiplayer;
			return BCS_S_OK;
		case ::_scenario_type_main_menu:
			halo3_scenario_type = halo3::_scenario_type_main_menu;
			return BCS_S_OK;
		case ::_scenario_type_multiplayer_shared:
			halo3_scenario_type = halo3::_scenario_type_multiplayer_shared;
			return BCS_S_OK;
		case ::_scenario_type_single_player_shared:
			halo3_scenario_type = halo3::_scenario_type_single_player_shared;
			return BCS_S_OK;
		case ::_scenario_type_sounds_shared:
			halo3_scenario_type = halo3::_scenario_type_sounds_shared;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT halo3_cache_file_shared_file_type_to_base_cache_file_shared_file_type(e_cache_file_shared_file_type halo3_cache_file_shared_file_type, ::e_cache_file_shared_file_type& base_cache_file_shared_file_type)
	{
		// #TODO: Handle pc64 shared file type (its different for some reason)
		switch (halo3_cache_file_shared_file_type)
		{
		case halo3::k_invalid_shared_file_type:
			base_cache_file_shared_file_type = ::k_invalid_shared_file_type;
			return BCS_S_OK;
		case halo3::_shared_file_mainmenu:
			base_cache_file_shared_file_type = ::_shared_file_mainmenu;
			return BCS_S_OK;
		case halo3::_shared_file_multiplayer:
			base_cache_file_shared_file_type = ::_shared_file_multiplayer;
			return BCS_S_OK;
		case halo3::_shared_file_campaign:
			base_cache_file_shared_file_type = ::_shared_file_campaign;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_cache_file_shared_file_type_to_halo3_cache_file_shared_file_type(::e_cache_file_shared_file_type base_cache_file_shared_file_type, e_cache_file_shared_file_type& halo3_cache_file_shared_file_type)
	{
		// #TODO: Handle pc64 shared file type (its different for some reason)
		switch (base_cache_file_shared_file_type)
		{
		case ::k_invalid_shared_file_type:
			halo3_cache_file_shared_file_type = halo3::k_invalid_shared_file_type;
			return BCS_S_OK;
		case ::_shared_file_mainmenu:
			halo3_cache_file_shared_file_type = halo3::_shared_file_mainmenu;
			return BCS_S_OK;
		case ::_shared_file_multiplayer:
			halo3_cache_file_shared_file_type = halo3::_shared_file_multiplayer;
			return BCS_S_OK;
		case ::_shared_file_campaign:
			halo3_cache_file_shared_file_type = halo3::_shared_file_campaign;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}
}
