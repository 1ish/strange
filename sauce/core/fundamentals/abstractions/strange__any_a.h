#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

#define STRANGE__ANY_O \
		strange__symbol_a (*cat)(void const* const me); \
		void (*free)(void const* const me); \
		void (*copy)(void const* const me, void* const cp); \
		bool (*is)(void const* const me, void* const at); \
		bool (*as)(void const* const me, void* const at); \
		strange__symbol_a (*type)(void const* const me); \
		bool (*something)(void const* const me); \
		bool (*nothing)(void const* const me); \

extern "C"
{
	struct strange__any_o
	{
		STRANGE__ANY_O
	};

	struct strange__any_a
	{
		strange__thing_d* d;
		strange__any_o const* o;
	};
}

#endif
