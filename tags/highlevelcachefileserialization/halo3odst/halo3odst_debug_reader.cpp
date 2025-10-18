#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST

c_halo3odst_debug_reader::c_halo3odst_debug_reader(c_halo3odst_cache_cluster& cache_cluster, c_halo3odst_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	string_id_buffer(),
	//string_id_index_buffer(),
	debug_tag_name_buffer(),
	string_id_index_buffer(),
	encrypted_string_id_buffer(),
	encrypted_file_table_buffer(),
	debug_tag_name_index_buffer()
{
	s_cache_file_buffers_info buffers_info;
	BCS_FAIL_THROW(cache_reader.get_buffers(buffers_info));

	int32_t string_id_index_offset;
	BCS_FAIL_THROW(cache_reader.get_string_id_index_offset(string_id_index_offset));

	int32_t string_id_data_offset;
	BCS_FAIL_THROW(cache_reader.get_string_id_data_offset(string_id_data_offset));

	int32_t string_id_data_count;
	BCS_FAIL_THROW(cache_reader.get_string_id_data_count(string_id_data_count));

	int32_t debug_tag_name_index_offset;
	BCS_FAIL_THROW(cache_reader.get_debug_tag_name_index_offset(debug_tag_name_index_offset));

	int32_t debug_tag_name_data_offset;
	BCS_FAIL_THROW(cache_reader.get_debug_tag_name_data_offset(debug_tag_name_data_offset));

	int32_t debug_tag_name_data_size;
	BCS_FAIL_THROW(cache_reader.get_debug_tag_name_data_size(debug_tag_name_data_size));

	int32_t string_id_index_buffer_relative_offset = string_id_index_offset - buffers_info.debug_section_buffer.offset;
	string_id_index_buffer = reinterpret_cast<const uint32_t*>(buffers_info.debug_section_buffer.begin + string_id_index_buffer_relative_offset);

	int32_t string_id_buffer_relative_offset = string_id_data_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_string_id_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + string_id_buffer_relative_offset);

	// #TODO: Fix (tracked_aligned_malloc fails, either we're reading the wrong value for the storage size or the data itself isn't aligned properly)
	//string_id_buffer = static_cast<char*>(tracked_aligned_malloc(string_id_data_count, 16));
	//if (string_id_buffer == nullptr)
	//{
	//	throw(BCS_E_FAIL);
	//}
	//memcpy(string_id_buffer, encrypted_string_id_buffer, string_id_data_count);
	//aes128_decrypt(encrypted_string_id_buffer, string_id_buffer, string_id_data_count, c_halo3odst_cache_file_reader::k_string_id_encryption_key);

	int32_t debug_tag_name_index_buffer_relative_offset = debug_tag_name_index_offset - buffers_info.debug_section_buffer.offset;
	debug_tag_name_index_buffer = reinterpret_cast<const uint32_t*>(buffers_info.debug_section_buffer.begin + debug_tag_name_index_buffer_relative_offset);

	int32_t debug_tag_name_data_relative_offset = debug_tag_name_data_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_file_table_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + debug_tag_name_data_relative_offset);

	// #TODO: Fix (tracked_aligned_malloc fails, either we're reading the wrong value for the table length or the data itself isn't aligned properly)
	//debug_tag_name_buffer = static_cast<char*>(tracked_aligned_malloc(debug_tag_name_data_size, 16));
	//if (debug_tag_name_buffer == nullptr)
	//{
	//	throw(BCS_E_FAIL);
	//}
	//memcpy(debug_tag_name_buffer, encrypted_file_table_buffer, debug_tag_name_data_size);
	//aes128_decrypt(encrypted_file_table_buffer, debug_tag_name_buffer, debug_tag_name_data_size, c_halo3odst_cache_file_reader::k_file_name_encryption_key);
}

c_halo3odst_debug_reader::~c_halo3odst_debug_reader()
{
	tracked_aligned_free(string_id_buffer);
	//tracked_aligned_free(string_id_index_buffer);
	tracked_aligned_free(debug_tag_name_buffer);
}

