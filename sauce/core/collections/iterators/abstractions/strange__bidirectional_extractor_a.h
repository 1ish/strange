#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_EXTRACTOR_A_H

namespace strange
{
	template <typename element_d>
	struct bidirectional_extractor_o :
		forward_extractor_o<element_d>
	{
		void (*decrement) (var<bidirectional_extractor_a<element_d>> const& me);
	};

	template <typename element_d>
	struct bidirectional_extractor_a
	{
		using operations = bidirectional_extractor_o<element_d>;
		using variations = any_v<bidirectional_extractor_a<element_d>>;
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
