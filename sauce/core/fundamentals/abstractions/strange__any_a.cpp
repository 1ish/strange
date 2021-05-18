#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

namespace strange
{
	symbol_a any_a::cat_f(void const* const me /* :<any># */)
	{
		static auto r = strange::val(symbol_t::create_f("<strange::any>")); //TODO cat
		return r.ret();
	}
}
