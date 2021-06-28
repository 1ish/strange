#include "../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> list_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::list>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename list_a<element_d>::creator_fp list_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "list")
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
	template struct list_a<int64_t>;
}
