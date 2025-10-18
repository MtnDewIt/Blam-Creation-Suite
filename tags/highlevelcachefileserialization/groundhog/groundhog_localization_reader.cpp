#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG

c_groundhog_localization_reader::c_groundhog_localization_reader(c_groundhog_cache_cluster& cache_cluster, c_groundhog_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{

}

c_groundhog_localization_reader::~c_groundhog_localization_reader()
{

}

#endif // BCS_BUILD_HIGH_LEVEL_GROUNDHOG
