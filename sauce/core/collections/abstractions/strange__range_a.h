#ifndef COM_ONEISH__STRANGE__RANGE_A_H
#define COM_ONEISH__STRANGE__RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct range_o : any_o
	{
		var<forward_extractor_a<element_d>> (*extract_begin)(con<range_a<element_d>> const& me);

		var<forward_extractor_a<element_d>>(*extract_end)(con<range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct range_a
	{
		using operations = range_o<element_d>;
		using creator_fp = var<range_a<element_d>>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
