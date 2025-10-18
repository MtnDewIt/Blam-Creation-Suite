#include "cachefileserialization-private-pch.h"

template<> BCS_SHARED void byteswap_inplace(s_file_last_modification_date& value)
{
	byteswap_inplace(value.filetime_low);
	byteswap_inplace(value.filetime_high);
}

BCS_RESULT file_date_format_for_output(s_file_last_modification_date* date, char* buffer, size_t buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	SYSTEMTIME SystemTime;
	FILETIME* lpFileTime = reinterpret_cast<FILETIME*>(date);
	
	if (!FileTimeToSystemTime(lpFileTime, &SystemTime))
	{
		return BCS_E_FAIL;
	}

	csnzprintf(
		buffer, 
		buffer_size, 
		"%d/%d/%d", 
		SystemTime.wMonth, 
		SystemTime.wDay, 
		SystemTime.wYear
	);

	return rs;
}


BCS_RESULT file_date_format_for_output_extended(s_file_last_modification_date* date, char* buffer, size_t buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	SYSTEMTIME SystemTime;
	FILETIME* lpFileTime = reinterpret_cast<FILETIME*>(date);

	if (!FileTimeToSystemTime(lpFileTime, &SystemTime))
	{
		return BCS_E_FAIL;
	}

	csnzprintf(
		buffer, 
		buffer_size, 
		"%04d-%02d-%02d %02d:%02d:%02d.%06d",
		SystemTime.wYear, 
		SystemTime.wMonth, 
		SystemTime.wDay, 
		SystemTime.wHour, 
		SystemTime.wMinute, 
		SystemTime.wSecond, 
		SystemTime.wMilliseconds
	);

	return rs;
}