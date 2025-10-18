#include "cachefileserialization-private-pch.h"

template<> BCS_SHARED void byteswap_inplace(s_cache_file_header& header)
{
	byteswap_inplace(header.header_signature);
	byteswap_inplace(header.version);
	byteswap_inplace(header.size);
	byteswap_inplace(header.compressed_file_padding);
}
