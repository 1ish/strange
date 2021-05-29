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
		symbol_t(any_a& me_ /* :<symbol>= */,
			char const* const s /* :_char_star_# */);

		symbol_t(any_a& me_ /* :<symbol>= */,
			any_a const& original_ /* :<symbol># */);

		virtual ~symbol_t();

		// symbol_o
		static symbol_o const* operations_f();
		static symbol_o const* pointer_operations_f();

		// inline
		static inline bool _equal_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& other_ /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me_.t);
			return std::strncmp(mt->symbol, other_.o->to_char_star(other_),
				std::max(mt->length, other_.o->length(other_))) == 0;
		}

		static inline bool _not_equal_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& other_ /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me_.t);
			return std::strncmp(mt->symbol, other_.o->to_char_star(other_),
				std::max(mt->length, other_.o->length(other_))) != 0;
		}

		static inline bool _less_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& other_ /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me_.t);
			return std::strncmp(mt->symbol, other_.o->to_char_star(other_),
				std::max(mt->length, other_.o->length(other_))) < 0;
		}

		static inline bool _greater_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& other_ /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me_.t);
			return std::strncmp(mt->symbol, other_.o->to_char_star(other_),
				std::max(mt->length, other_.o->length(other_))) > 0;
		}

		static inline bool _less_or_equal_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& other_ /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me_.t);
			return std::strncmp(mt->symbol, other_.o->to_char_star(other_),
				std::max(mt->length, other_.o->length(other_))) <= 0;
		}

		static inline bool _greater_or_equal_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& other_ /* :<symbol># */)
		{
			auto const mt = static_cast<symbol_t const* const>(me_.t);
			return std::strncmp(mt->symbol, other_.o->to_char_star(other_),
				std::max(mt->length, other_.o->length(other_))) >= 0;
		}

		// any_a
		static void _copy_e(any_a const& me_ /* :<symbol># */,
			any_a& copy_ /* :<symbol>= */);

		static bool is_e(val<> const& me_ /* :<symbol># */,
			val<> const& abstraction_ /* :<any># */);

		static var<symbol_a> type_e(val<> const& me_ /* :<symbol># */);

		static void _set_pointer_m(var<>& me_ /* :<symbol>= */,
			bool is_pointer /* :_bool_# */);

		static uint64_t hash_e(val<> const& me_ /* :<symbol># */);

		static bool equal_e(val<> const& me_ /* :<symbol># */,
			val<> const& other_ /* :<any># */);

		static bool not_equal_e(val<> const& me_ /* :<symbol># */,
			val<> const& other_ /* :<any># */);

		static bool less_e(val<> const& me_ /* :<symbol># */,
			val<> const& other_ /* :<any># */);

		static bool greater_e(val<> const& me_ /* :<symbol># */,
			val<> const& other_ /* :<any># */);

		static bool less_or_equal_e(val<> const& me_ /* :<symbol># */,
			val<> const& other_ /* :<any># */);

		static bool greater_or_equal_e(val<> const& me_ /* :<symbol># */,
			val<> const& other_ /* :<any># */);

		// symbol_a
		static var<symbol_a> add_e(val<symbol_a> const& me_ /* :<symbol># */,
			val<symbol_a> const& suffix_ /* :<symbol># */);

		static char const* to_char_star_e(val<symbol_a> const& me_ /* :<symbol># */);

		static int64_t length_e(val<symbol_a> const& me_ /* :<symbol># */);

		static char first_char_e(val<symbol_a> const& me_ /* :<symbol># */);

		static char last_char_e(val<symbol_a> const& me_ /* :<symbol># */);

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
