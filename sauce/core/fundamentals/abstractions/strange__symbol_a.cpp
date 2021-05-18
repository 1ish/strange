#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

namespace strange
{
	symbol_a symbol__cat_f(void const* const me /* :<symbol># */)
	{
		static auto r = strange::val(symbol_t::symbol__create_f("<strange::symbol>")); //TODO cat
		return r.ret();
	}
}
