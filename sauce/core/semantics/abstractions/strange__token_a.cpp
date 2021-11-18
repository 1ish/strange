#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> token_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::token>"); //TODO cat
		return r;
	}

	typename token_a::creator_fp token_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "token")
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
