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
	std::string const abstractions_dir = "../../strange/sauce/abstractions/";
	std::string const generate_cpp_dir = "../../strange/sauce/generated/";
}

#ifdef STRANGE_TASTE_DEBUG
std::ostream& std__cout = std::cout;
#else
std::stringstream discard;
std::ostream& std__cout = discard;
#endif

#include "strange_first_taste.h"
#include "strange_any_taste.h"
#include "strange_range_taste.h"
#include "strange_parser_hello_world_taste.h"
#include "strange_parser_symbol_taste.h"
#include "strange_parser_lake_taste.h"
#include "strange_parser_int_taste.h"
#include "strange_parser_float_taste.h"
#include "strange_parser_boole_taste.h"
#include "strange_parser_loop_taste.h"
#include "strange_parser_code_taste.h"
#include "strange_code_generate.h"
#include "strange_code_generate_cpp.h"
#include "strange_collections_generate_cpp.h"
#include "strange_iterators_generate_cpp.h"
