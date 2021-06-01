#include "../../../strange.h"

namespace strange
{
	var<symbol_a> kind_a::cat_e(con<> const& me_)
	{
		static auto r = sym("<strange::kind>"); //TODO cat
		return r;
	}

	kind_a::creator kind_a::creator_f(con<symbol_a> const& scope_,
		con<symbol_a> const& thing_,
		con<symbol_a> const& function_)
	{
		static auto const strange_s = sym("strange");
		if (scope_.o->equal(scope_, strange_s))
		{
			static auto const kind_s = sym("kind");
			if (thing_.o->equal(thing_, kind_s))
			{
				static auto const create_s = sym("create");
				if (function_.o->equal(function_, create_s))
				{
					//TODO return kind_t::create_f;
				}
			}
		}
		return nullptr;
	}
}
