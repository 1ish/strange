#include "../../../strange.h"

namespace strange
{
	var<symbol_a> cat_a::cat_e(void const* const me_ /* :<cat># */)
	{
		static auto r = sym("<strange::cat>"); //TODO cat
		return r;
	}

	cat_a::creator cat_a::creator_f(void const* const scope_ /* :<symbol># */,
		void const* const thing_ /* :<symbol># */,
		void const* const function_ /* :<symbol># */)
	{
		auto const sa = reinterpret_cast<symbol_a const* const>(scope_);
		auto const ta = reinterpret_cast<symbol_a const* const>(thing_);
		auto const fa = reinterpret_cast<symbol_a const* const>(function_);
		static auto const strange_s = sym("strange");
		if (sa->o->equal(sa, strange_s))
		{
			static auto const cat_s = sym("cat");
			if (ta->o->equal(ta, cat_s))
			{
				static auto const create_s = sym("create");
				if (fa->o->equal(fa, create_s))
				{
					// return cat_t::create_f;
				}
			}
		}
		return nullptr;
	}
}
