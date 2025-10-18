#pragma once

struct s_file_last_modification_date
{
	uint32_t filetime_low;
	uint32_t filetime_high;
};
static_assert(sizeof(s_file_last_modification_date) == 8);

BCS_SHARED BCS_RESULT file_date_format_for_output(s_file_last_modification_date* date, char* buffer, size_t buffer_size);
BCS_SHARED BCS_RESULT file_date_format_for_output_extended(s_file_last_modification_date* date, char* buffer, size_t buffer_size);