#include "../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> ordered_group_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::ordered_group>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename ordered_group_a<element_d>::creator_fp ordered_group_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "ordered_group")
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
	template struct ordered_group_a<int64_t>;
}
