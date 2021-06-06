#ifndef COM_ONEISH__STRANGE__CORE_H
#define COM_ONEISH__STRANGE__CORE_H

#include <atomic>
#include <cstdint>
#include <cstring>
#include <algorithm>

namespace strange
{
	struct any_a;
	struct symbol_a;
	struct cat_a;
	struct kind_a;
	template <typename type_d> struct data_a;
	template <typename element_d = any_a> struct range_a;

	struct thing_t;
	struct symbol_t;
}

#include "utilities/strange__val_u.hpp"

#include "fundamentals/enumerations/strange__representation_e.h"
#include "fundamentals/enumerations/strange__behaviour_e.h"

#include "fundamentals/abstractions/strange__any_a.h"
#include "fundamentals/abstractions/strange__symbol_a.h"
#include "fundamentals/abstractions/strange__cat_a.h"
#include "fundamentals/abstractions/strange__kind_a.h"
#include "fundamentals/abstractions/strange__data_a.h"

#include "collections/abstractions/strange__range_a.h"

#include "fundamentals/things/strange__thing_t.h"
#include "fundamentals/things/strange__symbol_t.h"

#endif
