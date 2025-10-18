#pragma once

/* ---------- types */

namespace halo3 
{
	namespace pc 
	{
		struct s_cache_file_tag_interop_type_fixup
		{
			qword interop_address;
			int32_t cache_file_interop_type;
		};
		static_assert(sizeof(s_cache_file_tag_interop_type_fixup) == 0x10);

		struct s_section
		{
			uint32_t count = 0;
			intptr64_t address = 0;
		};
		static_assert(sizeof(s_section) == 0x10);

#pragma pack(push, 8)
		struct s_cache_file_header
		{
			tag header_signature;
			int32_t version;
			int32_t size;
			int8_t engine_type;
			int8_t platform_type;
			int8_t pad0[2];
			int32_t tags_offset;
			int32_t total_tags_size;
			c_enum_no_init<halo3::e_scenario_type, short> scenario_type;
			c_enum_no_init<halo3::e_cache_file_shared_file_type, short> shared_cache_file_type;
			bool uncompressed;
			bool tracked;
			bool valid_shared_resource_usage;
			c_flags_no_init<halo3::e_cache_file_header_bit, unsigned char, halo3::k_num_cache_file_header_bits> header_flags;
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
			int32_t language;
			int32_t minor_version_number;
			s_file_last_modification_date shared_creation_date[4];
			int8_t unknown1[16];
			c_static_string<32> creator_name;
			c_static_string<32> build_number;
			c_static_string<32> name;
			c_static_string<256> tag_path;
			c_static_string<256> path;
			uintptr64_t expected_base_address;
			uintptr64_t tags_header_when_loaded;
			int8_t unknown2[16];
			c_basic_buffer64<void> tag_post_link_buffer;
			c_basic_buffer64<void> tag_language_dependent_read_only_buffer;
			c_basic_buffer64<void> tag_language_dependent_read_write_buffer;
			c_basic_buffer64<void> tag_language_neutral_read_write_buffer;
			c_basic_buffer64<void> tag_language_neutral_write_combined_buffer;
			c_basic_buffer64<void> tag_language_neutral_read_only_buffer;
			int32_t realtime_checksum;
			int32_t content_hash_mask;
			int64_t signature_marker;
			s_network_http_request_hash content_hashes[3];
			int8_t rsa_key_blob_hash[32]; // your guess is as good as mine
			s_rsa_signature rsa_signature;
			s_static_array<int32_t, halo3::k_number_of_cache_file_sections> section_offsets;
			s_static_array<halo3::s_cache_file_section_file_bounds, halo3::k_number_of_cache_file_sections> original_section_bounds;
			halo3::s_cache_file_shared_resource_usage shared_resource_usage;
			int8_t padding[5412]; // There is definitely more data in the padding. No clue what or where tho
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
		static_assert(k_cache_file_header_size == 0x4000);

#pragma pack(push, 8)
		struct s_cache_file_tags_header
		{
			s_section tag_groups; // s_cache_file_tag_group
			s_section tag_instances; // s_cache_file_tag_instance
			s_section global_tag_indices; // s_cache_file_global_tag_index
			s_section tag_interop_fixups; // s_cache_file_tag_interop_type_fixup
			dword tags_checksum;
			uint32_t signature;
		};
#pragma pack(pop)
		static constexpr size_t k_cache_file_tags_header_size = sizeof(s_cache_file_tags_header);
		static_assert(k_cache_file_tags_header_size == 0x48);
	}
}