#include "../../../strange.h"

namespace strange
{
	var<symbol_a> lock_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::lock>"); //TODO cat
		return r;
	}

	lock_a::creator_fp lock_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const lock_s = sym("lock");
			if (thing.o->equal(thing, lock_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					return lock_a::create;
				}
			}
		}
		return nullptr;
	}
}
