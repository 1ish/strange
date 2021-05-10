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

	strange__symbol_o const* strange__symbol_o_f();
	strange__symbol_o const* strange__symbol_p_f();
	strange__symbol_o const* strange__symbol_n_f();
	void strange__symbol___free_f(void const* const me);
	void strange__symbol___copy_f(void const* const me, void* const cp);
	void strange__symbol___clone_f(void const* const me, void* const cp);
	bool strange__symbol__is_f(void const* const me, void const* const ab);
	void strange__symbol__as_f(void const* const me, void* const ab);
	strange__symbol_a strange__symbol__type_f(void const* const me);
	bool strange__symbol__equal_f(void const* const me, void const* const other);
	bool strange__symbol__not_equal_f(void const* const me, void const* const other);
	bool strange__symbol__less_f(void const* const me, void const* const other);
	bool strange__symbol__greater_f(void const* const me, void const* const other);
	bool strange__symbol__less_or_equal_f(void const* const me, void const* const other);
	bool strange__symbol__greater_or_equal_f(void const* const me, void const* const other);

	strange__symbol_a strange__symbol__add_f(void const* const me, void const* const symbol);
	char const* strange__symbol___to_char_star_f(void const* const me);
	size_t strange__symbol__length_f(void const* const me);

	strange__symbol_a sym(char const* const s);
	strange__symbol_a no_sym();
}

#endif
