#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> kind_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::kind>"); //TODO cat
		return r;
	}

	kind_a::creator_fp kind_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "kind")
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
