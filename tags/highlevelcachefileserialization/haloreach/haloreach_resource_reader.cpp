#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH

c_haloreach_resource_reader::c_haloreach_resource_reader(c_haloreach_cache_cluster& cache_cluster, c_haloreach_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{

}

c_haloreach_resource_reader::~c_haloreach_resource_reader()
{

}

#endif // BCS_BUILD_HIGH_LEVEL_HALOREACH
