#include "../../../strange.h"

namespace strange
{
	var<symbol_a> cat_a::cat_e(con<> const& me_)
	{
		static auto r = sym("<strange::cat>"); //TODO cat
		return r;
	}

	cat_a::creator cat_a::creator_f(con<symbol_a> const& scope_,
		con<symbol_a> const& thing_,
		con<symbol_a> const& function_)
	{
		static auto const strange_s = sym("strange");
		if (scope_.o->equal(scope_, strange_s))
		{
			static auto const cat_s = sym("cat");
			if (thing_.o->equal(thing_, cat_s))
			{
				static auto const create_s = sym("create");
				if (function_.o->equal(function_, create_s))
				{
					//TODO return cat_t::create_f;
				}
			}
		}
		return nullptr;
	}
}
