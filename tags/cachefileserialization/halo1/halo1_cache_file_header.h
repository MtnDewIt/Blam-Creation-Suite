#pragma once

/* ---------- types */

namespace halo1
{
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
			int32_t tags_size;
			int32_t index_buffer_count;
			int32_t index_buffers_offset;
			c_static_string<32> name;
			c_static_string<32> build_number;
			short scenario_type;
			int32_t checksum;
			char unused2[0x794];
			tag footer_signature;
		};
		static_assert(sizeof(s_cache_file_header) == 0x800);
#pragma pack(pop)
	}

	namespace demo
	{
#pragma pack(push, 4)
		struct s_cache_file_header
		{
			char __data0[2];

			short scenario_type;

			char __data4[700];

			tag header_signature;
			int32_t tags_size;
			c_static_string<32> build_number;

			char __data2C8[672];

			int32_t version;
			c_static_string<32> name;

			char __data5AC[4];

			int32_t checksum;

			char __data5B4[52];

			int32_t size;
			int32_t tags_offset;
			tag footer_signature;

			char __data5F4[524];
		};
		static_assert(sizeof(s_cache_file_header) == 0x800);
#pragma pack(pop)
	}

	struct s_cache_file_tags_header
	{
		uint32_t tag_instances_address;
		uint32_t scenario_tag_index;

		uint32_t tags_checksum;

		uint32_t tag_count;

		int32_t vertex_buffer_count;
		uint32_t vertex_buffer_offset;

		int32_t index_buffer_count;
		uint32_t index_buffer_offset;

		int32_t vertex_index_buffer_size;

		uint32_t signature;
	};
	constexpr size_t k_halo1_cache_file_tags_header_size = sizeof(s_cache_file_tags_header);
	static_assert(k_halo1_cache_file_tags_header_size == 40, "sizeof(s_halo1_cache_file_tags_header) != 0x28");

	struct s_cache_file_tag_instance
	{
		tag group_tag;
		tag parent_group_tags[2];

		uint32_t tag_index;

		uint32_t name_address;
		uint32_t base_address;

		uint32_t bool_in_data_file;
		uint32_t unused1;
	};

	struct s_cache_file_resource_header
	{
		uint32_t type;
		uint32_t tag_names_offset;
		uint32_t tag_data_offset;
		uint32_t tag_instance_count;
	};

	struct s_cache_file_resource_instance
	{
		uint32_t name_address;
		uint32_t size;
		uint32_t address;
	};
}
