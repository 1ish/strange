#include "../../../strange.h"

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
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const kind_s = sym("kind");
			if (thing.o->equal(thing, kind_s))
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
