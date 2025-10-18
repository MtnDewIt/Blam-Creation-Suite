#pragma once

/* ---------- constants */

constexpr tag k_cache_header_signature = 'head';
constexpr tag k_cache_footer_signature = 'foot';
constexpr tag k_module_header_signature = 'mohd';
constexpr tag k_cache_tags_signature = 'tags';
constexpr tag k_cache_343i_signature = '343i';

/* ---------- definitions */

struct s_cache_file_header
{
	tag header_signature;
	int32_t version;
	int32_t size;
	int32_t compressed_file_padding;
};
