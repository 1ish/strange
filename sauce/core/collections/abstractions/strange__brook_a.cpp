#include "../../../strange.h"

namespace strange
{
	var<symbol_a> brook_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::brook>"); //TODO cat
		return r;
	}

	typename brook_a::creator_fp brook_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "brook")
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
