#pragma once

#include "base/rsa_signature.h"
#include "base/file_last_modification_date.h"
#include "base/network_http_request_hash.h"
#include "base/cache_file_build_info.h"
#include "base/cache_file_header.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
#include "halo1\halo1_cache_file_header.h"
#include "halo1\halo1_demo_cache_file_header.h"
#include "halo1\halo1_pc32_cache_file_header.h"
#include "halo1\halo1_pc64_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
#include "halo2\halo2_cache_file_header.h"
#include "halo2\halo2_alpha_xbox_cache_file_header.h"
#include "halo2\halo2_xbox_cache_file_header.h"
#include "halo2\halo2_pc32_cache_file_header.h"
#include "halo2\halo2_pc64_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include "halo3\halo3_cache_file_header.h"
#include "halo3\halo3_beta_xbox360_cache_file_header.h"
#include "halo3\halo3_xbox360_cache_file_header.h"
#include "halo3\halo3_xboxone_cache_file_header.h"
#include "halo3\halo3_pc_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#include "halo3odst\halo3odst_cache_file_header.h"
#include "halo3odst\halo3odst_xbox360_cache_file_header.h"
#include "halo3odst\halo3odst_pc_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "eldorado\eldorado_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#include "haloreach\haloreach_cache_file_header.h"
#include "haloreach\haloreach_alpha_xbox360_cache_file_header.h"
#include "haloreach\haloreach_xbox360_cache_file_header.h"
#include "haloreach\haloreach_pc_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include "halo4\halo4_cache_file_header.h"
#include "halo4\halo4_xbox360_cache_file_header.h"
#include "halo4\halo4_pc_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include "halo4\halo4_cache_file_header.h"
#include "halo4\halo4_pc_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
#include "haloinfinite\haloinfinite_cache_file_header.h"
#endif
