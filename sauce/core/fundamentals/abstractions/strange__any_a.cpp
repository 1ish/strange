#include "../../../strange.h"

namespace strange
{
	var<symbol_a> any_a::cat_e(void const* const me_ /* :<any># */)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator any_a::creator_f(char const* const scope /* :_char_star_# */,
		char const* const thing /* :_char_star_# */,
		char const* const name /* :_char_star_# */)
	{
		auto const s = sym(scope);
		auto const t = sym(thing);
		auto const n = sym(name);
		if (s.o->equal(s, sym("strange")))
		{
			if (t.o->equal(t, sym("thing")))
			{
				if (n.o->equal(n, sym("create")))
				{
					return thing_t::create_f;
				}
				else if (n.o->equal(n, sym("create_nothing")))
				{
					return thing_t::create_nothing_f;
				}
			}
		}
		return nullptr;
	}
}
