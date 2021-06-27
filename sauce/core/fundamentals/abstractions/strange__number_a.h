#ifndef COM_ONEISH__STRANGE__NUMBER_A_H
#define COM_ONEISH__STRANGE__NUMBER_A_H

namespace strange
{
	template <typename type_d>
	struct number_o :
		data_o<type_d>
	{
		static inline int64_t to_int64(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_same_v<type_d, int64_t>)
			{
				return me.o->extract(me);
			}
			else if constexpr (std::is_integral_v<type_d>)
			{
				return static_cast<int64_t>(me.o->extract(me));
			}
			else
			{
				return static_cast<int64_t>(std::llround(me.o->extract(me)));
			}
		}

		static inline uint64_t to_uint64(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_same_v<type_d, uint64_t>)
			{
				return me.o->extract(me);
			}
			else if constexpr (std::is_integral_v<type_d>)
			{
				return static_cast<uint64_t>(me.o->extract(me));
			}
			else
			{
				return static_cast<uint64_t>(std::llround(me.o->extract(me)));
			}
		}

		static inline double to_float64(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_same_v<type_d, double>)
			{
				return me.o->extract(me);
			}
			else
			{
				return static_cast<double>(me.o->extract(me));
			}
		}

		static inline int64_t byte_size(con<number_a<type_d>> const& me)
		{
			return static_cast<int64_t>(sizeof(type_d));
		}

		static inline bool is_int(con<number_a<type_d>> const& me)
		{
			return std::is_integral_v<type_d>;
		}

		static inline bool is_signed(con<number_a<type_d>> const& me)
		{
			return std::is_signed_v<type_d>;
		}

		static inline bool is_nan(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_integral_v<type_d>)
			{
				return false;
			}
			else
			{
				return std::isnan(me.o->extract(me));
			}
		}

		static inline bool is_inf(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_integral_v<type_d>)
			{
				return false;
			}
			else
			{
				return std::isinf(me.o->extract(me));
			}
		}

		static inline bool is_finite(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_integral_v<type_d>)
			{
				return true;
			}
			else
			{
				return std::isfinite(me.o->extract(me));
			}
		}

		static inline bool is_normal(con<number_a<type_d>> const& me)
		{
			if constexpr (std::is_integral_v<type_d>)
			{
				return true;
			}
			else
			{
				return std::isnormal(me.o->extract(me));
			}
		}

		static inline bool little_endian(con<number_a<type_d>> const& me)
		{
			union
			{
				uint32_t i;
				char c[4];
			} bint = { 0x01020304 };
			return bint.c[0] != 1;
		}
	};

	template <typename type_d>
	struct number_a
	{
		using operations = number_o<type_d>;
		using creator_fp = var<number_a<type_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
