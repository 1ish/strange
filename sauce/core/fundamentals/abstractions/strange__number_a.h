#ifndef COM_ONEISH__STRANGE__NUMBER_A_H
#define COM_ONEISH__STRANGE__NUMBER_A_H

namespace strange
{
	template <typename type_d>
	struct number_o :
		data_o<type_d>
	{
	};

	template <typename type_d>
	struct number_a
	{
		using operations = number_o<type_d>;
		using creator_fp = var<number_a<type_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
