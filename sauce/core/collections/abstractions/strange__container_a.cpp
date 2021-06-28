#include "../../../strange.h"

namespace strange
{
	var<symbol_a> container_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::container>"); //TODO cat
		return r;
	}

	container_a::creator_fp container_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "container")
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
