#ifndef COM_ONEISH__STRANGE__DATA_A_H
#define COM_ONEISH__STRANGE__DATA_A_H

namespace strange
{
	template <typename data_type>
	struct data_o : any_o
	{
		data_type const& (*extract_data)(con<data_a<data_type>> const& me);

		data_type& (*mutate_data)(var<data_a<data_type>> const& me);
	};

	template <typename data_type>
	struct data_a
	{
		using operations = data_o<data_type>;
		using creator = var<data_a<data_type>>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_f(con<> const& me); //TODO cat

		static creator creator_f(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
