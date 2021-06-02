#include "../../../strange.h"

namespace strange
{
	template <typename _type>
	var<symbol_a> data_a<_type>::cat_e(con<> const& me_)
	{
		static auto r = sym("<strange::data>"); //TODO cat
		return r;
	}

	template <typename _type>
	typename data_a<_type>::creator data_a<_type>::creator_f(con<symbol_a> const& scope_,
		con<symbol_a> const& thing_,
		con<symbol_a> const& function_)
	{
		static auto const strange_s = sym("strange");
		if (scope_.o->equal(scope_, strange_s))
		{
			static auto const data_s = sym("data");
			if (thing_.o->equal(thing_, data_s))
			{
				static auto const create_s = sym("create");
				if (function_.o->equal(function_, create_s))
				{
					//TODO return data_t::create_f;
				}
			}
		}
		return nullptr;
	}
}
