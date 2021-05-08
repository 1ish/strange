#pragma once

#define STR_CORE_SYMBOL_O \
		STR_CORE_ANY_O \
		str_core_symbol_a (*add)(void const* const me, void const* const symbol); \
		char const* (*to_c_string)(void const* const me); \
		size_t (*length)(void const* const me); \

extern "C"
{
	struct str_core_symbol_o
	{
		STR_CORE_SYMBOL_O
	};

	struct str_core_symbol_a
	{
		str_core_thing_d* d;
		str_core_symbol_o const* o;
	};
}
