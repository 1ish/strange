// strange_taste.cpp : run the unit tests
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define STRANGE_TASTE_DEBUG 1

#include "../sauce/strange.h"

using namespace strange;

namespace
{
	std::string const taste_dir = "../../strange/taste/";
}

#ifdef STRANGE_TASTE_DEBUG
std::ostream& std__cout = std::cout;
#else
std::stringstream discard;
std::ostream& std__cout = discard;
#endif

#include "strange_any_taste.h"
#include "strange_parse_hello_world_taste.h"
#include "strange_parse_symbol_taste.h"
