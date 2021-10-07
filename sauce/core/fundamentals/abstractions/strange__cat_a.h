#ifndef COM_ONEISH__STRANGE__CAT_A_H
#define COM_ONEISH__STRANGE__CAT_A_H

namespace strange
{
	struct cat_o :
		symbol_o
	{
		var<symbol_a> (*scope) (con<cat_a> const& me);

		var<symbol_a> (*name) (con<cat_a> const& me);

		var<list_a<var<kind_a>>> (*aspects) (con<cat_a> const& me);

		int64_t (*order) (con<cat_a> const& me);

		representation_e (*representation) (con<cat_a> const& me);

		// abstraction  <symbol>
		// dimension    <^element>
		// native       <+bool>
		// enumeration  <%behaviour>
		// meta         <~abstraction>
	};

	struct cat_a
	{
		using operations = cat_o;
		using creator_fp = var<cat_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
