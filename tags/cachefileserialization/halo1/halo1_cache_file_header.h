#pragma once

/* ---------- types */

namespace halo1
{
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
	static_assert(sizeof(s_cache_file_tag_instance) == 0x20);

	struct s_cache_file_resource_instance
	{
		uint32_t name_address;
		uint32_t size;
		uint32_t address;
	};
	static_assert(sizeof(s_cache_file_resource_instance) == 0xC);

	struct s_cache_file_resource_header
	{
		uint32_t type;
		uint32_t tag_names_offset;
		uint32_t tag_data_offset;
		uint32_t tag_instance_count;
	};
	static_assert(sizeof(s_cache_file_resource_header) == 0x10);

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
	static_assert(k_halo1_cache_file_tags_header_size == 0x28);
}
