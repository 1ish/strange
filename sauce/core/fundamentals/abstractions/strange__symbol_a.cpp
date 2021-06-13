#include "../../../strange.h"

namespace strange
{
	var<symbol_a> symbol_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator_fp symbol_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const symbol_s = sym("symbol");
			if (thing.o->equal(thing, symbol_s))
			{
				static auto const create_from_range_s = sym("create_from_range");
				if (function.o->equal(function, create_from_range_s))
				{
					return symbol_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
