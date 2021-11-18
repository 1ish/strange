#include "../../strange__core.h"

namespace strange
{
	template <typename type_d>
	var<symbol_a> number_a<type_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::number>"); //TODO cat
		return r;
	}

	template <typename type_d>
	typename number_a<type_d>::creator_fp number_a<type_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "number")
			{
				if (function == "create_from_range")
				{
					return number_t<type_d>::create_from_range;
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct number_a<int64_t>;
	template struct number_a<uint64_t>;
	template struct number_a<double>;
}
