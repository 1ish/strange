#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> expression_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::expression>"); //TODO cat
		return r;
	}

	typename expression_a::creator_fp expression_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "expression")
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
