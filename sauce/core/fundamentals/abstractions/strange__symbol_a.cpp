#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

extern "C"
{
	strange__symbol_a strange__symbol__cat_f(void const* const me /* :<symbol># */)
	{
		static auto r = strange::val(strange__symbol__create_f("<strange::symbol>"));
		return r.ret();
	}
}
