#pragma once

class c_halo4_cache_cluster;

class c_halo4_cache_file_reader : public c_cache_file_reader
{
public:
	c_halo4_cache_file_reader(c_halo4_cache_file_reader const&) = delete;
	BCS_SHARED c_halo4_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build);
	BCS_SHARED ~c_halo4_cache_file_reader();

	BCS_SHARED virtual BCS_RESULT get_build_info(s_cache_file_build_info& build_info) const override final;
	BCS_SHARED virtual BCS_RESULT get_debug_info(s_cache_file_debug_info& debug_info) const override final;
	BCS_SHARED BCS_RESULT get_section_buffer(e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const;
	BCS_SHARED virtual BCS_RESULT get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const override final;
	BCS_SHARED virtual BCS_RESULT get_buffers(s_cache_file_buffers_info& buffers_info) const override final;
	BCS_SHARED virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster) override final;
	BCS_SHARED virtual BCS_RESULT associate_cache_cluster(c_halo4_cache_cluster& cache_cluster) final;

	BCS_SHARED virtual BCS_RESULT virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const override final;
	BCS_SHARED virtual BCS_RESULT page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const override final;

	BCS_SHARED virtual BCS_RESULT get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const override final;

	c_fixed_wide_path filepath;
	s_engine_platform_build engine_platform_build;
	t_memory_mapped_file* file;
	s_memory_mapped_file_info file_info;
	c_halo4_cache_cluster* cache_cluster;

	BCS_SHARED BCS_RESULT get_tags_header_relative_offset(int32_t& tags_header_relative_offset) const;
	BCS_SHARED BCS_RESULT get_string_id_count(int32_t& string_id_count) const;
	BCS_SHARED BCS_RESULT get_string_id_index_offset(int32_t& string_id_index_offset) const;
	BCS_SHARED BCS_RESULT get_string_id_data_offset(int32_t& string_id_data_offset) const;
	BCS_SHARED BCS_RESULT get_string_id_data_count(int32_t& string_id_data_count) const;
	BCS_SHARED BCS_RESULT get_debug_tag_name_count(int32_t& debug_tag_name_count) const;
	BCS_SHARED BCS_RESULT get_debug_tag_name_index_offset(int32_t& debug_tag_name_index_offset) const;
	BCS_SHARED BCS_RESULT get_debug_tag_name_data_offset(int32_t& debug_tag_name_data_offset) const;
	BCS_SHARED BCS_RESULT get_debug_tag_name_data_size(int32_t& debug_tag_name_data_size) const;

	template<typename t_element>
	void byteswap_inplace(t_element& value)
	{
		if (get_platform_is_big_endian(engine_platform_build))
		{
			::byteswap_inplace(value);
		}
	}

	static constexpr char k_file_name_encryption_key[] = "LetsAllPlayNice!";
	static constexpr char k_string_id_encryption_key[] = "ILikeSafeStrings";
	static constexpr char k_localization_encryption_key[] = "BungieHaloReach!";
	static constexpr char k_network_encryption_key[] = "SneakerNetReigns";

private:
	union
	{
		s_cache_file_header cache_file_header;
		::halo4::pc::s_cache_file_header pc_cache_file_header;
		::halo4::xbox360::s_cache_file_header xbox360_cache_file_header;
	};
};
