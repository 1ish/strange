#include "../../../../strange.h"

namespace strange
{
	template <typename... elements_d>
	var<symbol_a> tuple_range_a<elements_d...>::cat(con<> const& me)
	{
		static auto r = sym("<strange::tuple_range>"); //TODO cat
		return r;
	}

	template <typename... elements_d>
	typename tuple_range_a<elements_d...>::creator_fp tuple_range_a<elements_d...>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const tuple_range_s = sym("tuple_range");
			if (thing.o->equal(thing, tuple_range_s))
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

	// instantiation
	template struct tuple_range_a<int64_t>;
}