#ifndef COM_ONEISH__STRANGE__TUPLE_MUTATOR_RANGE_A_H
#define COM_ONEISH__STRANGE__TUPLE_MUTATOR_RANGE_A_H

namespace strange
{
	template <typename... elements_d>
	struct tuple_mutator_range_o :
		mutator_range_o<var<tuple_a<elements_d...>>>
	{
		fit<forward_tuple_extractor_a<elements_d...>> (*mutator_begin) (var<tuple_mutator_range_a<elements_d...>> const& me);

		fit<forward_tuple_extractor_a<elements_d...>> (*mutator_end) (var<tuple_mutator_range_a<elements_d...>> const& me);
	};

	template <typename... elements_d>
	struct tuple_mutator_range_a
	{
		using is_mutator_range = bool;
		using operations = tuple_mutator_range_o<elements_d...>;
		using creator_fp = var<tuple_mutator_range_a<elements_d...>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
