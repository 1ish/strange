#include "../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> group_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::group>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename group_a<element_d>::creator_fp group_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "group")
			{
				if (function == "create_from_range")
				{
					// return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct group_a<int64_t>;
	template struct group_a<var<>>;
}
