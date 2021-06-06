#ifndef COM_ONEISH__STRANGE__RANGE_A_H
#define COM_ONEISH__STRANGE__RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct range_o : any_o
	{
		element_d const& (*extract_range)(con<range_a<element_d>> const& me);

		element_d& (*mutate_range)(var<range_a<element_d>> const& me);
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
