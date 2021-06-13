#ifndef COM_ONEISH__STRANGE__LIST_A_H
#define COM_ONEISH__STRANGE__LIST_A_H

namespace strange
{
	template <typename element_d>
	struct list_o : collection_o<int64_t, element_d, element_d>
	{
		rat<random_access_extractor_a<element_d>>(*random_access_begin)(con<list_a<element_d>> const& me);

		rat<random_access_extractor_a<element_d>>(*random_access_end)(con<list_a<element_d>> const& me);

		var<random_access_range_a<>>(*to_random_access_range_any)(con<list_a<element_d>> const& me);

		rat<random_access_mutator_a<element_d>>(*random_access_mutator_begin)(var<list_a<element_d>> const& me);

		rat<random_access_mutator_a<element_d>>(*random_access_mutator_end)(var<list_a<element_d>> const& me);

		var<random_access_mutator_range_a<>>(*to_random_access_mutator_range_any)(var<list_a<element_d>> const& me);

		var<list_a<>> (*to_list_any)(var<list_a<element_d>> const& me);
	};

	template <typename element_d>
	struct list_a
	{
		using is_mutator = bool;
		using operations = list_o<element_d>;
		using creator_fp = var<list_a<element_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
