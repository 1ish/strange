#include "../../../strange.h"

namespace strange
{
	var<symbol_a> type_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::type>"); //TODO cat
		return r;
	}

	type_a::creator_fp type_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "type")
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
