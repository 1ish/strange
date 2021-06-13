#include "../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> mutator_range_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::mutator_range>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename mutator_range_a<element_d>::creator_fp mutator_range_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const mutator_range_s = sym("mutator_range");
			if (thing.o->equal(thing, mutator_range_s))
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
	template struct mutator_range_a<int64_t>;
}
