#ifndef COM_ONEISH__STRANGE__KIND_A_H
#define COM_ONEISH__STRANGE__KIND_A_H

namespace strange
{
	struct kind_o : symbol_o
	{
		var<cat_a> (*category)(con<kind_a> const& me_);

		behaviour_e (*behaviour)(con<kind_a> const& me_);
	};

	struct kind_a
	{
		using operations = kind_o;
		using creator = var<kind_a>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_e(con<> const& me_); //TODO cat

		static creator creator_f(con<symbol_a> const& scope_,
			con<symbol_a> const& thing_,
			con<symbol_a> const& function_);
	};
}

#endif
