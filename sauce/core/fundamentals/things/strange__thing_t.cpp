#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <functional>

namespace strange
{
	// any_o
	strange__any_o const* strange__thing_o_f()
	{
		static strange__any_o o =
		{
			// any_a
			strange__any__cat_f,
			strange__thing___free_f,
			strange__thing___copy_f,
			strange__thing__is_f,
			strange__thing__as_f,
			strange__thing___as_f,
			strange__thing__type_f,
			strange__thing___set_pointer_f,
			strange__thing___pointer_f,
			strange__thing__set_something_f,
			strange__thing__something_f,
			strange__thing__set_error_f,
			strange__thing__error_f,
			strange__thing__hash_f,
			strange__thing__equal_f,
			strange__thing___equal_f,
			strange__thing__not_equal_f,
			strange__thing___not_equal_f,
			strange__thing__less_f,
			strange__thing___less_f,
			strange__thing__greater_f,
			strange__thing___greater_f,
			strange__thing__less_or_equal_f,
			strange__thing___less_or_equal_f,
			strange__thing__greater_or_equal_f,
			strange__thing___greater_or_equal_f
		};
		return &o;
	}

	strange__any_o const* strange__thing_p_f()
	{
		static strange__any_o p = []()
		{
			strange__any_o p = *strange__thing_o_f();
			p._copy = strange__thing___no_copy_f;
			return p;
		}();
		return &p;
	}

	// init
	void strange__thing__init_f(void* const me /* :<any>= */)
	{
		auto const ma = reinterpret_cast<strange__any_a* const>(me);
		strange::one(ma);
		ma->d->error.d = 0;
		ma->d->error.o = 0;
		ma->o = strange__thing_o_f();
	}

	// any_a
	void strange__thing___free_f(void const* const me /* :<any># */)
	{
		if (!strange__thing__something_f(me))
		{
			auto const ma = reinterpret_cast<strange__any_a const* const>(me);
			strange::rel(&(ma->d->error));
		}
	}

	void strange__thing___copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		ca->d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d)));
		if (!ca->d)
		{
			std::abort();
		}
		std::memcpy(ca->d, ma->d, sizeof(strange__thing_d));
		strange__thing___clone_f(me, cp);
	}

	void strange__thing___clone_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		strange::one(ca);
		if (!strange__thing__something_f(ca))
		{
			strange::ref(&(ca->d->error));
		}
	}

	void strange__thing___no_copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		strange::ref(ca);
	}

	bool strange__thing__is_f(void const* const me /* :<any># */,
		void const* const ab /* :<any># */)
	{
		auto const aa = reinterpret_cast<strange__any_a const* const>(ab);
		// ab.cat in me.cats
		static strange__thing_d* const mat = strange__any__cat_f(me).d;
		return aa->o->cat(aa).d == mat;
	}

	bool strange__thing__as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */)
	{
		if (!strange__thing__is_f(me, ab))
		{
			return false;
		}
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const aa = reinterpret_cast<strange__any_a* const>(ab);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		strange__thing___as_f(me, ab);
		strange::rep(aa, mp, ap);
		return true;
	}

	void strange__thing___as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const aa = reinterpret_cast<strange__any_a* const>(ab);
		if (aa->d != ma->d)
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

	strange__symbol_a strange__thing__type_f(void const* const me /* :<any># */)
	{
		static auto r = strange::val("strange::thing");
		return r.ret();
	}

	void strange__thing___set_pointer_f(void* const me /* :<any>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<strange__any_a* const>(me);
		if (is_pointer)
		{
			ma->o = strange__thing_p_f();
		}
		else
		{
			ma->o = strange__thing_o_f();
		}
	}

	bool strange__thing___pointer_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		return ma->o == strange__thing_p_f();
	}

	void strange__thing__set_something_f(void* const me /* :<any>= */,
		bool is_something /* :_bool_# */)
	{
		if (is_something == strange__thing__something_f(me))
		{
			return;
		}
		strange::mut(me);
		auto const ma = reinterpret_cast<strange__any_a* const>(me);
		if (is_something)
		{
			strange::rel(&(ma->d->error));
			ma->d->error.d = 0;
			ma->d->error.o = 0;
		}
		else
		{
			ma->d->error = strange__thing__create_f();
		}
	}

	bool strange__thing__something_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		return !ma->d->error.d;
	}

	void strange__thing__set_error_f(void* const me /* :<any>= */,
		void const* const error /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a* const>(me);
		auto const ea = reinterpret_cast<strange__any_a const* const>(error);
		if (ea->d == ma->d->error.d)
		{
			return;
		}
		auto const nothing = strange::val(strange__thing__create_nothing_f());
		if (ea->d == nothing.a.d) // no error
		{
			strange__thing__set_something_f(me, true);
		}
		else
		{
			strange::mut(me);
			ma->d->error = *ea;
			strange::ref(ea);
		}
	}

	strange__any_a strange__thing__error_f(void const* const me /* :<any># */)
	{
		if (strange__thing__something_f(me))
		{
			return strange__thing__create_nothing_f();
		}
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		strange::ref(&(ma->d->error));
		return ma->d->error;
	}

	uint64_t strange__thing__hash_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		return std::hash<void const*>{}(ma->d);
	}

	bool strange__thing__equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return strange__thing___equal_f(me, other);
	}

	bool strange__thing___equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d == oa->d;
	}

	bool strange__thing__not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return strange__thing___not_equal_f(me, other);
	}

	bool strange__thing___not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d != oa->d;
	}

	bool strange__thing__less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return strange__thing___less_f(me, other);
	}

	bool strange__thing___less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d < oa->d;
	}

	bool strange__thing__greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return strange__thing___greater_f(me, other);
	}

	bool strange__thing___greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d > oa->d;
	}

	bool strange__thing__less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return strange__thing___less_or_equal_f(me, other);
	}

	bool strange__thing___less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d <= oa->d;
	}

	bool strange__thing__greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return strange__thing___greater_or_equal_f(me, other);
	}

	bool strange__thing___greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d >= oa->d;
	}

	// creators
	strange__any_a strange__thing__create_f()
	{
		static auto r = strange::var([]()
		{
			strange__any_a r;
			r.d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d))); std::cout << "malloc\n";
			if (!r.d)
			{
				std::abort();
			}
			strange__thing__init_f(&r);
			return r;
		}());
		return r.ret();
	}

	strange__any_a strange__thing__create_nothing_f()
	{
		static auto r = strange::var([]()
		{
			strange__any_a r;
			r.d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d))); std::cout << "malloc\n";
			if (!r.d)
			{
				std::abort();
			}
			strange__thing__init_f(&r);
			r.d->error = strange__thing__create_f();
			return r;
		}());
		return r.ret();
	}
}
