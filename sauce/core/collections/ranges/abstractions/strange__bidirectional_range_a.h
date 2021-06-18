#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_RANGE_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct bidirectional_range_i
	{
		bit<bidirectional_extractor_a<element_d>> (*bidirectional_begin) (con<bidirectional_range_a<element_d>> const& me);

		bit<bidirectional_extractor_a<element_d>> (*bidirectional_end) (con<bidirectional_range_a<element_d>> const& me);

		var<bidirectional_range_a<>> (*to_bidirectional_range_any) (con<bidirectional_range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct bidirectional_range_o :
		range_o<element_d>,
		bidirectional_range_i<element_d>
	{
	};

	template <typename element_d>
	struct bidirectional_range_a
	{
		using non_mutator_range = bool;
		using operations = bidirectional_range_o<element_d>;
		using creator_fp = var<bidirectional_range_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
