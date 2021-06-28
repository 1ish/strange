#include "../../../strange.h"

namespace strange
{
	template <typename type_d>
	var<symbol_a> number_a<type_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::number>"); //TODO cat
		return r;
	}

	template <typename type_d>
	typename number_a<type_d>::creator_fp number_a<type_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const number_s = sym("number");
			if (thing.o->equal(thing, number_s))
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
	template struct number_a<int64_t>;
	template struct number_a<uint64_t>;
	template struct number_a<double>;
}
