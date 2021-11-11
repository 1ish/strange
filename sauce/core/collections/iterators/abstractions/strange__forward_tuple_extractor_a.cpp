#include "../../../../strange.h"

namespace strange
{
	template <typename... elements_d>
	var<symbol_a> forward_tuple_extractor_a<elements_d...>::cat(con<> const& me)
	{
		static auto r = sym("<strange::forward_tuple_extractor>"); //TODO cat
		return r;
	}

	template <typename... elements_d>
	typename forward_tuple_extractor_a<elements_d...>::creator_fp forward_tuple_extractor_a<elements_d...>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "forward_tuple_extractor")
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
	template struct forward_tuple_extractor_a<int64_t>;
	template struct forward_tuple_extractor_a<int64_t, int64_t>;
}
