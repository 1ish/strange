#include "../../../strange.h"

#include <functional>
#include <string_view>

namespace strange
{
	symbol_t::symbol_t(any_a& me_ /* :<symbol>= */,
		char const* const s /* :_char_star_# */)
	: thing_t{ me_ }
	, symbol{ nullptr }
	, length{ 0 }
	, hash{ 0 }
	{
		me_.o = symbol_t::operations_f();

		if (s)
		{
			length = std::strlen(s);
			symbol = new char[length + 1];
			std::memcpy(symbol, s, length + 1);
			hash = std::hash<std::string_view>{}(std::string_view{ symbol, static_cast<uint64_t>(length) });
		}
	}

	symbol_t::symbol_t(any_a& me_ /* :<symbol>= */,
		any_a const& original_ /* :<symbol># */)
	: thing_t{ me_, original_ }
	, symbol{ nullptr }
	, length{ 0 }
	, hash{ 0 }
	{
		me_.o = symbol_t::operations_f();

		auto const ot = static_cast<symbol_t const* const>(original_.t);
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
			{
				// any_a
				symbol_a::cat_e,
				_free_m,
				_copy_e,
				is_e,
				as_e,
				type_e,
				_set_pointer_m,
				_pointer_e,
				set_something_m,
				something_e,
				set_error_m,
				error_e,
				hash_e,
				equal_e,
				not_equal_e,
				less_e,
				greater_e,
				less_or_equal_e,
				greater_or_equal_e,
			},
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
			symbol_o ops = *symbol_t::operations_f();
			ops._copy = thing_t::_no_copy_e;
			return ops;
		}();
		return &operations;
	}

	// any_a
	void symbol_t::_copy_e(any_a const& me_ /* :<symbol># */,
		any_a& copy_ /* :<symbol>= */)
	{
		new symbol_t{ copy_, me_ };
		symbol_t::_clone_e(me_, copy_);
	}

	bool symbol_t::is_e(val<> const& me_ /* :<symbol># */,
		val<> const& abstraction_ /* :<any># */)
	{
		// abstraction_.cat in me_.cats
		auto const abc = abstraction_.o->cat;
		return abc == any_a::cat_e || abc == symbol_a::cat_e;
	}

	var<symbol_a> symbol_t::type_e(val<> const& me_ /* :<symbol># */)
	{
		static auto r = sym("strange::symbol");
		return r;
	}

	void symbol_t::_set_pointer_m(var<>& me_ /* :<symbol>= */,
		bool is_pointer /* :_bool_# */)
	{
		if (is_pointer)
		{
			me_.o = symbol_t::pointer_operations_f();
		}
		else
		{
			me_.o = symbol_t::operations_f();
		}
	}

	uint64_t symbol_t::hash_e(val<> const& me_ /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me_.t);
		return mt->hash;
	}

	bool symbol_t::equal_e(val<> const& me_ /* :<symbol># */,
		val<> const& other_ /* :<any># */)
	{
		auto const os = other_.dynamic<val<symbol_a>>();
		if (thing_t::something_e(os))
		{
			return symbol_t::_equal_e(me_.reference<val<symbol_a>>(), os);
		}
		return thing_t::equal_e(me_, other_);
	}

	bool symbol_t::not_equal_e(val<> const& me_ /* :<symbol># */,
		val<> const& other_ /* :<any># */)
	{
		auto const os = other_.dynamic<val<symbol_a>>();
		if (thing_t::something_e(os))
		{
			return symbol_t::_not_equal_e(me_.reference<val<symbol_a>>(), os);
		}
		return thing_t::not_equal_e(me_, other_);
	}

	bool symbol_t::less_e(val<> const& me_ /* :<symbol># */,
		val<> const& other_ /* :<any># */)
	{
		auto const os = other_.dynamic<val<symbol_a>>();
		if (thing_t::something_e(os))
		{
			return symbol_t::_less_e(me_.reference<val<symbol_a>>(), os);
		}
		return thing_t::less_e(me_, other_);
	}

	bool symbol_t::greater_e(val<> const& me_ /* :<symbol># */,
		val<> const& other_ /* :<any># */)
	{
		auto const os = other_.dynamic<val<symbol_a>>();
		if (thing_t::something_e(os))
		{
			return symbol_t::_greater_e(me_.reference<val<symbol_a>>(), os);
		}
		return thing_t::greater_e(me_, other_);
	}

	bool symbol_t::less_or_equal_e(val<> const& me_ /* :<symbol># */,
		val<> const& other_ /* :<any># */)
	{
		auto const os = other_.dynamic<val<symbol_a>>();
		if (thing_t::something_e(os))
		{
			return symbol_t::_less_or_equal_e(me_.reference<val<symbol_a>>(), os);
		}
		return thing_t::less_or_equal_e(me_, other_);
	}

	bool symbol_t::greater_or_equal_e(val<> const& me_ /* :<symbol># */,
		val<> const& other_ /* :<any># */)
	{
		auto const os = other_.dynamic<val<symbol_a>>();
		if (thing_t::something_e(os))
		{
			return symbol_t::_greater_or_equal_e(me_.reference<val<symbol_a>>(), os);
		}
		return thing_t::greater_or_equal_e(me_, other_);
	}

	// symbol_a
	var<symbol_a> symbol_t::add_e(val<symbol_a> const& me_ /* :<symbol># */,
		val<symbol_a> const& suffix_ /* :<symbol># */)
	{
		// can assume suffix_ implements symbol_a, but not that is has a symbol_t
		auto const mt = static_cast<symbol_t const* const>(me_.t);
		any_a r;
		auto const rt = new symbol_t{ r, nullptr };
		symbol_t::_initialise_m(r);
		int64_t const suffix_length = suffix_.o->length(suffix_);
		rt->length = mt->length + suffix_length;
		rt->symbol = new char[rt->length + 1];
		std::memcpy(rt->symbol, mt->symbol, mt->length);
		std::memcpy(rt->symbol + mt->length, suffix_.o->to_char_star(suffix_), suffix_length + 1);
		rt->hash = std::hash<std::string_view>{}(std::string_view{ rt->symbol, static_cast<uint64_t>(rt->length) });
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	char const* symbol_t::to_char_star_e(val<symbol_a> const& me_ /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me_.t);
		return mt->symbol;
	}

	int64_t symbol_t::length_e(val<symbol_a> const& me_ /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me_.t);
		return mt->length;
	}

	char symbol_t::first_char_e(val<symbol_a> const& me_ /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me_.t);
		return (mt->symbol)[0];
	}

	char symbol_t::last_char_e(val<symbol_a> const& me_ /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me_.t);
		return (mt->symbol)[std::max(int64_t{ 0 }, mt->length - 1)];
	}

	// creators
	var<symbol_a> symbol_t::create_f(char const* const s /* :_char_star_# */)
	{
		any_a r;
		new symbol_t{ r, s };
		symbol_t::_initialise_m(r);
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	var<symbol_a> symbol_t::create_empty_f()
	{
		static auto r = symbol_t::create_f("");
		return r;
	}
}
