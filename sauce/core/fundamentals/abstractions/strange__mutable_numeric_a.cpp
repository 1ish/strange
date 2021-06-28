#include "../../../strange.h"

namespace strange
{
	var<symbol_a> mutable_numeric_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::mutable_numeric>"); //TODO cat
		return r;
	}

	typename mutable_numeric_a::creator_fp mutable_numeric_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "mutable_numeric")
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
