#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_RANGE_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct bidirectional_mutator_range_o : mutator_range_o<element_d>
	{
		bit<bidirectional_mutator_a<element_d>> (*bidirectional_mutator_begin)(var<bidirectional_mutator_range_a<element_d>> const& me);

		bit<bidirectional_mutator_a<element_d>> (*bidirectional_mutator_end)(var<bidirectional_mutator_range_a<element_d>> const& me);

		var<bidirectional_mutator_range_a<>> (*to_bidirectional_mutator_range_any)(var<bidirectional_mutator_range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct bidirectional_mutator_range_a
	{
		using is_mutator = bool;
		using operations = bidirectional_mutator_range_o<element_d>;
		using creator_fp = var<bidirectional_mutator_range_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
