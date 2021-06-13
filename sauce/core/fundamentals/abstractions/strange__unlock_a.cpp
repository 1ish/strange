#include "../../../strange.h"

namespace strange
{
	var<symbol_a> unlock_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::unlock>"); //TODO cat
		return r;
	}

	unlock_a::creator_fp unlock_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const lock_s = sym("lock");
			if (thing.o->equal(thing, lock_s))
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
}
