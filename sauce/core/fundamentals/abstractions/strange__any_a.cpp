#include "../../../strange.h"

namespace strange
{
	var<symbol_a> any_a::cat_e(void const* const me_ /* :<any># */)
	{
		static auto r = sym("<strange::any>"); //TODO cat
		return r;
	}
}
