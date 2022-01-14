#ifndef COM_ONEISH__STRANGE__CAT_A_H
#define COM_ONEISH__STRANGE__CAT_A_H

namespace strange
{
	struct cat_o : // operations
		symbol_o
	{
		int64_t (*order) (con<cat_a> const& me);

		representation_e (*representation) (con<cat_a> const& me);

		var<symbol_a> (*scope) (con<cat_a> const& me);

		var<symbol_a> (*name) (con<cat_a> const& me);

		var<list_a<var<kind_a>>> (*aspects) (con<cat_a> const& me);

		// abstraction  <symbol>
		// dimension    ^element^
		// native       <+bool>
		// enumeration  %behaviour%
		// meta         <~abstraction>
		// function     <(x #, y #) =>
	};

	struct cat_b // base
	{
		mutable thing_t* t;
		mutable cat_o const* o;
	};

	template <typename base_d>
	struct cat_c : // constant
		symbol_c<base_d>
	{
		using me_d = con<cat_a>;

		inline int64_t order() const;

		inline representation_e representation() const;

		inline var<symbol_a> scope() const;

		inline var<symbol_a> name() const;

		inline var<list_a<var<kind_a>>> aspects() const;
	};
	
	template <typename base_d>
	struct cat_v : // variable
		symbol_v<base_d>
	{
		using me_d = var<cat_a>;
	};

	struct cat_a : // abstraction
		cat_c<cat_b>
	{
		using operations = cat_o;
		using variations = cat_v<cat_a>;
		using creator_fp = var<cat_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
