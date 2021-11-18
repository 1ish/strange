#include "../../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> contiguous_mutator_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::contiguous_mutator>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename contiguous_mutator_a<element_d>::creator_fp contiguous_mutator_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "contiguous_mutator")
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
	template struct contiguous_mutator_a<>;
	template struct contiguous_mutator_a<int64_t>;
}
