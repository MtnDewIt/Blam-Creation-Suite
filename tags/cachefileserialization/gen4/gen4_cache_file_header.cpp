#include "cachefileserialization-private-pch.h"

#if \
defined(BCS_BUILD_HIGH_LEVEL_HALO3) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO3ODST) || \
defined(BCS_BUILD_HIGH_LEVEL_ELDORADO) || \
defined(BCS_BUILD_HIGH_LEVEL_HALOREACH) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO4) || \
defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)

template<> BCS_SHARED void byteswap_inplace(gen4::s_cache_file_section_file_bounds& value)
{
	byteswap_inplace(value.offset);
	byteswap_inplace(value.size);
}

template<> BCS_SHARED void byteswap_inplace(gen4::s_cache_file_local_resource_location& value)
{
	// #TODO: Handle byteswapping bitfields
	//byteswap_inplace(value.flags);
	//byteswap_inplace(value.file_size);

	byteswap_inplace(value.flags_and_file_size);
	byteswap_inplace(value.memory_size);
	byteswap_inplace(value.entire_checksum);
}

template<> BCS_SHARED void byteswap_inplace(gen4::s_cache_file_insertion_point_resource_usage& value)
{
	byteswap_inplace(value.initial_zone_set_index);
	byteswap_inplace(value.pad);
	byteswap_inplace(value.shared_required_locations);
	byteswap_inplace(value.local_required_locations);
}

template<> BCS_SHARED void byteswap_inplace(gen4::s_cache_file_shared_resource_usage& value)
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

#endif

namespace gen4 
{
	BCS_SHARED BCS_RESULT gen4_scenario_type_to_base_scenario_type(e_scenario_type gen4_scenario_type, ::e_scenario_type& base_scenario_type)
	{
		switch (gen4_scenario_type)
		{
		case gen4::_scenario_type_invalid:
			base_scenario_type = ::_scenario_type_invalid;
			return BCS_S_OK;
		case gen4::_scenario_type_solo:
			base_scenario_type = ::_scenario_type_solo;
			return BCS_S_OK;
		case gen4::_scenario_type_multiplayer:
			base_scenario_type = ::_scenario_type_multiplayer;
			return BCS_S_OK;
		case gen4::_scenario_type_main_menu:
			base_scenario_type = ::_scenario_type_main_menu;
			return BCS_S_OK;
		case gen4::_scenario_type_multiplayer_shared:
			base_scenario_type = ::_scenario_type_multiplayer_shared;
			return BCS_S_OK;
		case gen4::_scenario_type_single_player_shared:
			base_scenario_type = ::_scenario_type_single_player_shared;
			return BCS_S_OK;
		case gen4::_scenario_type_sounds_shared:
			base_scenario_type = ::_scenario_type_sounds_shared;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_scenario_type_to_gen4_scenario_type(::e_scenario_type base_scenario_type, e_scenario_type& gen4_scenario_type)
	{
		switch (base_scenario_type)
		{
		case ::_scenario_type_invalid:
			gen4_scenario_type = gen4::_scenario_type_invalid;
			return BCS_S_OK;
		case ::_scenario_type_solo:
			gen4_scenario_type = gen4::_scenario_type_solo;
			return BCS_S_OK;
		case ::_scenario_type_multiplayer:
			gen4_scenario_type = gen4::_scenario_type_multiplayer;
			return BCS_S_OK;
		case ::_scenario_type_main_menu:
			gen4_scenario_type = gen4::_scenario_type_main_menu;
			return BCS_S_OK;
		case ::_scenario_type_multiplayer_shared:
			gen4_scenario_type = gen4::_scenario_type_multiplayer_shared;
			return BCS_S_OK;
		case ::_scenario_type_single_player_shared:
			gen4_scenario_type = gen4::_scenario_type_single_player_shared;
			return BCS_S_OK;
		case ::_scenario_type_sounds_shared:
			gen4_scenario_type = gen4::_scenario_type_sounds_shared;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT gen4_cache_file_shared_file_type_to_base_cache_file_shared_file_type(e_cache_file_shared_file_type gen4_cache_file_shared_file_type, ::e_cache_file_shared_file_type& base_cache_file_shared_file_type)
	{
		switch (gen4_cache_file_shared_file_type)
		{
		case gen4::k_invalid_shared_file_type:
			base_cache_file_shared_file_type = ::k_invalid_shared_file_type;
			return BCS_S_OK;
		case gen4::_shared_file_mainmenu:
			base_cache_file_shared_file_type = ::_shared_file_mainmenu;
			return BCS_S_OK;
		case gen4::_shared_file_multiplayer:
			base_cache_file_shared_file_type = ::_shared_file_multiplayer;
			return BCS_S_OK;
		case gen4::_shared_file_campaign:
			base_cache_file_shared_file_type = ::_shared_file_campaign;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_cache_file_shared_file_type_to_gen4_cache_file_shared_file_type(::e_cache_file_shared_file_type base_cache_file_shared_file_type, e_cache_file_shared_file_type& gen4_cache_file_shared_file_type)
	{
		switch (base_cache_file_shared_file_type)
		{
		case ::k_invalid_shared_file_type:
			gen4_cache_file_shared_file_type = gen4::k_invalid_shared_file_type;
			return BCS_S_OK;
		case ::_shared_file_mainmenu:
			gen4_cache_file_shared_file_type = gen4::_shared_file_mainmenu;
			return BCS_S_OK;
		case ::_shared_file_multiplayer:
			gen4_cache_file_shared_file_type = gen4::_shared_file_multiplayer;
			return BCS_S_OK;
		case ::_shared_file_campaign:
			gen4_cache_file_shared_file_type = gen4::_shared_file_campaign;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}
}
