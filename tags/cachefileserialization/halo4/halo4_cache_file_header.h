#pragma once

namespace halo4
{
	struct s_cache_file_tag_group
	{
		tag group_tag;
		tag parent_group_tags[2];
		uint32_t name;
	};
	static_assert(sizeof(s_cache_file_tag_group) == 0x10);

	struct s_cache_file_tag_instance
	{
		unsigned short group_index;
		unsigned short tag_index_datum_header;
		uint32_t base_address;
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x8);

	struct s_cache_file_global_tag_index
	{
		uint32_t group_tag;
		int32_t tag_index;
	};
	static_assert(sizeof(s_cache_file_global_tag_index) == 0x8);

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

	namespace pc
	{
#pragma pack(push, 4)
		struct s_cache_file_header
		{
			tag header_signature;
			int32_t version;
			int32_t size;
			int32_t compressed_file_padding;
			int32_t tags_offset;
			int32_t total_tags_size;
			c_enum_no_init<gen4::e_scenario_type, short> scenario_type;
			c_enum_no_init<gen4::e_cache_file_shared_file_type, short> shared_cache_file_type;
			bool uncompressed;
			bool tracked;
			bool valid_shared_resource_usage;
			c_flags_no_init<gen4::e_cache_file_header_bit, unsigned char, gen4::k_num_cache_file_header_bits> header_flags;
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
			s_file_last_modification_date shared_creation_date[4]; // k_shared_resource_database_type_count
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
			s_static_array<int32_t, gen4::k_number_of_cache_file_sections> section_offsets;
			s_static_array<gen4::s_cache_file_section_file_bounds, gen4::k_number_of_cache_file_sections> original_section_bounds;
			gen4::s_cache_file_shared_resource_usage shared_resource_usage;
			int8_t unknown1D728[16];
			uint32_t late_binding_tag_reference_fixup_info_count;
			uint32_t late_binding_tag_reference_fixup_info_address;
			uint32_t cache_file_fixups_count;
			uint32_t cache_file_fixups_address;
			int8_t unknown1D738[16];
			uint32_t unknown1D73C;
			uint32_t unknown1D740;
			uint32_t unknown1D744;
			uint32_t unknown1D748;
			int8_t unknown1D74C[28];
			uint32_t unknown1D768;
			uint32_t unknown1D76C;
			int8_t padding[2088];
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_pc_cache_file_header = sizeof(s_cache_file_header);
		static_assert(k_pc_cache_file_header == 0x1E000);

		struct s_cache_file_tags_header
		{
			s_section tag_groups; // s_cache_file_tag_group (should be a 64 bit pointer)
			s_section tag_instances; // s_cache_file_tag_instance (should be a 64 bit pointer)
			s_section global_tag_indices; // s_cache_file_global_tag_index (should be a 64 bit pointer)
			s_section tag_interop_fixups; // s_cache_file_tag_interop_type_fixup (should be a 64 bit pointer)
			int32_t unknown20;
			dword tags_checksum;
			uint32_t signature;
		};
		static constexpr size_t k_pc_cache_file_tags_header = sizeof(s_cache_file_tags_header);
		static_assert(k_pc_cache_file_tags_header == 0x2C);
	}
	namespace xbox360
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
			c_enum_no_init<gen4::e_scenario_type, short> scenario_type;
			c_enum_no_init<gen4::e_cache_file_shared_file_type, short> shared_cache_file_type;
			bool uncompressed;
			bool tracked;
			bool valid_shared_resource_usage;
			c_flags_no_init<gen4::e_cache_file_header_bit, unsigned char, gen4::k_num_cache_file_header_bits> header_flags;
			s_file_last_modification_date slot_modification_date;
			int32_t low_detail_texture_number;
			int32_t low_detail_texture_offset;
			int32_t low_detail_texture_byte_count;
			int32_t string_id_count;
			int32_t string_id_data_count;
			int32_t string_id_index_offset;
			int32_t string_id_data_offset;
			c_flags_no_init<gen4::e_cache_file_shared_file_type, unsigned char, gen4::k_number_of_shared_file_types> shared_map_usage;
			s_file_last_modification_date creation_date;
			s_file_last_modification_date shared_creation_date[3]; // k_shared_resource_database_type_count
			c_static_string<32> name;
			int32_t language;
			c_static_string<256> tag_path;
			int32_t minor_version_number;
			int32_t debug_tag_name_count;
			int32_t debug_tag_name_data_offset;
			int32_t debug_tag_name_data_size;
			int32_t debug_tag_name_index_offset;
			uint32_t tag_remap_count; // c_wrapped_array tag_remap_info
			uint32_t tag_remap_address;
			uint32_t dlc_tag_remap_count; // c_wrapped_array dlc_tag_remap_info
			uint32_t dlc_tag_remap_address;
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
			s_static_array<int32_t, gen4::k_number_of_cache_file_sections> section_offsets;
			s_static_array<gen4::s_cache_file_section_file_bounds, gen4::k_number_of_cache_file_sections> original_section_bounds;
			gen4::s_cache_file_shared_resource_usage shared_resource_usage;
			int8_t unknown1D728[16];
			uint32_t late_binding_tag_reference_fixup_info_count;
			uint32_t late_binding_tag_reference_fixup_info_address;
			uint32_t cache_file_fixups_count;
			uint32_t cache_file_fixups_address;
			int8_t unknown1D738[16];
			uint32_t unknown1D73C;
			uint32_t unknown1D740;
			uint32_t unknown1D744;
			uint32_t unknown1D748;
			int8_t unknown1D74C[28];
			uint32_t unknown1D768; 
			uint32_t unknown1D76C;
			int8_t padding[2160];
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_xbox360_cache_file_header = sizeof(s_cache_file_header);
		static_assert(k_xbox360_cache_file_header == 0x1E000);

		struct s_cache_file_tags_header
		{
			s_section tag_groups; // s_cache_file_tag_group
			s_section tag_instances; // s_cache_file_tag_instance
			s_section global_tag_indices; // s_cache_file_global_tag_index
			s_section tag_interop_fixups; // s_cache_file_tag_interop_type_fixup
			dword tags_checksum;
			uint32_t signature;
		};
		static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
		static_assert(k_cache_file_tags_header == 0x28);

		bool cache_file_header_verify(s_cache_file_header& header);
	}
}
