#ifndef COM_ONEISH__STRANGE__ORDERED_TABLE_A_H
#define COM_ONEISH__STRANGE__ORDERED_TABLE_A_H

namespace strange
{
	template <typename key_d, typename value_d>
	struct ordered_table_o :
		collection_o<key_d, value_d, var<tuple_a<key_d, value_d>>>
	{
		var<bidirectional_tuple_range_a<key_d, value_d>> (*range) (con<ordered_table_a<key_d, value_d>> const& me);

		var<bidirectional_tuple_mutator_range_a<key_d, value_d>> (*mutator_range) (var<ordered_table_a<key_d, value_d>> const& me);

		var<ordered_table_a<>> (*to_collection_any) (con<ordered_table_a<key_d, value_d>> const& me);

		var<bidirectional_range_a<std::pair<key_d, value_d>>> (*_pair_range) (con<ordered_table_a<key_d, value_d>> const& me);

		var<bidirectional_mutator_range_a<std::pair<key_d, value_d>>> (*_pair_mutator_range) (var<ordered_table_a<key_d, value_d>> const& me);
	};

	template <typename key_d, typename value_d>
	struct ordered_table_a
	{
		using operations = ordered_table_o<key_d, value_d>;
		using creator_fp = var<ordered_table_a<key_d, value_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
