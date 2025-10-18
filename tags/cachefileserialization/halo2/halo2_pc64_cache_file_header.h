#pragma once

/* ---------- types */

namespace halo2
{
	namespace pc64 
	{
#pragma pack(push, 8)
		struct s_cache_file_header
		{
			tag header_signature;
			int32_t version;
			int32_t size;
			int8_t engine_type;
			int8_t platform_type;
			int8_t pad0[2];
			uintptr64_t tags_header_when_loaded;
			short scenario_type; // c_enum_no_init<gen3::e_scenario_type, short> 
			short shared_cache_file_type; // c_enum_no_init<gen3::e_cache_file_shared_file_type, short>
			bool uncompressed;
			bool tracked;
			bool valid_shared_resource_usage;
			unsigned char header_flags; // c_flags_no_init<gen3::e_cache_file_header_bit, unsigned char, gen3::k_num_cache_file_header_bits>
			int32_t debug_tag_name_count;
			int32_t debug_tag_name_data_offset;
			int32_t debug_tag_name_data_size;
			int32_t debug_tag_name_index_offset;
			int32_t string_id_count;
			int32_t string_id_data_count;
			int32_t string_id_index_offset;
			int32_t string_id_data_offset;
			int32_t string_id_namespace_count;
			int32_t string_id_namespace_offset;
			s_file_last_modification_date shared_creation_date[3];
			int8_t unknown60[16];
			c_static_string<32> creator_name;
			c_static_string<32> build_number;
			c_static_string<32> name;
			c_static_string<256> tag_path;
			c_static_string<256> path;
			int32_t expected_base_address; // TODO: Confirm if pointer
			int32_t tags_instances_size; // TODO: Update if above true
			int32_t tag_data_size;
			int8_t unknown2DC[20];
			int32_t raw_table_offset;
			int32_t raw_table_size;
			int8_t unknown2F8[16];
			int32_t compressed_data_chunk_size;
			int32_t compressed_data_offset;
			int32_t compressed_chunk_table_offset;
			int32_t compressed_chunk_count;
			int8_t unused2[100];
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
		static_assert(k_cache_file_header_size == 0x380);
	}
}