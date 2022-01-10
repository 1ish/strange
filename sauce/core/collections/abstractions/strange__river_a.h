#ifndef COM_ONEISH__STRANGE__RIVER_A_H
#define COM_ONEISH__STRANGE__RIVER_A_H

namespace strange
{
	struct river_o :
		reader_o
	{
		void (*put_byte) (var<river_a> const& me,
			uint8_t byte);

		void (*write) (var<river_a> const& me,
			con<lake_a> const& lake);

		int64_t (*tellp) (con<river_a> const& me);

		void (*seekp_beg) (var<river_a> const& me,
			int64_t offset);

		void (*seekp_end) (var<river_a> const& me,
			int64_t offset);

		void (*seekp_cur) (var<river_a> const& me,
			int64_t offset);

		bool (*flush) (var<river_a> const& me);
	};

	struct river_a
	{
		using non_mutator_range = bool;
		using operations = river_o;
		using variations = any_v<river_a>;
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
