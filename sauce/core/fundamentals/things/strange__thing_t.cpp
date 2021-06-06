#include "../../../strange.h"

#include <functional>

namespace strange
{
	thing_t::thing_t(any_a& me)
	: refs{ 0 }
	, error { nullptr, nullptr }
	{
		me.t = this;
		me.o = thing_t::operations_f();
	}

	thing_t::thing_t(any_a& me,
		any_a const& original)
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
			any_a::cat_f,
			is_f,
			as_f,
			type_f,
			set_error_f,
			error_f,
			hash_f,
			equal_f,
			not_equal_f,
			less_f,
			greater_f,
			less_or_equal_f,
			greater_or_equal_f,
			_free_f,
			_copy_f,
			_set_pointer_f,
			_pointer_f,
		};
		return &operations;
	}

	any_o const* thing_t::pointer_operations_f()
	{
		static any_o operations = []()
		{
			any_o ops = *thing_t::operations_f();
			ops._copy = thing_t::_no_copy_f;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool thing_t::is_f(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		return abstraction.o->cat == any_a::cat_f;
	}

	bool thing_t::as_f(con<> const& me,
		var<> const& abstraction)
	{
		if (!me.o->is(me, abstraction))
		{
			return false;
		}
		abstraction = me;
		return true;
	}

	var<symbol_a> thing_t::type_f(con<> const& me)
	{
		static auto r = sym("strange::thing");
		return r;
	}

	void thing_t::set_error_f(var<> const& me,
		con<> const& error)
	{
		auto& mate = reinterpret_cast<var<>&>(me.t->error);
		if (mate.t != error.t)
		{
			auto const nothing = thing_t::create_nothing_f();
			if (error.t == nothing.t)
			{
				thing_t::set_something_f(me, true);
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

	var<> thing_t::error_f(con<> const& me)
	{
		if (thing_t::something_f(me))
		{
			return thing_t::create_nothing_f();
		}
		return var<any_a>{ me.t->error };
	}

	uint64_t thing_t::hash_f(con<> const& me)
	{
		return static_cast<uint64_t>(std::hash<void const*>{}(me.t));
	}

	bool thing_t::equal_f(con<> const& me,
		con<> const& other)
	{
		return thing_t::_equal_f(me, other);
	}

	bool thing_t::not_equal_f(con<> const& me,
		con<> const& other)
	{
		return thing_t::_not_equal_f(me, other);
	}

	bool thing_t::less_f(con<> const& me,
		con<> const& other)
	{
		return thing_t::_less_f(me, other);
	}

	bool thing_t::greater_f(con<> const& me,
		con<> const& other)
	{
		return thing_t::_greater_f(me, other);
	}

	bool thing_t::less_or_equal_f(con<> const& me,
		con<> const& other)
	{
		return thing_t::_less_or_equal_f(me, other);
	}

	bool thing_t::greater_or_equal_f(con<> const& me,
		con<> const& other)
	{
		return thing_t::_greater_or_equal_f(me, other);
	}

	void thing_t::_free_f(any_a const& me)
	{
		delete me.t;
	}

	void thing_t::_copy_f(any_a const& me,
		any_a& copy)
	{
		new thing_t{ copy, me };
		thing_t::_clone_f(me, copy);
	}

	void thing_t::_no_copy_f(any_a const& me,
		any_a& copy)
	{
		copy = me;
	}

	void thing_t::_set_pointer_f(var<> const& me,
		bool is_pointer)
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

	bool thing_t::_pointer_f(con<> const& me)
	{
		return me.o->_copy == thing_t::_no_copy_f;
	}

	// creators
	var<> thing_t::create_f()
	{
		static auto thing = var([]()
		{
			any_a r;
			new thing_t{ r };
			thing_t::_initialise_f(r);
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
			thing_t::_initialise_f(r);
			auto const e = thing_t::create_f();
			e.inc();
			r.t->error = e;
			return r;
		}());
		return nothing;
	}
}
