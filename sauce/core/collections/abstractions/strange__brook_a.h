#ifndef COM_ONEISH__STRANGE__BROOK_A_H
#define COM_ONEISH__STRANGE__BROOK_A_H

namespace strange
{
	struct brook_o :
		queue_o<int8_t>
	{
	};

	struct brook_a
	{
		using non_mutator_range = bool;
		using operations = brook_o;
		using creator_fp = var<brook_a> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
