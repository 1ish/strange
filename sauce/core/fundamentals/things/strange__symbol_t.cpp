#include "../../../strange.h"
#include "../../utilities/strange__value_u.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string_view>

namespace strange
{
	symbol_t::symbol_t(void* const me_ /* :<symbol>= */,
		char const* const s /* :_char_star_# */)
	: thing_t{ me_ }
	, symbol{ nullptr }
	, length{ 0 }
	, hash{ 0 }
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me_);
		ma->o = symbol_t::operations_f();

		if (s)
		{
			length = std::strlen(s);
			symbol = new char[length + 1];
			std::memcpy(symbol, s, length + 1);
			hash = std::hash<std::string_view>{}(std::string_view{ symbol, static_cast<uint64_t>(length) });
		}
	}

	symbol_t::symbol_t(void* const me_ /* :<symbol>= */,
		void const* const original_ /* :<symbol># */)
	: thing_t{ me_, original_ }
	, symbol{ nullptr }
	, length{ 0 }
	, hash{ 0 }
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me_);
		ma->o = symbol_t::operations_f();

		auto const oa = reinterpret_cast<symbol_a const* const>(original_);
		auto const ot = static_cast<symbol_t const* const>(oa->t);
		length = ot->length;
		symbol = new char[length + 1];
		std::memcpy(symbol, ot->symbol, length + 1);
		hash = ot->hash;
	}

	symbol_t::~symbol_t()
	{
		delete[] symbol;
	}

	// symbol_o
	symbol_o const* symbol_t::operations_f()
	{
		static symbol_o operations =
		{
			// any_a
			symbol_a::cat_e,
			_free_m,
			_copy_e,
			is_e,
			as_e,
			_as_e,
			type_e,
			_set_pointer_m,
			_pointer_e,
			set_something_m,
			something_e,
			set_error_m,
			error_e,
			hash_e,
			equal_e,
			_equal_e,
			not_equal_e,
			_not_equal_e,
			less_e,
			_less_e,
			greater_e,
			_greater_e,
			less_or_equal_e,
			_less_or_equal_e,
			greater_or_equal_e,
			_greater_or_equal_e,
			// symbol_a
			add_e,
			to_char_star_e,
			length_e,
			first_char_e,
			last_char_e,
		};
		return &operations;
	}

	symbol_o const* symbol_t::pointer_operations_f()
	{
		static symbol_o operations = []()
		{
			symbol_o operations = *symbol_t::operations_f();
			operations._copy = thing_t::_no_copy_e;
			return operations;
		}();
		return &operations;
	}

	// any_a
	void symbol_t::_copy_e(void const* const me_ /* :<symbol># */,
		void* const copy_ /* :<symbol>= */)
	{
		new symbol_t{ copy_, me_ };
		symbol_t::_clone_e(me_, copy_);
	}

	bool symbol_t::is_e(void const* const me_ /* :<symbol># */,
		void const* const abstraction_ /* :<any># */)
	{
		auto const aa = reinterpret_cast<symbol_a const* const>(abstraction_);
		auto const abc = aa->o->cat(aa).t;
		// abstraction_.cat in me_.cats
		static thing_t* mats[] =
		{
			any_a::cat_e(me_).t,
			symbol_a::cat_e(me_).t
		};
		return abc == mats[0] || abc == mats[1];
	}

	bool symbol_t::as_e(void const* const me_ /* :<symbol># */,
		void* const abstraction_ /* :<any>= */)
	{
		if (!symbol_t::is_e(me_, abstraction_))
		{
			return false;
		}
		auto const ma = reinterpret_cast<any_a const* const>(me_);
		auto const aa = reinterpret_cast<any_a* const>(abstraction_);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		thing_t::_as_e(me_, abstraction_);
		thing_t::_repoint_m(aa, mp, ap);
		return true;
	}

	var<symbol_a> symbol_t::type_e(void const* const me_ /* :<symbol># */)
	{
		static auto r = strange::sym("strange::symbol");
		return r;
	}

	void symbol_t::_set_pointer_m(void* const me_ /* :<symbol>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me_);
		if (is_pointer)
		{
			ma->o = symbol_t::pointer_operations_f();
		}
		else
		{
			ma->o = symbol_t::operations_f();
		}
	}

	bool symbol_t::_pointer_e(void const* const me_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		return ma->o == symbol_t::pointer_operations_f();
	}

	uint64_t symbol_t::hash_e(void const* const me_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		return md->hash;
	}

	bool symbol_t::equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_equal_e(me_, os);
		}
		return thing_t::equal_e(me_, other_);
	}

	bool symbol_t::_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other_);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) == 0;
	}

	bool symbol_t::not_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_not_equal_e(me_, os);
		}
		return thing_t::not_equal_e(me_, other_);
	}

	bool symbol_t::_not_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other_);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) != 0;
	}

	bool symbol_t::less_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_less_e(me_, os);
		}
		return thing_t::less_e(me_, other_);
	}

	bool symbol_t::_less_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other_);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) < 0;
	}

	bool symbol_t::greater_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_greater_e(me_, os);
		}
		return thing_t::greater_e(me_, other_);
	}

	bool symbol_t::_greater_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other_);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) > 0;
	}

	bool symbol_t::less_or_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_less_or_equal_e(me_, os);
		}
		return thing_t::less_or_equal_e(me_, other_);
	}

	bool symbol_t::_less_or_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other_);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) <= 0;
	}

	bool symbol_t::greater_or_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other_);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_greater_or_equal_e(me_, os);
		}
		return thing_t::greater_or_equal_e(me_, other_);
	}

	bool symbol_t::_greater_or_equal_e(void const* const me_ /* :<symbol># */,
		void const* const other_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other_);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) >= 0;
	}

	// symbol_a
	var<symbol_a> symbol_t::add_e(void const* const me_ /* :<symbol># */,
		void const* const suffix_ /* :<symbol># */)
	{
		// cannot assume symbol has a symbol_t, only that it implements symbol_a
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t* const>(ma->t);
		auto const sa = reinterpret_cast<symbol_a const* const>(suffix_);
		symbol_a r;
		auto const rd = new symbol_t{ &r, static_cast<const char* const>(nullptr) };
		symbol_t::_initialise_m(&r);
		int64_t const symbol_length = sa->o->length(sa);
		rd->length = md->length + symbol_length;
		rd->symbol = new char[rd->length + 1];
		std::memcpy(rd->symbol, md->symbol, md->length);
		std::memcpy(rd->symbol + md->length, sa->o->to_char_star(sa), symbol_length + 1);
		rd->hash = std::hash<std::string_view>{}(std::string_view{ rd->symbol, static_cast<uint64_t>(rd->length) });
		return var<symbol_a>{ r };
	}

	char const* symbol_t::to_char_star_e(void const* const me_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return md->symbol;
	}

	int64_t symbol_t::length_e(void const* const me_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return md->length;
	}

	char symbol_t::first_char_e(void const* const me_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return (md->symbol)[0];
	}

	char symbol_t::last_char_e(void const* const me_ /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me_);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return (md->symbol)[std::max(int64_t{ 0 }, md->length - 1)];
	}

	// creators
	var<symbol_a> symbol_t::create_f(char const* const s /* :_char_star_# */)
	{
		symbol_a r;
		auto const rd = new symbol_t{ &r, s };
		symbol_t::_initialise_m(&r);
		return var<symbol_a>{ r };
	}

	var<symbol_a> symbol_t::create_empty_f()
	{
		static auto r = symbol_t::create_f("");
		return r;
	}
}
