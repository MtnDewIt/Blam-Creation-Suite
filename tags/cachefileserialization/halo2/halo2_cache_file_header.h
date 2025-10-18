#pragma once

/* ---------- types */

namespace halo2 
{
	struct s_cache_file_tag_instance
	{
		tag group_tag;
		uint32_t tag_index;
		uint32_t offset_from_base_address;
		uint32_t aligned_tag_size;
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x10);

#pragma pack(push, 4)
	struct s_cache_file_tags_header
	{
		uintptr32_t tag_groups; 
		int32_t tag_group_count;
		uintptr32_t tag_instances;
		int32_t scenario_tag_index;
		int32_t game_globals_tag_index;
		int32_t tags_checksum;
		int32_t tag_count;
		tag signature;
	};
#pragma pack(pop)
	static constexpr size_t k_cache_file_tags_header_size = sizeof(s_cache_file_tags_header);
	static_assert(k_cache_file_tags_header_size == 0x20);
}