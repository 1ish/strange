#include "../../../strange.h"

namespace strange
{
	var<symbol_a> any_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator_fp any_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const thing_s = sym("thing");
			if (thing.o->equal(thing, thing_s))
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
