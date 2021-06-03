#include "../../../strange.h"

namespace strange
{
	var<symbol_a> kind_a::cat_f(con<> const& me)
	{
		static auto r = sym("<strange::kind>"); //TODO cat
		return r;
	}

	kind_a::creator kind_a::creator_f(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const kind_s = sym("kind");
			if (thing.o->equal(thing, kind_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					//TODO return kind_t::create_f;
				}
			}
		}
		return nullptr;
	}
}
