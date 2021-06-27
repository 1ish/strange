#ifndef COM_ONEISH__STRANGE__LAKE_A_H
#define COM_ONEISH__STRANGE__LAKE_A_H

namespace strange
{
	struct lake_o :
		list_o<int8_t>
	{
	};

	struct lake_a
	{
		using non_mutator_range = bool;
		using operations = lake_o;
		using creator_fp = var<lake_a> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
