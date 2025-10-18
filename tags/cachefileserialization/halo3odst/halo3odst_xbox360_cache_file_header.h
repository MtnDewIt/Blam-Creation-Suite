#pragma once

/* ---------- types */

namespace halo3odst
{
	namespace xbox360
	{
		struct s_cache_file_tag_interop_type_fixup
		{
			dword interop_address;
			int32_t cache_file_interop_type;
		};
		static_assert(sizeof(s_cache_file_tag_interop_type_fixup) == 0x8);

		struct s_section
		{
			uint32_t count = 0;
			intptr32_t address = 0;
		};
		static_assert(sizeof(s_section) == 0x8);

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
			c_enum_no_init<halo3odst::e_scenario_type, short> scenario_type;
			c_enum_no_init<halo3odst::e_cache_file_shared_file_type, short> shared_cache_file_type;
			bool uncompressed;
			bool tracked;
			bool valid_shared_resource_usage;
			c_flags_no_init<halo3odst::e_cache_file_header_bit, unsigned char, k_num_cache_file_header_bits> header_flags;
			s_file_last_modification_date slot_modification_date;
			int32_t low_detail_texture_number;
			int32_t low_detail_texture_offset;
			int32_t low_detail_texture_byte_count;
			int32_t string_id_count;
			int32_t string_id_data_count;
			int32_t string_id_index_offset;
			int32_t string_id_data_offset;
			c_flags_no_init<halo3odst::e_cache_file_shared_file_type, unsigned char, halo3odst::k_number_of_shared_file_types> shared_map_usage;
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
			s_static_array<int32_t, halo3odst::k_number_of_cache_file_sections> section_offsets;
			s_static_array<halo3odst::s_cache_file_section_file_bounds, halo3odst::k_number_of_cache_file_sections> original_section_bounds;
			halo3odst::s_cache_file_shared_resource_usage shared_resource_usage;
			int8_t padding[480];
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
		static_assert(k_cache_file_header_size == 0x3000);

#pragma pack(push, 4)
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
		static_assert(k_cache_file_tags_header_size == 0x28);
	}
}