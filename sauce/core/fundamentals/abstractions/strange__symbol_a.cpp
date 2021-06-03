#include "../../../strange.h"

namespace strange
{
	var<symbol_a> symbol_a::cat_e(con<> const& me)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator symbol_a::creator_f(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const symbol_s = sym("symbol");
			if (thing.o->equal(thing, symbol_s))
			{
				static auto const create_empty_s = sym("create_empty");
				if (function.o->equal(function, create_empty_s))
				{
					return symbol_t::create_empty_f;
				}
			}
		}
		return nullptr;
	}
}
