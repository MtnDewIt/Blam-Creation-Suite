#pragma once

/* ---------- types */

namespace halo2
{
	namespace xbox 
	{
#pragma pack(push, 4)
		struct s_cache_file_header
		{
			tag header_signature;
			int32_t version;
			int32_t size;
			int32_t compressed_file_padding;
			int32_t tags_offset;
			int32_t tags_instances_size;
			int32_t tag_data_size;
			int32_t total_tags_size;
			c_static_string<256> path;
			c_static_string<32> build_number;
			short scenario_type; // c_enum_no_init<gen3::e_scenario_type, short> 
			short shared_cache_file_type; // c_enum_no_init<gen3::e_cache_file_shared_file_type, short>
			int32_t checksum;
			bool uncompressed;
			bool tracked;
			bool valid_shared_resource_usage;
			unsigned char header_flags; // c_flags_no_init<gen3::e_cache_file_header_bit, unsigned char, k_num_cache_file_header_bits>
			s_file_last_modification_date slot_modification_date;
			int32_t low_detail_texture_number;
			int32_t low_detail_texture_offset;
			int32_t low_detail_texture_byte_count;
			int32_t string_id_offset;
			int32_t string_id_count;
			int32_t string_id_data_count;
			int32_t string_id_index_offset;
			int32_t string_id_data_offset;
			bool shared_map_usage[3];
			int8_t pad3[1];
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
			int32_t custom_language_packs_offset;
			int32_t custom_language_packs_size;
			int32_t custom_runtime_gestalt_sound_definition_index;
			int32_t geometry_data_offset;
			int32_t geometry_data_size;
			int32_t realtime_checksum;
			int32_t mopp_checksum;
			int8_t unused2[1296];
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
		static_assert(k_cache_file_header_size == 0x800);
	}
}