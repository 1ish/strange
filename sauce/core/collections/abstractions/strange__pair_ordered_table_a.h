#ifndef COM_ONEISH__STRANGE__PAIR_ORDERED_TABLE_A_H
#define COM_ONEISH__STRANGE__PAIR_ORDERED_TABLE_A_H

namespace strange
{
	template <typename key_d, typename value_d>
	struct pair_ordered_table_o :
		ordered_table_o<key_d, value_d>
	{
		var<pair_table_a<key_d, value_d>> (*pair_table) (con<pair_ordered_table_a<key_d, value_d>> const& me);

		var<bidirectional_range_a<std::pair<key_d const, value_d>>> (*pair_range) (con<pair_ordered_table_a<key_d, value_d>> const& me);

		bit<bidirectional_extractor_a<std::pair<key_d const, value_d>>> (*pair_begin) (con<pair_ordered_table_a<key_d, value_d>> const& me);

		bit<bidirectional_extractor_a<std::pair<key_d const, value_d>>> (*pair_end) (con<pair_ordered_table_a<key_d, value_d>> const& me);

		var<bidirectional_mutator_range_a<std::pair<key_d const, value_d>>> (*pair_mutator_range) (var<pair_ordered_table_a<key_d, value_d>> const& me);

		bit<bidirectional_mutator_a<std::pair<key_d const, value_d>>> (*pair_mutator_begin) (var<pair_ordered_table_a<key_d, value_d>> const& me);

		bit<bidirectional_mutator_a<std::pair<key_d const, value_d>>> (*pair_mutator_end) (var<pair_ordered_table_a<key_d, value_d>> const& me);
	};

	template <typename key_d, typename value_d>
	struct pair_ordered_table_a
	{
		using non_mutator_range = bool;
		using operations = pair_ordered_table_o<key_d, value_d>;
		using creator_fp = var<pair_ordered_table_a<key_d, value_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
