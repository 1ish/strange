#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> numeric_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::numeric>"); //TODO cat
		return r;
	}

	typename numeric_a::creator_fp numeric_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "numeric")
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
