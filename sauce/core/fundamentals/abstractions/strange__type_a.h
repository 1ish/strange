#ifndef COM_ONEISH__STRANGE__TYPE_A_H
#define COM_ONEISH__STRANGE__TYPE_A_H

namespace strange
{
	struct type_o : // operations
		symbol_o
	{
		var<symbol_a> (*scope) (con<type_a> const& me);

		var<symbol_a> (*name) (con<type_a> const& me);

		var<list_a<var<kind_a>>> (*aspects) (con<type_a> const& me);
	};

	struct type_b // base
	{
		mutable thing_t* t;
		mutable type_o const* o;
	};

	template <typename base_d>
	struct type_c : // constant
		symbol_c<base_d>
	{
		using me_d = con<type_a>;

		inline var<symbol_a> scope() const;

		inline var<symbol_a> name() const;

		inline var<list_a<var<kind_a>>> aspects() const;
	};
	
	template <typename base_d>
	struct type_v : // variable
		symbol_v<base_d>
	{
		using me_d = var<type_a>;
	};

	struct type_a : // abstraction
		type_c<type_b>
	{
		using operations = type_o;
		using variations = type_v<type_a>;
		using creator_fp = var<type_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
