#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <functional>

namespace strange
{
	thing_t::~thing_t()
	{
		if (error.t)
		{
			strange::rel(&error);
		}
	}

	// any_o
	any_o const* thing_t::operations_f()
	{
		static any_o operations =
		{
			// any_a
			any_a::cat_f,
			thing_t::_free_f,
			thing_t::_copy_f,
			thing_t::is_f,
			thing_t::as_f,
			thing_t::_as_f,
			thing_t::type_f,
			thing_t::_set_pointer_f,
			thing_t::_pointer_f,
			thing_t::set_something_f,
			thing_t::something_f,
			thing_t::set_error_f,
			thing_t::error_f,
			thing_t::hash_f,
			thing_t::equal_f,
			thing_t::_equal_f,
			thing_t::not_equal_f,
			thing_t::_not_equal_f,
			thing_t::less_f,
			thing_t::_less_f,
			thing_t::greater_f,
			thing_t::_greater_f,
			thing_t::less_or_equal_f,
			thing_t::_less_or_equal_f,
			thing_t::greater_or_equal_f,
			thing_t::_greater_or_equal_f
		};
		return &operations;
	}

	any_o const* thing_t::pointer_operations_f()
	{
		static any_o operations = []()
		{
			any_o operations = *thing_t::operations_f();
			operations._copy = thing_t::_no_copy_f;
			return operations;
		}();
		return &operations;
	}

	// init
	void thing_t::init_f(void* const me /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		strange::one(ma);
		ma->t->error.t = 0;
		ma->t->error.o = 0;
		ma->o = thing_t::operations_f();
	}

	// any_a
	void thing_t::_free_f(void const* const me /* :<any># */)
	{
	}

	void thing_t::_copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const ca = reinterpret_cast<any_a* const>(cp);
		ca->t = new thing_t;
		std::memcpy(ca->t, ma->t, sizeof(thing_t));
		thing_t::_clone_f(me, cp);
	}

	void thing_t::_clone_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ca = reinterpret_cast<any_a* const>(cp);
		strange::one(ca);
		if (!thing_t::something_f(ca))
		{
			strange::ref(&(ca->t->error));
		}
	}

	void thing_t::_no_copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ca = reinterpret_cast<any_a* const>(cp);
		strange::ref(ca);
	}

	bool thing_t::is_f(void const* const me /* :<any># */,
		void const* const ab /* :<any># */)
	{
		auto const aa = reinterpret_cast<any_a const* const>(ab);
		// ab.cat in me.cats
		static thing_t* const mat = any_a::cat_f(me).t;
		return aa->o->cat(aa).t == mat;
	}

	bool thing_t::as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */)
	{
		if (!thing_t::is_f(me, ab))
		{
			return false;
		}
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const aa = reinterpret_cast<any_a* const>(ab);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		thing_t::_as_f(me, ab);
		strange::rep(aa, mp, ap);
		return true;
	}

	void thing_t::_as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const aa = reinterpret_cast<any_a* const>(ab);
		if (aa->t != ma->t)
		{
			strange::rel(aa);
			*aa = *ma;
			strange::ref(aa);
		}
		else
		{
			aa->o = ma->o;
		}
	}

	symbol_a thing_t::type_f(void const* const me /* :<any># */)
	{
		static auto r = strange::val("strange::thing");
		return r.ret();
	}

	void thing_t::_set_pointer_f(void* const me /* :<any>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		if (is_pointer)
		{
			ma->o = thing_t::pointer_operations_f();
		}
		else
		{
			ma->o = thing_t::operations_f();
		}
	}

	bool thing_t::_pointer_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		return ma->o == thing_t::pointer_operations_f();
	}

	void thing_t::set_something_f(void* const me /* :<any>= */,
		bool is_something /* :_bool_# */)
	{
		if (is_something == thing_t::something_f(me))
		{
			return;
		}
		strange::mut(me);
		auto const ma = reinterpret_cast<any_a* const>(me);
		if (is_something)
		{
			strange::rel(&(ma->t->error));
			ma->t->error.t = 0;
			ma->t->error.o = 0;
		}
		else
		{
			ma->t->error = thing_t::create_f();
		}
	}

	bool thing_t::something_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		return !ma->t->error.t;
	}

	void thing_t::set_error_f(void* const me /* :<any>= */,
		void const* const error /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		auto const ea = reinterpret_cast<any_a const* const>(error);
		if (ea->t == ma->t->error.t)
		{
			return;
		}
		auto const nothing = strange::val(thing_t::create_nothing_f());
		if (ea->t == nothing.a.t) // no error
		{
			thing_t::set_something_f(me, true);
		}
		else
		{
			strange::mut(me);
			ma->t->error = *ea;
			strange::ref(ea);
		}
	}

	any_a thing_t::error_f(void const* const me /* :<any># */)
	{
		if (thing_t::something_f(me))
		{
			return thing_t::create_nothing_f();
		}
		auto const ma = reinterpret_cast<any_a const* const>(me);
		strange::ref(&(ma->t->error));
		return ma->t->error;
	}

	uint64_t thing_t::hash_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		return std::hash<void const*>{}(ma->t);
	}

	bool thing_t::equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing_t::_equal_f(me, other);
	}

	bool thing_t::_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->t == oa->t;
	}

	bool thing_t::not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing_t::_not_equal_f(me, other);
	}

	bool thing_t::_not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->t != oa->t;
	}

	bool thing_t::less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing_t::_less_f(me, other);
	}

	bool thing_t::_less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->t < oa->t;
	}

	bool thing_t::greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing_t::_greater_f(me, other);
	}

	bool thing_t::_greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->t > oa->t;
	}

	bool thing_t::less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing_t::_less_or_equal_f(me, other);
	}

	bool thing_t::_less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->t <= oa->t;
	}

	bool thing_t::greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing_t::_greater_or_equal_f(me, other);
	}

	bool thing_t::_greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->t >= oa->t;
	}

	// creators
	any_a thing_t::create_f()
	{
		static auto r = strange::var([]()
		{
			any_a r;
			r.t = new thing_t;
			thing_t::init_f(&r);
			return r;
		}());
		return r.ret();
	}

	any_a thing_t::create_nothing_f()
	{
		static auto r = strange::var([]()
		{
			any_a r;
			r.t = new thing_t;
			thing_t::init_f(&r);
			r.t->error = thing_t::create_f();
			return r;
		}());
		return r.ret();
	}
}
