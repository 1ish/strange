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
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const mutable_numeric_s = sym("mutable_numeric");
			if (thing.o->equal(thing, mutable_numeric_s))
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
