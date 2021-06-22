#include "../../../strange.h"

namespace strange
{
	var<symbol_a> lake_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::lake>"); //TODO cat
		return r;
	}

	typename lake_a::creator_fp lake_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const lake_s = sym("lake");
			if (thing.o->equal(thing, lake_s))
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
