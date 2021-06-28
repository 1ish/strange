#include "../../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> bidirectional_extractor_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::bidirectional_extractor>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename bidirectional_extractor_a<element_d>::creator_fp bidirectional_extractor_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "bidirectional_extractor")
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
	template struct bidirectional_extractor_a<int64_t>;
	template struct bidirectional_extractor_a<uint64_t>;
	template struct bidirectional_extractor_a<double>;
}
