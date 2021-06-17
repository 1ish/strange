#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_RANGE_A_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct random_access_range_i
	{
		rat<random_access_extractor_a<element_d>> (*random_access_begin) (con<random_access_range_a<element_d>> const& me);

		rat<random_access_extractor_a<element_d>> (*random_access_end) (con<random_access_range_a<element_d>> const& me);

		var<random_access_range_a<>> (*to_random_access_range_any) (con<random_access_range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct random_access_range_o :
		bidirectional_range_o<element_d>,
		random_access_range_i<element_d>
	{
	};

	template <typename element_d>
	struct random_access_range_a
	{
		using non_mutator = bool;
		using operations = random_access_range_o<element_d>;
		using creator_fp = var<random_access_range_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
