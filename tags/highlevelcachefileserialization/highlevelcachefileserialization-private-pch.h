#pragma once

#include <platform/platform-public-pch.h>
#include <templatelibrary/templatelibrary-public-pch.h>
#include <shared/shared-public-pch.h>
#include <stringdefinitions/stringdefinitions-public-pch.h>
#include <cachefileserialization/cachefileserialization-public-pch.h>
#include <tagframework/tagframework-public-pch.h>
#include <tagdefinitions/tagdefinitions-public-pch.h>
#include <tagreflection/tagreflection-public-pch.h>
#include <tagfileserialization/tagfileserialization-public-pch.h>
#include <graphicslib/graphicslib-public-pch.h>
#include <geometrylib/geometrylib-public-pch.h>

#include <platform/platform-exports-pch.h>
#include "highlevelcachefileserialization-public-pch.h"

#include "eldorado/postprocessing/eldorado_1_106708_cert_ms23.h"
#include "eldorado/postprocessing/prototype_resource.h"

#define ZLIB_CONST
#include <zlib/zlib.h>
#include <oozle/oozle.h>
#include <lzxlib/lzxdecoder.h>
#include <lz4.h>

#if defined(BCS_BUILD_HIGH_LEVEL_STUBBS) || defined(BCS_BUILD_HIGH_LEVEL_HALO1)
#include <tagdefinitions/halo1_pc64_guerilla/halo1-tools-pc64.h>
#include <tagcodegen/halo1_pc64_guerilla/halo1-pc64-public-pch.h>
#include <tagdefinitions/stubbs_pc64_cache_release/stubbs-pc64.h>
#include <tagcodegen/stubbs_pc64_cache_release/stubbs-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
#include <tagdefinitions/halo2_pc64_guerilla/halo2-tools-pc64.h>
#include <tagcodegen/halo2_pc64_guerilla/halo2-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include <tagdefinitions/halo3_pc64_guerilla/halo3-tools-pc64.h>
#include <tagcodegen/halo3_pc64_guerilla/halo3-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#include <tagdefinitions/halo3odst_pc64_guerilla/halo3odst-tools-pc64.h>
#include <tagcodegen/halo3odst_pc64_guerilla/halo3odst-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#include <tagdefinitions/haloreach_pc64_sapien/haloreach-tools-pc64.h>
#include <tagcodegen/haloreach_pc64_sapien/haloreach-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include <tagdefinitions/halo4_pc64_sapien/halo4-tools-pc64.h>
#include <tagcodegen/halo4_pc64_sapien/halo4-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include <tagdefinitions/groundhog_pc64_sapien/groundhog-pc64.h>
#include <tagcodegen/groundhog_pc64_sapien/groundhog-pc64-public-pch.h>
#endif