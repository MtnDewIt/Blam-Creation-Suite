#pragma once

class c_haloreach_cache_cluster;
class c_haloreach_cache_file_reader;

class c_haloreach_resource_reader : public c_resource_reader
{
public:
	c_haloreach_resource_reader(c_haloreach_cache_cluster& cache_cluster, c_haloreach_cache_file_reader& cache_reader);
	~c_haloreach_resource_reader();

private:
	c_haloreach_cache_cluster& cache_cluster;
	c_haloreach_cache_file_reader& cache_reader;
};
