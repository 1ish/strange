#include "../../../strange.h"

#include <functional>
#include <string_view>

namespace strange
{
	// symbol_o
	symbol_o const* symbol_t::_operations()
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
				less,
				less_or_equal,
				_free,
				_copy,
				_set_pointer,
				_pointer,
			},
			{
				// symbol_a
				add,
				to_char_star,
				length,
				first_char,
				last_char,
			},
		};
		return &operations;
	}

	symbol_o const* symbol_t::_pointer_operations()
	{
		static symbol_o operations = []()
		{
			symbol_o ops = *symbol_t::_operations();
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
		return mt->hash_;
	}

	bool symbol_t::equal(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (os.o->something(os))
		{
			return symbol_t::_equal(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::equal(me, other);
	}

	bool symbol_t::less(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (os.o->something(os))
		{
			return symbol_t::_less(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::less(me, other);
	}

	bool symbol_t::less_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const os = other.dyn<con<symbol_a>>();
		if (os.o->something(os))
		{
			return symbol_t::_less_or_equal(me.ref<con<symbol_a>>(), os);
		}
		return thing_t::less_or_equal(me, other);
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
		me.o = reinterpret_cast<any_o const*>(is_pointer ? symbol_t::_pointer_operations() : symbol_t::_operations());
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
		rt->length_ = mt->length_ + suffixlength;
		rt->symbol_ = new char[rt->length_ + 1];
		std::memcpy(rt->symbol_, mt->symbol_, mt->length_);
		std::memcpy(rt->symbol_ + mt->length_, suffix.o->to_char_star(suffix), suffixlength + 1);
		rt->hash_ = std::hash<std::string_view>{}(std::string_view{ rt->symbol_, static_cast<uint64_t>(rt->length_) });
		return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
	}

	char const* symbol_t::to_char_star(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->symbol_;
	}

	int64_t symbol_t::length(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return mt->length_;
	}

	char symbol_t::first_char(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return (mt->symbol_)[0];
	}

	char symbol_t::last_char(con<symbol_a> const& me)
	{
		auto const mt = static_cast<symbol_t const* const>(me.t);
		return (mt->symbol_)[std::max(int64_t{ 0 }, mt->length_ - 1)];
	}
}
