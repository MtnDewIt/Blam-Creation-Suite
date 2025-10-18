#pragma once

/* ---------- types */

namespace eldorado
{
    struct s_strings_file_header
	{
		unsigned int string_count;
		unsigned int string_data_size;
	};
	static_assert(sizeof(s_strings_file_header) == 0x8);

    struct s_cache_file_tag_instance
	{
		dword checksum;
		dword total_size;
		short dependency_count;
		short data_fixup_count;
		short resource_fixup_count;
		short padding;
		dword offset; // offset from `base`
		tag group_tags[3];
		dword group_name; // string id
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x24);

    struct s_cache_file_section_header
	{
		dword __unknown0;
		int file_offsets;
		int file_count;
		dword __unknownC;
		s_file_last_modification_date creation_date;
		dword __unknown18;
		dword __unknown1C;
	};
	static_assert(sizeof(s_cache_file_section_header) == 0x20);
}