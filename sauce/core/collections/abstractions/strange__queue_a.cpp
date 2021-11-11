#include "../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> queue_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::queue>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename queue_a<element_d>::creator_fp queue_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "queue")
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
	template struct queue_a<>;
	template struct queue_a<int64_t>;
}