BCS_RESULT c_halo3odst_debug_reader::string_id_to_string(string_id stringid, const char*& string)
{
	uint32_t const string_id_index = (stringid >> string_id_index_shift) & string_id_index_mask;
	uint32_t const string_id_namespace = (stringid >> string_id_namespace_shift) & string_id_namespace_mask;
	uint32_t const string_id_length = (stringid >> string_id_length_shift) & string_id_length_mask;

	return string_id_to_string(string_id_index, string_id_namespace, string_id_length, string);
}

BCS_RESULT c_halo3odst_debug_reader::string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string)
{
	BCS_RESULT rs = BCS_S_OK;

	uint32_t string_index;
	if (BCS_FAILED(rs = string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index)))
	{
		return rs;
	}

	// #TODO: Handle big endian 
	//int32_t string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	int32_t string_id_buffer_offset = string_id_index_buffer[string_index];
	string = string_id_buffer + string_id_buffer_offset;

	return rs;
}


BCS_RESULT c_halo3odst_debug_reader::get_tag_filepath(uint32_t tag_index, const char*& filepath)
{
	BCS_RESULT rs = BCS_S_OK;

	int32_t file_count;
	if (BCS_FAILED(rs = cache_reader.get_debug_tag_name_count(file_count)))
	{
		return rs;
	}

	if (tag_index < 0 || tag_index > static_cast<unsigned long>(file_count))
	{
		return BCS_E_FAIL;
	}

	// #TODO: Handle big endian 
	//uint32_t file_buffer_offset = _byteswap_ulong(file_table_index_buffer[tag_index]);
	uint32_t file_buffer_offset = debug_tag_name_index_buffer[tag_index];
	filepath = debug_tag_name_buffer + file_buffer_offset;

	return rs;
}

BCS_RESULT c_halo3odst_debug_reader::get_group_name(tag group_tag, const char*& group_name)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo3odst_debug_reader::get_group_id(tag group_tag, const char*& group_id)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo3odst_debug_reader::string_id_to_index(string_id stringid, uint32_t& string_index)
{
	uint32_t const string_id_index = (stringid & string_id_index_mask) >> string_id_index_shift;
	uint32_t const string_id_namespace = (stringid & string_id_namespace_mask) >> string_id_namespace_shift;
	uint32_t const string_id_length = (stringid & string_id_length_mask) >> string_id_length_shift;

	return string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index);
}

BCS_RESULT c_halo3odst_debug_reader::string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index)
{
	int32_t string_id_index_buffer_count;
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = cache_reader.get_string_id_count(string_id_index_buffer_count)))
	{
		return rs;
	}

	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
	{
		if (string_id_namespace > k_xbox360_engine_string_id_namespace_count)
		{
			return BCS_E_FAIL;
		}
		if (string_id_namespace == 0 && string_id_index > (string_id_index_buffer_count - (k_xbox360_engine_string_ids_total - k_xbox360_engine_set_counts[0])))
		{
			return BCS_E_FAIL;
		}
		if (string_id_namespace > 0 && string_id_index > k_xbox360_engine_set_counts[string_id_namespace])
		{
			return BCS_E_FAIL;
		}

		uint32_t offset = 0;
		if (string_id_namespace == 0 && string_id_index >= k_xbox360_engine_set_counts[0])
		{
			offset = k_xbox360_engine_string_ids_total - k_xbox360_engine_set_counts[0];
		}
		else
		{
			for (uint32_t namespace_index = 0; namespace_index < string_id_namespace; namespace_index++) // #TODO: pre calculate this table
			{
				// offset += cache_file.string_id_namespace_table[namespace_index] & 0x1FFFF; // halo reach cache table
				offset += k_xbox360_engine_set_counts[namespace_index];
			}
		}
		string_index = string_id_index + offset;
	}
	return rs;
	default:
		return BCS_E_UNSUPPORTED;
	}
	return BCS_E_UNSUPPORTED;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO3ODST
