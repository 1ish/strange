#include "../../../strange.h"

namespace strange
{
	void any_o::set_something(var<> const& me,
		bool is_something)
	{
		thing_t::set_something_f(me, is_something);
	}

	bool any_o::something(con<> const& me)
	{
		return thing_t::something_f(me);
	}

	var<symbol_a> any_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator_fp any_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const thing_s = sym("thing");
			if (thing.o->equal(thing, thing_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					return thing_t::create_f;
				}
				static auto const create_nothing_s = sym("create_nothing");
				if (function.o->equal(function, create_nothing_s))
				{
					return thing_t::create_nothing_f;
				}
			}
		}
		return nullptr;
	}
}
