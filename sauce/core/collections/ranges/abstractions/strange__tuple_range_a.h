#ifndef COM_ONEISH__STRANGE__TUPLE_RANGE_A_H
#define COM_ONEISH__STRANGE__TUPLE_RANGE_A_H

namespace strange
{
	template <typename... elements_d>
	struct tuple_range_i
	{
		fit<forward_tuple_extractor_a<elements_d...>> (*begin) (con<tuple_range_a<elements_d...>> const& me);

		fit<forward_tuple_extractor_a<elements_d...>> (*end) (con<tuple_range_a<elements_d...>> const& me);

		var<range_a<>> (*to_range_any) (con<tuple_range_a<elements_d...>> const& me);
	};

	template <typename... elements_d>
	struct tuple_range_o :
		range_o<var<tuple_a<elements_d...>>>,
		tuple_range_i<elements_d...>
	{
	};

	template <typename... elements_d>
	struct tuple_range_a
	{
		using non_mutator_range = bool;
		using operations = tuple_range_o<elements_d...>;
		using creator_fp = var<tuple_range_a<elements_d...>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
