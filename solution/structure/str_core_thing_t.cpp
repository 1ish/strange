#include "str.h"
#include "str_core_value_c.hpp"

#include <cstdlib>
#include <iostream>

extern "C"
{
	str_core_any_o const* str_core_thing_o_f()
	{
		static str_core_any_o o =
		{
			str_core_thing_free_f,
			str_core_thing_copy_f,
			str_core_thing_type_f,
			str_core_thing_nothing_f,
			str_core_thing_something_f
		};
		return &o;
	}

	str_core_any_o const* str_core_nothing_o_f()
	{
		static str_core_any_o o =
		{
			str_core_thing_free_f,
			str_core_thing_copy_f,
			str_core_thing_type_f,
			str_core_thing_something_f,
			str_core_thing_nothing_f
		};
		return &o;
	}

	void str_core_thing_free_f(void const* const me)
	{
	}

	void str_core_thing_copy_f(void const* const me, void* const cp)
	{
		str_core_any_a const* const ma = (str_core_any_a const* const)(me);
		str_core_any_a* const ca = (str_core_any_a* const)(cp);
		ca->d = (str_core_thing_d*)(std::malloc(sizeof(str_core_thing_d)));
		if (!ca->d)
		{
			std::exit(1);
		}
		// redundant: std::memcpy(ca->d, ma->d, sizeof(str_core_thing_d));
		ca->d->refs = 1;
		// redundant: str_core_thing_clone_f(me, cp);
	}

	void str_core_thing_clone_f(void const* const me, void* const cp)
	{
	}

	str_core_symbol_a str_core_thing_type_f(void const* const me)
	{
		static auto r = var(sym("str_core_thing"));
		return r.ret();
	}

	bool str_core_thing_nothing_f(void const* const me)
	{
		return false;
	}

	bool str_core_thing_something_f(void const* const me)
	{
		return true;
	}

	void mutate(void* const me)
	{
		str_core_any_a* const ma = (str_core_any_a* const)(me);
		if (ma->d->refs > 1)
		{
			str_core_any_a cp = *ma;
			ma->o->copy(me, &cp);
			--(ma->d->refs);
			*ma = cp;
		}
	}

	static str_core_any_a nothing_s()
	{
		str_core_any_a r;
		r.d = (str_core_thing_d* const)(std::malloc(sizeof(str_core_thing_d))); std::cout << "malloc\n";
		if (!r.d)
		{
			std::exit(1);
		}
		r.d->refs = 1;
		r.o = str_core_nothing_o_f();
		return r;
	}

	str_core_any_a nothing()
	{
		static auto r = var(nothing_s());
		return r.ret();
	}

	static str_core_any_a something_s()
	{
		str_core_any_a r;
		r.d = (str_core_thing_d* const)(std::malloc(sizeof(str_core_thing_d))); std::cout << "malloc\n";
		if (!r.d)
		{
			std::exit(1);
		}
		r.d->refs = 1;
		r.o = str_core_thing_o_f();
		return r;
	}

	str_core_any_a something()
	{
		static auto r = var(something_s());
		return r.ret();
	}
}
