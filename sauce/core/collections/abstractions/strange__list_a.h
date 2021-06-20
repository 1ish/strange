#ifndef COM_ONEISH__STRANGE__LIST_A_H
#define COM_ONEISH__STRANGE__LIST_A_H

namespace strange
{
	template <typename element_d>
	struct list_o :
		queue_o<element_d>
	{
		var<contiguous_range_a<element_d>> (*range) (con<list_a<element_d>> const& me);

		var<contiguous_mutator_range_a<element_d>> (*mutator_range) (var<list_a<element_d>> const& me);

		var<list_a<>> (*to_collection_any) (con<list_a<element_d>> const& me);
	};

	template <typename element_d>
	struct list_a
	{
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
