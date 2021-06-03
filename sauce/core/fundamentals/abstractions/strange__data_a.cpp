#include "../../../strange.h"

namespace strange
{
	template <typename _type>
	var<symbol_a> data_a<_type>::cat_e(con<> const& me)
	{
		static auto r = sym("<strange::data>"); //TODO cat
		return r;
	}

	template <typename _type>
	typename data_a<_type>::creator data_a<_type>::creator_f(con<symbol_a> const& scope,
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
