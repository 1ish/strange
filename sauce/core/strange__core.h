#ifndef COM_ONEISH__STRANGE__CORE_H
#define COM_ONEISH__STRANGE__CORE_H

#include <cstdint>
#include <cstddef>

namespace strange
{
	struct any_a;
	struct symbol_a;

	struct thing_d;
	struct symbol_d;
}

#include "fundamentals/abstractions/strange__any_a.h"
#include "fundamentals/abstractions/strange__symbol_a.h"

#include "fundamentals/things/strange__thing_t.h"
#include "fundamentals/things/strange__symbol_t.h"

namespace strange
{
	symbol_a any__cat_f(void const* const me /* :<any># */);
	symbol_a symbol__cat_f(void const* const me /* :<symbol># */);
}

#endif
