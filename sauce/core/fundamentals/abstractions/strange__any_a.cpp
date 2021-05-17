#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

namespace strange
{
	symbol_a any__cat_f(void const* const me /* :<any># */)
	{
		static auto r = strange::val(symbol__create_f("<strange::any>")); //TODO cat
		return r.ret();
	}
}
