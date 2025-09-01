#pragma once

enum e_string_namespace
{
	_string_namespace_global = 0,
	_string_namespace_gui,
	_string_namespace_gui_alert,
	_string_namespace_gui_dialog,
	_string_namespace_game_engine,
	_string_namespace_game_start,
	_string_namespace_online,
	_string_namespace_saved_game,
	_string_namespace_gpu,
	k_string_namespace_count
};

struct s_constant_string_id_namespace
{
	const char* name;
	uint32_t string_count;
	const char** constant_string_ids;
};

struct s_constant_string_id_table
{
	uint32_t namespace_bits;
	uint32_t index_bits;
	uint32_t length_bits;
	uint32_t num_namespaces;
	s_constant_string_id_namespace** namespaces;
	uint32_t* serialization_namespace_order;
};

BCS_SHARED extern BCS_RESULT get_constant_string_id_table_by_engine_platform_build(s_engine_platform_build engine_platform_build, s_constant_string_id_table*& constant_string_id_table);
