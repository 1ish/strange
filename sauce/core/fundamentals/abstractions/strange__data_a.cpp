#include "../../../strange.h"

namespace strange
{
	template <typename type_d>
	var<symbol_a> data_a<type_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::data>"); //TODO cat
		return r;
	}

	template <typename type_d>
	typename data_a<type_d>::creator_fp data_a<type_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		static auto const strange_s = sym("strange");
		if (scope.o->equal(scope, strange_s))
		{
			if constexpr (!std::is_reference_v<type_d>)
			{
				static auto const create_from_range_s = sym("create_from_range");
				static auto const data_s = sym("data");
				if (thing.o->equal(thing, data_s))
				{
					if (function.o->equal(function, create_from_range_s))
					{
						return data_t<type_d>::create_from_range;
					}
				}
				if constexpr (std::is_pointer_v<type_d>)
				{
					static auto const data_pointer_s = sym("data_pointer");
					if (thing.o->equal(thing, data_pointer_s))
					{
						if (function.o->equal(function, create_from_range_s))
						{
							return data_pointer_t<type_d>::create_from_range;
						}
					}
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct data_a<int64_t>;
	template struct data_a<int64_t&>;
	template struct data_a<default_copy<std::shared_timed_mutex>>;
	template struct data_a<default_copy<std::string>>;

	template struct data_a<int64_t*>;
	template struct data_a<std::shared_lock<std::shared_timed_mutex>*>;
	template struct data_a<std::unique_lock<std::shared_timed_mutex>*>;
}
