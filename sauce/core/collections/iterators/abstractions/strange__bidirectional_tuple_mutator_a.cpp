#include "../../../strange__core.h"

namespace strange
{
	template <typename... elements_d>
	var<symbol_a> bidirectional_tuple_mutator_a<elements_d...>::cat(con<> const& me)
	{
		static auto r = sym("<strange::bidirectional_tuple_mutator>"); //TODO cat
		return r;
	}

	template <typename... elements_d>
	typename bidirectional_tuple_mutator_a<elements_d...>::creator_fp bidirectional_tuple_mutator_a<elements_d...>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "bidirectional_tuple_mutator")
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
	template struct bidirectional_tuple_mutator_a<int64_t, int64_t>;
}
