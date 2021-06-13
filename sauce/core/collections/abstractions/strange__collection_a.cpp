#include "../../../strange.h"

namespace strange
{
	template <typename key_d, typename value_d, typename element_d>
	var<symbol_a> collection_a<key_d, value_d, element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::collection>"); //TODO cat
		return r;
	}

	template <typename key_d, typename value_d, typename element_d>
	typename collection_a<key_d, value_d, element_d>::creator_fp collection_a<key_d, value_d, element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			static auto const collection_s = sym("collection");
			if (thing.o->equal(thing, collection_s))
			{
				static auto const create_s = sym("create");
				if (function.o->equal(function, create_s))
				{
					//TODO return collection_t::create;
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct collection_a<int64_t, int64_t, int64_t>;
}
