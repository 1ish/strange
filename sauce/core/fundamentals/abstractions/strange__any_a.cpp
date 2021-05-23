#include "../../../strange.h"
#include <cstring>

namespace strange
{
	var<symbol_a> any_a::cat_e(void const* const me_ /* :<any># */)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}

	any_a::creator any_a::creator_f(char const* const scope /* :_char_star_# */,
		char const* const thing /* :_char_star_# */,
		char const* const function /* :_char_star_# */)
	{
		static char const strange_s[] = "strange";
		if (std::strncmp(scope, strange_s, sizeof(strange_s)) == 0)
		{
			static char const thing_s[] = "thing";
			if (std::strncmp(thing, thing_s, sizeof(thing_s)) == 0)
			{
				static char const create_s[] = "create";
				if (std::strncmp(function, create_s, sizeof(create_s)) == 0)
				{
					return thing_t::create_f;
				}
				static char const create_nothing_s[] = "create_nothing";
				if (std::strncmp(function, create_nothing_s, sizeof(create_nothing_s)) == 0)
				{
					return thing_t::create_nothing_f;
				}
			}
		}
		return nullptr;
	}
}
