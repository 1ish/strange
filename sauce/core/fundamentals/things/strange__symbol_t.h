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

		symbol_t(any_a& me,
			char const* const s);

		symbol_t(any_a& me,
			any_a const& original);

		symbol_t(symbol_t const&) = delete;

		symbol_t& operator=(symbol_t const&) = delete;

		virtual ~symbol_t();

	private:
		// symbol_o
		static symbol_o const* _operations();
		static symbol_o const* _pointer_operations();

	public:
		// inline
		static inline bool _equal(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->to_char_star(other),
				std::max(mt->length_, other.o->length(other))) == 0;
		}

		static inline bool _less(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->to_char_star(other),
				std::max(mt->length_, other.o->length(other))) < 0;
		}

		static inline bool _greater(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->to_char_star(other),
				std::max(mt->length_, other.o->length(other))) > 0;
		}

		static inline bool _less_or_equal(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->to_char_star(other),
				std::max(mt->length_, other.o->length(other))) <= 0;
		}

		static inline bool _greater_or_equal(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_, other.o->to_char_star(other),
				std::max(mt->length_, other.o->length(other))) >= 0;
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

		static bool greater(con<> const& me,
			con<> const& other);

		static bool less_or_equal(con<> const& me,
			con<> const& other);

		static bool greater_or_equal(con<> const& me,
			con<> const& other);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(var<> const& me,
			bool is_pointer);

		// symbol_a
		static var<symbol_a> add(con<symbol_a> const& me,
			con<symbol_a> const& suffix);

		static char const* to_char_star(con<symbol_a> const& me);

		static int64_t length(con<symbol_a> const& me);

		static char first_char(con<symbol_a> const& me);

		static char last_char(con<symbol_a> const& me);

	public:
		// creators
		static var<symbol_a> create(char const* const s);
		static var<symbol_a> create_empty();
	};

	inline var<symbol_a> sym(char const* const s)
	{
		return symbol_t::create(s);
	}
}

#endif
