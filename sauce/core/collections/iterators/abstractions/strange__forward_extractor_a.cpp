#include "../../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> forward_extractor_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::forward_extractor>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename forward_extractor_a<element_d>::creator_fp forward_extractor_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "forward_extractor")
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
	template struct forward_extractor_a<int64_t>;
}
