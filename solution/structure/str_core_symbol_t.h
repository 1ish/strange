#pragma once

#define STR_CORE_SYMBOL_D \
		STR_CORE_THING_D \
		char* symbol; \
		size_t length; \

extern "C"
{
	struct str_core_symbol_d
	{
		STR_CORE_SYMBOL_D
	};

	str_core_symbol_o const* str_core_symbol_o_f();
	void str_core_symbol_free_f(void const* const me);
	void str_core_symbol_copy_f(void const* const me, void* const cp);
	void str_core_symbol_clone_f(void const* const me, void* const cp);
	str_core_symbol_a str_core_symbol_type_f(void const* const me);
	str_core_symbol_a str_core_symbol_add_f(void const* const me, void const* const symbol);
	char const* str_core_symbol_to_c_string_f(void const* const me);
	size_t str_core_symbol_length_f(void const* const me);

	str_core_symbol_a sym(char const* const s);
}
