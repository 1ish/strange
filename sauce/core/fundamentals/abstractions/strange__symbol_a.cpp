#include "../../../strange.h"
#include <cstring>

namespace strange
{
	var<symbol_a> symbol_a::cat_e(void const* const me_ /* :<symbol># */)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}

	symbol_a::creator symbol_a::creator_f(char const* const scope /* :_char_star_# */,
		char const* const thing /* :_char_star_# */,
		char const* const function /* :_char_star_# */)
	{
		static char const strange_s[] = "strange";
		if (std::strncmp(scope, strange_s, sizeof(strange_s)) == 0)
		{
			static char const symbol_s[] = "symbol";
			if (std::strncmp(thing, symbol_s, sizeof(symbol_s)) == 0)
			{
				static char const create_empty_s[] = "create_empty";
				if (std::strncmp(function, create_empty_s, sizeof(create_empty_s)) == 0)
				{
					return symbol_t::create_empty_f;
				}
			}
		}
		return nullptr;
	}
}
