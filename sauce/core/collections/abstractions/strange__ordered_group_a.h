#ifndef COM_ONEISH__STRANGE__ORDERED_GROUP_A_H
#define COM_ONEISH__STRANGE__ORDERED_GROUP_A_H

namespace strange
{
	template <typename element_d>
	struct ordered_group_o :
		group_o<element_d>
	{
		var<bidirectional_range_a<element_d>> (*range) (con<ordered_group_a<element_d>> const& me);

		bit<bidirectional_extractor_a<element_d>> (*begin) (con<ordered_group_a<element_d>> const& me);

		bit<bidirectional_extractor_a<element_d>> (*end) (con<ordered_group_a<element_d>> const& me);
	};

	template <typename element_d>
	struct ordered_group_a
	{
		using non_mutator_range = bool;
		using operations = ordered_group_o<element_d>;
		using variations = any_v<ordered_group_a<element_d>>;
		using creator_fp = var<ordered_group_a<element_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
