#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string_view>

namespace strange
{
	// symbol_o
	symbol_o const* symbol_t::symbol_o_f()
	{
		static symbol_o o =
		{
			// any_a
			symbol_a::symbol__cat_f,
			symbol_t::symbol___free_f,
			symbol_t::symbol___copy_f,
			symbol_t::symbol__is_f,
			symbol_t::symbol__as_f,
			thing_t::thing___as_f,
			symbol_t::symbol__type_f,
			symbol_t::symbol___set_pointer_f,
			symbol_t::symbol___pointer_f,
			thing_t::thing__set_something_f,
			thing_t::thing__something_f,
			thing_t::thing__set_error_f,
			thing_t::thing__error_f,
			symbol_t::symbol__hash_f,
			symbol_t::symbol__equal_f,
			symbol_t::symbol___equal_f,
			symbol_t::symbol__not_equal_f,
			symbol_t::symbol___not_equal_f,
			symbol_t::symbol__less_f,
			symbol_t::symbol___less_f,
			symbol_t::symbol__greater_f,
			symbol_t::symbol___greater_f,
			symbol_t::symbol__less_or_equal_f,
			symbol_t::symbol___less_or_equal_f,
			symbol_t::symbol__greater_or_equal_f,
			symbol_t::symbol___greater_or_equal_f,
			// symbol_a
			symbol_t::symbol__add_f,
			symbol_t::symbol__to_char_star_f,
			symbol_t::symbol__length_f,
			symbol_t::symbol__first_char_f,
			symbol_t::symbol__last_char_f
		};
		return &o;
	}

	symbol_o const* symbol_t::symbol_p_f()
	{
		static symbol_o o = []()
		{
			symbol_o o = *symbol_o_f();
			o._copy = thing_t::thing___no_copy_f;
			return o;
		}();
		return &o;
	}

