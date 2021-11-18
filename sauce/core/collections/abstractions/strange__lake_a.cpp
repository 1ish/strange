#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> lake_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::lake>"); //TODO cat
		return r;
	}

	typename lake_a::creator_fp lake_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "lake")
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
