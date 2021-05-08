// strange_taste.cpp : run the unit tests
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define STRANGE_TASTE_DEBUG 1

namespace
{
	char const* const taste_dir = "../../strange/taste/";
	char const* const abstractions_dir = "../../strange/sauce/";
	char const* const generate_cpp_dir = "../../strange/sauce/";
}

#ifdef STRANGE_TASTE_DEBUG
std::ostream& std__cout = std::cout;
#else
std_stringstream discard;
std::ostream& std__cout = discard;
#endif

#include "../sauce/strange.h"
#include "../sauce/core/utilities/strange__value_c.hpp"

#include <iostream>

#include "core/fundamentals/taste__strange__thing_t.hpp"