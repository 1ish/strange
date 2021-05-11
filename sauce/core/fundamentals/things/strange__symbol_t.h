#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

#define STRANGE__SYMBOL_D \
		STRANGE__THING_D \
		char* symbol; \
		size_t length; \

extern "C"
{
	struct strange__symbol_d
	{
		STRANGE__SYMBOL_D
	};

	// symbol_o
	strange__symbol_o const* strange__symbol_o_f();
	strange__symbol_o const* strange__symbol_p_f();
	strange__symbol_o const* strange__symbol_n_f();

	// any_a
	void strange__symbol___free_f(void const* const me /* <symbol># */);

	void strange__symbol___copy_f(void const* const me /* <symbol># */,
		void* const cp /* <symbol>= */);

	void strange__symbol___clone_f(void const* const me /* <symbol># */,
		void* const cp /* <symbol>= */);

	bool strange__symbol__is_f(void const* const me /* <symbol># */,
		void const* const ab /* <any># */);

	bool strange__symbol__as_f(void const* const me /* <symbol># */,
		void* const ab /* <any>= */);

	void strange__symbol___as_f(void const* const me /* <symbol># */,
		void* const ab /* <any>= */);

	strange__symbol_a strange__symbol__type_f(void const* const me /* <symbol># */);

	bool strange__symbol__equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */);

	bool strange__symbol___equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */);

	bool strange__symbol__not_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */);

	bool strange__symbol___not_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */);

	bool strange__symbol__less_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */);

	bool strange__symbol___less_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */);

	bool strange__symbol__greater_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */);

	bool strange__symbol___greater_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */);

	bool strange__symbol__less_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */);

	bool strange__symbol___less_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */);

	bool strange__symbol__greater_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <any># */);

	bool strange__symbol___greater_or_equal_f(void const* const me /* <symbol># */,
		void const* const other /* <symbol># */);

	// symbol_a
	strange__symbol_a strange__symbol__add_f(void const* const me /* <symbol># */,
		void const* const symbol /* <symbol># */);

	char const* strange__symbol___to_char_star_f(void const* const me /* <symbol># */);

	size_t strange__symbol__length_f(void const* const me /* <symbol># */);

	// constructors
	strange__symbol_a sym(char const* const s);
	strange__symbol_a no_sym();
}

#endif
