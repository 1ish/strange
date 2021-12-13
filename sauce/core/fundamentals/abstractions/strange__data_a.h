#ifndef COM_ONEISH__STRANGE__DATA_A_H
#define COM_ONEISH__STRANGE__DATA_A_H

namespace strange
{
	template <typename type_d>
	struct data_o : // operations
		any_o
	{
		ptr<> (*read_lock) (con<data_a<type_d>> const& me);

		ptr<> (*write_lock) (var<data_a<type_d>> const& me);

		type_d const& (*extract) (con<data_a<type_d>> const& me);

		type_d& (*mutate) (var<data_a<type_d>> const& me);
	};

	template <typename type_d>
	struct data_b // base
	{
		mutable thing_t* t;
		mutable data_o<type_d> const* o;
	};

	template <typename base_d, typename type_d>
	struct data_c : // constant
		any_c<base_d>
	{
		using me_d = con<data_a<type_d>>;

		inline ptr<> read_lock() const;

		inline type_d const& extract() const;
	};

	template <typename base_d, typename type_d>
	struct data_v : // variable
		any_v<base_d>
	{
		using me_d = var<data_a<type_d>>;

		inline ptr<> write_lock() const;

		inline type_d& mutate() const;
	};

	template <typename type_d>
	struct data_a : // abstraction
		data_c<data_b<type_d>, type_d>
	{
		using operations = data_o<type_d>;
		using variations = data_v<data_a<type_d>, type_d>;
		using creator_fp = var<data_a<type_d>>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
