#include "../../../strange.h"

namespace strange
{
	template <typename... elements_d>
	var<symbol_a> tuple_a<elements_d...>::cat(con<> const& me)
	{
		static auto r = sym("<strange::tuple>"); //TODO cat
		return r;
	}

	template <typename... elements_d>
	typename tuple_a<elements_d...>::creator_fp tuple_a<elements_d...>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const tuple_s = sym("tuple");
			if (thing.o->equal(thing, tuple_s))
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
	template struct tuple_a<int64_t>;
}
