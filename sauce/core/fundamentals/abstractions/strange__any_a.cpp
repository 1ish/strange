#include "../../../strange.h"

namespace strange
{
	var<symbol_a> any_a::cat_e(val<> const& me_)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator any_a::creator_f(val<symbol_a> const& scope_,
		val<symbol_a> const& thing_,
		val<symbol_a> const& function_)
	{
		static auto const strange_s = sym("strange");
		if (scope_.o->equal(scope_, strange_s))
		{
			static auto const thing_s = sym("thing");
			if (thing_.o->equal(thing_, thing_s))
			{
				static auto const create_s = sym("create");
				if (function_.o->equal(function_, create_s))
				{
					return thing_t::create_f;
				}
				static auto const create_nothing_s = sym("create_nothing");
				if (function_.o->equal(function_, create_nothing_s))
				{
					return thing_t::create_nothing_f;
				}
			}
		}
		return nullptr;
	}
}
