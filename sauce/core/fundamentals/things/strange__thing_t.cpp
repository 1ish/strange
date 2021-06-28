#include "../../../strange.h"

#include <functional>

namespace strange
{
	// any_o
	any_o const* thing_t::_operations()
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
			less,
			less_or_equal,
			pack,
			_free,
			_copy,
			_set_pointer,
			_pointer,
		};
		return &operations;
	}

	any_o const* thing_t::_pointer_operations()
	{
		static any_o operations = []()
		{
			any_o ops = *thing_t::_operations();
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
		con<> const& error_)
	{
		auto& mate = reinterpret_cast<var<>&>(me.t->error_);
		if (mate.t != error_.t)
		{
			auto const nothing = thing_t::create_nothing();
			if (error_.t == nothing.t)
			{
				if (mate.t)
				{
					me.mut();
					mate.dec();
					mate.t = nullptr;
					mate.o = nullptr;
				}
			}
			else
			{
				me.mut();
				if (mate.t)
				{
					mate.dec();
				}
				mate.t = error_.t;
				mate.o = error_.o;
				mate.inc();
			}
		}
		else
		{
			mate.o = error_.o;
		}
	}

	var<> thing_t::error(con<> const& me)
	{
		if (!me.t->error_.t)
		{
			return thing_t::create_nothing();
		}
		return var<>{ me.t->error_ };
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

	bool thing_t::less(con<> const& me,
		con<> const& other)
	{
		return thing_t::_less(me, other);
	}

	bool thing_t::less_or_equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::_less_or_equal(me, other);
	}

	bool thing_t::pack(con<> const& me,
		var<container_a> const& container)
	{
		//TODO	container.o->push_back(container, container.o->make_lake(container,
		//			text(me.o->something(me) ? "strange::thing::create" : "strange::thing::create_nothing")));
		return false;
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
		me.o = is_pointer ? thing_t::_pointer_operations() : thing_t::_operations();
	}

	bool thing_t::_pointer(con<> const& me)
	{
		return me.o->_copy == thing_t::_no_copy;
	}
}
