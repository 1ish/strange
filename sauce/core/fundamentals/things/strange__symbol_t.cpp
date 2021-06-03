#include "../../../strange.h"

#include <functional>
#include <string_view>

namespace strange
{
	symbol_t::symbol_t(any_a& me /* :<symbol>= */,
		char const* const s /* :_char_star_# */)
	: thing_t{ me }
	, symbol{ nullptr }
	, length{ 0 }
	, hash{ 0 }
	{
		me.o = symbol_t::operations_f();

		if (s)
		{
			length = std::strlen(s);
			symbol = new char[length + 1];
			std::memcpy(symbol, s, length + 1);
			hash = std::hash<std::string_view>{}(std::string_view{ symbol, static_cast<uint64_t>(length) });
		}
	}

	symbol_t::symbol_t(any_a& me /* :<symbol>= */,
		any_a const& original /* :<symbol># */)
	: thing_t{ me, original }
	, symbol{ nullptr }
	, length{ 0 }
	, hash{ 0 }
	{
		me.o = symbol_t::operations_f();

		auto const ot = static_cast<symbol_t const* const>(original.t);
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
				symbol_a::cat_f,
				is_f,
				as_f,
				type_f,
				set_something_f,
				something_f,
				set_error_f,
				error_f,
				hash_f,
				equal_f,
				not_equal_f,
				less_f,
				greater_f,
				less_or_equal_f,
				greater_or_equal_f,
				_free_f,
				_copy_f,
				_set_pointer_f,
				_pointer_f,
			},
			// symbol_a
			add_f,
			to_char_star_f,
			length_f,
			first_char_f,
			last_char_f,
		};
		return &operations;
	}

	symbol_o const* symbol_t::pointer_operations_f()
	{
		static symbol_o operations = []()
		{
			symbol_o ops = *symbol_t::operations_f();
			ops._copy = thing_t::_no_copy_f;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool symbol_t::is_f(con<> const& me /* :<symbol># */,
		con<> const& abstraction /* :<any># */)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat_f || abc == symbol_a::cat_f;
	}

	var<symbol_a> symbol_t::type_f(con<> const& me /* :<symbol># */)
	{
		static auto r = sym("strange::symbol");
		return r;
	}

	uint64_t symbol_t::hash_f(con<> const& me /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->hash;
	}

	bool symbol_t::equal_f(con<> const& me /* :<symbol># */,
		con<> const& other /* :<any># */)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (thing_t::something_f(os))
		{
			return symbol_t::_equal_f(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::equal_f(me, other);
	}

	bool symbol_t::not_equal_f(con<> const& me /* :<symbol># */,
		con<> const& other /* :<any># */)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (thing_t::something_f(os))
		{
			return symbol_t::_not_equal_f(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::not_equal_f(me, other);
	}

	bool symbol_t::less_f(con<> const& me /* :<symbol># */,
		con<> const& other /* :<any># */)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (thing_t::something_f(os))
		{
			return symbol_t::_less_f(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::less_f(me, other);
	}

	bool symbol_t::greater_f(con<> const& me /* :<symbol># */,
		con<> const& other /* :<any># */)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (thing_t::something_f(os))
		{
			return symbol_t::_greater_f(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::greater_f(me, other);
	}

	bool symbol_t::less_or_equal_f(con<> const& me /* :<symbol># */,
		con<> const& other /* :<any># */)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (thing_t::something_f(os))
		{
			return symbol_t::_less_or_equal_f(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::less_or_equal_f(me, other);
	}

	bool symbol_t::greater_or_equal_f(con<> const& me /* :<symbol># */,
		con<> const& other /* :<any># */)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (thing_t::something_f(os))
		{
			return symbol_t::_greater_or_equal_f(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::greater_or_equal_f(me, other);
	}

	void symbol_t::_copy_f(any_a const& me /* :<symbol># */,
		any_a& copy /* :<symbol>= */)
	{
		new symbol_t{ copy, me };
		symbol_t::_clone_f(me, copy);
	}

	void symbol_t::_set_pointer_f(var<> const& me /* :<symbol>= */,
		bool is_pointer /* :_bool_# */)
	{
		if (is_pointer)
		{
			me.o = symbol_t::pointer_operations_f();
		}
		else
		{
			me.o = symbol_t::operations_f();
		}
	}

	// symbol_a
	var<symbol_a> symbol_t::add_f(con<symbol_a> const& me /* :<symbol># */,
		con<symbol_a> const& suffix /* :<symbol># */)
	{
		// can assume suffix implements symbol_a, but not that is has a symbol_t
		auto const mt = static_cast<symbol_t const* const>(me.t);
		any_a r;
		auto const rt = new symbol_t{ r, nullptr };
		symbol_t::_initialise_f(r);
		int64_t const suffixlength = suffix.o->length(suffix);
		rt->length = mt->length + suffixlength;
		rt->symbol = new char[rt->length + 1];
		std::memcpy(rt->symbol, mt->symbol, mt->length);
		std::memcpy(rt->symbol + mt->length, suffix.o->to_char_star(suffix), suffixlength + 1);
		rt->hash = std::hash<std::string_view>{}(std::string_view{ rt->symbol, static_cast<uint64_t>(rt->length) });
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	char const* symbol_t::to_char_star_f(con<symbol_a> const& me /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->symbol;
	}

	int64_t symbol_t::length_f(con<symbol_a> const& me /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->length;
	}

	char symbol_t::first_char_f(con<symbol_a> const& me /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return (mt->symbol)[0];
	}

	char symbol_t::last_char_f(con<symbol_a> const& me /* :<symbol># */)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return (mt->symbol)[std::max(int64_t{ 0 }, mt->length - 1)];
	}

	// creators
	var<symbol_a> symbol_t::create_f(char const* const s /* :_char_star_# */)
	{
		any_a r;
		new symbol_t{ r, s };
		symbol_t::_initialise_f(r);
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	var<symbol_a> symbol_t::create_empty_f()
	{
		static auto r = symbol_t::create_f("");
		return r;
	}
}
