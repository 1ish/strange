#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct strange__symbol_d : strange__thing_d
	{
		char* symbol;
		int64_t length;
		uint64_t hash;
	};

	// symbol_o
	strange__symbol_o const* strange__symbol_o_f();
	strange__symbol_o const* strange__symbol_p_f();

	// init
	void strange__symbol__init_f(void* const me /* :<symbol>= */,
		char const* const s /* :_char_star_# */);

	// any_a
	void strange__symbol___free_f(void const* const me /* :<symbol># */);

	void strange__symbol___copy_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */);

	void strange__symbol___clone_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */);

	bool strange__symbol__is_f(void const* const me /* :<symbol># */,
		void const* const ab /* :<any># */);

	bool strange__symbol__as_f(void const* const me /* :<symbol># */,
		void* const ab /* :<any>= */);

	strange__symbol_a strange__symbol__type_f(void const* const me /* :<symbol># */);

	void strange__symbol___set_pointer_f(void* const me /* :<symbol>= */,
		bool is_pointer /* :_bool_# */);

	bool strange__symbol___pointer_f(void const* const me /* :<symbol># */);

	uint64_t strange__symbol__hash_f(void const* const me /* :<symbol># */);

	bool strange__symbol__equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */);

	bool strange__symbol___equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */);

	bool strange__symbol__not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */);

	bool strange__symbol___not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */);

	bool strange__symbol__less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */);

	bool strange__symbol___less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */);

	bool strange__symbol__greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */);

	bool strange__symbol___greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */);

	bool strange__symbol__less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */);

	bool strange__symbol___less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */);

	bool strange__symbol__greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */);

	bool strange__symbol___greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */);

	// symbol_a
	strange__symbol_a strange__symbol__add_f(void const* const me /* :<symbol># */,
		void const* const suffix /* :<symbol># */);

	char const* strange__symbol__to_char_star_f(void const* const me /* :<symbol># */);

	int64_t strange__symbol__length_f(void const* const me /* :<symbol># */);

	char strange__symbol__first_char_f(void const* const me /* :<symbol># */);

	char strange__symbol__last_char_f(void const* const me /* :<symbol># */);

	// creators
	strange__symbol_a strange__symbol__create_f(char const* const s /* :_char_star_# */);
	strange__symbol_a strange__symbol__create_empty_f();
}

#endif
