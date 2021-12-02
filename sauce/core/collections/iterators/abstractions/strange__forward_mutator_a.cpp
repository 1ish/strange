#include "../../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> forward_mutator_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::forward_mutator>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename forward_mutator_a<element_d>::creator_fp forward_mutator_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "forward_mutator")
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
	template struct forward_mutator_a<>;
	template struct forward_mutator_a<int64_t>;
	template struct forward_mutator_a<var<tuple_a<int64_t, int64_t>>>;
	template struct forward_mutator_a<std::pair<int64_t const, int64_t>>;
}
