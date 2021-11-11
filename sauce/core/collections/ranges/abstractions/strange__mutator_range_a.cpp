#include "../../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> mutator_range_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::mutator_range>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename mutator_range_a<element_d>::creator_fp mutator_range_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "mutator_range")
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
	template struct mutator_range_a<>;
	template struct mutator_range_a<int64_t>;
}
