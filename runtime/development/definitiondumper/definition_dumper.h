#pragma once

class c_definition_dumper 
{
public:
	c_definition_dumper();
	~c_definition_dumper();

	s_engine_platform_build engine_platform_build;
	c_runtime_tag_definitions* runtime_tag_definitions = new() c_runtime_tag_definitions();

	c_fixed_wide_path regex;

	std::vector<const wchar_t*> candidates;

	BCS_RESULT dump_definitions();
};