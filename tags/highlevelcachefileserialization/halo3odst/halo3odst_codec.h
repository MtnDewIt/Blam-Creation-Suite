#pragma once

enum e_halo3odst_compression_codec : char
{
	_halo3odst_compression_uncompressed,
	_halo3odst_compression_xdkcompress
};

extern blofeld::s_tag_persistent_identifier k_halo3odst_xdkcompress_codec_identifier;

int h3odst_codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
int h3odst_codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
