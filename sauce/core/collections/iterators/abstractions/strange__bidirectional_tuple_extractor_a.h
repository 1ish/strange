#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_TUPLE_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_TUPLE_EXTRACTOR_A_H

namespace strange
{
	template <typename... elements_d>
	struct bidirectional_tuple_extractor_o :
		forward_tuple_extractor_o<elements_d...>
	{
		void (*decrement) (var<bidirectional_tuple_extractor_a<elements_d...>> const& me);
	};

	template <typename... elements_d>
	struct bidirectional_tuple_extractor_a
	{
		using operations = bidirectional_tuple_extractor_o<elements_d...>;
		using variations = any_v<bidirectional_tuple_extractor_a<elements_d...>>;
		using creator_fp = fit<bidirectional_tuple_extractor_a<elements_d...>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
