#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct symbol_t : thing_t
	{
	protected:
		char* symbol_;
		int64_t length_;
		uint64_t hash_;

		inline symbol_t(any_a const& me,
			char const* s)
		: thing_t{ me }
		, symbol_{ nullptr }
		, length_{ 0 }
		, hash_{ 0 }
		{
			me.o = symbol_t::_operations();

			if (s)
			{
				length_ = std::strlen(s);
				symbol_ = new char[length_ + 1];
				std::memcpy(symbol_, s, length_ + 1);
				hash_ = std::hash<std::string_view>{}(std::string_view{ symbol_, static_cast<uint64_t>(length_) });
			}
		}

		inline symbol_t(any_a const& me,
			any_a const& original)
		: thing_t{ me, original }
		, symbol_{ nullptr }
		, length_{ 0 }
		, hash_{ 0 }
		{
			me.o = symbol_t::_operations();

			auto const ot = static_cast<symbol_t const* const>(original.t);
			length_ = ot->length_;
			symbol_ = new char[length_ + 1];
			std::memcpy(symbol_, ot->symbol_, length_ + 1);
			hash_ = ot->hash_;
		}

		symbol_t(symbol_t const&) = delete;

		symbol_t& operator=(symbol_t const&) = delete;

		virtual ~symbol_t()
		{
			delete[] symbol_;
		}

	private:
		// symbol_o
		static symbol_o const* _operations();
		static symbol_o const* _pointer_operations();

	public:
		// inline
		static inline bool equal_symbol(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->char_star(other), mt->length_ + 1) == 0;
		}

		static inline bool less_symbol(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->char_star(other), mt->length_ + 1) < 0;
		}

		static inline bool less_or_equal_symbol(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->char_star(other), mt->length_ + 1) <= 0;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static uint64_t hash(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		static bool less(con<> const& me,
			con<> const& other);

		static bool less_or_equal(con<> const& me,
			con<> const& other);

		static void _copy(any_a const& me,
			any_a const& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// symbol_a
		static var<symbol_a> add(con<symbol_a> const& me,
			con<symbol_a> const& suffix);

		static char const* char_star(con<symbol_a> const& me);

		static int64_t length(con<symbol_a> const& me);

		static char first_char(con<symbol_a> const& me);

		static char last_char(con<symbol_a> const& me);

	public:
		// creators
		static inline var<symbol_a> create(char const* s)
		{
			any_a r;
			new symbol_t{ r, s };
			symbol_t::_initialise(r);
			return var<symbol_a>{ reinterpret_cast<symbol_a&>(r) };
		}

		static inline var<symbol_a> create_empty()
		{
			static auto r = symbol_t::create("");
			return r;
		}

		static inline var<symbol_a> create_from_range(con<range_a<>> const& range)
		{
			return create_empty();
		}

		static inline var<symbol_a> unpack(con<container_a> const& container)
		{
			return create_empty();
		}
	};

	inline var<symbol_a> sym(char const* s)
	{
		return symbol_t::create(s);
	}
}

#endif
