#ifndef COM_ONEISH__STRANGE__DATA_A_H
#define COM_ONEISH__STRANGE__DATA_A_H

namespace strange
{
	template <typename _type>
	struct data_o : any_o
	{
		_type const& (*extract_data)(con<data_a<_type>> const& me);

		_type& (*mutate_data)(var<data_a<_type>> const& me);
	};

	template <typename _type>
	struct data_a
	{
		using operations = data_o<_type>;
		using creator = var<data_a<_type>>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_e(con<> const& me); //TODO cat

		static creator creator_f(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
