#include "../../../strange.h"

namespace strange
{
	var<symbol_a> cat_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::cat>"); //TODO cat
		return r;
	}

	cat_a::creator_fp cat_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const cat_s = sym("cat");
			if (thing.o->equal(thing, cat_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					//TODO return cat_t::create;
				}
			}
		}
		return nullptr;
	}
}
