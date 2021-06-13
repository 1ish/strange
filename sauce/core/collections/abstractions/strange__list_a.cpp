#include "../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> list_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::list>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename list_a<element_d>::creator_fp list_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const list_s = sym("list");
			if (thing.o->equal(thing, list_s))
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
	template struct list_a<int64_t>;
}
