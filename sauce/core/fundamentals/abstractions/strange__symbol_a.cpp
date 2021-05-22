#include "../../../strange.h"

namespace strange
{
	var<symbol_a> symbol_a::cat_e(void const* const me_ /* :<symbol># */)
	{
		static auto r = sym("<strange::symbol>"); //TODO cat
		return r;
	}
}
