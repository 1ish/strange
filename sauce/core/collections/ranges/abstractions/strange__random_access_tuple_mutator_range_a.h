#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_TUPLE_MUTATOR_RANGE_A_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_TUPLE_MUTATOR_RANGE_A_H

namespace strange
{
	template <typename... elements_d>
	struct random_access_tuple_mutator_range_o :
		bidirectional_tuple_mutator_range_o<elements_d...>
	{
		rat<random_access_tuple_mutator_a<elements_d...>> (*mutator_begin) (var<random_access_tuple_mutator_range_a<elements_d...>> const& me);

		rat<random_access_tuple_mutator_a<elements_d...>> (*mutator_end) (var<random_access_tuple_mutator_range_a<elements_d...>> const& me);
	};

	template <typename... elements_d>
	struct random_access_tuple_mutator_range_a
	{
		using is_mutator_range = bool;
		using operations = random_access_tuple_mutator_range_o<elements_d...>;
		using creator_fp = var<random_access_tuple_mutator_range_a<elements_d...>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
