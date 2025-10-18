#pragma once

enum e_groundhog_compression_codec : char
{
	_groundhog_compression_uncompressed,
	_groundhog_compression_xdkcompress
};

extern blofeld::s_tag_persistent_identifier k_groundhog_xdkcompress_codec_identifier;

int groundhog_codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
int groundhog_codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
