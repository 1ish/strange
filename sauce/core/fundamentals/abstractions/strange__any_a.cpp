#include "../../../strange.h"

namespace strange
{
	var<symbol_a> any_a::cat_e(void const* const me_ /* :<any># */)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator any_a::creator_f(void const* const scope_ /* :<symbol># */,
		void const* const thing_ /* :<symbol># */,
		void const* const function_ /* :<symbol># */)
	{
		auto const sa = reinterpret_cast<symbol_a const* const>(scope_);
		auto const ta = reinterpret_cast<symbol_a const* const>(thing_);
		auto const fa = reinterpret_cast<symbol_a const* const>(function_);
		static auto const strange_s = sym("strange");
		if (sa->o->equal(sa, strange_s))
		{
			static auto const thing_s = sym("thing");
			if (ta->o->equal(ta, thing_s))
			{
				static auto const create_s = sym("create");
				if (fa->o->equal(fa, create_s))
				{
					return thing_t::create_f;
				}
				static auto const create_nothing_s = sym("create_nothing");
				if (fa->o->equal(fa, create_nothing_s))
				{
					return thing_t::create_nothing_f;
				}
			}
		}
		return nullptr;
	}
}
