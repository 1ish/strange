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
			strange__any__cat_f,
			strange__thing___free_f,
			strange__thing___copy_f,
			strange__thing__is_f,
			strange__thing__as_f,
			strange__thing__type_f,
			strange__thing__something_f,
			strange__thing__nothing_f,
			strange__thing__equal_f,
			strange__thing__not_equal_f,
			strange__thing__less_f,
			strange__thing__greater_f,
			strange__thing__less_or_equal_f,
			strange__thing__greater_or_equal_f
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

	void strange__thing___free_f(void const* const me)
	{
	}

	void strange__thing___copy_f(void const* const me, void* const cp)
	{
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		ca->d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__thing_d)));
		if (!ca->d)
		{
			std::exit(1);
		}
		ca->d->refs = 1;
	}

	void strange__thing___no_copy_f(void const* const me, void* const cp)
	{
		auto const ca = reinterpret_cast<strange__any_a* const>(cp);
		++(ca->d->refs);
	}

	bool strange__thing__is_f(void const* const me, void const* const ab)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const aa = reinterpret_cast<strange__any_a const* const>(ab);
		// ab.cat in me.cats
		static strange__thing_d* const mat = strange__any__cat_f(me).d;
		return aa->d == ma->d || aa->o->cat(aa).d == mat;
	}

	void strange__thing__as_f(void const* const me, void* const ab)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const aa = reinterpret_cast<strange__any_a* const>(ab);
		if (aa->d != ma->d)
		{
			if (!--(aa->d->refs))
			{
				aa->o->_free(aa);
				std::free(aa->d); std::cout << "free\n";
			}
			*aa = *ma;
			++(ma->d->refs);
		}
	}

	strange__symbol_a strange__thing__type_f(void const* const me)
	{
		static auto r = var(sym("strange::thing"));
		return r.ret();
	}

	bool strange__thing__something_f(void const* const me)
	{
		return true;
	}

	bool strange__thing__nothing_f(void const* const me)
	{
		return false;
	}

	bool strange__thing__equal_f(void const* const me, void const* const other)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d == oa->d;
	}

	bool strange__thing__not_equal_f(void const* const me, void const* const other)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d != oa->d;
	}

	bool strange__thing__less_f(void const* const me, void const* const other)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d < oa->d;
	}

	bool strange__thing__greater_f(void const* const me, void const* const other)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d > oa->d;
	}

	bool strange__thing__less_or_equal_f(void const* const me, void const* const other)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d <= oa->d;
	}

	bool strange__thing__greater_or_equal_f(void const* const me, void const* const other)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		return ma->d >= oa->d;
	}

	void mutate(void* const me)
	{
		auto const ma = reinterpret_cast<strange__any_a* const>(me);
		if (ma->d->refs > 1)
		{
			strange__any_a cp = *ma;
			ma->o->_copy(me, &cp);
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
