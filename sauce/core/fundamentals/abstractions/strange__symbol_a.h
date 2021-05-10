#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

#define STRANGE__SYMBOL_O \
		STRANGE__ANY_O \
		strange__symbol_a (*add)(void const* const me, void const* const symbol); \
		char const* (*to_char_star)(void const* const me); /* non-standard */ \
		size_t (*length)(void const* const me); \

extern "C"
{
	struct strange__symbol_o
	{
		STRANGE__SYMBOL_O
	};

	struct strange__symbol_a
	{
		strange__thing_d* d;
		strange__symbol_o const* o;
	};
}

#endif
