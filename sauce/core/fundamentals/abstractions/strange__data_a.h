#ifndef COM_ONEISH__STRANGE__DATA_A_H
#define COM_ONEISH__STRANGE__DATA_A_H

namespace strange
{
	template <typename type_d>
	struct data_o :
		any_o
	{
		ptr<> (*read_lock) (con<data_a<type_d>> const& me);

		ptr<> (*write_lock) (var<data_a<type_d>> const& me);

		type_d const& (*extract) (con<data_a<type_d>> const& me);

		type_d& (*mutate) (var<data_a<type_d>> const& me);
	};

	template <typename type_d>
	struct data_a
	{
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
