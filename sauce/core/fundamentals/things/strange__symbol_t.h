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
	void strange__symbol__free_f(void const* const me);
	void strange__symbol__copy_f(void const* const me, void* const cp);
	void strange__symbol__clone_f(void const* const me, void* const cp);
	bool strange__symbol_is_f(void const* const me, void const* const ab);
	void strange__symbol_as_f(void const* const me, void* const ab);
	strange__symbol_a strange__symbol_type_f(void const* const me);
	strange__symbol_a strange__symbol_add_f(void const* const me, void const* const symbol);
	char const* strange__symbol__to_char_star_f(void const* const me);
	size_t strange__symbol_length_f(void const* const me);

	strange__symbol_a sym(char const* const s);
	strange__symbol_a no_sym();
}

#endif
