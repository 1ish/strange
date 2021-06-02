#ifndef COM_ONEISH__STRANGE__CAT_A_H
#define COM_ONEISH__STRANGE__CAT_A_H

namespace strange
{
	struct cat_o : symbol_o
	{
		var<symbol_a>(*name)(con<cat_a> const& me_);

		representation_e (*representation)(con<cat_a> const& me_);

		//TODO var<flock_a<var<cat_a>>> (*aspects)(con<cat_a> const& me_);

		int64_t (*order)(con<cat_a> const& me_);
	};

	struct cat_a
	{
		using operations = cat_o;
		using creator = var<cat_a>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_e(con<> const& me_); //TODO cat

		static creator creator_f(con<symbol_a> const& scope_,
			con<symbol_a> const& thing_,
			con<symbol_a> const& function_);
	};
}

#endif
