#pragma once

#include "high_level_transplant_context.h"

#include "base/cache_file_api.h"
#include "base/cache_file_reader.h"
#include "base/cache_cluster.h"
#include "base/debug_reader.h"
#include "base/localization_reader.h"
#include "base/resource_reader.h"
#include "base/tag_reader.h"
#include "base/tag_group.h"
#include "base/tag_instance.h"
#include "base/api_interop.h"
#include "base/postprocessing_fixup.h"
#include "base/type_iteration_helpers.h"

#if defined(BCS_BUILD_HIGH_LEVEL_STUBBS) || defined(BCS_BUILD_HIGH_LEVEL_HALO1)
#include "halo1/halo1_cache_file_reader.h"
#include "halo1/halo1_cache_cluster.h"
#include "halo1/halo1_debug_reader.h"
#include "halo1/halo1_localization_reader.h"
#include "halo1/halo1_resource_reader.h"
#include "halo1/halo1_tag_reader.h"
#include "halo1/halo1_tag_group.h"
#include "halo1/halo1_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
#include "halo2/halo2_cache_file_reader.h"
#include "halo2/halo2_cache_cluster.h"
#include "halo2/halo2_debug_reader.h"
#include "halo2/halo2_localization_reader.h"
#include "halo2/halo2_resource_reader.h"
#include "halo2/halo2_tag_reader.h"
#include "halo2/halo2_tag_group.h"
#include "halo2/halo2_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include "halo3/halo3_codec.h"
#include "halo3/halo3_api_interop.h"
#include "halo3/halo3_cache_file_reader.h"
#include "halo3/halo3_cache_cluster.h"
#include "halo3/halo3_debug_reader.h"
#include "halo3/halo3_localization_reader.h"
#include "halo3/halo3_resource_reader.h"
#include "halo3/halo3_tag_reader.h"
#include "halo3/halo3_tag_group.h"
#include "halo3/halo3_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#include "halo3odst/halo3odst_codec.h"
#include "halo3odst/halo3odst_api_interop.h"
#include "halo3odst/halo3odst_cache_file_reader.h"
#include "halo3odst/halo3odst_cache_cluster.h"
#include "halo3odst/halo3odst_debug_reader.h"
#include "halo3odst/halo3odst_localization_reader.h"
#include "halo3odst/halo3odst_resource_reader.h"
#include "halo3odst/halo3odst_tag_reader.h"
#include "halo3odst/halo3odst_tag_group.h"
#include "halo3odst/halo3odst_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "eldorado/eldorado_api_interop.h"
#include "eldorado/eldorado_cache_file_reader.h"
#include "eldorado/eldorado_cache_cluster.h"
#include "eldorado/eldorado_debug_reader.h"
#include "eldorado/eldorado_localization_reader.h"
#include "eldorado/eldorado_resource_reader.h"
#include "eldorado/eldorado_resource_handle.h"
#include "eldorado/eldorado_tag_reader.h"
#include "eldorado/eldorado_tag_group.h"
#include "eldorado/eldorado_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#include "haloreach/haloreach_codec.h"
#include "haloreach/haloreach_api_interop.h"
#include "haloreach/haloreach_cache_file_reader.h"
#include "haloreach/haloreach_cache_cluster.h"
#include "haloreach/haloreach_debug_reader.h"
#include "haloreach/haloreach_localization_reader.h"
#include "haloreach/haloreach_resource_reader.h"
#include "haloreach/haloreach_tag_reader.h"
#include "haloreach/haloreach_tag_group.h"
#include "haloreach/haloreach_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include "halo4/halo4_codec.h"
#include "halo4/halo4_api_interop.h"
#include "halo4/halo4_cache_file_reader.h"
#include "halo4/halo4_cache_cluster.h"
#include "halo4/halo4_debug_reader.h"
#include "halo4/halo4_localization_reader.h"
#include "halo4/halo4_resource_reader.h"
#include "halo4/halo4_tag_reader.h"
#include "halo4/halo4_tag_group.h"
#include "halo4/halo4_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include "groundhog/groundhog_codec.h"
#include "groundhog/groundhog_api_interop.h"
#include "groundhog/groundhog_cache_file_reader.h"
#include "groundhog/groundhog_cache_cluster.h"
#include "groundhog/groundhog_debug_reader.h"
#include "groundhog/groundhog_localization_reader.h"
#include "groundhog/groundhog_resource_reader.h"
#include "groundhog/groundhog_tag_reader.h"
#include "groundhog/groundhog_tag_group.h"
#include "groundhog/groundhog_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
#include "haloinfinite/infinite_cache_file_reader.h"
#include "haloinfinite/infinite_cache_cluster.h"
#include "haloinfinite/infinite_debug_reader.h"
#include "haloinfinite/infinite_localization_reader.h"
#include "haloinfinite/infinite_resource_reader.h"
#include "haloinfinite/infinite_tag_reader.h"
#include "haloinfinite/infinite_tag_group.h"
#include "haloinfinite/infinite_tag_instance.h"
#include "haloinfinite/infinite_ucs_reader.h"
#include "haloinfinite/infinite_generic_module_file_entry.h"
#include "haloinfinite/infinite_file_entry_block_map.h"
#endif
