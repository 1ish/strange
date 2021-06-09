#include "../../../strange.h"

namespace strange
{
	inline var<> unlock_o::read_lock(con<lock_a> const& me)
	{
		return thing_t::create();
	}

	inline var<> unlock_o::write_lock(con<lock_a> const& me)
	{
		return thing_t::create();
	}

	var<symbol_a> unlock_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::unlock>"); //TODO cat
		return r;
	}

	var<unlock_a> unlock_a::create()
	{
		return var<unlock_a>{};
	}

	unlock_a::creator_fp unlock_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const mutex_s = sym("mutex");
			if (thing.o->equal(thing, mutex_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					return unlock_a::create;
				}
			}
		}
		return nullptr;
	}
}
