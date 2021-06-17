#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_EXTRACTOR_A_H

namespace strange
{
	template <typename element_d>
	struct bidirectional_extractor_i
	{
		void (*decrement) (var<bidirectional_extractor_a<element_d>> const& me);

		bit<bidirectional_extractor_a<>> (*to_bidirectional_extractor_any) (con<bidirectional_extractor_a<element_d>> const& me);
	};

	template <typename element_d>
	struct bidirectional_extractor_o :
		forward_extractor_o<element_d>,
		bidirectional_extractor_i<element_d>
	{
	};

	template <typename element_d>
	struct bidirectional_extractor_a
	{
		using operations = bidirectional_extractor_o<element_d>;
		using creator_fp = bit<bidirectional_extractor_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
