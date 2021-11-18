#include "../../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> range_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::range>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename range_a<element_d>::creator_fp range_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "range")
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
	template struct range_a<>;
	template struct range_a<int64_t>;
}
