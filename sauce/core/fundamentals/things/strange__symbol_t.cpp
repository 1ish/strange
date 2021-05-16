#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

extern "C"
{
	// symbol_o
	strange__symbol_o const* strange__symbol_o_f()
	{
		static strange__symbol_o o =
		{
			// any_a
			strange__symbol__cat_f,
			strange__symbol___free_f,
			strange__symbol___copy_f,
			strange__symbol__is_f,
			strange__symbol__as_f,
			strange__thing___as_f,
			strange__symbol__type_f,
			strange__symbol___set_pointer_f,
			strange__symbol___pointer_f,
			strange__thing__set_something_f,
			strange__thing__something_f,
			strange__thing__set_error_f,
			strange__thing__error_f,
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
			// symbol_a
			strange__symbol__add_f,
			strange__symbol__to_char_star_f,
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

	// init
	void strange__symbol_init_f(void* const me /* :<symbol>= */,
		char const* const s /* :_char_star_# */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		strange__thing_init_f(ma);
		if (s)
		{
			md->length = std::strlen(s);
			md->symbol = reinterpret_cast<char*>(std::malloc(md->length + 1)); std::cout << "malloc\n";
			if (!md->symbol)
			{
				std::abort();
			}
			std::memcpy(md->symbol, s, md->length + 1);
		}
		ma->o = strange__symbol_o_f();
	}

	// any_a
	void strange__symbol___free_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		std::free(md->symbol); std::cout << "free\n";
		strange__thing___free_f(ma);
	}

	void strange__symbol___copy_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const ca = reinterpret_cast<strange__symbol_a* const>(cp);
		ca->d = reinterpret_cast<strange__thing_d*>(std::malloc(sizeof(strange__symbol_d)));
		if (!ca->d)
		{
			std::abort();
		}
		std::memcpy(ca->d, ma->d, sizeof(strange__symbol_d));
		strange__symbol___clone_f(ma, ca);
	}

	void strange__symbol___clone_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const ca = reinterpret_cast<strange__symbol_a* const>(cp);
		auto const cd = reinterpret_cast<strange__symbol_d* const>(ca->d);
		strange__thing___clone_f(ma, ca);
		cd->symbol = reinterpret_cast<char*>(std::malloc(cd->length + 1)); std::cout << "malloc\n";
		if (!cd->symbol)
		{
			std::abort();
		}
		std::memcpy(cd->symbol, md->symbol, cd->length + 1);
	}

	bool strange__symbol__is_f(void const* const me /* :<symbol># */,
		void const* const ab /* :<any># */)
	{
		auto const aa = reinterpret_cast<strange__symbol_a const* const>(ab);
		auto const abc = aa->o->cat(aa).d;
		// ab.cat in me.cats
		static strange__thing_d* mats[] =
		{
			strange__any__cat_f(me).d,
			strange__symbol__cat_f(me).d
		};
		return abc == mats[0] || abc == mats[1];
	}

	bool strange__symbol__as_f(void const* const me /* :<symbol># */,
		void* const ab /* :<any>= */)
	{
		if (!strange__symbol__is_f(me, ab))
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

	strange__symbol_a strange__symbol__type_f(void const* const me /* :<symbol># */)
	{
		static auto r = strange::var(strange__symbol("strange::symbol"));
		return r.ret();
	}

	void strange__symbol___set_pointer_f(void* const me /* :<symbol>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a* const>(me);
		if (is_pointer)
		{
			ma->o = strange__symbol_p_f();
		}
		else
		{
			ma->o = strange__symbol_o_f();
		}
	}

	bool strange__symbol___pointer_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		return ma->o == strange__symbol_p_f();
	}

	bool strange__symbol__equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = strange::var(strange__symbol_empty());
		if (oa->o->as(oa, os))
		{
			return strange__symbol___equal_f(me, os);
		}
		return strange__thing__equal_f(me, other);
	}

	bool strange__symbol___equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) == 0;
	}

	bool strange__symbol__not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = strange::var(strange__symbol_empty());
		if (oa->o->as(oa, os))
		{
			return strange__symbol___not_equal_f(me, os);
		}
		return strange__thing__not_equal_f(me, other);
	}

	bool strange__symbol___not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) != 0;
	}

	bool strange__symbol__less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = strange::var(strange__symbol_empty());
		if (oa->o->as(oa, os))
		{
			return strange__symbol___less_f(me, os);
		}
		return strange__thing__less_f(me, other);
	}

	bool strange__symbol___less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) < 0;
	}

	bool strange__symbol__greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = strange::var(strange__symbol_empty());
		if (oa->o->as(oa, os))
		{
			return strange__symbol___greater_f(me, os);
		}
		return strange__thing__greater_f(me, other);
	}

	bool strange__symbol___greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) > 0;
	}

	bool strange__symbol__less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = strange::var(strange__symbol_empty());
		if (oa->o->as(oa, os))
		{
			return strange__symbol___less_or_equal_f(me, os);
		}
		return strange__thing__less_or_equal_f(me, other);
	}

	bool strange__symbol___less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) <= 0;
	}

	bool strange__symbol__greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<strange__any_a const* const>(other);
		auto os = strange::var(strange__symbol_empty());
		if (oa->o->as(oa, os))
		{
			return strange__symbol___greater_or_equal_f(me, os);
		}
		return strange__thing__greater_or_equal_f(me, other);
	}

	bool strange__symbol___greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d const* const>(ma->d);
		auto const os = reinterpret_cast<strange__symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) >= 0;
	}

	// symbol_a
	strange__symbol_a strange__symbol__add_f(void const* const me /* :<symbol># */,
		void const* const suffix /* :<symbol># */)
	{
		// cannot assume symbol has a symbol_d, only that it implements symbol_a
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		auto const sa = reinterpret_cast<strange__symbol_a const* const>(suffix);
		auto const rd = reinterpret_cast<strange__symbol_d* const>(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::abort();
		}
		strange__symbol_a r;
		r.d = reinterpret_cast<strange__thing_d*>(rd);
		strange__symbol_init_f(&r, 0);
		int64_t const symbol_length = sa->o->length(sa);
		rd->length = md->length + symbol_length;
		rd->symbol = reinterpret_cast<char*>(std::malloc(rd->length + 1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::abort();
		}
		std::memcpy(rd->symbol, md->symbol, md->length);
		std::memcpy(rd->symbol + md->length, sa->o->to_char_star(sa), symbol_length + 1);
		return r;
	}

	char const* strange__symbol__to_char_star_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		return md->symbol;
	}

	int64_t strange__symbol__length_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<strange__symbol_a const* const>(me);
		auto const md = reinterpret_cast<strange__symbol_d* const>(ma->d);
		return md->length;
	}

	// constructors
	strange__symbol_a strange__symbol(char const* const s /* :_char_star_# */)
	{
		auto const rd = reinterpret_cast<strange__symbol_d* const>(std::malloc(sizeof(strange__symbol_d))); std::cout << "malloc\n";
		if (!rd)
		{
			std::abort();
		}
		strange__symbol_a r;
		r.d = reinterpret_cast<strange__thing_d*>(rd);
		strange__symbol_init_f(&r, s);
		return r;
	}

	strange__symbol_a strange__symbol_empty()
	{
		static auto r = strange::var(strange__symbol(""));
		return r.ret();
	}
}
