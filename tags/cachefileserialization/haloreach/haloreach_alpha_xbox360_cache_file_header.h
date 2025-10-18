#pragma once

/* ---------- types */

namespace haloreach
{
	namespace xbox360
	{
		namespace alpha 
		{
			struct s_cache_file_local_resource_location
			{
				// #TODO: Handle byteswapping bitfields
				//int32_t flags : 2;
				//int32_t file_size : 30;

				int32_t flags_and_file_size;
				int32_t memory_size;
				s_network_http_request_hash entire_checksum;
			};
			static_assert(sizeof(s_cache_file_local_resource_location) == 0x1C);

			struct s_cache_file_insertion_point_resource_usage
			{
				int8_t initial_zone_set_index;
				int8_t pad[3];
				int32_t shared_required_locations[32]; // c_static_flags<1024>
				int32_t local_required_locations[10]; // c_static_flags<320>
				int8_t unknownAC[8];
			};
			static_assert(sizeof(s_cache_file_insertion_point_resource_usage) == 0xB4);

			struct s_cache_file_shared_resource_usage
			{
				uint32_t shared_layout_identifier[4]; // s_tag_persistent_identifier
				int16_t shared_location_count;
				int16_t local_location_count;
				int32_t first_file_offset;
				uint32_t codec_identifier[4]; // s_tag_persistent_identifier
				s_static_array<s_cache_file_local_resource_location, 320> local_locations;
				int8_t insertion_point_usage_count;
				int8_t pad[3];
				s_static_array<s_cache_file_insertion_point_resource_usage, 9> insertion_point_usages;
			};
			static_assert(sizeof(s_cache_file_shared_resource_usage) == 0x2980);

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
				c_enum_no_init<haloreach::e_scenario_type, short> scenario_type;
				c_enum_no_init<haloreach::e_cache_file_shared_file_type, short> shared_cache_file_type;
				bool uncompressed;
				bool tracked;
				bool valid_shared_resource_usage;
				c_flags_no_init<haloreach::e_cache_file_header_bit, unsigned char, k_num_cache_file_header_bits> header_flags;
				s_file_last_modification_date slot_modification_date;
				int32_t low_detail_texture_number;
				int32_t low_detail_texture_offset;
				int32_t low_detail_texture_byte_count;
				int32_t string_id_count;
				int32_t string_id_data_count;
				int32_t string_id_index_offset;
				int32_t string_id_data_offset;
				c_flags_no_init<haloreach::e_cache_file_shared_file_type, unsigned char, haloreach::k_number_of_shared_file_types> shared_map_usage;
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
				c_basic_buffer32<void> tag_post_link_buffer;
				c_basic_buffer32<void> tag_language_dependent_read_only_buffer;
				c_basic_buffer32<void> tag_language_dependent_read_write_buffer;
				c_basic_buffer32<void> tag_language_neutral_read_write_buffer;
				c_basic_buffer32<void> tag_language_neutral_write_combined_buffer;
				c_basic_buffer32<void> tag_language_neutral_read_only_buffer;
				int32_t content_hash_mask;
				int32_t pad2[1];
				int64_t signature_marker;
				s_network_http_request_hash content_hashes[3];
				s_rsa_signature rsa_signature;
				s_static_array<int32_t, haloreach::k_number_of_cache_file_sections> section_offsets;
				s_static_array<haloreach::s_cache_file_section_file_bounds, haloreach::k_number_of_cache_file_sections> original_section_bounds;
				s_cache_file_shared_resource_usage shared_resource_usage;
				int8_t padding[4576];
				tag footer_signature;
			};
#pragma pack(pop)
			static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
			static_assert(k_cache_file_header_size == 0x4000);
		}
	}
}