#include "../../../strange.h"
#include "../../utilities/strange__value_u.hpp"

namespace strange
{
	val<symbol_a> symbol_a::cat_f(void const* const me /* :<symbol># */)
	{
		static auto r = strange::sym("<strange::symbol>"); //TODO cat
		return r;
	}
}
