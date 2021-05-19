#include "../../../strange.h"
#include "../../utilities/strange__value_u.hpp"

namespace strange
{
	val<symbol_a> any_a::cat_f(void const* const me /* :<any># */)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}
}
