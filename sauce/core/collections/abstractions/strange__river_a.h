#ifndef COM_ONEISH__STRANGE__RIVER_A_H
#define COM_ONEISH__STRANGE__RIVER_A_H

namespace strange
{
	struct river_o :
		brook_o
	{
		uint8_t (*get_byte) (var<river_a> const& me);

		uint8_t (*peek_byte) (var<river_a> const& me);

		void (*unget_byte) (var<river_a> const& me);

		void (*put_back_byte) (var<river_a> const& me,
			uint8_t byte);

		var<lake_a> (*get_line) (var<river_a> const& me,
			int64_t count,
			uint8_t delimiter);

		var<lake_a> (*read) (var<river_a> const& me,
			int64_t count);

		void (*ignore) (var<river_a> const& me,
			int64_t count);

		var<lake_a> (*lake) (var<river_a> const& me);

		int64_t (*tellg) (con<river_a> const& me);

		void (*seekg_beg) (var<river_a> const& me,
			int64_t offset);

		void (*seekg_end) (var<river_a> const& me,
			int64_t offset);

		void (*seekg_cur) (var<river_a> const& me,
			int64_t offset);

		bool (*sync) (var<river_a> const& me);

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

		void (*set_good) (var<river_a> const& me);

		void (*set_eof) (var<river_a> const& me);

		void (*set_fail) (var<river_a> const& me);

		void (*set_bad) (var<river_a> const& me);

		bool (*good) (con<river_a> const& me);

		bool (*eof) (con<river_a> const& me);

		bool (*fail) (con<river_a> const& me);

		bool (*bad) (con<river_a> const& me);

		var<text_a> (*filename) (con<river_a> const& me);

		void (*close) (var<river_a> const& me);

		bool (*closed) (con<river_a> const& me);
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
