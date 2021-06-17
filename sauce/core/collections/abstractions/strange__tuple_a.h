#ifndef COM_ONEISH__STRANGE__TUPLE_A_H
#define COM_ONEISH__STRANGE__TUPLE_A_H

namespace strange
{
	template <typename... elements_d>
	struct tuple_i
	{
		var<range_a<>> (*to_range_any) (con<tuple_a<elements_d...>> const& me);
	};

	template <typename... elements_d>
	struct tuple_o :
		any_o,
		tuple_i<elements_d...>
	{
	};

	template <typename... elements_d>
	struct tuple_a
	{
		using operations = tuple_o<elements_d...>;
		using creator_fp = var<tuple_a<elements_d...>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
