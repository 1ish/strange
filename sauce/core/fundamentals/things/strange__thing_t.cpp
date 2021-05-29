#include "../../../strange.h"

#include <functional>

namespace strange
{
	thing_t::thing_t(any_a& me_ /* :<any>= */)
	: refs{ 0 }
	, error { nullptr, nullptr }
	{
		me_.t = this;
		me_.o = thing_t::operations_f();
	}

	thing_t::thing_t(any_a& me_ /* :<any>= */,
		any_a const& original_ /* :<any># */)
	: refs{ 0 }
	, error { original_.t->error }
	{
		me_.t = this;
		me_.o = thing_t::operations_f();

		if (error.t)
		{
			reinterpret_cast<var<>&>(error).ref();
		}
	}

	thing_t::~thing_t()
	{
		if (error.t)
		{
			reinterpret_cast<var<>&>(error).rel();
		}
	}

	// any_o
	any_o const* thing_t::operations_f()
	{
		static any_o operations =
		{
			// any_a
			any_a::cat_e,
			_free_m,
			_copy_e,
			is_e,
			as_e,
			type_e,
			_set_pointer_m,
			_pointer_e,
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
	void thing_t::_free_m(any_a& me_ /* :<any>= */)
	{
		delete me_.t;
	}

	void thing_t::_copy_e(any_a const& me_ /* :<any># */,
		any_a& copy_ /* :<any>= */)
	{
		new thing_t{ copy_, me_ };
		thing_t::_clone_e(me_, copy_);
	}

	void thing_t::_no_copy_e(any_a const& me_ /* :<any># */,
		any_a& copy_ /* :<any>= */)
	{
		copy_ = me_;
	}

	bool thing_t::is_e(val<> const& me_ /* :<any># */,
		val<> const& abstraction_ /* :<any># */)
	{
		// abstraction_.cat in me_.cats
		return abstraction_.o->cat == any_a::cat_e;
	}

	bool thing_t::as_e(val<> const& me_ /* :<any># */,
		var<>& abstraction_ /* :<any>= */)
	{
		if (!me_.o->is(me_, abstraction_))
		{
			return false;
		}
		bool const mp = me_.o->_pointer(me_);
		bool const ap = abstraction_.o->_pointer(abstraction_);
		abstraction_ = me_;
		thing_t::_repoint_m(abstraction_, mp, ap);
		return true;
	}

	var<symbol_a> thing_t::type_e(val<> const& me_ /* :<any># */)
	{
		static auto r = sym("strange::thing");
		return r;
	}

	void thing_t::_set_pointer_m(var<>& me_ /* :<any>= */,
		bool is_pointer /* :_bool_# */)
	{
		if (is_pointer)
		{
			me_.o = thing_t::pointer_operations_f();
		}
		else
		{
			me_.o = thing_t::operations_f();
		}
	}

	bool thing_t::_pointer_e(val<> const& me_ /* :<any># */)
	{
		return me_.o->_copy == thing_t::_no_copy_e;
	}

	void thing_t::set_something_m(var<>& me_ /* :<any>= */,
		bool is_something /* :_bool_# */)
	{
		if (is_something == thing_t::something_e(me_))
		{
			return;
		}
		me_.mut();
		auto& mate = reinterpret_cast<var<>&>(me_.t->error);
		if (is_something)
		{
			mate.rel();
			mate.t = nullptr;
			mate.o = nullptr;
		}
		else
		{
			auto const err = thing_t::create_f();
			err.ref();
			mate.t = err.t;
			mate.o = err.o;
		}
	}

	bool thing_t::something_e(val<> const& me_ /* :<any># */)
	{
		return !me_.t->error.t;
	}

	void thing_t::set_error_m(var<>& me_ /* :<any>= */,
		val<> const& error_ /* :<any># */)
	{
		auto& mate = reinterpret_cast<var<>&>(me_.t->error);
		if (mate.t != error_.t)
		{
			auto const nothing = thing_t::create_nothing_f();
			if (error_.t == nothing.t)
			{
				thing_t::set_something_m(me_, true);
				return;
			}
			me_.mut();
			if (mate.t)
			{
				mate.rel();
			}
			mate.t = error_.t;
			mate.o = error_.o;
			mate.ref();
		}
		else
		{
			mate.o = error_.o;
		}
		if (mate.o)
		{
			if (mate.o->_pointer(mate))
			{
				mate.o->_set_pointer(mate, false);
				mate.mut();
			}
		}
	}

	var<> thing_t::error_e(val<> const& me_ /* :<any># */)
	{
		if (thing_t::something_e(me_))
		{
			return thing_t::create_nothing_f();
		}
		return var<any_a>{ me_.t->error };
	}

	uint64_t thing_t::hash_e(val<> const& me_ /* :<any># */)
	{
		return static_cast<uint64_t>(std::hash<void const*>{}(me_.t));
	}

	bool thing_t::equal_e(val<> const& me_ /* :<any># */,
		val<> const& other_ /* :<any># */)
	{
		return thing_t::_equal_e(me_, other_);
	}

	bool thing_t::not_equal_e(val<> const& me_ /* :<any># */,
		val<> const& other_ /* :<any># */)
	{
		return thing_t::_not_equal_e(me_, other_);
	}

	bool thing_t::less_e(val<> const& me_ /* :<any># */,
		val<> const& other_ /* :<any># */)
	{
		return thing_t::_less_e(me_, other_);
	}

	bool thing_t::greater_e(val<> const& me_ /* :<any># */,
		val<> const& other_ /* :<any># */)
	{
		return thing_t::_greater_e(me_, other_);
	}

	bool thing_t::less_or_equal_e(val<> const& me_ /* :<any># */,
		val<> const& other_ /* :<any># */)
	{
		return thing_t::_less_or_equal_e(me_, other_);
	}

	bool thing_t::greater_or_equal_e(val<> const& me_ /* :<any># */,
		val<> const& other_ /* :<any># */)
	{
		return thing_t::_greater_or_equal_e(me_, other_);
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
			e.ref();
			r.t->error = e;
			return r;
		}());
		return nothing;
	}
}
