#include "../../../strange.h"

namespace strange
{
	template <typename type_d>
	var<symbol_a> data_a<type_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::data>"); //TODO cat
		return r;
	}

	template <typename type_d>
	typename data_a<type_d>::creator_fp data_a<type_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const data_s = sym("data");
			if (thing.o->equal(thing, data_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					//TODO return data_t::create;
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct data_a<int64_t>;
}
