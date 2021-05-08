#pragma once

#define STR_CORE_THING_D \
		int64_t refs; \

extern "C"
{
	struct str_core_thing_d
	{
		STR_CORE_THING_D
	};

	str_core_any_o const* str_core_thing_o_f();
	void str_core_thing_free_f(void const* const me);
	void str_core_thing_copy_f(void const* const me, void* const cp);
	void str_core_thing_clone_f(void const* const me, void* const cp);
	str_core_symbol_a str_core_thing_type_f(void const* const me);
	bool str_core_thing_nothing_f(void const* const me);
	bool str_core_thing_something_f(void const* const me);

	void mutate(void* const me);
	str_core_any_a nothing();
	str_core_any_a something();
}
