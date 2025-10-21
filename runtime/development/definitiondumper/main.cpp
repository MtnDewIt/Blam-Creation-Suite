#include "definitiondumper-private-pch.h"

extern "C" int bcs_main()
{
	BCS_RESULT rs = BCS_S_OK;

	c_definition_dumper* definition_dumper = new() c_definition_dumper();

	if (BCS_FAILED(rs = definition_dumper->dump_definitions()))
	{
		return rs;
	}

	delete definition_dumper;

	return rs;
}
