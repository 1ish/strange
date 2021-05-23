#include "../../../strange.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <functional>

namespace strange
{
	thing_t::thing_t(void* const me_ /* :<any>= */)
	: refs{ 0 }
	, error { nullptr, nullptr }
	{
		auto const ma = reinterpret_cast<any_a* const>(me_);
		ma->t = this;
		ma->o = thing_t::operations_f();

		std::cout << "new thing\n";
	}

	thing_t::thing_t(void* const me_ /* :<any>= */,
		void const* const original_ /* :<any># */)
	: refs{ 0 }
	, error { reinterpret_cast<any_a const* const>(original_)->t->error }
	{
		auto const ma = reinterpret_cast<any_a* const>(me_);
		ma->t = this;
		ma->o = thing_t::operations_f();

		if (error.t)
		{
			thing_t::_reference_e(&error);
		}

		std::cout << "copy thing\n";
	}

	thing_t::~thing_t()
	{
		if (error.t)
		{
			thing_t::_release_m(&error);
		}

		std::cout << "delete thing\n";
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
			_as_e,
			type_e,
			_set_pointer_m,
			_pointer_e,
			set_something_m,
			something_e,
			set_error_m,
			error_e,
			hash_e,
			equal_e,
			_equal_e,
			not_equal_e,
			_not_equal_e,
			less_e,
			_less_e,
			greater_e,
			_greater_e,
			less_or_equal_e,
			_less_or_equal_e,
			greater_or_equal_e,
			_greater_or_equal_e,
		};
		return &operations;
	}

	any_o const* thing_t::pointer_operations_f()
	{
		static any_o operations = []()
		{
			any_o operations = *thing_t::operations_f();
			operations._copy = thing_t::_no_copy_e;
			return operations;
		}();
		return &operations;
	}

	// any_a
	void thing_t::_free_m(void* const me_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		delete ma->t;
	}

	void thing_t::_copy_e(void const* const me_ /* :<any># */,
		void* const copy_ /* :<any>= */)
	{
		new thing_t{ copy_, me_ };
		thing_t::_clone_e(me_, copy_);
	}

	void thing_t::_no_copy_e(void const* const me_ /* :<any># */,
		void* const copy_ /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const ca = reinterpret_cast<any_a* const>(copy_);
		thing_t::_reference_e(ma);
		*ca = *ma;
	}

	bool thing_t::is_e(void const* const me_ /* :<any># */,
		void const* const abstraction_ /* :<any># */)
	{
		auto const aa = reinterpret_cast<any_a const* const>(abstraction_);
		// abstraction_.cat in me_.cats
		static thing_t* const mat = any_a::cat_e(me_).t;
		return aa->o->cat(aa).t == mat;
	}

	bool thing_t::as_e(void const* const me_ /* :<any># */,
		void* const abstraction_ /* :<any>= */)
	{
		if (!thing_t::is_e(me_, abstraction_))
		{
			return false;
		}
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const aa = reinterpret_cast<any_a* const>(abstraction_);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		thing_t::_as_e(me_, abstraction_);
		thing_t::_repoint_m(aa, mp, ap);
		return true;
	}

	void thing_t::_as_e(void const* const me_ /* :<any># */,
		void* const abstraction_ /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const aa = reinterpret_cast<any_a* const>(abstraction_);
		if (aa->t != ma->t)
		{
			thing_t::_release_m(aa);
			*aa = *ma;
			thing_t::_reference_e(aa);
		}
		else
		{
			aa->o = ma->o;
		}
	}

	var<symbol_a> thing_t::type_e(void const* const me_ /* :<any># */)
	{
		static auto r = sym("strange::thing");
		return r;
	}

	void thing_t::_set_pointer_m(void* const me_ /* :<any>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me_);
		if (is_pointer)
		{
			ma->o = thing_t::pointer_operations_f();
		}
		else
		{
			ma->o = thing_t::operations_f();
		}
	}

	bool thing_t::_pointer_e(void const* const me_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		return ma->o->_copy == thing_t::_no_copy_e;
	}

	void thing_t::set_something_m(void* const me_ /* :<any>= */,
		bool is_something /* :_bool_# */)
	{
		if (is_something == thing_t::something_e(me_))
		{
			return;
		}
		thing_t::mutate_m(me_);
		auto const ma = reinterpret_cast<any_a* const>(me_);
		auto const mate = &(ma->t->error);
		if (is_something)
		{
			thing_t::_release_m(mate);
			mate->t = nullptr;
			mate->o = nullptr;
		}
		else
		{
			auto const err = thing_t::create_f();
			err.ref();
			*mate = err;
		}
	}

	bool thing_t::something_e(void const* const me_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		return !ma->t->error.t;
	}

	void thing_t::set_error_m(void* const me_ /* :<any>= */,
		void const* const error_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me_);
		auto const mate = &(ma->t->error);
		auto const ea = reinterpret_cast<any_a const* const>(error_);
		if (mate->t != ea->t)
		{
			auto const nothing = thing_t::create_nothing_f();
			if (ea->t == nothing.t)
			{
				thing_t::set_something_m(me_, true);
				return;
			}
			thing_t::mutate_m(me_);
			if (mate->t)
			{
				thing_t::_release_m(mate);
			}
			*mate = *ea;
			thing_t::_reference_e(mate);
		}
		else
		{
			mate->o = ea->o;
		}
		if (mate->o && mate->o->_pointer(mate))
		{
			mate->o->_set_pointer(mate, false);
			thing_t::mutate_m(mate);
		}
	}

	var<any_a> thing_t::error_e(void const* const me_ /* :<any># */)
	{
		if (thing_t::something_e(me_))
		{
			return thing_t::create_nothing_f();
		}
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		return var<any_a>{ ma->t->error };
	}

	uint64_t thing_t::hash_e(void const* const me_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		return static_cast<uint64_t>(std::hash<void const*>{}(ma->t));
	}

	bool thing_t::equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		return thing_t::_equal_e(me_, other_);
	}

	bool thing_t::_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		return ma->t == oa->t;
	}

	bool thing_t::not_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		return thing_t::_not_equal_e(me_, other_);
	}

	bool thing_t::_not_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		return ma->t != oa->t;
	}

	bool thing_t::less_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		return thing_t::_less_e(me_, other_);
	}

	bool thing_t::_less_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		return ma->t < oa->t;
	}

	bool thing_t::greater_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		return thing_t::_greater_e(me_, other_);
	}

	bool thing_t::_greater_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		return ma->t > oa->t;
	}

	bool thing_t::less_or_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		return thing_t::_less_or_equal_e(me_, other_);
	}

	bool thing_t::_less_or_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		return ma->t <= oa->t;
	}

	bool thing_t::greater_or_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		return thing_t::_greater_or_equal_e(me_, other_);
	}

	bool thing_t::_greater_or_equal_e(void const* const me_ /* :<any># */,
		void const* const other_ /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		return ma->t >= oa->t;
	}

	// creators
	var<any_a> thing_t::create_f()
	{
		static auto thing = var([]()
		{
			any_a r;
			new thing_t{ &r };
			thing_t::_initialise_m(&r);
			return r;
		}());
		return thing;
	}

	var<any_a> thing_t::create_nothing_f()
	{
		static auto nothing = var([]()
		{
			any_a r;
			new thing_t{ &r };
			thing_t::_initialise_m(&r);
			auto const e = thing_t::create_f();
			e.ref();
			r.t->error = e;
			return r;
		}());
		return nothing;
	}
}
