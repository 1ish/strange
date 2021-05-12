#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

extern "C"
{
	strange__symbol_a strange__any__cat_f(void const* const me /* <any># */)
	{
		static auto r = var(strange__symbol("<strange::any>"));
		return r.ret();
	}
}
