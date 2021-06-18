#ifndef COM_ONEISH__STRANGE__TABLE_A_H
#define COM_ONEISH__STRANGE__TABLE_A_H

namespace strange
{
	template <typename key_d, typename value_d>
	struct table_i
	{
		var<table_a<>> (*to_table_any) (con<table_a<key_d, value_d>> const& me);

		fit<forward_extractor_a<std::pair<key_d, value_d>>> (*_pair_begin) (con<table_a<key_d, value_d>> const& me);

		fit<forward_extractor_a<std::pair<key_d, value_d>>> (*_pair_end) (con<table_a<key_d, value_d>> const& me);

		var<range_a<std::pair<key_d, value_d>>> (*_pair_range) (con<table_a<key_d, value_d>> const& me);

		fit<forward_mutator_a<std::pair<key_d, value_d>>> (*_pair_mutator_begin) (var<table_a<key_d, value_d>> const& me);

		fit<forward_mutator_a<std::pair<key_d, value_d>>> (*_pair_mutator_end) (var<table_a<key_d, value_d>> const& me);

		var<mutator_range_a<std::pair<key_d, value_d>>> (*_pair_mutator_range) (var<table_a<key_d, value_d>> const& me);
	};

	template <typename key_d, typename value_d>
	struct table_o :
		collection_o<key_d, value_d, tuple_a<key_d, value_d>>,
		mutator_range_i<tuple_a<key_d, value_d>>, //TODO tuple_range_i & tuple_mutator_range_i
		table_i<key_d, value_d>
	{
	};

	template <typename key_d, typename value_d>
	struct table_a
	{
		using is_mutator = bool;
		using operations = table_o<key_d, value_d>;
		using creator_fp = var<table_a<key_d, value_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
