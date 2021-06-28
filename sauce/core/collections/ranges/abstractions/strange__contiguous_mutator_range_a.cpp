#include "../../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> contiguous_mutator_range_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::contiguous_mutator_range>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename contiguous_mutator_range_a<element_d>::creator_fp contiguous_mutator_range_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "contiguous_mutator_range")
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
	template struct contiguous_mutator_range_a<int64_t>;
}
