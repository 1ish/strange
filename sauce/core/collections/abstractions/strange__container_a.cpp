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
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const container_s = sym("container");
			if (thing.o->equal(thing, container_s))
			{
				static auto const create_from_range_s = sym("create_from_range");
				if (function.o->equal(function, create_from_range_s))
				{
					// return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
