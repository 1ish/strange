#pragma once

#define STR_CORE_ANY_O \
		void (*free)(void const* const me); \
		void (*copy)(void const* const me, void* const cp); \
		str_core_symbol_a (*type)(void const* const me); \
		bool (*nothing)(void const* const me); \
		bool (*something)(void const* const me); \

extern "C"
{
	struct str_core_any_o
	{
		STR_CORE_ANY_O
	};

	struct str_core_any_a
	{
		str_core_thing_d* d;
		str_core_any_o const* o;
	};
}
