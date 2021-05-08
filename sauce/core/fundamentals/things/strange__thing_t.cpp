#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <iostream>

extern "C"
{
	strange__any_o const* strange__thing_o_f()
	{
		static strange__any_o o =
		{
			strange__thing_free_f,
			strange__thing_copy_f,
			strange__thing_type_f,
			strange__thing_nothing_f,
			strange__thing_something_f
		};
		return &o;
	}

	strange__any_o const* strange__nothing_o_f()
	{
		static strange__any_o o =
		{
			strange__thing_free_f,
			strange__thing_copy_f,
			strange__thing_type_f,
			strange__thing_something_f,
			strange__thing_nothing_f
		};
		return &o;
	}

	void strange__thing_free_f(void const* const me)
	{
	}

	void strange__thing_copy_f(void const* const me, void* const cp)
	{
		strange__any_a const* const ma = (strange__any_a const* const)(me);
		strange__any_a* const ca = (strange__any_a* const)(cp);
		ca->d = (strange__thing_d*)(std::malloc(sizeof(strange__thing_d)));
		if (!ca->d)
		{
			std::exit(1);
		}
		// redundant: std::memcpy(ca->d, ma->d, sizeof(strange__thing_d));
		ca->d->refs = 1;
		// redundant: strange__thing_clone_f(me, cp);
	}

	void strange__thing_clone_f(void const* const me, void* const cp)
	{
	}

	strange__symbol_a strange__thing_type_f(void const* const me)
	{
		static auto r = var(sym("strange__thing"));
		return r.ret();
	}

	bool strange__thing_nothing_f(void const* const me)
	{
		return false;
	}

	bool strange__thing_something_f(void const* const me)
	{
		return true;
	}

	void mutate(void* const me)
	{
		strange__any_a* const ma = (strange__any_a* const)(me);
		if (ma->d->refs > 1)
		{
			strange__any_a cp = *ma;
			ma->o->copy(me, &cp);
			--(ma->d->refs);
			*ma = cp;
		}
	}

	static strange__any_a nothing_s()
	{
		strange__any_a r;
		r.d = (strange__thing_d* const)(std::malloc(sizeof(strange__thing_d))); std::cout << "malloc\n";
		if (!r.d)
		{
			std::exit(1);
		}
		r.d->refs = 1;
		r.o = strange__nothing_o_f();
		return r;
	}

	strange__any_a nothing()
	{
		static auto r = var(nothing_s());
		return r.ret();
	}

	static strange__any_a something_s()
	{
		strange__any_a r;
		r.d = (strange__thing_d* const)(std::malloc(sizeof(strange__thing_d))); std::cout << "malloc\n";
		if (!r.d)
		{
			std::exit(1);
		}
		r.d->refs = 1;
		r.o = strange__thing_o_f();
		return r;
	}

	strange__any_a something()
	{
		static auto r = var(something_s());
		return r.ret();
	}
}
