#include "../../../strange.h"

namespace strange
{
	var<symbol_a> any_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator_fp any_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "thing")
			{
				if (function == "create_from_range")
				{
					return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
