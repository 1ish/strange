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

	template <typename A>
	inline var<A> nothing()
	{
		auto const n = thing_t::create_nothing_f();
		static typename A::operations const ops =
		{
			A::cat_e,
			n.o->_free,
			n.o->_copy,
			n.o->is,
			n.o->as,
			n.o->_as,
			n.o->type,
			n.o->_set_pointer,
			n.o->_pointer,
			n.o->set_something,
			n.o->something,
			n.o->set_error,
			n.o->error,
			n.o->hash,
			n.o->equal,
			n.o->_equal,
			n.o->not_equal,
			n.o->_not_equal,
			n.o->less,
			n.o->_less,
			n.o->greater,
			n.o->_greater,
			n.o->less_or_equal,
			n.o->_less_or_equal,
			n.o->greater_or_equal,
			n.o->_greater_or_equal,
		};
		A a;
		a.t = n.t;
		a.o = &ops;
		return var<A>{ a };
	}
}

#endif
