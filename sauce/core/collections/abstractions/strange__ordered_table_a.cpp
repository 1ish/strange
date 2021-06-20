#include "../../../strange.h"

namespace strange
{
	template <typename key_d, typename value_d>
	var<symbol_a> ordered_table_a<key_d, value_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::ordered_table>"); //TODO cat
		return r;
	}

	template <typename key_d, typename value_d>
	typename ordered_table_a<key_d, value_d>::creator_fp ordered_table_a<key_d, value_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const ordered_table_s = sym("ordered_table");
			if (thing.o->equal(thing, ordered_table_s))
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
	template struct ordered_table_a<int64_t, int64_t>;
}
