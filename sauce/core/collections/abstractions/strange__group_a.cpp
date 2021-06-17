#include "../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> group_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::group>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename group_a<element_d>::creator_fp group_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const group_s = sym("group");
			if (thing.o->equal(thing, group_s))
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
	template struct group_a<int64_t>;
}
