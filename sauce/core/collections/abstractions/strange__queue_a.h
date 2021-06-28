#ifndef COM_ONEISH__STRANGE__QUEUE_A_H
#define COM_ONEISH__STRANGE__QUEUE_A_H

namespace strange
{
	template <typename element_d>
	struct queue_o :
		collection_o<int64_t, element_d, element_d>
	{
		var<random_access_range_a<element_d>> (*range) (con<queue_a<element_d>> const& me);

		rat<random_access_extractor_a<element_d>> (*begin) (con<queue_a<element_d>> const& me);

		rat<random_access_extractor_a<element_d>> (*end) (con<queue_a<element_d>> const& me);

		var<random_access_range_a<>> (*any_range) (con<queue_a<element_d>> const& me);

		var<random_access_mutator_range_a<element_d>> (*mutator_range) (var<queue_a<element_d>> const& me);

		rat<random_access_mutator_a<element_d>> (*mutator_begin) (var<queue_a<element_d>> const& me);

		rat<random_access_mutator_a<element_d>> (*mutator_end) (var<queue_a<element_d>> const& me);

		var<queue_a<>> (*any_collection) (con<queue_a<element_d>> const& me);
	};

	template <typename element_d>
	struct queue_a
	{
		using non_mutator_range = bool;
		using operations = queue_o<element_d>;
		using creator_fp = var<queue_a<element_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
