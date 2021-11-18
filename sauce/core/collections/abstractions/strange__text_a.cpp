#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> text_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::text>"); //TODO cat
		return r;
	}

	typename text_a::creator_fp text_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "text")
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
