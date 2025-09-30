#pragma once

namespace halo4
{
	namespace pc
	{
//#pragma pack(push, 4)
//		struct s_cache_file_header : ::s_cache_file_header
//		{
//			intptr64_t tags_header_address;
//			int32_t tag_buffer_offset;
//			int32_t total_tags_size;
//			c_static_string<256> source_file;
//			c_static_string<32> build;
//			c_enum_no_init<gen3::e_scenario_type, short> scenario_type;
//			c_enum_no_init<gen3::e_scenario_load_type, short> scenario_load_type;
//			bool unknown140;
//			bool tracked_build;
//			bool unknown142; // something involved with packages
//			c_flags_no_init<gen3::e_cache_file_header_bit, unsigned char> header_flags;
//			int32_t unknown144;
//			int32_t unknown148;
//			int32_t unknown14C;
//			int32_t unknown150;
//			int32_t unknown154;
//			int32_t string_id_index_buffer_count;
//			int32_t string_id_string_storage_size;
//			int32_t string_id_index_buffer_offset;
//			int32_t string_id_string_storage_offset;
//			c_flags_no_init<gen3::e_cache_file_shared_file_type, unsigned char> shared_file_type_flags; // see cached_map_file_dependencies_loaded for more information
//			gen3::s_file_last_modification_date timestamp; // see cached_map_file_dependencies_loaded for more information
//			gen3::s_file_last_modification_date scenario_type_timestamps[3]; // see cached_map_file_dependencies_loaded for more information
//			c_static_string<32> name;
//			int32_t unknown1AC;
//			c_static_string<256> scenario_path;
//			int32_t minor_version;
//			int32_t file_count;
//			int32_t file_table_offset;
//			int32_t file_table_length;
//			int32_t file_table_indices_offset;
//
//			uint32_t tag_remap_count;
//			uint32_t tag_remap_address;
//			uint32_t dlc_tag_remap_count;
//			uint32_t dlc_tag_remap_address;
//
//			int32_t unknown2D4;
//			c_static_string<32> unknown2D8;
//			intptr64_t expected_base_address;
//			uint32_t xdk_version;
//			c_basic_buffer64<void> tag_post_link_buffer;
//			c_basic_buffer64<void> tag_language_dependent_read_only_buffer;
//			c_basic_buffer64<void> tag_language_dependent_read_write_buffer;
//			c_basic_buffer64<void> tag_language_neutral_read_write_buffer;
//			c_basic_buffer64<void> tag_language_neutral_write_combined_buffer;
//			c_basic_buffer64<void> tag_language_neutral_read_only_buffer;
//			int32_t unknown330;
//			int32_t unknown334;
//			int32_t unknown478;
//			int32_t unknown338;
//			gen3::s_network_http_request_hash hash;
//			gen3::s_rsa_signature rsa;
//			s_static_array<int32_t, gen3::k_number_of_cache_file_sections> offset_masks;
//			s_static_array<gen3::s_cache_file_section_file_bounds, gen3::k_number_of_cache_file_sections> section_file_bounds;
//			//unsigned int unknown4AC;
//
//			//unsigned __int8 gap4B0[100836];
//
//			//unsigned __int8 unknown18E94;
//			//unsigned __int8 unknown18E95;
//			//unsigned __int8 unknown18E96;
//			//unsigned __int8 unknown18E97;
//
//			//s_static_array<gen3::s_cache_file_insertion_point_resource_usage, 12> insertion_point_resource_usage;
//
//			//char gap1D728[16];
//
//			//uint32_t late_binding_tag_reference_fixup_info_count;
//			//uint32_t late_binding_tag_reference_fixup_info_address;
//
//			//char gap1D740[2236];
//			
//			tag footer_signature;
//
//			byteswap_inplace();
//		};
//#pragma pack(pop)
//
//
//		
//		static constexpr int32_t k_cache_file_header_size = sizeof(s_cache_file_header);
//		static_assert(k_cache_file_header_size == 0x1E000);
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
			s_file_last_modification_date shared_creation_date[3];
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

		struct s_cache_file_tags_header
		{
			s_section tag_groups; // s_cache_file_tag_group
			s_section tag_instances; // s_cache_file_tag_instance
			s_section global_tag_indices; // s_cache_file_global_tag_index
			s_section tag_interop_fixups; // s_cache_file_tag_interop_type_fixup
			int32_t unknown20;
			dword tags_checksum;
			uint32_t signature;
		};
		static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
		static_assert(k_cache_file_tags_header == 0x2C);

		bool cache_file_header_verify(s_cache_file_header& header);
	}
}
