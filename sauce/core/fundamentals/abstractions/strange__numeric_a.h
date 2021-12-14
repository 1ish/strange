#ifndef COM_ONEISH__STRANGE__NUMERIC_A_H
#define COM_ONEISH__STRANGE__NUMERIC_A_H

namespace strange
{
	struct numeric_o : // operations
		any_o
	{
		int64_t (*int64) (con<numeric_a> const& me);

		uint64_t (*uint64) (con<numeric_a> const& me);

		double (*float64) (con<numeric_a> const& me);

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

	struct numeric_b // base
	{
		mutable thing_t* t;
		mutable numeric_o const* o;
	};

	template <typename base_d>
	struct numeric_c : // constant
		any_c<base_d>
	{
		using me_d = con<numeric_a>;

		inline int64_t int64() const;

		inline uint64_t uint64() const;

		inline double float64() const;

		inline int64_t byte_size() const;

		inline bool is_int() const;

		inline bool is_signed() const;

		inline bool is_nan() const;

		inline bool is_inf() const;

		inline bool is_finite() const;

		inline bool is_normal() const;

		inline bool little_endian() const;
	};

	template <typename base_d>
	struct numeric_v : // variable
		any_v<base_d>
	{
		using me_d = var<numeric_a>;
	};
	
	struct numeric_a : // abstraction
		numeric_c<numeric_b>
	{
		using operations = numeric_o;
		using variations = numeric_v<numeric_a>;
		using creator_fp = var<numeric_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
