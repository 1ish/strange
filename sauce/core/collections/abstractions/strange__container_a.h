#ifndef COM_ONEISH__STRANGE__CONTAINER_A_H
#define COM_ONEISH__STRANGE__CONTAINER_A_H

namespace strange
{
	struct container_o :
		collection_o<con<container_a>, var<container_a>, var<container_a>>
	{
		// thing
		var<container_a> (*make_thing) (con<container_a> const& me,
			con<> const& thing);

		bool (*is_thing) (con<container_a> const& me);

		var<> (*thing) (con<container_a> const& me);

		// boolean
		var<container_a> (*make_boolean) (con<container_a> const& me,
			bool boolean);

		bool (*is_boolean) (con<container_a> const& me);

		bool (*boolean) (con<container_a> const& me);

		// int64
		var<container_a> (*make_int64) (con<container_a> const& me,
			int64_t int64);

		bool (*is_int64) (con<container_a> const& me);

		int64_t (*int64) (con<container_a> const& me);

		// float64
		var<container_a> (*make_float64) (con<container_a> const& me,
			double float64);

		bool (*is_float64) (con<container_a> const& me);

		double (*float64) (con<container_a> const& me);

		// symbol
		var<container_a> (*make_symbol) (con<container_a> const& me,
			con<symbol_a> const& symbol);

		bool (*is_symbol) (con<container_a> const& me);

		var<symbol_a> (*symbol) (con<container_a> const& me);

		// lake
		var<container_a> (*make_lake) (con<container_a> const& me,
			con<lake_a> const& lake);

		bool (*is_lake) (con<container_a> const& me);

		var<lake_a> (*lake) (con<container_a> const& me);

		// inventory
		var<container_a> (*make_inventory) (con<container_a> const& me);

		bool (*is_inventory) (con<container_a> const& me);

		bool (*inventory_has) (con<container_a> const& me,
			int64_t index);

		var<container_a> (*inventory_at) (con<container_a> const& me,
			int64_t index);

		void (*inventory_update) (var<container_a> const& me,
			int64_t index,
			var<container_a> const& container);

		bool (*inventory_insert) (var<container_a> const& me,
			int64_t index,
			var<container_a> const& container);

		bool (*inventory_erase) (var<container_a> const& me,
			int64_t index);

		// directory
		var<container_a> (*make_directory) (con<container_a> const& me);

		bool (*is_directory) (con<container_a> const& me);

		bool (*directory_has) (con<container_a> const& me,
			con<symbol_a> const& symbol);

		var<container_a> (*directory_at) (con<container_a> const& me,
			con<symbol_a> const& symbol);

		void (*directory_update) (var<container_a> const& me,
			con<symbol_a> const& symbol,
			var<container_a> const& container);

		bool (*directory_insert) (var<container_a> const& me,
			con<symbol_a> const& symbol,
			var<container_a> const& container);

		bool (*directory_erase) (var<container_a> const& me,
			con<symbol_a> const& symbol);
	};

	struct container_a
	{
		using non_mutator_range = bool;
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
