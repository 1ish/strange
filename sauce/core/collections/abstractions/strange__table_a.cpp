#include "../../../strange.h"

namespace strange
{
	template <typename key_d, typename value_d>
	var<symbol_a> table_a<key_d, value_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::table>"); //TODO cat
		return r;
	}

	template <typename key_d, typename value_d>
	typename table_a<key_d, value_d>::creator_fp table_a<key_d, value_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "table")
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
	template struct table_a<int64_t, int64_t>;
}
