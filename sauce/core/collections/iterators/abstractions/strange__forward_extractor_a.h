#ifndef COM_ONEISH__STRANGE__FORWARD_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__FORWARD_EXTRACTOR_A_H

namespace strange
{
	template <typename element_d>
	struct forward_extractor_o :
		any_o
	{
		element_d (*get) (con<forward_extractor_a<element_d>> const& me);

		void (*increment) (var<forward_extractor_a<element_d>> const& me);

		element_d const& (*_operator_star) (con<forward_extractor_a<element_d>> const& me);

		element_d const* (*_operator_arrow) (con<forward_extractor_a<element_d>> const& me);
	};

	template <typename element_d>
	struct forward_extractor_a
	{
		using operations = forward_extractor_o<element_d>;
		using creator_fp = fit<forward_extractor_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
