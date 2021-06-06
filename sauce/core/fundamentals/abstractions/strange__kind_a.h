#ifndef COM_ONEISH__STRANGE__KIND_A_H
#define COM_ONEISH__STRANGE__KIND_A_H

namespace strange
{
	struct kind_o : symbol_o
	{
		var<cat_a> (*the_cat)(con<kind_a> const& me);

		behaviour_e (*behaviour)(con<kind_a> const& me);

		// constant  :<any>#
		// variable  :<any>=
		// pointer   :<any>&
		// shared    :<any>$
	};

	struct kind_a
	{
		using operations = kind_o;
		using creator = var<kind_a>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_f(con<> const& me); //TODO cat

		static creator creator_f(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
