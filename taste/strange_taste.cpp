// strange_taste.cpp : run the unit tests
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define STRANGE_TASTE_DEBUG 1

#include "../sauce/strange.h"

using namespace strange;

namespace
{
	std_string const taste_dir = "../../strange/taste/";
	std_string const abstractions_dir = "../../strange/sauce/";
	std_string const generate_cpp_dir = "../../strange/sauce/";
}

#ifdef STRANGE_TASTE_DEBUG
std::ostream& std__cout = std::cout;
#else
std_stringstream discard;
std::ostream& std__cout = discard;
#endif
