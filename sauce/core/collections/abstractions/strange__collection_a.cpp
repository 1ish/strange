#include "../../strange__core.h"

namespace strange
{
	template <typename key_d, typename value_d, typename element_d>
	var<symbol_a> collection_a<key_d, value_d, element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::collection>"); //TODO cat
		return r;
	}

	template <typename key_d, typename value_d, typename element_d>
	typename collection_a<key_d, value_d, element_d>::creator_fp collection_a<key_d, value_d, element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "collection")
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
	template struct collection_a<int64_t, int64_t, int64_t>;
	template struct collection_a<int64_t, var<>, var<>>;
	template struct collection_a<var<>, var<>, var<>>;
	template struct collection_a<int64_t, int64_t, var<tuple_a<int64_t, int64_t>>>;
}
