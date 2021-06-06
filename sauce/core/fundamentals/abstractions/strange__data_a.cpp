#include "../../../strange.h"

namespace strange
{
	template <typename data_type>
	var<symbol_a> data_a<data_type>::cat_f(con<> const& me)
	{
		static auto r = sym("<strange::data>"); //TODO cat
		return r;
	}

	template <typename data_type>
	typename data_a<data_type>::creator data_a<data_type>::creator_f(con<symbol_a> const& scope,
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
					//TODO return data_t::create_f;
				}
			}
		}
		return nullptr;
	}
}
