#ifndef COM_ONEISH__STRANGE__MUTABLE_NUMERIC_A_H
#define COM_ONEISH__STRANGE__MUTABLE_NUMERIC_A_H

namespace strange
{
	struct mutable_numeric_o : // operations
		numeric_o
	{
		void (*from_int64) (var<mutable_numeric_a> const& me,
			int64_t number);

		void (*from_uint64) (var<mutable_numeric_a> const& me,
			uint64_t number);

		void (*from_float64) (var<mutable_numeric_a> const& me,
			double number);
	};

	struct mutable_numeric_b // base
	{
		mutable thing_t* t;
		mutable mutable_numeric_o const* o;
	};

	template <typename base_d>
	struct mutable_numeric_c : // constant
		numeric_c<base_d>
	{
		using me_d = con<mutable_numeric_a>;
	};

	template <typename base_d>
	struct mutable_numeric_v : // variable
		numeric_v<base_d>
	{
		using me_d = var<mutable_numeric_a>;

		inline void from_int64(int64_t number) const;

		inline void from_uint64(uint64_t number) const;

		inline void from_float64(double number) const;
	};

	struct mutable_numeric_a : // abstraction
		mutable_numeric_c<mutable_numeric_b>
	{
		using operations = mutable_numeric_o;
		using variations = mutable_numeric_v<mutable_numeric_a>;
		using creator_fp = var<mutable_numeric_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
