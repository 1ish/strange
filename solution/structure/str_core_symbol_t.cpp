#include "str.h"
#include "str_core_value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>

extern "C"
{
	str_core_symbol_o const* str_core_symbol_o_f()
	{
		static str_core_symbol_o o =
		{
			str_core_symbol_free_f,
			str_core_symbol_copy_f,
			str_core_symbol_type_f,
			str_core_thing_nothing_f,
			str_core_thing_something_f,
			str_core_symbol_add_f,
			str_core_symbol_to_c_string_f,
			str_core_symbol_length_f
		};
		return &o;
	}

	void str_core_symbol_free_f(void const* const me)
	{
		str_core_symbol_a const* const ma = (str_core_symbol_a const* const)(me);
		str_core_symbol_d* const md = (str_core_symbol_d* const)(ma->d);
		std::free(md->symbol); std::cout << "free\n";
		str_core_thing_free_f(me);
	}

	void str_core_symbol_copy_f(void const* const me, void* const cp)
	{
		str_core_symbol_a const* const ma = (str_core_symbol_a const* const)(me);
		str_core_symbol_a* const ca = (str_core_symbol_a* const)(cp);
		ca->d = (str_core_thing_d*)(std::malloc(sizeof(str_core_symbol_d)));
		if (!ca->d)
		{
			std::exit(1);
		}
		std::memcpy(ca->d, ma->d, sizeof(str_core_symbol_d));
		ca->d->refs = 1;
		str_core_symbol_clone_f(me, cp);
	}

	void str_core_symbol_clone_f(void const* const me, void* const cp)
	{
		// redundant: str_core_thing_clone_f(me, cp);
		str_core_symbol_a const* const ma = (str_core_symbol_a const* const)(me);
		str_core_symbol_d const* const md = (str_core_symbol_d const* const)(ma->d);
		str_core_symbol_a* const ca = (str_core_symbol_a* const)(cp);
		str_core_symbol_d* const cd = (str_core_symbol_d* const)(ca->d);
		cd->symbol = (char*)(std::malloc(cd->length + 1)); std::cout << "malloc\n";
		if (!cd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(cd->symbol, md->symbol, cd->length + 1);
	}

	str_core_symbol_a str_core_symbol_type_f(void const* const me)
	{
		static auto r = var(sym("str_core_symbol"));
		return r.ret();
	}

	str_core_symbol_a str_core_symbol_add_f(void const* const me, void const* const symbol)
	{
		// cannot assume symbol has a symbol_d, only that it implements symbol_a
		str_core_symbol_a const* const ma = (str_core_symbol_a const* const)(me);
		str_core_symbol_d* const md = (str_core_symbol_d* const)(ma->d);
		str_core_symbol_a const* const sa = (str_core_symbol_a const* const)(symbol);
		str_core_symbol_d* const rd = (str_core_symbol_d* const)(std::malloc(sizeof(str_core_symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::exit(1);
		}
		rd->refs = 1;

		size_t const symbol_length = sa->o->length(sa);
		rd->length = md->length + symbol_length;
		rd->symbol = (char*)(std::malloc(rd->length + 1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(rd->symbol, md->symbol, md->length);
		std::memcpy(rd->symbol + md->length, sa->o->to_c_string(sa), symbol_length + 1);

		str_core_symbol_a r;
		r.d = (str_core_thing_d*)(rd);
		r.o = str_core_symbol_o_f();

		return r;
	}

	char const* str_core_symbol_to_c_string_f(void const* const me)
	{
		str_core_symbol_a const* const ma = (str_core_symbol_a const* const)(me);
		str_core_symbol_d* const md = (str_core_symbol_d* const)(ma->d);
		return md->symbol;
	}

	size_t str_core_symbol_length_f(void const* const me)
	{
		str_core_symbol_a const* const ma = (str_core_symbol_a const* const)(me);
		str_core_symbol_d* const md = (str_core_symbol_d* const)(ma->d);
		return md->length;
	}

	str_core_symbol_a sym(char const* const s)
	{
		str_core_symbol_d* const rd = (str_core_symbol_d* const)(std::malloc(sizeof(str_core_symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::exit(1);
		}
		rd->refs = 1;

		rd->length = std::strlen(s);
		rd->symbol = (char*)(std::malloc(rd->length + 1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(rd->symbol, s, rd->length + 1);

		str_core_symbol_a r;
		r.d = (str_core_thing_d*)(rd);
		r.o = str_core_symbol_o_f();
		
		return r;
	}
}
