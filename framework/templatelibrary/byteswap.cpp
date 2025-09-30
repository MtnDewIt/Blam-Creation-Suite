#include "templatelibrary-private-pch.h"

template<> BCS_SHARED void byteswap_inplace<char>(char& value)
{
	// swallow
}

template<> BCS_SHARED void byteswap_inplace<int8_t>(int8_t& value)
{
	// swallow
}

template<> BCS_SHARED void byteswap_inplace<uint8_t>(uint8_t& value)
{
	// swallow
}

template<> BCS_SHARED void byteswap_inplace<int16_t>(int16_t& value)
{
	value = static_cast<int16_t>(_byteswap_ushort(static_cast<unsigned short>(value)));
}

template<> BCS_SHARED void byteswap_inplace<uint16_t>(uint16_t& value)
{
	value = _byteswap_ushort(value);
}

template<> BCS_SHARED void byteswap_inplace<long>(long& value)
{
	value = static_cast<long>(_byteswap_ulong(static_cast<unsigned long>(value)));
}

template<> BCS_SHARED void byteswap_inplace<unsigned long>(unsigned long& value)
{
	value = _byteswap_ulong(value);
}

template<> BCS_SHARED void byteswap_inplace<int32_t>(int32_t& value)
{
	value = static_cast<int32_t>(_byteswap_ulong(static_cast<unsigned long>(value)));
}

template<> BCS_SHARED void byteswap_inplace<uint32_t>(uint32_t& value)
{
	value = _byteswap_ulong(value);
}

template<> BCS_SHARED void byteswap_inplace<int64_t>(int64_t& value)
{
	value = static_cast<int64_t>(_byteswap_uint64(static_cast<uint64_t>(value)));
}

template<> BCS_SHARED void byteswap_inplace<uint64_t>(uint64_t& value)
{
	value = _byteswap_uint64(value);
}

template<> BCS_SHARED void byteswap_inplace<bool>(bool& value)
{
	// swallow
}
