#pragma once

class c_halo3odst_cache_cluster;
class c_halo3odst_cache_file_reader;

class c_halo3odst_resource_reader : public c_resource_reader
{
public:
	c_halo3odst_resource_reader(c_halo3odst_cache_cluster& cache_cluster, c_halo3odst_cache_file_reader& cache_reader);
	~c_halo3odst_resource_reader();

private:
	c_halo3odst_cache_cluster& cache_cluster;
	c_halo3odst_cache_file_reader& cache_reader;
};
