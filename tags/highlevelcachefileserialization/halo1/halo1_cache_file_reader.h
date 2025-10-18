#pragma once

class c_halo1_cache_cluster;

class c_halo1_header_wrapper
{
public:
	tag& header_signature;
	int32_t& version;
	int32_t& size;
	int32_t* compressed_file_padding;
	int32_t& tags_offset;
	int32_t& tags_size;
	int32_t* index_buffer_count;
	int32_t* index_buffers_offset;
	c_static_string<32>& name;
	c_static_string<32>& build_number;
	short& scenario_type;
	int32_t& checksum;
	tag& footer_signature;

	uint32_t const _structure_size;

	c_halo1_header_wrapper() = delete;
	c_halo1_header_wrapper(c_halo1_header_wrapper const&) = delete;
	c_halo1_header_wrapper& operator=(c_halo1_header_wrapper const&) = delete;

	c_halo1_header_wrapper(halo1::demo::s_cache_file_header& cache_file_header) :
		header_signature(cache_file_header.header_signature),
		version(cache_file_header.version),
		size(cache_file_header.size),
		compressed_file_padding(nullptr /*cache_file_header.compressed_file_padding*/),
		tags_offset(cache_file_header.tags_offset),
		tags_size(cache_file_header.tags_size),
		index_buffer_count(nullptr /*cache_file_header.index_buffer_count*/),
		index_buffers_offset(nullptr /*cache_file_header.index_buffers_offset*/),
		name(cache_file_header.name),
		build_number(cache_file_header.build_number),
		scenario_type(cache_file_header.scenario_type),
		checksum(cache_file_header.checksum),
		footer_signature(cache_file_header.footer_signature),
		_structure_size(sizeof(cache_file_header))
	{

	}

	c_halo1_header_wrapper(halo1::pc32::s_cache_file_header& cache_file_header) :
		header_signature(cache_file_header.header_signature),
		version(cache_file_header.version),
		size(cache_file_header.size),
		compressed_file_padding(&cache_file_header.compressed_file_padding),
		tags_offset(cache_file_header.tags_offset),
		tags_size(cache_file_header.tags_size),
		index_buffer_count(&cache_file_header.index_buffer_count),
		index_buffers_offset(&cache_file_header.index_buffers_offset),
		name(cache_file_header.name),
		build_number(cache_file_header.build_number),
		scenario_type(cache_file_header.scenario_type),
		checksum(cache_file_header.checksum),
		footer_signature(cache_file_header.footer_signature),
		_structure_size(sizeof(cache_file_header))
	{

	}

	c_halo1_header_wrapper(halo1::pc64::s_cache_file_header& cache_file_header) :
		header_signature(cache_file_header.header_signature),
		version(cache_file_header.version),
		size(cache_file_header.size),
		compressed_file_padding(nullptr /*cache_file_header.compressed_file_padding*/),
		tags_offset(cache_file_header.tags_offset),
		tags_size(cache_file_header.tags_size),
		index_buffer_count(&cache_file_header.index_buffer_count),
		index_buffers_offset(&cache_file_header.index_buffers_offset),
		name(cache_file_header.name),
		build_number(cache_file_header.build_number),
		scenario_type(cache_file_header.scenario_type),
		checksum(cache_file_header.checksum),
		footer_signature(cache_file_header.footer_signature),
		_structure_size(sizeof(cache_file_header))
	{

	}
};

class c_halo1_cache_file_reader : public c_cache_file_reader
{
public:
	c_halo1_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build);
	~c_halo1_cache_file_reader();

	virtual BCS_RESULT get_build_info(s_cache_file_build_info& build_info) const;
	virtual BCS_RESULT get_debug_info(s_cache_file_debug_info& debug_info) const;
	BCS_RESULT get_section_buffer(e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffers(s_cache_file_buffers_info& buffers_info) const;
	virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster);
	virtual BCS_RESULT associate_cache_cluster(c_halo1_cache_cluster& cache_cluster);

	virtual BCS_RESULT virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const;
	virtual BCS_RESULT page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const;

	virtual BCS_RESULT get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const;

	BCS_RESULT get_cache_file_resource_instance(uint32_t index, const halo1::s_cache_file_resource_instance*& cache_file_resource_instance);
	BCS_RESULT get_cache_file_resource_instance_data(uint32_t index, const void*& tag_instance_data);
	BCS_RESULT get_cache_file_resource_instance_name(uint32_t index, const char*& tag_instance_name);

	bool is_resource_file;

	c_fixed_wide_path filepath;
	s_engine_platform_build engine_platform_build;
	t_memory_mapped_file* file;
	s_memory_mapped_file_info file_info;
	c_halo1_cache_cluster* cache_cluster;

	c_halo1_header_wrapper* cache_file_header;
	halo1::s_cache_file_resource_header* cache_file_resource_header;


	static constexpr char k_file_name_encryption_key[] = "LetsAllPlayNice!";
	static constexpr char k_string_id_encryption_key[] = "ILikeSafeStrings";
	static constexpr char k_localization_encryption_key[] = "BungieHaloReach!";
	static constexpr char k_network_encryption_key[] = "SneakerNetReigns";
};
