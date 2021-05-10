#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

extern "C"
{
	strange__symbol_a strange__any__cat_f(void const* const me)
	{
		static auto r = var(sym("<strange::any>"));
		return r.ret();
	}
}
