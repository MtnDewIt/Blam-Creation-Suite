#pragma once

enum e_haloreach_compression_codec : char
{
	_haloreach_compression_uncompressed,
	_haloreach_compression_xdkcompress
};

extern blofeld::s_tag_persistent_identifier k_haloreach_xdkcompress_codec_identifier;

int hreach_codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
int hreach_codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
