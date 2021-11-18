#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> unlock_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::unlock>"); //TODO cat
		return r;
	}

	unlock_a::creator_fp unlock_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "unlock")
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
