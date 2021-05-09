#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

extern "C"
{
	strange__symbol_a strange__symbol_cat_f(void const* const me)
	{
		static auto r = var(sym("strange__symbol"));
		return r.ret();
	}
}
