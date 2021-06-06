#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct symbol_t : thing_t
	{
	protected:
		char* symbol_n;
		int64_t length_n;
		uint64_t hash_n;

		symbol_t(any_a& me,
			char const* const s);

		symbol_t(any_a& me,
			any_a const& original);

		symbol_t(symbol_t const&) = delete;

		symbol_t& operator=(symbol_t const&) = delete;

		virtual ~symbol_t();

	private:
		// symbol_o
		static symbol_o const* operations_f();
		static symbol_o const* pointer_operations_f();

	public:
		// inline
		static inline bool _equal_f(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_n, other.o->to_char_star(other),
				std::max(mt->length_n, other.o->length(other))) == 0;
		}

		static inline bool _not_equal_f(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_n, other.o->to_char_star(other),
				std::max(mt->length_n, other.o->length(other))) != 0;
		}

		static inline bool _less_f(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_n, other.o->to_char_star(other),
				std::max(mt->length_n, other.o->length(other))) < 0;
		}

		static inline bool _greater_f(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_n, other.o->to_char_star(other),
				std::max(mt->length_n, other.o->length(other))) > 0;
		}

		static inline bool _less_or_equal_f(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_n, other.o->to_char_star(other),
				std::max(mt->length_n, other.o->length(other))) <= 0;
		}

		static inline bool _greater_or_equal_f(con<symbol_a> const& me,
			con<symbol_a> const& other)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol_n, other.o->to_char_star(other),
				std::max(mt->length_n, other.o->length(other))) >= 0;
		}

	protected:
		// any_a
		static bool is_f(con<> const& me,
			con<> const& abstraction);

		static bool as_f(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type_f(con<> const& me);

		static uint64_t hash_f(con<> const& me);

		static bool equal_f(con<> const& me,
			con<> const& other);

		static bool not_equal_f(con<> const& me,
			con<> const& other);

		static bool less_f(con<> const& me,
			con<> const& other);

		static bool greater_f(con<> const& me,
			con<> const& other);

		static bool less_or_equal_f(con<> const& me,
			con<> const& other);

		static bool greater_or_equal_f(con<> const& me,
			con<> const& other);

		static void _copy_f(any_a const& me,
			any_a& copy);

		static void _set_pointer_f(var<> const& me,
			bool is_pointer);

		// symbol_a
		static var<symbol_a> add_f(con<symbol_a> const& me,
			con<symbol_a> const& suffix);

		static char const* to_char_star_f(con<symbol_a> const& me);

		static int64_t length_f(con<symbol_a> const& me);

		static char first_char_f(con<symbol_a> const& me);

		static char last_char_f(con<symbol_a> const& me);

	public:
		// creators
		static var<symbol_a> create_f(char const* const s);
		static var<symbol_a> create_empty_f();
	};

	inline var<symbol_a> sym(char const* const s)
	{
		return symbol_t::create_f(s);
	}
}

#endif
