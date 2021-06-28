#ifndef COM_ONEISH__STRANGE__CONTIGUOUS_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__CONTIGUOUS_EXTRACTOR_A_H

namespace strange
{
	template <typename element_d>
	struct contiguous_extractor_o :
		random_access_extractor_o<element_d>
	{
		rat<contiguous_extractor_a<element_d>> (*add) (con<contiguous_extractor_a<element_d>> const& me,
			int64_t offset);
	};

	template <typename element_d>
	struct contiguous_extractor_a
	{
		using operations = contiguous_extractor_o<element_d>;
		using creator_fp = rat<contiguous_extractor_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
