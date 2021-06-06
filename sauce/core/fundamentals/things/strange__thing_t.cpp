#include "../../../strange.h"

#include <functional>

namespace strange
{
	thing_t::thing_t(any_a& me)
	: refs_n{ 0 }
	, error_n { nullptr, nullptr }
	{
		me.t = this;
		me.o = thing_t::operations();
	}

	thing_t::thing_t(any_a& me,
		any_a const& original)
	: refs_n{ 0 }
	, error_n { original.t->error_n }
	{
		me.t = this;
		me.o = thing_t::operations();

		if (error_n.t)
		{
			reinterpret_cast<var<>&>(error_n).inc();
		}
	}

	thing_t::~thing_t()
	{
		if (error_n.t)
		{
			reinterpret_cast<var<>&>(error_n).dec();
		}
	}

	// any_o
	any_o const* thing_t::operations()
	{
		static any_o operations =
		{
			// any_a
			any_a::cat,
			is,
			as,
			type,
			set_error,
			error,
			hash,
			equal,
			not_equal,
			less,
			greater,
			less_or_equal,
			greater_or_equal,
			_free,
			_copy,
			_set_pointer,
			_pointer,
		};
		return &operations;
	}

	any_o const* thing_t::pointer_operations()
	{
		static any_o operations = []()
		{
			any_o ops = *thing_t::operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool thing_t::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		return abstraction.o->cat == any_a::cat;
	}

	bool thing_t::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!thing_t::is(me, abstraction))
		{
			return false;
		}
		abstraction = me;
		return true;
	}

	var<symbol_a> thing_t::type(con<> const& me)
	{
		static auto r = sym("strange::thing");
		return r;
	}

	void thing_t::set_error(var<> const& me,
		con<> const& error_n)
	{
		auto& mate = reinterpret_cast<var<>&>(me.t->error_n);
		if (mate.t != error_n.t)
		{
			auto const nothing = thing_t::create_nothing();
			if (error_n.t == nothing.t)
			{
				thing_t::set_something(me, true);
				return;
			}
			me.mut();
			if (mate.t)
			{
				mate.dec();
			}
			mate.t = error_n.t;
			mate.o = error_n.o;
			mate.inc();
		}
		else
		{
			mate.o = error_n.o;
		}
		if (mate.o && mate.o->_pointer(mate))
		{
			mate.o->_set_pointer(mate, false);
			mate.mut();
		}
	}

	var<> thing_t::error(con<> const& me)
	{
		if (thing_t::something(me))
		{
			return thing_t::create_nothing();
		}
		return var<any_a>{ me.t->error_n };
	}

	uint64_t thing_t::hash(con<> const& me)
	{
		return static_cast<uint64_t>(std::hash<void const*>{}(me.t));
	}

	bool thing_t::equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::_equal(me, other);
	}

	bool thing_t::not_equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::_not_equal(me, other);
	}

	bool thing_t::less(con<> const& me,
		con<> const& other)
	{
		return thing_t::_less(me, other);
	}

	bool thing_t::greater(con<> const& me,
		con<> const& other)
	{
		return thing_t::_greater(me, other);
	}

	bool thing_t::less_or_equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::_less_or_equal(me, other);
	}

	bool thing_t::greater_or_equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::_greater_or_equal(me, other);
	}

	void thing_t::_free(any_a const& me)
	{
		delete me.t;
	}

	void thing_t::_copy(any_a const& me,
		any_a& copy)
	{
		new thing_t{ copy, me };
		thing_t::_clone(me, copy);
	}

	void thing_t::_no_copy(any_a const& me,
		any_a& copy)
	{
		copy = me;
	}

	void thing_t::_set_pointer(var<> const& me,
		bool is_pointer)
	{
		if (is_pointer)
		{
			me.o = thing_t::pointer_operations();
		}
		else
		{
			me.o = thing_t::operations();
		}
	}

	bool thing_t::_pointer(con<> const& me)
	{
		return me.o->_copy == thing_t::_no_copy;
	}

	// creators
	var<> thing_t::create()
	{
		static auto thing = var([]()
		{
			any_a r;
			new thing_t{ r };
			thing_t::_initialise(r);
			return r;
		}());
		return thing;
	}

	var<> thing_t::create_nothing()
	{
		static auto nothing = var([]()
		{
			any_a r;
			new thing_t{ r };
			thing_t::_initialise(r);
			auto const e = thing_t::create();
			e.inc();
			r.t->error_n = e;
			return r;
		}());
		return nothing;
	}
}
