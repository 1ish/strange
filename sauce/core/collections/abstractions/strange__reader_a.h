#ifndef COM_ONEISH__STRANGE__READER_A_H
#define COM_ONEISH__STRANGE__READER_A_H

namespace strange
{
	struct reader_o :
		brook_o
	{
		uint8_t (*get_byte) (var<reader_a> const& me);

		uint8_t (*peek_byte) (var<reader_a> const& me);

		void (*unget_byte) (var<reader_a> const& me);

		void (*put_back_byte) (var<reader_a> const& me,
			uint8_t byte);

		var<lake_a> (*get_line) (var<reader_a> const& me,
			int64_t count,
			uint8_t delimiter);

		var<lake_a> (*read) (var<reader_a> const& me,
			int64_t count);

		void (*ignore) (var<reader_a> const& me,
			int64_t count);

		var<lake_a> (*lake) (var<reader_a> const& me);

		int64_t (*tellg) (con<reader_a> const& me);

		void (*seekg_beg) (var<reader_a> const& me,
			int64_t offset);

		void (*seekg_end) (var<reader_a> const& me,
			int64_t offset);

		void (*seekg_cur) (var<reader_a> const& me,
			int64_t offset);

		bool (*sync) (var<reader_a> const& me);

		void (*set_good) (var<reader_a> const& me);

		void (*set_eof) (var<reader_a> const& me);

		void (*set_fail) (var<reader_a> const& me);

		void (*set_bad) (var<reader_a> const& me);

		bool (*good) (con<reader_a> const& me);

		bool (*eof) (con<reader_a> const& me);

		bool (*fail) (con<reader_a> const& me);

		bool (*bad) (con<reader_a> const& me);

		var<text_a> (*filename) (con<reader_a> const& me);

		void (*close) (var<reader_a> const& me);

		bool (*closed) (con<reader_a> const& me);
	};

	struct reader_a
	{
		using non_mutator_range = bool;
		using operations = reader_o;
		using variations = any_v<reader_a>;
		using creator_fp = var<reader_a> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
