#pragma once

/* ---------- types */

namespace halo1
{
	namespace pc64
	{
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
			int32_t tags_size;
			int32_t index_buffer_count;
			int32_t index_buffers_offset;
			c_static_string<32> name;
			c_static_string<32> build_number;
			short scenario_type;
			int8_t pad[2];
			int32_t checksum;
			char unused2[0x794];
			tag footer_signature;
		};
#pragma pack(pop)
		static constexpr size_t k_cache_file_header_size = sizeof(s_cache_file_header);
		static_assert(k_cache_file_header_size == 0x800);
	}
}