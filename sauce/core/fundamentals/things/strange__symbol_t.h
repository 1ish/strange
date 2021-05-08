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
	void strange__symbol_free_f(void const* const me);
	void strange__symbol_copy_f(void const* const me, void* const cp);
	void strange__symbol_clone_f(void const* const me, void* const cp);
	strange__symbol_a strange__symbol_type_f(void const* const me);
	strange__symbol_a strange__symbol_add_f(void const* const me, void const* const symbol);
	char const* strange__symbol_to_c_string_f(void const* const me);
	size_t strange__symbol_length_f(void const* const me);

	strange__symbol_a sym(char const* const s);
}

#endif
