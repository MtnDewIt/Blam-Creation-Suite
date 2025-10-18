#pragma once

/* ---------- types */

namespace halo3odst 
{
	enum e_scenario_type
	{
		_scenario_type_solo,
		_scenario_type_multiplayer,
		_scenario_type_main_menu,
		_scenario_type_multiplayer_shared,
		_scenario_type_single_player_shared,
		_scenario_type_sounds_shared,
		k_scenario_type_count [[maybe_unused]],
		_scenario_type_invalid = NONE
	};

	enum e_cache_file_shared_file_type
	{
		_shared_file_mainmenu,
		_shared_file_multiplayer,
		_shared_file_campaign,
		k_number_of_shared_file_types [[maybe_unused]],
		k_invalid_shared_file_type = NONE,
	};

	enum e_cache_file_header_bit
	{
		_cache_file_header_bit_use_absolute_addressing, // #NOTE: Appears to be related to loading maps off of a hard drive
		_cache_file_header_bit_unknown,
		k_num_cache_file_header_bits [[maybe_unused]],
	};

	enum e_map_file_index
	{
		k_total_tracked_cached_map_files_count = 9,
		k_no_cached_map_file_index = -1
	};

	enum e_cache_file_section
	{
		_cache_file_debug_section,
		_cache_file_resource_section,
		_cache_file_tag_section,
		_cache_file_language_pack_section,
		k_number_of_cache_file_sections [[maybe_unused]]
	};

	enum e_cache_file_content_hash
	{
		_cache_file_content_hash_header = 0,
		_cache_file_content_hash_tags_language_dependent = 1,
		_cache_file_content_hash_tags_language_neutral = 2,
		k_cache_file_content_hash_count = 3
	};

	struct s_cache_file_tag_group
	{
		tag group_tag;
		tag parent_group_tags[2];
		uint32_t name;
	};
	static_assert(sizeof(s_cache_file_tag_group) == 0x10);

	struct s_cache_file_tag_instance
	{
		unsigned short group_index;
		unsigned short tag_index_datum_header;
		uint32_t base_address;
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x8);

	struct s_cache_file_global_tag_index
	{
		uint32_t group_tag;
		int32_t tag_index;
	};
	static_assert(sizeof(s_cache_file_global_tag_index) == 0x8);

	struct s_cache_file_section_file_bounds
	{
		int32_t offset;
		int32_t size;
	};
	static_assert(sizeof(s_cache_file_section_file_bounds) == 0x8);

	struct s_cache_file_local_resource_location
	{
		// #TODO: Handle byteswapping bitfields
		//int32_t flags : 2;
		//int32_t file_size : 30;

		int32_t flags_and_file_size;
		int32_t memory_size;
		s_network_http_request_hash entire_checksum;
	};
	static_assert(sizeof(s_cache_file_local_resource_location) == 0x1C);

	struct s_cache_file_insertion_point_resource_usage
	{
		int8_t initial_zone_set_index;
		int8_t pad[3];
		int32_t shared_required_locations[32]; // c_static_flags<1024>
		int32_t local_required_locations[10]; // c_static_flags<320>
		int8_t unknownAC[8];
	};
	static_assert(sizeof(s_cache_file_insertion_point_resource_usage) == 0xB4);

	struct s_cache_file_shared_resource_usage
	{
		uint32_t shared_layout_identifier[4]; // s_tag_persistent_identifier
		int16_t shared_location_count;
		int16_t local_location_count;
		int32_t first_file_offset;
		uint32_t codec_identifier[4]; // s_tag_persistent_identifier
		s_static_array<s_cache_file_local_resource_location, 320> local_locations;
		int8_t insertion_point_usage_count;
		int8_t pad[3];
		s_static_array<s_cache_file_insertion_point_resource_usage, 9> insertion_point_usages;
	};
	static_assert(sizeof(s_cache_file_shared_resource_usage) == 0x2980);

	BCS_SHARED extern BCS_RESULT halo3odst_scenario_type_to_base_scenario_type(e_scenario_type halo3odst_scenario_type, ::e_scenario_type& base_scenario_type);
	BCS_SHARED extern BCS_RESULT base_scenario_type_to_halo3odst_scenario_type(::e_scenario_type base_scenario_type, e_scenario_type& halo3odst_scenario_type);

