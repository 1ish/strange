#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct symbol_t : thing_t
	{
		char* symbol;
		int64_t length;
		uint64_t hash;

		// symbol_o
		static symbol_o const* operations_f();
		static symbol_o const* pointer_operations_f();

		// init
		static void init_f(void* const me /* :<symbol>= */,
			char const* const s /* :_char_star_# */);

		// any_a
		static void _free_f(void const* const me /* :<symbol># */);

		static void _copy_f(void const* const me /* :<symbol># */,
			void* const cp /* :<symbol>= */);

		static void _clone_f(void const* const me /* :<symbol># */,
			void* const cp /* :<symbol>= */);

		static bool is_f(void const* const me /* :<symbol># */,
			void const* const ab /* :<any># */);

		static bool as_f(void const* const me /* :<symbol># */,
			void* const ab /* :<any>= */);

		static symbol_a type_f(void const* const me /* :<symbol># */);

		static void _set_pointer_f(void* const me /* :<symbol>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_f(void const* const me /* :<symbol># */);

		static uint64_t hash_f(void const* const me /* :<symbol># */);

		static bool equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool not_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _not_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool less_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _less_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool greater_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _greater_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool less_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _less_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool greater_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _greater_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		// symbol_a
		static symbol_a add_f(void const* const me /* :<symbol># */,
			void const* const suffix /* :<symbol># */);

		static char const* to_char_star_f(void const* const me /* :<symbol># */);

		static int64_t length_f(void const* const me /* :<symbol># */);

		static char first_char_f(void const* const me /* :<symbol># */);

		static char last_char_f(void const* const me /* :<symbol># */);

		// creators
		static symbol_a create_f(char const* const s /* :_char_star_# */);
		static symbol_a create_empty_f();
	};
}

#endif
