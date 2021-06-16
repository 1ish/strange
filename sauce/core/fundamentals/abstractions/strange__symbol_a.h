#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct symbol_i
	{
		var<symbol_a> (*add) (con<symbol_a> const& me,
			con<symbol_a> const& suffix);

		char const* (*to_char_star) (con<symbol_a> const& me);

		int64_t (*length) (con<symbol_a> const& me);

		char (*first_char) (con<symbol_a> const& me);

		char (*last_char) (con<symbol_a> const& me);
	};

	struct symbol_o :
		any_i,
		symbol_i
	{
	};

	struct symbol_a
	{
		using interface = symbol_i;
		using operations = symbol_o;
		using creator_fp = var<symbol_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
