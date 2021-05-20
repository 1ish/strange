#ifndef COM_ONEISH__STRANGE__VALUE_C_H
#define COM_ONEISH__STRANGE__VALUE_C_H

#include <cstdlib>
#include <iostream>

#include "strange__val_u.hpp"

namespace strange
{
	static_assert(sizeof(std::atomic_int64_t) == sizeof(int64_t), "required to be true: sizeof(std::atomic_int64_t) == sizeof(int64_t)");

	inline void ref(any_a const* const abstraction /* :<any># */)
	{
		++(abstraction->t->refs);
	}

	inline void rel(any_a const* const abstraction /* :<any># */)
	{
		if (!--(abstraction->t->refs))
		{
			abstraction->o->_free(abstraction);
		}
	}

	inline void mut(void* const me /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
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
				strange::mut(after);
				after->o->_set_pointer(after, true);
			}
			else
			{
				after->o->_set_pointer(after, false);
				strange::mut(after);
			}
		}
	}

	inline var<strange::symbol_a> sym(char const* const s)
	{
		return strange::symbol_t::create_f(s);
	}
}

#endif
