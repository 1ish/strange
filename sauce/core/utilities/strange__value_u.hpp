#ifndef COM_ONEISH__STRANGE__VALUE_C_H
#define COM_ONEISH__STRANGE__VALUE_C_H

#include "strange__val_u.hpp"

namespace strange
{
	template <typename A>
	inline var<A> no()
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

	inline var<symbol_a> sym(char const* const s /* :_char_star_# */)
	{
		return symbol_t::create_f(s);
	}
}

#endif
