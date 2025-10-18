#pragma once

enum e_scenario_type
{
	_scenario_type_solo,
	_scenario_type_multiplayer,
	_scenario_type_main_menu,
	_scenario_type_multiplayer_shared,
	_scenario_type_single_player_shared,
	_scenario_type_sounds_shared,
	k_number_of_scenario_types [[maybe_unused]],
	_scenario_type_invalid = NONE
};

enum e_cache_file_header_bit
{
	_cache_file_header_bit_use_absolute_addressing,
	_cache_file_header_bit_unknown,
	k_num_cache_file_header_bits [[maybe_unused]]
};

enum e_cache_file_shared_file_type
{
	_shared_file_mainmenu,
	_shared_file_multiplayer,
	_shared_file_campaign,
	k_number_of_shared_file_types [[maybe_unused]],
	k_invalid_shared_file_type = NONE
};

struct s_cache_file_build_info
{
	int32_t version;
	int32_t size;
	int32_t compressed_file_padding;
	c_static_string<256> path;
	c_static_string<32> build_number;
	e_scenario_type scenario_type;
	e_cache_file_shared_file_type shared_cache_file_type;
	c_flags_no_init<e_cache_file_header_bit, unsigned char, k_num_cache_file_header_bits> header_flags;
	c_flags_no_init<e_cache_file_shared_file_type, unsigned char, k_number_of_shared_file_types> shared_map_usage;
	s_file_last_modification_date creation_date;
	c_static_string<32> name;
	c_static_string<256> tag_path;
	intptr32_t expected_base_address;
	uint32_t xdk_version;
	s_network_http_request_hash content_hashes[3];
	s_rsa_signature rsa_signature;
};
