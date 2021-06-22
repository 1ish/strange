#ifndef COM_ONEISH__STRANGE__CONTAINER_A_H
#define COM_ONEISH__STRANGE__CONTAINER_A_H

namespace strange
{
	struct container_o :
		collection_o<container_a, container_a, container_a>
	{
		var<container_a> (*make_thing) (con<container_a> const& me,
			con<> const& thing);

		bool (*is_thing) (con<container_a> const& me);

		var<> (*thing) (con<container_a> const& me);

		var<container_a> (*make_boolean) (con<container_a> const& me,
			bool boolean);

		bool (*is_boolean) (con<container_a> const& me);

		bool (*boolean) (con<container_a> const& me);

		var<container_a> (*make_int64) (con<container_a> const& me,
			int64_t int64);

		bool (*is_int64) (con<container_a> const& me);

		int64_t (*int64) (con<container_a> const& me);

		var<container_a> (*make_float64) (con<container_a> const& me,
			double float64);

		bool (*is_float64) (con<container_a> const& me);

		double (*float64) (con<container_a> const& me);

		var<container_a> (*make_lake) (con<container_a> const& me,
			con<lake_a> const& lake);

		bool (*is_lake) (con<container_a> const& me);

		var<lake_a> (*lake) (con<container_a> const& me);

		var<container_a> (*make_inventory) (con<container_a> const& me);

		bool (*is_inventory) (con<container_a> const& me);

		var<queue_a<var<container_a>>> (*inventory) (con<container_a> const& me);

		var<container_a> (*make_directory) (con<container_a> const& me);

		bool (*is_directory) (con<container_a> const& me);

		var<table_a<var<lake_a>, var<container_a>>> (*directory) (con<container_a> const& me);
	};

	struct container_a
	{
		using operations = container_o;
		using creator_fp = var<container_a> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
