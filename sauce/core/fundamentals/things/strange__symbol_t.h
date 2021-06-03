#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct symbol_t : thing_t
	{
		char* symbol;
		int64_t length;
		uint64_t hash;

	protected:
		symbol_t(any_a& me /* :<symbol>= */,
			char const* const s /* :_char_star_# */);

		symbol_t(any_a& me /* :<symbol>= */,
			any_a const& original /* :<symbol># */);

		symbol_t(symbol_t const&) = delete;

		symbol_t& operator=(symbol_t const&) = delete;

		virtual ~symbol_t();

	private:
		// symbol_o
		static symbol_o const* operations_f();
		static symbol_o const* pointer_operations_f();

	public:
		// inline
		static inline bool _equal_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& other /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol, other.o->to_char_star(other),
				std::max(mt->length, other.o->length(other))) == 0;
		}

		static inline bool _not_equal_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& other /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol, other.o->to_char_star(other),
				std::max(mt->length, other.o->length(other))) != 0;
		}

		static inline bool _less_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& other /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol, other.o->to_char_star(other),
				std::max(mt->length, other.o->length(other))) < 0;
		}

		static inline bool _greater_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& other /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol, other.o->to_char_star(other),
				std::max(mt->length, other.o->length(other))) > 0;
		}

		static inline bool _less_or_equal_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& other /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol, other.o->to_char_star(other),
				std::max(mt->length, other.o->length(other))) <= 0;
		}

		static inline bool _greater_or_equal_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& other /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me.t);
			return std::strncmp(mt->symbol, other.o->to_char_star(other),
				std::max(mt->length, other.o->length(other))) >= 0;
		}

	protected:
		// any_a
		static bool is_f(con<> const& me /* :<symbol># */,
			con<> const& abstraction /* :<any># */);

		static var<symbol_a> type_f(con<> const& me /* :<symbol># */);

		static uint64_t hash_f(con<> const& me /* :<symbol># */);

		static bool equal_f(con<> const& me /* :<symbol># */,
			con<> const& other /* :<any># */);

		static bool not_equal_f(con<> const& me /* :<symbol># */,
			con<> const& other /* :<any># */);

		static bool less_f(con<> const& me /* :<symbol># */,
			con<> const& other /* :<any># */);

		static bool greater_f(con<> const& me /* :<symbol># */,
			con<> const& other /* :<any># */);

		static bool less_or_equal_f(con<> const& me /* :<symbol># */,
			con<> const& other /* :<any># */);

		static bool greater_or_equal_f(con<> const& me /* :<symbol># */,
			con<> const& other /* :<any># */);

		static void _copy_f(any_a const& me /* :<symbol># */,
			any_a& copy /* :<symbol>= */);

		static void _set_pointer_f(var<> const& me /* :<symbol>= */,
			bool is_pointer /* :_bool_# */);

		// symbol_a
		static var<symbol_a> add_f(con<symbol_a> const& me /* :<symbol># */,
			con<symbol_a> const& suffix /* :<symbol># */);

		static char const* to_char_star_f(con<symbol_a> const& me /* :<symbol># */);

		static int64_t length_f(con<symbol_a> const& me /* :<symbol># */);

		static char first_char_f(con<symbol_a> const& me /* :<symbol># */);

		static char last_char_f(con<symbol_a> const& me /* :<symbol># */);

	public:
		// creators
		static var<symbol_a> create_f(char const* const s /* :_char_star_# */);
		static var<symbol_a> create_empty_f();
	};

	inline var<symbol_a> sym(char const* const s /* :_char_star_# */)
	{
		return symbol_t::create_f(s);
	}
}

#endif
