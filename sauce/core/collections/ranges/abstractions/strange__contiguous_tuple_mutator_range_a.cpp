#include "../../../../strange.h"

namespace strange
{
	template <typename... elements_d>
	var<symbol_a> contiguous_tuple_mutator_range_a<elements_d...>::cat(con<> const& me)
	{
		static auto r = sym("<strange::contiguous_tuple_mutator_range>"); //TODO cat
		return r;
	}

	template <typename... elements_d>
	typename contiguous_tuple_mutator_range_a<elements_d...>::creator_fp contiguous_tuple_mutator_range_a<elements_d...>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "contiguous_tuple_mutator_range")
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
	template struct contiguous_tuple_mutator_range_a<int64_t>;
}
