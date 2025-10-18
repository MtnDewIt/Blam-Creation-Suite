#pragma once

/* ---------- types */

namespace halo1 
{
	namespace pc32
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