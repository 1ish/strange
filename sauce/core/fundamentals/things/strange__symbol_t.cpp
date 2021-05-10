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
			strange__symbol_cat_f,
			strange__symbol_free_f,
			strange__symbol_copy_f,
			strange__symbol_is_f,
			strange__symbol_as_f,
			strange__symbol_type_f,
			strange__thing_something_f,
			strange__thing_nothing_f,

			strange__symbol_add_f,
			strange__symbol_to_char_star_f,
			strange__symbol_length_f
		};
		return &o;
	}

	strange__symbol_o const* strange__symbol_p_f()
	{
		static strange__symbol_o o = []()
		{
			strange__symbol_o o = *strange__symbol_o_f();
			o.copy = strange__thing_no_copy_f;
			return o;
		}();
		return &o;
	}

	strange__symbol_o const* strange__symbol_n_f()
	{
		static strange__symbol_o o = []()
		{
			strange__symbol_o o = *strange__symbol_o_f();
			std::swap(o.something, o.nothing);
			return o;
		}();
		return &o;
	}

	void strange__symbol_free_f(void const* const me)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		std::free(md->symbol); std::cout << "free\n";
		strange__thing_free_f(me);
	}

	void strange__symbol_copy_f(void const* const me, void* const cp)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const ca = reinterpret_cast<strange__symbol_a* const>(cp);
		ca->d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__symbol_d)));
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
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const ca = reinterpret_cast<strange__symbol_a* const>(cp);
		auto const cd = reinterpret_cast<strange__symbol_d* const>(ca->d);
		cd->symbol = reinterpret_cast<char*>(std::malloc(cd->length + 1)); std::cout << "malloc\n";
		if (!cd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(cd->symbol, md->symbol, cd->length + 1);
	}

	bool strange__symbol_is_f(void const* const me, void const* const ab)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const aa = reinterpret_cast<strange__symbol_a const* const>(ab);
		if (aa->d == ma->d)
		{
			return true;
		}
		auto const ac = aa->o->cat(aa).d;
		// ab.cat in me.cats
		static strange__thing_d* mats[] = { strange__any_cat_f(me).d, strange__symbol_cat_f(me).d };
		return ac == mats[0] || ac == mats[1];
	}

	void strange__symbol_as_f(void const* const me, void* const ab)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const aa = reinterpret_cast<strange__symbol_a* const>(ab);
		if (aa->d != ma->d)
		{
			if (!--(aa->d->refs))
			{
				aa->o->free(aa);
				std::free(aa->d); std::cout << "free\n";
			}
			*aa = *ma;
			++(ma->d->refs);
		}
	}

	strange__symbol_a strange__symbol_type_f(void const* const me)
	{
		static auto r = var(sym("strange__symbol"));
		return r.ret();
	}

	strange__symbol_a strange__symbol_add_f(void const* const me, void const* const symbol)
	{
		// cannot assume symbol has a symbol_d, only that it implements symbol_a
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		auto const sa = reinterpret_cast<strange__symbol_a const* const>(symbol);
		auto const rd = reinterpret_cast<strange__symbol_d* const>(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::exit(1);
		}
		rd->refs = 1;

		size_t const symbol_length = sa->o->length(sa);
		rd->length = md->length + symbol_length;
		rd->symbol = reinterpret_cast<char*>(std::malloc(rd->length + 1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(rd->symbol, md->symbol, md->length);
		std::memcpy(rd->symbol + md->length, sa->o->to_char_star(sa), symbol_length + 1);

		strange__symbol_a r;
		r.d = reinterpret_cast<strange__thing_d*>(rd);
		r.o = strange__symbol_o_f();

		return r;
	}

	char const* strange__symbol_to_char_star_f(void const* const me)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		return md->symbol;
	}

	size_t strange__symbol_length_f(void const* const me)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		return md->length;
	}

	strange__symbol_a sym(char const* const s)
	{
		auto const rd = reinterpret_cast<strange__symbol_d* const>(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::exit(1);
		}
		rd->refs = 1;

		rd->length = std::strlen(s);
		rd->symbol = reinterpret_cast<char*>(std::malloc(rd->length + 1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::exit(1);
		}
		std::memcpy(rd->symbol, s, rd->length + 1);

		strange__symbol_a r;
		r.d = reinterpret_cast<strange__thing_d*>(rd);
		r.o = strange__symbol_o_f();
		
		return r;
	}
}
