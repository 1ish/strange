#ifndef COM_ONEISH__STRANGE__PARCEL_A_H
#define COM_ONEISH__STRANGE__PARCEL_A_H

namespace strange
{
	struct parcel_o :
		container_o
	{
		void (*close) (var<parcel_a> const& me);

		bool (*closed) (con<parcel_a> const& me);

		void (*reopen) (var<parcel_a> const& me);

		void (*from_json) (var<parcel_a> const& me,
			con<text_a> const& json);

		var<text_a> (*to_json) (con<parcel_a> const& me);

		void (*from_binary) (var<parcel_a> const& me,
			con<lake_a> const& lake);

		var<lake_a> (*to_binary) (con<parcel_a> const& me);
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
