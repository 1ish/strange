#include "../../../strange.h"

namespace strange
{
	var<symbol_a> river_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::river>"); //TODO cat
		return r;
	}

	typename river_a::creator_fp river_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "river")
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