	BCS_SHARED extern BCS_RESULT halo3odst_cache_file_shared_file_type_to_base_cache_file_shared_file_type(e_cache_file_shared_file_type halo3odst_cache_file_shared_file_type, ::e_cache_file_shared_file_type& base_cache_file_shared_file_type);
	BCS_SHARED extern BCS_RESULT base_cache_file_shared_file_type_to_halo3odst_cache_file_shared_file_type(::e_cache_file_shared_file_type base_cache_file_shared_file_type, e_cache_file_shared_file_type& halo3odst_cache_file_shared_file_type);
	template<typename t_halo3odst_storage, typename t_base_storage>
	inline BCS_RESULT halo3odst_cache_file_shared_file_flags_to_base_cache_file_shared_file_flags(
		c_flags_no_init<halo3odst::e_cache_file_shared_file_type, t_halo3odst_storage, k_number_of_shared_file_types> const& halo3odst_cache_file_shared_file_flags,
		c_flags_no_init<::e_cache_file_shared_file_type, t_base_storage, ::k_number_of_shared_file_types>& base_cache_file_shared_file_flags)
	{
		base_cache_file_shared_file_flags.clear();
		base_cache_file_shared_file_flags.set(::_shared_file_mainmenu, halo3odst_cache_file_shared_file_flags.test(_shared_file_mainmenu));
		base_cache_file_shared_file_flags.set(::_shared_file_multiplayer, halo3odst_cache_file_shared_file_flags.test(_shared_file_multiplayer));
		base_cache_file_shared_file_flags.set(::_shared_file_campaign, halo3odst_cache_file_shared_file_flags.test(_shared_file_campaign));
		return BCS_S_OK;
	}
	template<typename t_halo3odst_storage, typename t_base_storage>
	inline BCS_RESULT base_cache_file_shared_file_flags_to_halo3odst_cache_file_shared_file_flags(
		c_flags_no_init<::e_cache_file_shared_file_type, t_base_storage, ::k_number_of_shared_file_types> const& base_cache_file_shared_file_flags,
		c_flags_no_init<halo3odst::e_cache_file_shared_file_type, t_halo3odst_storage, k_number_of_shared_file_types>& halo3odst_cache_file_shared_file_flags)
	{
		halo3odst_cache_file_shared_file_flags.clear();
		halo3odst_cache_file_shared_file_flags.set(::_shared_file_mainmenu, base_cache_file_shared_file_flags.test(_shared_file_mainmenu));
		halo3odst_cache_file_shared_file_flags.set(::_shared_file_multiplayer, base_cache_file_shared_file_flags.test(_shared_file_multiplayer));
		halo3odst_cache_file_shared_file_flags.set(::_shared_file_campaign, base_cache_file_shared_file_flags.test(_shared_file_campaign));
		return BCS_S_OK;
	}

	template<typename t_halo3odst_storage, typename t_base_storage>
	inline BCS_RESULT halo3odst_cache_file_header_flags_to_base_cache_file_header_flags(
		c_flags_no_init<halo3odst::e_cache_file_header_bit, t_halo3odst_storage, k_num_cache_file_header_bits> const& halo3odst_cache_file_header_flags,
		c_flags_no_init<::e_cache_file_header_bit, t_base_storage, ::k_num_cache_file_header_bits>& base_cache_file_header_flags)
	{
		base_cache_file_header_flags.clear();
		base_cache_file_header_flags.set(::_cache_file_header_bit_use_absolute_addressing, halo3odst_cache_file_header_flags.test(_cache_file_header_bit_use_absolute_addressing));
		base_cache_file_header_flags.set(::_cache_file_header_bit_unknown, halo3odst_cache_file_header_flags.test(_cache_file_header_bit_unknown));
		return BCS_S_OK;
	}
	template<typename t_halo3odst_storage, typename t_base_storage>
	inline BCS_RESULT base_cache_file_header_flags_to_halo3odst_cache_file_header_flags(
		c_flags_no_init<::e_cache_file_header_bit, t_base_storage, ::k_num_cache_file_header_bits> const& base_cache_file_header_flags,
		c_flags_no_init<halo3odst::e_cache_file_header_bit, t_halo3odst_storage, k_num_cache_file_header_bits>& halo3odst_cache_file_header_flags)
	{
		halo3odst_cache_file_header_flags.clear();
		halo3odst_cache_file_header_flags.set(::_cache_file_header_bit_use_absolute_addressing, base_cache_file_header_flags.test(_cache_file_header_bit_use_absolute_addressing));
		halo3odst_cache_file_header_flags.set(::_cache_file_header_bit_unknown, base_cache_file_header_flags.test(_cache_file_header_bit_unknown));
		return BCS_S_OK;
	}
}