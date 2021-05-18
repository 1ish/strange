#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct symbol_d : thing_d
	{
		char* symbol;
		int64_t length;
		uint64_t hash;

		// symbol_o
		static symbol_o const* symbol_o_f();
		static symbol_o const* symbol_p_f();

		// init
		static void symbol__init_f(void* const me /* :<symbol>= */,
			char const* const s /* :_char_star_# */);

		// any_a
		static void symbol___free_f(void const* const me /* :<symbol># */);

		static void symbol___copy_f(void const* const me /* :<symbol># */,
			void* const cp /* :<symbol>= */);

		static void symbol___clone_f(void const* const me /* :<symbol># */,
			void* const cp /* :<symbol>= */);

		static bool symbol__is_f(void const* const me /* :<symbol># */,
			void const* const ab /* :<any># */);

		static bool symbol__as_f(void const* const me /* :<symbol># */,
			void* const ab /* :<any>= */);

		static symbol_a symbol__type_f(void const* const me /* :<symbol># */);

		static void symbol___set_pointer_f(void* const me /* :<symbol>= */,
			bool is_pointer /* :_bool_# */);

		static bool symbol___pointer_f(void const* const me /* :<symbol># */);

		static uint64_t symbol__hash_f(void const* const me /* :<symbol># */);

		static bool symbol__equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool symbol___equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool symbol__not_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool symbol___not_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool symbol__less_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool symbol___less_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool symbol__greater_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool symbol___greater_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool symbol__less_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool symbol___less_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool symbol__greater_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool symbol___greater_or_equal_f(void const* const me /* :<symbol># */,
			void const* const other /* :<symbol># */);

		// symbol_a
		static symbol_a symbol__add_f(void const* const me /* :<symbol># */,
			void const* const suffix /* :<symbol># */);

		static char const* symbol__to_char_star_f(void const* const me /* :<symbol># */);

		static int64_t symbol__length_f(void const* const me /* :<symbol># */);

		static char symbol__first_char_f(void const* const me /* :<symbol># */);

		static char symbol__last_char_f(void const* const me /* :<symbol># */);

		// creators
		static symbol_a symbol__create_f(char const* const s /* :_char_star_# */);
		static symbol_a symbol__create_empty_f();
	};
}

#endif
