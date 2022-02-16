#ifndef COM_ONEISH__STRANGE__QUEUE_A_H
#define COM_ONEISH__STRANGE__QUEUE_A_H

namespace strange
{
	template <typename element_d>
	struct queue_o : // operations
		collection_o<int64_t, element_d, element_d>
	{
		var<random_access_range_a<element_d>> (*range) (con<queue_a<element_d>> const& me);

		rat<random_access_extractor_a<element_d>> (*begin) (con<queue_a<element_d>> const& me);

		rat<random_access_extractor_a<element_d>> (*end) (con<queue_a<element_d>> const& me);

		var<random_access_mutator_range_a<element_d>> (*mutator_range) (var<queue_a<element_d>> const& me);

		rat<random_access_mutator_a<element_d>> (*mutator_begin) (var<queue_a<element_d>> const& me);

		rat<random_access_mutator_a<element_d>> (*mutator_end) (var<queue_a<element_d>> const& me);
	};

	template <typename element_d>
	struct queue_b // base
	{
		mutable thing_t* t;
		mutable queue_o<element_d> const* o;
	};

	template <typename base_d, typename element_d>
	struct queue_c : // constant
		collection_c<base_d, int64_t, element_d, element_d>
	{
		using me_d = con<queue_a<element_d>>;

		inline var<random_access_range_a<element_d>> range() const;

		inline rat<random_access_extractor_a<element_d>> begin() const;

		inline rat<random_access_extractor_a<element_d>> end() const;
	};

	template <typename base_d, typename element_d>
	struct queue_v : // variable
		collection_v<base_d, int64_t, element_d, element_d>
	{
		using me_d = var<queue_a<element_d>>;

		inline var<random_access_mutator_range_a<element_d>> mutator_range() const;

		inline rat<random_access_mutator_a<element_d>> mutator_begin() const;

		inline rat<random_access_mutator_a<element_d>> mutator_end() const;
	};

	template <typename element_d>
	struct queue_a : // abstraction
		queue_c<queue_b<element_d>, element_d>
	{
		using non_mutator_range = bool;
		using operations = queue_o<element_d>;
		using variations = queue_v<queue_a<element_d>, element_d>;
		using creator_fp = var<queue_a<element_d>> (*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
