#include "../../../strange__core.h"

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
	template struct mutator_range_a<uint8_t>;
	template struct mutator_range_a<var<tuple_a<int64_t, int64_t>>>;
	template struct mutator_range_a<std::pair<int64_t const, int64_t>>;
}
