#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>

extern "C"
{
	strange__symbol_o const* strange__symbol_o_f()
	{
		static strange__symbol_o o =
		{
			strange__symbol_free_f,
			strange__symbol_copy_f,
			strange__symbol_type_f,
			strange__thing_nothing_f,
			strange__thing_something_f,
			strange__symbol_add_f,
			strange__symbol_to_c_string_f,
			strange__symbol_length_f
		};
		return &o;
	}

	void strange__symbol_free_f(void const* const me)
	{
		strange__symbol_a const* const ma = (strange__symbol_a const* const)(me);
		strange__symbol_d* const md = (strange__symbol_d* const)(ma->d);
		std::free(md->symbol); std::cout << "free\n";
		strange__thing_free_f(me);
	}

	void strange__symbol_copy_f(void const* const me, void* const cp)
	{
		strange__symbol_a const* const ma = (strange__symbol_a const* const)(me);
		strange__symbol_a* const ca = (strange__symbol_a* const)(cp);
		ca->d = (strange__thing_d*)(std::malloc(sizeof(strange__symbol_d)));
		if (!ca->d)
		{
			std::exit(1);
		}
		std::memcpy(ca->d, ma->d, sizeof(strange__symbol_d));
		ca->d->refs = 1;
		strange__symbol_clone_f(me, cp);
	}

	void strange__symbol_clone_f(void const* const me, void* const cp)
	{
		// redundant: strange__thing_clone_f(me, cp);
		strange__symbol_a const* const ma = (strange__symbol_a const* const)(me);
		strange__symbol_d const* const md = (strange__symbol_d const* const)(ma->d);
		strange__symbol_a* const ca = (strange__symbol_a* const)(cp);
		strange__symbol_d* const cd = (strange__symbol_d* const)(ca->d);
		cd->symbol = (char*)(std::malloc(cd->length + 1)); std::cout << "malloc\n";
		if (!cd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(cd->symbol, md->symbol, cd->length + 1);
	}

	strange__symbol_a strange__symbol_type_f(void const* const me)
	{
		static auto r = var(sym("strange__symbol"));
		return r.ret();
	}

	strange__symbol_a strange__symbol_add_f(void const* const me, void const* const symbol)
	{
		// cannot assume symbol has a symbol_d, only that it implements symbol_a
		strange__symbol_a const* const ma = (strange__symbol_a const* const)(me);
		strange__symbol_d* const md = (strange__symbol_d* const)(ma->d);
		strange__symbol_a const* const sa = (strange__symbol_a const* const)(symbol);
		strange__symbol_d* const rd = (strange__symbol_d* const)(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
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

		strange__symbol_a r;
		r.d = (strange__thing_d*)(rd);
		r.o = strange__symbol_o_f();

		return r;
	}

	char const* strange__symbol_to_c_string_f(void const* const me)
	{
		strange__symbol_a const* const ma = (strange__symbol_a const* const)(me);
		strange__symbol_d* const md = (strange__symbol_d* const)(ma->d);
		return md->symbol;
	}

	size_t strange__symbol_length_f(void const* const me)
	{
		strange__symbol_a const* const ma = (strange__symbol_a const* const)(me);
		strange__symbol_d* const md = (strange__symbol_d* const)(ma->d);
		return md->length;
	}

	strange__symbol_a sym(char const* const s)
	{
		strange__symbol_d* const rd = (strange__symbol_d* const)(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
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

		strange__symbol_a r;
		r.d = (strange__thing_d*)(rd);
		r.o = strange__symbol_o_f();
		
		return r;
	}
}
