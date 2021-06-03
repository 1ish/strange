#include "../../../strange.h"

#include <functional>

namespace strange
{
	thing_t::thing_t(any_a& me /* :<any>= */)
	: refs{ 0 }
	, error { nullptr, nullptr }
	{
		me.t = this;
		me.o = thing_t::operations_f();
	}

	thing_t::thing_t(any_a& me /* :<any>= */,
		any_a const& original /* :<any># */)
	: refs{ 0 }
	, error { original.t->error }
	{
		me.t = this;
		me.o = thing_t::operations_f();

		if (error.t)
		{
			reinterpret_cast<var<>&>(error).inc();
		}
	}

	thing_t::~thing_t()
	{
		if (error.t)
		{
			reinterpret_cast<var<>&>(error).dec();
		}
	}

	// any_o
	any_o const* thing_t::operations_f()
	{
		static any_o operations =
		{
			// any_a
			any_a::cat_e,
			is_e,
			as_e,
			type_e,
			set_something_m,
			something_e,
			set_error_m,
			error_e,
			hash_e,
			equal_e,
			not_equal_e,
			less_e,
			greater_e,
			less_or_equal_e,
			greater_or_equal_e,
			_free_m,
			_copy_e,
			_set_pointer_m,
			_pointer_e,
		};
		return &operations;
	}

	any_o const* thing_t::pointer_operations_f()
	{
		static any_o operations = []()
		{
			any_o ops = *thing_t::operations_f();
			ops._copy = thing_t::_no_copy_e;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool thing_t::is_e(con<> const& me /* :<any># */,
		con<> const& abstraction /* :<any># */)
	{
		// abstraction.cat in me.cats
		return abstraction.o->cat == any_a::cat_e;
	}

	bool thing_t::as_e(con<> const& me /* :<any># */,
		var<> const& abstraction /* :<any>= */)
	{
		if (!me.o->is(me, abstraction))
		{
			return false;
		}
		abstraction = me;
		return true;
	}

	var<symbol_a> thing_t::type_e(con<> const& me /* :<any># */)
	{
		static auto r = sym("strange::thing");
		return r;
	}

	void thing_t::set_something_m(var<> const& me /* :<any>= */,
		bool is_something /* :_bool_# */)
	{
		if (is_something == thing_t::something_e(me))
		{
			return;
		}
		me.mut();
		auto& mate = reinterpret_cast<var<>&>(me.t->error);
		if (is_something)
		{
			mate.dec();
			mate.t = nullptr;
			mate.o = nullptr;
		}
		else
		{
			auto const err = thing_t::create_f();
			err.inc();
			mate.t = err.t;
			mate.o = err.o;
		}
	}

	bool thing_t::something_e(con<> const& me /* :<any># */)
	{
		return !me.t->error.t;
	}

	void thing_t::set_error_m(var<> const& me /* :<any>= */,
		con<> const& error /* :<any># */)
	{
		auto& mate = reinterpret_cast<var<>&>(me.t->error);
		if (mate.t != error.t)
		{
			auto const nothing = thing_t::create_nothing_f();
			if (error.t == nothing.t)
			{
				thing_t::set_something_m(me, true);
				return;
			}
			me.mut();
			if (mate.t)
			{
				mate.dec();
			}
			mate.t = error.t;
			mate.o = error.o;
			mate.inc();
		}
		else
		{
			mate.o = error.o;
		}
		if (mate.o && mate.o->_pointer(mate))
		{
			mate.o->_set_pointer(mate, false);
			mate.mut();
		}
	}

	var<> thing_t::error_e(con<> const& me /* :<any># */)
	{
		if (thing_t::something_e(me))
		{
			return thing_t::create_nothing_f();
		}
		return var<any_a>{ me.t->error };
	}

	uint64_t thing_t::hash_e(con<> const& me /* :<any># */)
	{
		return static_cast<uint64_t>(std::hash<void const*>{}(me.t));
	}

	bool thing_t::equal_e(con<> const& me /* :<any># */,
		con<> const& other /* :<any># */)
	{
		return thing_t::_equal_e(me, other);
	}

	bool thing_t::not_equal_e(con<> const& me /* :<any># */,
		con<> const& other /* :<any># */)
	{
		return thing_t::_not_equal_e(me, other);
	}

	bool thing_t::less_e(con<> const& me /* :<any># */,
		con<> const& other /* :<any># */)
	{
		return thing_t::_less_e(me, other);
	}

	bool thing_t::greater_e(con<> const& me /* :<any># */,
		con<> const& other /* :<any># */)
	{
		return thing_t::_greater_e(me, other);
	}

	bool thing_t::less_or_equal_e(con<> const& me /* :<any># */,
		con<> const& other /* :<any># */)
	{
		return thing_t::_less_or_equal_e(me, other);
	}

	bool thing_t::greater_or_equal_e(con<> const& me /* :<any># */,
		con<> const& other /* :<any># */)
	{
		return thing_t::_greater_or_equal_e(me, other);
	}

	void thing_t::_free_m(any_a const& me /* :<any>= */)
	{
		delete me.t;
	}

	void thing_t::_copy_e(any_a const& me /* :<any># */,
		any_a& copy /* :<any>= */)
	{
		new thing_t{ copy, me };
		thing_t::_clone_e(me, copy);
	}

	void thing_t::_no_copy_e(any_a const& me /* :<any># */,
		any_a& copy /* :<any>= */)
	{
		copy = me;
	}

	void thing_t::_set_pointer_m(var<> const& me /* :<any>= */,
		bool is_pointer /* :_bool_# */)
	{
		if (is_pointer)
		{
			me.o = thing_t::pointer_operations_f();
		}
		else
		{
			me.o = thing_t::operations_f();
		}
	}

	bool thing_t::_pointer_e(con<> const& me /* :<any># */)
	{
		return me.o->_copy == thing_t::_no_copy_e;
	}

	// creators
	var<> thing_t::create_f()
	{
		static auto thing = var([]()
		{
			any_a r;
			new thing_t{ r };
			thing_t::_initialise_m(r);
			return r;
		}());
		return thing;
	}

	var<> thing_t::create_nothing_f()
	{
		static auto nothing = var([]()
		{
			any_a r;
			new thing_t{ r };
			thing_t::_initialise_m(r);
			auto const e = thing_t::create_f();
			e.inc();
			r.t->error = e;
			return r;
		}());
		return nothing;
	}
}
