#pragma once

struct s_network_http_request_hash
{
	char hash[20];
};
static_assert(sizeof(s_network_http_request_hash) == 0x14);