	// init
	void symbol_t::symbol__init_f(void* const me /* :<symbol>= */,
		char const* const s /* :_char_star_# */)
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		thing_t::thing__init_f(ma);
		if (s)
		{
			md->length = std::strlen(s);
			md->symbol = reinterpret_cast<char*>(std::malloc(md->length + 1)); std::cout << "malloc\n";
			if (!md->symbol)
			{
				std::abort();
			}
			std::memcpy(md->symbol, s, md->length + 1);
			md->hash = std::hash<std::string_view>{}(std::string_view{ md->symbol, static_cast<uint64_t>(md->length) });
		}
		ma->o = symbol_o_f();
	}

	// any_a
	void symbol_t::symbol___free_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		std::free(md->symbol); std::cout << "free\n";
		thing_t::thing___free_f(ma);
	}

	void symbol_t::symbol___copy_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const ca = reinterpret_cast<symbol_a* const>(cp);
		ca->d = reinterpret_cast<thing_t*>(std::malloc(sizeof(symbol_t)));
		if (!ca->d)
		{
			std::abort();
		}
		std::memcpy(ca->d, ma->d, sizeof(symbol_t));
		symbol_t::symbol___clone_f(ma, ca);
	}

	void symbol_t::symbol___clone_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const ca = reinterpret_cast<symbol_a* const>(cp);
		auto const cd = reinterpret_cast<symbol_t* const>(ca->d);
		thing_t::thing___clone_f(ma, ca);
		cd->symbol = reinterpret_cast<char*>(std::malloc(cd->length + 1)); std::cout << "malloc\n";
		if (!cd->symbol)
		{
			std::abort();
		}
		std::memcpy(cd->symbol, md->symbol, cd->length + 1);
	}

	bool symbol_t::symbol__is_f(void const* const me /* :<symbol># */,
		void const* const ab /* :<any># */)
	{
		auto const aa = reinterpret_cast<symbol_a const* const>(ab);
		auto const abc = aa->o->cat(aa).d;
		// ab.cat in me.cats
		static thing_t* mats[] =
		{
			any_a::any__cat_f(me).d,
			symbol_a::symbol__cat_f(me).d
		};
		return abc == mats[0] || abc == mats[1];
	}

	bool symbol_t::symbol__as_f(void const* const me /* :<symbol># */,
		void* const ab /* :<any>= */)
	{
		if (!symbol_t::symbol__is_f(me, ab))
		{
			return false;
		}
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const aa = reinterpret_cast<any_a* const>(ab);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		thing_t::thing___as_f(me, ab);
		strange::rep(aa, mp, ap);
		return true;
	}

	symbol_a symbol_t::symbol__type_f(void const* const me /* :<symbol># */)
	{
		static auto r = strange::val("strange::symbol");
		return r.ret();
	}

	void symbol_t::symbol___set_pointer_f(void* const me /* :<symbol>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me);
		if (is_pointer)
		{
			ma->o = symbol_p_f();
		}
		else
		{
			ma->o = symbol_o_f();
		}
	}

	bool symbol_t::symbol___pointer_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		return ma->o == symbol_p_f();
	}

	uint64_t symbol_t::symbol__hash_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		return md->hash;
	}

	bool symbol_t::symbol__equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = strange::var(symbol_t::symbol__create_empty_f());
		if (oa->o->as(oa, os))
		{
			return symbol_t::symbol___equal_f(me, os);
		}
		return thing_t::thing__equal_f(me, other);
	}

	bool symbol_t::symbol___equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) == 0;
	}

	bool symbol_t::symbol__not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = strange::var(symbol_t::symbol__create_empty_f());
		if (oa->o->as(oa, os))
		{
			return symbol_t::symbol___not_equal_f(me, os);
		}
		return thing_t::thing__not_equal_f(me, other);
	}

	bool symbol_t::symbol___not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) != 0;
	}

	bool symbol_t::symbol__less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = strange::var(symbol_t::symbol__create_empty_f());
		if (oa->o->as(oa, os))
		{
			return symbol_t::symbol___less_f(me, os);
		}
		return thing_t::thing__less_f(me, other);
	}

	bool symbol_t::symbol___less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) < 0;
	}

	bool symbol_t::symbol__greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = strange::var(symbol_t::symbol__create_empty_f());
		if (oa->o->as(oa, os))
		{
			return symbol_t::symbol___greater_f(me, os);
		}
		return thing_t::thing__greater_f(me, other);
	}

	bool symbol_t::symbol___greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) > 0;
	}

	bool symbol_t::symbol__less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = strange::var(symbol_t::symbol__create_empty_f());
		if (oa->o->as(oa, os))
		{
			return symbol_t::symbol___less_or_equal_f(me, os);
		}
		return thing_t::thing__less_or_equal_f(me, other);
	}

	bool symbol_t::symbol___less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) <= 0;
	}

	bool symbol_t::symbol__greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = strange::var(symbol_t::symbol__create_empty_f());
		if (oa->o->as(oa, os))
		{
			return symbol_t::symbol___greater_or_equal_f(me, os);
		}
		return thing_t::thing__greater_or_equal_f(me, other);
	}

	bool symbol_t::symbol___greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t const* const>(ma->d);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) >= 0;
	}

	// symbol_a
	symbol_a symbol_t::symbol__add_f(void const* const me /* :<symbol># */,
		void const* const suffix /* :<symbol># */)
	{
		// cannot assume symbol has a symbol_t, only that it implements symbol_a
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		auto const sa = reinterpret_cast<symbol_a const* const>(suffix);
		auto const rd = reinterpret_cast<symbol_t* const>(std::malloc(sizeof(symbol_t))); std::cout << "malloc\n";
		if (!rd)
		{
			std::abort();
		}
		symbol_a r;
		r.d = reinterpret_cast<thing_t*>(rd);
		symbol_t::symbol__init_f(&r, 0);
		int64_t const symbol_length = sa->o->length(sa);
		rd->length = md->length + symbol_length;
		rd->symbol = reinterpret_cast<char*>(std::malloc(rd->length + 1)); std::cout << "malloc\n";
		if (!rd->symbol)
		{
			std::abort();
		}
		std::memcpy(rd->symbol, md->symbol, md->length);
		std::memcpy(rd->symbol + md->length, sa->o->to_char_star(sa), symbol_length + 1);
		rd->hash = std::hash<std::string_view>{}(std::string_view{ rd->symbol, static_cast<uint64_t>(rd->length) });
		return r;
	}

	char const* symbol_t::symbol__to_char_star_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		return md->symbol;
	}

	int64_t symbol_t::symbol__length_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		return md->length;
	}

	char symbol_t::symbol__first_char_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		return (md->symbol)[0];
	}

	char symbol_t::symbol__last_char_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = reinterpret_cast<symbol_t* const>(ma->d);
		return (md->symbol)[std::max(int64_t{ 0 }, md->length - 1)];
	}

	// creators
	symbol_a symbol_t::symbol__create_f(char const* const s /* :_char_star_# */)
	{
		auto const rd = reinterpret_cast<symbol_t* const>(std::malloc(sizeof(symbol_t))); std::cout << "malloc\n";
		if (!rd)
		{
			std::abort();
		}
		symbol_a r;
		r.d = reinterpret_cast<thing_t*>(rd);
		symbol_t::symbol__init_f(&r, s);
		return r;
	}

	symbol_a symbol_t::symbol__create_empty_f()
	{
		static auto r = strange::var(symbol_t::symbol__create_f(""));
		return r.ret();
	}
}
