#include "../../../strange.h"

namespace strange
{
	var<symbol_a> symbol_a::cat_e(void const* const me_ /* :<symbol># */)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator symbol_a::creator_f(char const* const scope /* :_char_star_# */,
		char const* const thing /* :_char_star_# */,
		char const* const function /* :_char_star_# */)
	{
		auto const s = sym(scope);
		auto const t = sym(thing);
		auto const f = sym(function);
		if (s.o->equal(s, sym("strange")))
		{
			if (t.o->equal(t, sym("symbol")))
			{
				if (f.o->equal(f, sym("create_empty")))
				{
					return symbol_t::create_empty_f;
				}
			}
		}
		return nullptr;
	}
}
