#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> lock_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::lock>"); //TODO cat
		return r;
	}

	lock_a::creator_fp lock_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "lock")
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
