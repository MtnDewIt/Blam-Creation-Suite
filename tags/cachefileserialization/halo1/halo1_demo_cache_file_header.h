#pragma once

/* ---------- types */

namespace halo1 
{
	namespace demo
	{
#pragma pack(push, 4)
		struct s_cache_file_header
		{
			char __data0[2];
			short scenario_type;
			int8_t pad[2];
			char __data4[698];
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
#pragma pack(pop)
		static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
		static_assert(k_cache_file_header_size == 0x800);
	}
}