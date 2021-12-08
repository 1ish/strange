#include "../../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> bidirectional_range_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::bidirectional_range>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename bidirectional_range_a<element_d>::creator_fp bidirectional_range_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "bidirectional_range")
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
	template struct bidirectional_range_a<>;
	template struct bidirectional_range_a<int64_t>;
	template struct bidirectional_range_a<uint8_t>;
	template struct bidirectional_range_a<std::pair<int64_t const, int64_t>>;
}
