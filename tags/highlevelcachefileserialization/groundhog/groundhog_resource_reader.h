#pragma once

class c_groundhog_cache_cluster;
class c_groundhog_cache_file_reader;

class c_groundhog_resource_reader : public c_resource_reader
{
public:
	c_groundhog_resource_reader(c_groundhog_cache_cluster& cache_cluster, c_groundhog_cache_file_reader& cache_reader);
	~c_groundhog_resource_reader();

private:
	c_groundhog_cache_cluster& cache_cluster;
	c_groundhog_cache_file_reader& cache_reader;
};
