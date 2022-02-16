#ifndef COM_ONEISH__STRANGE__CONTAINER_A_H
#define COM_ONEISH__STRANGE__CONTAINER_A_H

namespace strange
{
	struct container_o : // operations
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

	struct container_b // base
	{
		mutable thing_t* t;
		mutable container_o const* o;
	};

	template <typename base_d>
	struct container_c : // constant
		collection_c<base_d, con<container_a>, var<container_a>, var<container_a>>
	{
		using me_d = con<container_a>;

		// thing
		inline var<container_a> make_thing(con<> const& thing) const;

		inline bool is_thing() const;

		inline var<> thing() const;

		// boolean
		inline var<container_a> make_boolean(bool boolean) const;

		inline bool is_boolean() const;

		inline bool boolean() const;

		// int64
		inline var<container_a> make_int64(int64_t int64) const;

		inline bool is_int64() const;

		inline int64_t int64() const;

		// float64
		inline var<container_a> make_float64(double float64) const;

		inline bool is_float64() const;

		inline double float64() const;

		// symbol
		inline var<container_a> make_symbol(con<symbol_a> const& symbol) const;

		inline bool is_symbol() const;

		inline var<symbol_a> symbol() const;

		// lake
		inline var<container_a> make_lake(con<lake_a> const& lake) const;

		inline bool is_lake() const;

		inline var<lake_a> lake() const;

		// inventory
		inline var<container_a> make_inventory() const;

		inline bool is_inventory() const;

		inline bool inventory_has(int64_t index) const;

		inline var<container_a> inventory_at(int64_t index) const;

		// directory
		inline var<container_a> make_directory() const;

		inline bool is_directory() const;

		inline bool directory_has(con<symbol_a> const& symbol) const;

		inline var<container_a> directory_at(con<symbol_a> const& symbol) const;
	};

	template <typename base_d>
	struct container_v : // variable
		collection_v<base_d, con<container_a>, var<container_a>, var<container_a>>
	{
		using me_d = var<container_a>;

		// inventory
		inline void inventory_update(int64_t index,
			var<container_a> const& container) const;

		inline bool inventory_insert(int64_t index,
			var<container_a> const& container) const;

		inline bool inventory_erase(int64_t index) const;

		// directory
		inline void directory_update(con<symbol_a> const& symbol,
			var<container_a> const& container) const;

		inline bool directory_insert(con<symbol_a> const& symbol,
			var<container_a> const& container) const;

		inline bool directory_erase(con<symbol_a> const& symbol) const;
	};

	struct container_a : // abstraction
		container_c<container_b>
	{
		using non_mutator_range = bool;
		using operations = container_o;
		using variations = container_v<container_a>;
		using creator_fp = var<container_a> (*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
