#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> reader_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::reader>"); //TODO cat
		return r;
	}

	typename reader_a::creator_fp reader_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "reader")
			{
				if (function == "create_from_range")
				{
					// return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
