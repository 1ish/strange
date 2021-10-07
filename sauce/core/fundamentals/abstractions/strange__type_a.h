#ifndef COM_ONEISH__STRANGE__TYPE_A_H
#define COM_ONEISH__STRANGE__TYPE_A_H

namespace strange
{
	struct type_o :
		symbol_o
	{
		var<symbol_a> (*scope) (con<type_a> const& me);

		var<symbol_a> (*name) (con<type_a> const& me);

		var<list_a<var<kind_a>>> (*aspects) (con<type_a> const& me);
	};

	struct type_a
	{
		using operations = type_o;
		using creator_fp = var<type_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
