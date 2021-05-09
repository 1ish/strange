#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <iostream>
#include <utility>

extern "C"
{
	strange__any_o const* strange__thing_o_f()
	{
		static strange__any_o o =
		{
			strange__any_cat_f,
			strange__thing_free_f,
			strange__thing_copy_f,
			strange__thing_is_f,
			strange__thing_as_f,
			strange__thing_type_f,
			strange__thing_something_f,
			strange__thing_nothing_f
		};
		return &o;
	}

	strange__any_o const* strange__thing_p_f()
	{
		static strange__any_o p = []()
		{
			strange__any_o p = *strange__thing_o_f();
			p.copy = strange__thing_no_copy_f;
			return p;
		}();
		return &p;
	}

	strange__any_o const* strange__thing_n_f()
	{
		static strange__any_o n = []()
		{
			strange__any_o n = *strange__thing_o_f();
			std::swap(n.something, n.nothing);
			return n;
		}();
		return &n;
	}

	void strange__thing_free_f(void const* const me)
	{
	}

	void strange__thing_copy_f(void const* const me, void* const cp)
	{
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		ca->d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d)));
		if (!ca->d)
		{
			std::exit(1);
		}
		ca->d->refs = 1;
	}

	void strange__thing_no_copy_f(void const* const me, void* const cp)
	{
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		++(ca->d->refs);
	}

	bool strange__thing_is_f(void const* const me, void* const at)
	{
		return false;
	}

	bool strange__thing_as_f(void const* const me, void* const at)
	{
		return false;
	}

	strange__symbol_a strange__thing_type_f(void const* const me)
	{
		static auto r = var(sym("strange__thing"));
		return r.ret();
	}

	bool strange__thing_something_f(void const* const me)
	{
		return true;
	}

	bool strange__thing_nothing_f(void const* const me)
	{
		return false;
	}

	void mutate(void* const me)
	{
		auto const ma = reinterpret_cast<strange__any_a* const>(me);
		if (ma->d->refs > 1)
		{
			strange__any_a cp = *ma;
			ma->o->copy(me, &cp);
			--(ma->d->refs);
			*ma = cp;
		}
	}

	strange__any_a something()
	{
		static auto r = var([]()
		{
			strange__any_a r;
			r.d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d))); std::cout << "malloc\n";
			if (!r.d)
			{
				std::exit(1);
			}
			r.d->refs = 1;
			r.o = strange__thing_o_f();
			return r;
		}());
		return r.ret();
	}

	strange__any_a nothing()
	{
		static auto r = var([]()
		{
			strange__any_a r;
			r.d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d))); std::cout << "malloc\n";
			if (!r.d)
			{
				std::exit(1);
			}
			r.d->refs = 1;
			r.o = strange__thing_n_f();
			return r;
		}());
		return r.ret();
	}
}
