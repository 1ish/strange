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
		if (scope == "strange")
		{
			if (thing == "data")
			{
				if (function == "create_from_range")
				{
					return data_t<type_d>::create_from_range;
				}
			}
			else if constexpr (std::is_pointer_v<type_d>)
			{
				if (thing == "data_pointer")
				{
					if (function == "create_from_range")
					{
						return data_pointer_t<type_d>::create_from_range;
					}
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct data_a<int64_t>;
	template struct data_a<uint64_t>;
	template struct data_a<double>;
	template struct data_a<default_copy<std::shared_mutex>>;
	template struct data_a<default_copy<std::string>>;

	template struct data_a<int64_t*>;
	template struct data_a<std::shared_lock<std::shared_mutex>*>;
	template struct data_a<std::unique_lock<std::shared_mutex>*>;
}
