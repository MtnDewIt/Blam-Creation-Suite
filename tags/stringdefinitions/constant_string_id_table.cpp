#include "stringdefinitions-private-pch.h"

BCS_RESULT get_constant_string_id_table_by_engine_platform_build(s_engine_platform_build engine_platform_build, s_constant_string_id_table*& constant_string_id_table)
{
	if (engine_platform_build.engine_type == _engine_type_eldorado)
	{
		switch (engine_platform_build.build)
		{
		case _build_eldorado_1_106708_cert_ms23:
			constant_string_id_table = &eldorado_1_106708_cert_ms23::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_155080_cert_ms23:
			constant_string_id_table = &eldorado_1_155080_cert_ms23::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_171227_cert_ms23:
			constant_string_id_table = &eldorado_1_171227_cert_ms23::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_177150_cert_ms23:
			constant_string_id_table = &eldorado_1_177150_cert_ms23::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_235640_cert_ms25:
			constant_string_id_table = &eldorado_1_235640_cert_ms25::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_301003_cert_MS26_new:
			constant_string_id_table = &eldorado_1_301003_cert_ms26_new::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_332089_Live:
			constant_string_id_table = &eldorado_1_332089_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_373869_Live:
			constant_string_id_table = &eldorado_1_373869_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_416138_Live:
			constant_string_id_table = &eldorado_1_416138_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_430653_Live:
			constant_string_id_table = &eldorado_1_430653_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_454665_Live:
			constant_string_id_table = &eldorado_1_454665_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_479394_Live:
			constant_string_id_table = &eldorado_1_479394_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_498295_Live:
			constant_string_id_table = &eldorado_1_498295_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_530945_Live:
			constant_string_id_table = &eldorado_1_530945_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_533032_Live:
			constant_string_id_table = &eldorado_1_533032_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_554482_Live:
			constant_string_id_table = &eldorado_1_554482_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_571698_Live:
			constant_string_id_table = &eldorado_1_571698_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_604673_Live:
			constant_string_id_table = &eldorado_1_604673_live::constant_string_id_table;
			return BCS_S_OK;
		case _build_eldorado_1_700255_cert_ms30_oct19:
			constant_string_id_table = &eldorado_1_700255_cert_ms30_oct19::constant_string_id_table;
			return BCS_S_OK;
		}
	}
	return BCS_E_UNSUPPORTED;
}
