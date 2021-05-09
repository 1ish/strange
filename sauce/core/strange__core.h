#ifndef COM_ONEISH__STRANGE__CORE_H
#define COM_ONEISH__STRANGE__CORE_H

#include <cstdint>

extern "C"
{
	struct strange__any_a;
	struct strange__symbol_a;

	struct strange__thing_d;
	struct strange__symbol_d;
}

#include "fundamentals/abstractions/strange__any_a.h"
#include "fundamentals/abstractions/strange__symbol_a.h"

#include "fundamentals/things/strange__thing_t.h"
#include "fundamentals/things/strange__symbol_t.h"

extern "C"
{
	strange__symbol_a strange__any_cat_f(void const* const me);
	strange__symbol_a strange__symbol_cat_f(void const* const me);
}

#endif
