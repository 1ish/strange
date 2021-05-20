#ifndef COM_ONEISH__STRANGE__VALUE_C_H
#define COM_ONEISH__STRANGE__VALUE_C_H

#include "strange__val_u.hpp"

namespace strange
{
	inline void ref(any_a const* const abstraction /* :<any># */)
	{
		++(abstraction->t->refs);
	}

	inline void rel(any_a* const abstraction /* :<any>= */)
	{
		if (!--(abstraction->t->refs))
		{
			abstraction->o->_free(abstraction);
		}
	}

	inline void mut(void* const me_ /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me_);
		if (ma->t->refs > 1)
		{
			any_a cp = *ma;
			ma->o->_copy(ma, &cp);
			rel(ma);
			*ma = cp;
			ref(ma);
		}
	}

	inline void rep(any_a* const after /* :<any>= */,
		bool pointer_before /* :_bool_# */,
		bool pointer_after /* :_bool_# */)
	{
		if (pointer_after != pointer_before)
		{
			if (pointer_after)
			{
				mut(after);
				after->o->_set_pointer(after, true);
			}
			else
			{
				after->o->_set_pointer(after, false);
				mut(after);
			}
		}
	}

	inline var<symbol_a> sym(char const* const s /* :_char_star_# */)
	{
		return symbol_t::create_f(s);
	}
}

#endif
