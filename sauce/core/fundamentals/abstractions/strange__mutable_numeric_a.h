#ifndef COM_ONEISH__STRANGE__MUTABLE_NUMERIC_A_H
#define COM_ONEISH__STRANGE__MUTABLE_NUMERIC_A_H

namespace strange
{
	struct mutable_numeric_o :
		numeric_o
	{
		void (*from_int64) (var<mutable_numeric_a> const& me,
			int64_t number);

		void (*from_uint64) (var<mutable_numeric_a> const& me,
			uint64_t number);

		void (*from_float64) (var<mutable_numeric_a> const& me,
			double number);
	};

	struct mutable_numeric_a
	{
		using operations = mutable_numeric_o;
		using variations = any_v<mutable_numeric_a>;
		using creator_fp = var<mutable_numeric_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
