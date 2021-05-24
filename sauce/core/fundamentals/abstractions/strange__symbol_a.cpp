#include "../../../strange.h"

namespace strange
{
	var<symbol_a> symbol_a::cat_e(void const* const me_ /* :<symbol># */)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator symbol_a::creator_f(void const* const scope_ /* :<symbol># */,
		void const* const thing_ /* :<symbol># */,
		void const* const function_ /* :<symbol># */)
	{
		auto const sa = reinterpret_cast<symbol_a const* const>(scope_);
		auto const ta = reinterpret_cast<symbol_a const* const>(thing_);
		auto const fa = reinterpret_cast<symbol_a const* const>(function_);
		static auto const strange_s = sym("strange");
		if (sa->o->equal(sa, strange_s))
		{
			static auto const symbol_s = sym("symbol");
			if (ta->o->equal(ta, symbol_s))
			{
				static auto const create_empty_s = sym("create_empty");
				if (fa->o->equal(fa, create_empty_s))
				{
					return symbol_t::create_empty_f;
				}
			}
		}
		return nullptr;
	}
}
