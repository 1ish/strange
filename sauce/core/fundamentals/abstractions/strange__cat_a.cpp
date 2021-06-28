#include "../../../strange.h"

namespace strange
{
	var<symbol_a> cat_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::cat>"); //TODO cat
		return r;
	}

	cat_a::creator_fp cat_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "cat")
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
