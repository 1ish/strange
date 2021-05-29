#ifndef COM_ONEISH__STRANGE__CAT_A_H
#define COM_ONEISH__STRANGE__CAT_A_H

namespace strange
{
	struct cat_o : symbol_o
	{
		int64_t (*order)(val<cat_a> const& me_);

		var<symbol_a> (*name)(val<cat_a> const& me_);

		//TODO var<flock_a<cat_a>> (*aspects)(val<cat_a> const& me_);
	};

	struct cat_a
	{
		using operations = cat_o;
		using creator = var<cat_a>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_e(val<> const& me_); //TODO cat

		static creator creator_f(val<symbol_a> const& scope_,
			val<symbol_a> const& thing_,
			val<symbol_a> const& function_);
	};
}

#endif
