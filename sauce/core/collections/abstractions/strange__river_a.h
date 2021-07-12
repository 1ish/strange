#ifndef COM_ONEISH__STRANGE__RIVER_A_H
#define COM_ONEISH__STRANGE__RIVER_A_H

namespace strange
{
	struct river_o :
		brook_o
	{
	};

	struct river_a
	{
		using non_mutator_range = bool;
		using operations = river_o;
		using creator_fp = var<river_a> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
