#include "../../../strange.h"

namespace strange
{
	var<symbol_a> symbol_a::cat_e(con<> const& me_)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator symbol_a::creator_f(con<symbol_a> const& scope_,
		con<symbol_a> const& thing_,
		con<symbol_a> const& function_)
	{
		static auto const strange_s = sym("strange");
		if (scope_.o->equal(scope_, strange_s))
		{
			static auto const symbol_s = sym("symbol");
			if (thing_.o->equal(thing_, symbol_s))
			{
				static auto const create_empty_s = sym("create_empty");
				if (function_.o->equal(function_, create_empty_s))
				{
					return symbol_t::create_empty_f;
				}
			}
		}
		return nullptr;
	}
}
