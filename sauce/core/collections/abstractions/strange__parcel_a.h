#ifndef COM_ONEISH__STRANGE__PARCEL_A_H
#define COM_ONEISH__STRANGE__PARCEL_A_H

namespace strange
{
	struct parcel_o :
		container_o
	{
	};

	struct parcel_a
	{
		using operations = parcel_o;
		using creator_fp = var<parcel_a> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
