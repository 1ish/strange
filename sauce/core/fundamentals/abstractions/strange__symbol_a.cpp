#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> symbol_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator_fp symbol_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "symbol")
			{
				if (function == "create_from_range")
				{
					return symbol_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
