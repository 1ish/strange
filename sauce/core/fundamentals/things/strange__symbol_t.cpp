#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

extern "C"
{
	strange__symbol_o const* strange__symbol_o_f()
	{
		static strange__symbol_o o =
		{
			strange__symbol__cat_f,
			strange__symbol___free_f,
			strange__symbol___copy_f,
			strange__symbol__is_f,
			strange__symbol__as_f,
			strange__symbol___as_f,
			strange__symbol__type_f,
			strange__thing__something_f,
			strange__thing__nothing_f,
			strange__symbol__equal_f,
			strange__symbol___equal_f,
			strange__symbol__not_equal_f,
			strange__symbol___not_equal_f,
			strange__symbol__less_f,
			strange__symbol___less_f,
			strange__symbol__greater_f,
			strange__symbol___greater_f,
			strange__symbol__less_or_equal_f,
			strange__symbol___less_or_equal_f,
			strange__symbol__greater_or_equal_f,
			strange__symbol___greater_or_equal_f,

			strange__symbol__add_f,
			strange__symbol___to_char_star_f,
			strange__symbol__length_f
		};
		return &o;
	}

	strange__symbol_o const* strange__symbol_p_f()
	{
		static strange__symbol_o o = []()
		{
			strange__symbol_o o = *strange__symbol_o_f();
			o._copy = strange__thing___no_copy_f;
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

	void strange__symbol___free_f(void const* const me /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		std::free(md->symbol); std::cout << "free\n";
		strange__thing___free_f(me);
	}

	void strange__symbol___copy_f(void const* const me /* <symbol># */,
		void* const cp /* <symbol>= */)
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
		strange__symbol___clone_f(me, cp);
	}

	void strange__symbol___clone_f(void const* const me /* <symbol># */,
		void* const cp /* <symbol>= */)
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

	bool strange__symbol__is_f(void const* const me /* <symbol># */,
		void const* const ab /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const aa = reinterpret_cast<strange__symbol_a const* const>(ab);
		if (aa->d == ma->d)
		{
			return true;
		}
		auto const abc = aa->o->cat(aa).d;
		// ab.cat in me.cats
		static strange__thing_d* mats[] =
		{
			strange__any__cat_f(me).d,
			strange__symbol__cat_f(me).d
		};
		return abc == mats[0] || abc == mats[1];
	}

	bool strange__symbol__as_f(void const* const me /* <symbol># */,
		void* const ab /* <any>= */)
	{
		if (!strange__symbol__is_f(me, ab))
		{
			return false;
		}
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const aa = reinterpret_cast<strange__symbol_a* const>(ab);
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
		return true;
	}

	void strange__symbol___as_f(void const* const me /* <symbol># */,
		void* const ab /* <any>= */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const aa = reinterpret_cast<strange__symbol_a* const>(ab);
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

	strange__symbol_a strange__symbol__type_f(void const* const me /* <symbol># */)
	{
		static auto r = var(strange__symbol("strange::symbol"));
		return r.ret();
	}

	bool strange__symbol__equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = var(strange__no_symbol());
		if (oa->o->is(oa, os))
		{
			oa->o->as(oa, os);
			auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
			return std::strncmp(md->symbol, os.a.o->_to_char_star(os),
				std::max(md->length, os.a.o->length(os))) == 0;
		}
		return ma->d == oa->d; // strange__thing__equal_f(me, other)
	}

	bool strange__symbol___equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->_to_char_star(os),
			std::max(md->length, os->o->length(os))) == 0;
	}

	bool strange__symbol__not_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = var(strange__no_symbol());
		if (oa->o->is(oa, os))
		{
			oa->o->as(oa, os);
			auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
			return std::strncmp(md->symbol, os.a.o->_to_char_star(os),
				std::max(md->length, os.a.o->length(os))) != 0;
		}
		return ma->d != oa->d; // strange__thing__not_equal_f(me, other)
	}

	bool strange__symbol___not_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->_to_char_star(os),
			std::max(md->length, os->o->length(os))) != 0;
	}

	bool strange__symbol__less_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = var(strange__no_symbol());
		if (oa->o->is(oa, os))
		{
			oa->o->as(oa, os);
			auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
			return std::strncmp(md->symbol, os.a.o->_to_char_star(os),
				std::max(md->length, os.a.o->length(os))) < 0;
		}
		return ma->d < oa->d; // strange__thing__less_f(me, other)
	}

	bool strange__symbol___less_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->_to_char_star(os),
			std::max(md->length, os->o->length(os))) < 0;
	}

	bool strange__symbol__greater_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = var(strange__no_symbol());
		if (oa->o->is(oa, os))
		{
			oa->o->as(oa, os);
			auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
			return std::strncmp(md->symbol, os.a.o->_to_char_star(os),
				std::max(md->length, os.a.o->length(os))) > 0;
		}
		return ma->d > oa->d; // strange__thing__greater_f(me, other)
	}

	bool strange__symbol___greater_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->_to_char_star(os),
			std::max(md->length, os->o->length(os))) > 0;
	}

	bool strange__symbol__less_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = var(strange__no_symbol());
		if (oa->o->is(oa, os))
		{
			oa->o->as(oa, os);
			auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
			return std::strncmp(md->symbol, os.a.o->_to_char_star(os),
				std::max(md->length, os.a.o->length(os))) <= 0;
		}
		return ma->d <= oa->d; // strange__thing__less_or_equal_f(me, other)
	}

	bool strange__symbol___less_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->_to_char_star(os),
			std::max(md->length, os->o->length(os))) <= 0;
	}

	bool strange__symbol__greater_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = var(strange__no_symbol());
		if (oa->o->is(oa, os))
		{
			oa->o->as(oa, os);
			auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
			return std::strncmp(md->symbol, os.a.o->_to_char_star(os),
				std::max(md->length, os.a.o->length(os))) >= 0;
		}
		return ma->d >= oa->d; // strange__thing__greater_or_equal_f(me, other)
	}

	bool strange__symbol___greater_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__any_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->_to_char_star(os),
			std::max(md->length, os->o->length(os))) >= 0;
	}

	strange__symbol_a strange__symbol__add_f(void const* const me /* <symbol># */,
		void const* const symbol /* <symbol># */)
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
		std::memcpy(rd->symbol + md->length, sa->o->_to_char_star(sa), symbol_length + 1);

		strange__symbol_a r;
		r.d = reinterpret_cast<strange__thing_d*>(rd);
		r.o = strange__symbol_o_f();

		return r;
	}

	char const* strange__symbol___to_char_star_f(void const* const me /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		return md->symbol;
	}

	size_t strange__symbol__length_f(void const* const me /* <symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		return md->length;
	}

	strange__symbol_a strange__symbol(char const* const s)
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

	strange__symbol_a strange__no_symbol()
	{
		auto const rd = reinterpret_cast<strange__symbol_d* const>(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::exit(1);
		}
		rd->refs = 1;

		rd->length = 0;
		rd->symbol = reinterpret_cast<char*>(std::malloc(1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::exit(1);
		}
		*(rd->symbol) = 0;

		strange__symbol_a r;
		r.d = reinterpret_cast<strange__thing_d*>(rd);
		r.o = strange__symbol_n_f();

		return r;
	}
}
