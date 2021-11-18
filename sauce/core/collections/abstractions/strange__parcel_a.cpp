#include "../../strange__core.h"

namespace strange
{
	var<symbol_a> parcel_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::parcel>"); //TODO cat
		return r;
	}

	typename parcel_a::creator_fp parcel_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "parcel")
			{
				if (function == "create_from_range")
				{
					// return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
