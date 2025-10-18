#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	BCS_RESULT tag_definitions_register()
	{
		BCS_RESULT rs = BCS_S_OK;

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo1, _platform_type_pc_64bit }, blofeld::halo1::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo 1 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_stubbs, _platform_type_pc_64bit }, blofeld::stubbs::pc64::tag_groups)))
		{
			console_write_line("Failed to register Stubbs 64Bit Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo2, _platform_type_pc_64bit }, blofeld::halo2::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo 2 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo3, _platform_type_pc_64bit }, blofeld::halo3::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo 3 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo3odst, _platform_type_pc_64bit }, blofeld::halo3odst::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo 3 ODST MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.106708 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_155080_cert_ms23 }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.155080 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_171227_cert_ms23 }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.171227 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_177150_cert_ms23 }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.177150 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_235640_cert_ms25 }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.235640 cert_ms25 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_301003_cert_MS26_new }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.301003 cert_MS26_new Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_332089_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.332089 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_373869_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.373869 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_416138_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.416138 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_430653_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.430653 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_454665_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.454665 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_479394_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.479394 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_498295_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.498295 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_530945_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.530945 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_533032_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.533032 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_554482_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.554482 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_571698_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.571698 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_604673_Live }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.604673 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_700255_cert_ms30_oct19 }, blofeld::eldorado::pc32::tag_groups)))
		{
			console_write_line("Failed to register Eldorado 1.700255 cert_ms30_oct19 Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_haloreach, _platform_type_xbox_360 }, blofeld::haloreach::xbox360::tag_groups)))
		{
			console_write_line("Failed to register Halo Reach 11883 Xbox 360 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_haloreach, _platform_type_pc_64bit }, blofeld::haloreach::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo Reach MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo4, _platform_type_xbox_360 }, blofeld::halo4::xbox360::tag_groups)))
		{
			console_write_line("Failed to register Halo 4 November 13 2013 Xbox 360 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo4, _platform_type_pc_64bit }, blofeld::halo4::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo 4 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_groundhog, _platform_type_pc_64bit }, blofeld::groundhog::pc64::tag_groups)))
		{
			console_write_line("Failed to register Groundhog MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_halo5, _platform_type_pc_64bit }, blofeld::halo5::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo 5 Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_register_tag_group_collection({ _engine_type_haloinfinite, _platform_type_pc_64bit }, blofeld::haloinfinite::pc64::tag_groups)))
		{
			console_write_line("Failed to register Halo Infinite Tag Definitions");
			return rs;
		}
#endif

		return rs;
	}

	BCS_RESULT tag_definitions_unregister()
	{
		BCS_RESULT rs = BCS_S_OK;

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo1, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo 1 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_stubbs, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Stubbs 64Bit Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo2, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo 2 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo3, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo 3 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo3odst, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo 3 ODST MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 })))
		{
			console_write_line("Failed to unregister Eldorado 1.106708 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_155080_cert_ms23 })))
		{
			console_write_line("Failed to unregister Eldorado 1.155080 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_171227_cert_ms23 })))
		{
			console_write_line("Failed to unregister Eldorado 1.171227 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_177150_cert_ms23 })))
		{
			console_write_line("Failed to unregister Eldorado 1.177150 cert_ms23 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_235640_cert_ms25 })))
		{
			console_write_line("Failed to unregister Eldorado 1.235640 cert_ms25 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_301003_cert_MS26_new })))
		{
			console_write_line("Failed to unregister Eldorado 1.301003 cert_MS26_new Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_332089_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.332089 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_373869_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.373869 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_416138_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.416138 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_430653_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.430653 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_454665_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.454665 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_479394_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.479394 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_498295_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.498295 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_530945_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.530945 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_533032_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.533032 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_554482_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.554482 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_571698_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.571698 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_604673_Live })))
		{
			console_write_line("Failed to unregister Eldorado 1.604673 Live Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_700255_cert_ms30_oct19 })))
		{
			console_write_line("Failed to unregister Eldorado 1.700255 cert_ms30_oct19 Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_haloreach, _platform_type_xbox_360 })))
		{
			console_write_line("Failed to unregister Halo Reach 11883 Xbox 360 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_haloreach, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo Reach MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo4, _platform_type_xbox_360 })))
		{
			console_write_line("Failed to unregister Halo 4 November 13 2013 Xbox 360 Tag Definitions");
			return rs;
		}
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo4, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo 4 MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_groundhog, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Groundhog MCC PC Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo5, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo 5 Tag Definitions");
			return rs;
		}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
		if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_haloinfinite, _platform_type_pc_64bit })))
		{
			console_write_line("Failed to unregister Halo Infinite Tag Definitions");
			return rs;
		}
#endif

		return rs;
	}
}
