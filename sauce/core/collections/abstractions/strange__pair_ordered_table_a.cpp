#include "../../strange__core.h"

namespace strange
{
	template <typename key_d, typename value_d>
	var<symbol_a> pair_ordered_table_a<key_d, value_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::pair_ordered_table>"); //TODO cat
		return r;
	}

	template <typename key_d, typename value_d>
	typename pair_ordered_table_a<key_d, value_d>::creator_fp pair_ordered_table_a<key_d, value_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "pair_ordered_table")
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
	template struct pair_ordered_table_a<int64_t, int64_t>;
}
