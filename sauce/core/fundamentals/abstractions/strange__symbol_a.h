#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct symbol_o : any_o
	{
		var<symbol_a> (*add)(val<symbol_a> const& me_,
			val<symbol_a> const& suffix_);

		char const* (*to_char_star)(val<symbol_a> const& me_);

		int64_t (*length)(val<symbol_a> const& me_);

		char (*first_char)(val<symbol_a> const& me_);

		char (*last_char)(val<symbol_a> const& me_);
	};

	struct symbol_a
	{
		using operations = symbol_o;
		using creator = var<symbol_a>(*)();

		thing_t* t;
		operations const* o;

		static var<symbol_a> cat_e(val<> const& me_); //TODO cat

		static creator creator_f(val<symbol_a> const& scope_,
			val<symbol_a> const& thing_,
			val<symbol_a> const& function_);
	};
}

#endif
