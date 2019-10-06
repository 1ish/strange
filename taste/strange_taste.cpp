// strange_taste.cpp : run the unit tests
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../sauce/strange.h"

using namespace strange;

namespace
{
	std::string const taste_dir = "../../strange/taste/";
}

#include "strange_any_taste.h"
#include "strange_parse_hello_world_taste.h"
