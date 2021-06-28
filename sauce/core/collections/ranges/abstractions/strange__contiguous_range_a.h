#ifndef COM_ONEISH__STRANGE__CONTIGUOUS_RANGE_A_H
#define COM_ONEISH__STRANGE__CONTIGUOUS_RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct contiguous_range_o :
		random_access_range_o<element_d>
	{
		rat<contiguous_extractor_a<element_d>> (*begin) (con<contiguous_range_a<element_d>> const& me);

		rat<contiguous_extractor_a<element_d>> (*end) (con<contiguous_range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct contiguous_range_a
	{
		using non_mutator_range = bool;
		using operations = contiguous_range_o<element_d>;
		using creator_fp = var<contiguous_range_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
