#ifndef COM_ONEISH__STRANGE__DATA_A_H
#define COM_ONEISH__STRANGE__DATA_A_H

namespace strange
{
	template <typename type_d>
	struct data_i
	{
		type_d const& (*extract_data) (con<data_a<type_d>> const& me);

		type_d& (*mutate_data) (var<data_a<type_d>> const& me);
	};

	template <typename type_d>
	struct data_o :
		any_i,
		data_i<type_d>
	{
	};

	template <typename type_d>
	struct data_a
	{
		using interface = data_i<type_d>;
		using operations = data_o<type_d>;
		using creator_fp = var<data_a<type_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
