#include "../../../strange.h"

#include <functional>
#include <string_view>

namespace strange
{
	symbol_t::symbol_t(any_a& me,
		char const* const s)
	: thing_t{ me }
	, symbol_n{ nullptr }
	, length_n{ 0 }
	, hash_n{ 0 }
	{
		me.o = symbol_t::operations();

		if (s)
		{
			length_n = std::strlen(s);
			symbol_n = new char[length_n + 1];
			std::memcpy(symbol_n, s, length_n + 1);
			hash_n = std::hash<std::string_view>{}(std::string_view{ symbol_n, static_cast<uint64_t>(length_n) });
		}
	}

	symbol_t::symbol_t(any_a& me,
		any_a const& original)
	: thing_t{ me, original }
	, symbol_n{ nullptr }
	, length_n{ 0 }
	, hash_n{ 0 }
	{
		me.o = symbol_t::operations();

		auto const ot = static_cast<symbol_t const* const>(original.t);
		length_n = ot->length_n;
		symbol_n = new char[length_n + 1];
		std::memcpy(symbol_n, ot->symbol_n, length_n + 1);
		hash_n = ot->hash_n;
	}

	symbol_t::~symbol_t()
	{
		delete[] symbol_n;
	}

	// symbol_o
	symbol_o const* symbol_t::operations()
	{
		static symbol_o operations =
		{
			{
				// any_a
				symbol_a::cat,
				is,
				as,
				type,
				set_error,
				error,
				hash,
				equal,
				not_equal,
				less,
				greater,
				less_or_equal,
				greater_or_equal,
				_free,
				_copy,
				_set_pointer,
				_pointer,
			},
			// symbol_a
			add,
			to_char_star,
			length,
			first_char,
			last_char,
		};
		return &operations;
	}

	symbol_o const* symbol_t::pointer_operations()
	{
		static symbol_o operations = []()
		{
			symbol_o ops = *symbol_t::operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool symbol_t::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat || abc == symbol_a::cat;
	}

	bool symbol_t::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!symbol_t::is(me, abstraction))
		{
			return false;
		}
		abstraction = me;
		return true;
	}

	var<symbol_a> symbol_t::type(con<> const& me)
	{
		static auto r = sym("strange::symbol");
		return r;
	}

	uint64_t symbol_t::hash(con<> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->hash_n;
	}

	bool symbol_t::equal(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (symbol_t::something(os))
		{
			return symbol_t::_equal(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::equal(me, other);
	}

	bool symbol_t::not_equal(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (symbol_t::something(os))
		{
			return symbol_t::_not_equal(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::not_equal(me, other);
	}

	bool symbol_t::less(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (symbol_t::something(os))
		{
			return symbol_t::_less(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::less(me, other);
	}

	bool symbol_t::greater(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (symbol_t::something(os))
		{
			return symbol_t::_greater(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::greater(me, other);
	}

	bool symbol_t::less_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (symbol_t::something(os))
		{
			return symbol_t::_less_or_equal(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::less_or_equal(me, other);
	}

	bool symbol_t::greater_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (symbol_t::something(os))
		{
			return symbol_t::_greater_or_equal(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::greater_or_equal(me, other);
	}

	void symbol_t::_copy(any_a const& me,
		any_a& copy)
	{
		new symbol_t{ copy, me };
		symbol_t::_clone(me, copy);
	}

	void symbol_t::_set_pointer(var<> const& me,
		bool is_pointer)
	{
		if (is_pointer)
		{
			me.o = symbol_t::pointer_operations();
		}
		else
		{
			me.o = symbol_t::operations();
		}
	}

	// symbol_a
	var<symbol_a> symbol_t::add(con<symbol_a> const& me,
		con<symbol_a> const& suffix)
	{
		// can assume suffix implements symbol_a, but not that is has a symbol_t
		auto const mt = static_cast<symbol_t const* const>(me.t);
		any_a r;
		auto const rt = new symbol_t{ r, nullptr };
		symbol_t::_initialise(r);
		int64_t const suffixlength = suffix.o->length(suffix);
		rt->length_n = mt->length_n + suffixlength;
		rt->symbol_n = new char[rt->length_n + 1];
		std::memcpy(rt->symbol_n, mt->symbol_n, mt->length_n);
		std::memcpy(rt->symbol_n + mt->length_n, suffix.o->to_char_star(suffix), suffixlength + 1);
		rt->hash_n = std::hash<std::string_view>{}(std::string_view{ rt->symbol_n, static_cast<uint64_t>(rt->length_n) });
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	char const* symbol_t::to_char_star(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->symbol_n;
	}

	int64_t symbol_t::length(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->length_n;
	}

	char symbol_t::first_char(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return (mt->symbol_n)[0];
	}

	char symbol_t::last_char(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return (mt->symbol_n)[std::max(int64_t{ 0 }, mt->length_n - 1)];
	}

	// creators
	var<symbol_a> symbol_t::create(char const* const s)
	{
		any_a r;
		new symbol_t{ r, s };
		symbol_t::_initialise(r);
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	var<symbol_a> symbol_t::create_empty()
	{
		static auto r = symbol_t::create("");
		return r;
	}
}
