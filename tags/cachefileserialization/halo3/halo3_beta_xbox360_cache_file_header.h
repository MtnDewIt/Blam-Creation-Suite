#pragma once

/* ---------- types */

namespace halo3
{
	namespace xbox360
	{
		namespace beta 
		{
#pragma pack(push, 4)
			struct s_cache_file_header
			{
				tag header_signature;
				int32_t version;
				int32_t size;
				int32_t compressed_file_padding;
				uintptr32_t tags_header_when_loaded;
				int32_t tags_offset;
				int32_t total_tags_size;
				c_static_string<256> path;
				c_static_string<32> build_number;
				c_enum_no_init<halo3::e_scenario_type, short> scenario_type;
				c_enum_no_init<halo3::e_cache_file_shared_file_type, short> shared_cache_file_type;
				int32_t checksum;
				bool uncompressed;
				bool tracked;
				bool valid_shared_resource_usage;
				c_flags_no_init<halo3::e_cache_file_header_bit, unsigned char, k_num_cache_file_header_bits> header_flags;
				s_file_last_modification_date slot_modification_date;
				int32_t low_detail_texture_number;
				int32_t low_detail_texture_offset;
				int32_t low_detail_texture_byte_count;
				int32_t string_id_offset;
				int32_t string_id_count;
				int32_t string_id_data_count;
				int32_t string_id_index_offset;
				int32_t string_id_data_offset;
				c_flags_no_init<halo3::e_cache_file_shared_file_type, unsigned char, halo3::k_number_of_shared_file_types> shared_map_usage;
				s_file_last_modification_date creation_date;
				s_file_last_modification_date shared_creation_date[3];
				c_static_string<32> name;
				int32_t language;
				c_static_string<256> tag_path;
				int32_t minor_version_number;
				int32_t debug_tag_name_count;
				int32_t debug_tag_name_data_offset;
				int32_t debug_tag_name_data_size;
				int32_t debug_tag_name_index_offset;
				int32_t realtime_checksum;
				c_static_string<32> creator_name;
				uintptr32_t expected_base_address;
				uint32_t xdk_version;
				// #TODO: Confirm if these buffers are valid for halo 3 beta
				c_basic_buffer32<void> tag_post_link_buffer;
				c_basic_buffer32<void> tag_language_dependent_read_only_buffer;
				c_basic_buffer32<void> tag_language_dependent_read_write_buffer;
				// #TODO: Map data that exists in padding
				int8_t padding[1260];
				tag footer_signature;
			};
#pragma pack(pop)
			static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
			static_assert(k_cache_file_header_size == 0x800);
		}
	}
}