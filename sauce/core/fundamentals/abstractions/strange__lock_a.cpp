#include "../../../strange.h"

namespace strange
{
	inline var<> lock_o::read_lock(con<lock_a> const& me)
	{
		return dat(std::make_shared<std::shared_lock<std::shared_timed_mutex>>(_read_lock(me)));
	}

	inline var<> lock_o::write_lock(con<lock_a> const& me)
	{
		return dat(std::make_shared<std::unique_lock<std::shared_timed_mutex>>(_write_lock(me)));
	}

	var<symbol_a> lock_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::lock>"); //TODO cat
		return r;
	}

	var<lock_a> lock_a::create()
	{
		return dat_non_copyable<std::shared_timed_mutex>().val<var<lock_a>>();
	}

	lock_a::creator_fp lock_a::creator(con<symbol_a> const& scope,
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
					return lock_a::create;
				}
			}
		}
		return nullptr;
	}
}
