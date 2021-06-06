#include "../../../../strange.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> forward_extractor_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::forward_extractor>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename forward_extractor_a<element_d>::creator_fp forward_extractor_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const forward_extractor_s = sym("forward_extractor");
			if (thing.o->equal(thing, forward_extractor_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					//TODO return forward_extractor_t::create;
				}
			}
		}
		return nullptr;
	}
}
