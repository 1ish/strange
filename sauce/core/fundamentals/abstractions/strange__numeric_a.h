#ifndef COM_ONEISH__STRANGE__NUMERIC_A_H
#define COM_ONEISH__STRANGE__NUMERIC_A_H

namespace strange
{
	struct numeric_o :
		any_o
	{
		int64_t (*to_int64) (con<numeric_a> const& me);

		uint64_t (*to_uint64) (con<numeric_a> const& me);

		double (*to_float64) (con<numeric_a> const& me);

		int64_t (*byte_size) (con<numeric_a> const& me);

		bool (*is_int) (con<numeric_a> const& me);

		bool (*is_signed) (con<numeric_a> const& me);

		bool (*is_nan) (con<numeric_a> const& me);

		bool (*is_inf) (con<numeric_a> const& me);

		bool (*is_finite) (con<numeric_a> const& me);

		bool (*is_normal) (con<numeric_a> const& me);

		static inline bool little_endian(con<numeric_a> const& me)
		{
			union
			{
				uint32_t i;
				char c[4];
			} bint = { 0x01020304 };
			return bint.c[0] != 1;
		}
	};

	struct numeric_a
	{
		using operations = numeric_o;
		using creator_fp = var<numeric_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
