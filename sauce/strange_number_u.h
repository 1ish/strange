#ifndef COM_ONEISH_STRANGE_NUMBER_U_H
#define COM_ONEISH_STRANGE_NUMBER_U_H

namespace strange
{

template <typename F>
inline misunderstanding_a<> dis(F&& s);

template <typename PRIMITIVE>
class number_u
{
public:
	static inline PRIMITIVE from_number__(number_a<> const& other);
	static inline PRIMITIVE from_int_64__(int64_t other);
	static inline PRIMITIVE from_uint_64__(uint64_t other);
	static inline PRIMITIVE from_float_64__(double other);
	static inline int64_t to_int_64__(PRIMITIVE other);
	static inline uint64_t to_uint_64__(PRIMITIVE other);
	static inline double to_float_64__(PRIMITIVE other);
	static inline PRIMITIVE modulo__(PRIMITIVE x, PRIMITIVE y);
	static inline bool is_int__();
	static inline bool is_signed__();
	static inline bool is_nan__(PRIMITIVE number);
	static inline bool is_inf__(PRIMITIVE number);
	static inline bool is_finite__(PRIMITIVE number);
	static inline bool is_normal__(PRIMITIVE number);
};

template <>
class number_u<int8_t>
{
public:
	static inline int8_t from_number__(number_a<> const& other)
	{
		return int8_t(other.to_int_64__());
	}

	static inline int8_t from_int_64__(int64_t other)
	{
		return int8_t(other);
	}

	static inline int8_t from_uint_64__(uint64_t other)
	{
		return int8_t(other);
	}

	static inline int8_t from_float_64__(double other)
	{
		return int8_t(std::llround(other));
	}

	static inline int64_t to_int_64__(int8_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(int8_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint64_t(other);
	}

	static inline double to_float_64__(int8_t other)
	{
		return double(other);
	}

	static inline int8_t modulo__(int8_t x, int8_t y)
	{
		return int8_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return true;
	}

	static inline bool is_nan__(int8_t number)
	{
		return false;
	}

	static inline bool is_inf__(int8_t number)
	{
		return false;
	}

	static inline bool is_finite__(int8_t number)
	{
		return true;
	}

	static inline bool is_normal__(int8_t number)
	{
		return true;
	}
};

template <>
class number_u<uint8_t>
{
public:
	static inline uint8_t from_number__(number_a<> const& other)
	{
		return uint8_t(other.to_uint_64__());
	}

	static inline uint8_t from_int_64__(int64_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint8_t(other);
	}

	static inline uint8_t from_uint_64__(uint64_t other)
	{
		return uint8_t(other);
	}

	static inline uint8_t from_float_64__(double other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		auto r = std::llround(other);
		if (r < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
		return uint8_t(r);
#else
		return uint8_t(std::llround(other));
#endif
	}

	static inline int64_t to_int_64__(uint8_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(uint8_t other)
	{
		return other;
	}

	static inline double to_float_64__(uint8_t other)
	{
		return double(other);
	}

	static inline uint8_t modulo__(uint8_t x, uint8_t y)
	{
		return uint8_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return false;
	}

	static inline bool is_nan__(uint8_t number)
	{
		return false;
	}

	static inline bool is_inf__(uint8_t number)
	{
		return false;
	}

	static inline bool is_finite__(uint8_t number)
	{
		return true;
	}

	static inline bool is_normal__(uint8_t number)
	{
		return true;
	}
};

template <>
class number_u<int16_t>
{
public:
	static inline int16_t from_number__(number_a<> const& other)
	{
		return int16_t(other.to_int_64__());
	}

	static inline int16_t from_int_64__(int64_t other)
	{
		return int16_t(other);
	}

	static inline int16_t from_uint_64__(uint64_t other)
	{
		return int16_t(other);
	}

	static inline int16_t from_float_64__(double other)
	{
		return int16_t(std::llround(other));
	}

	static inline int64_t to_int_64__(int16_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(int16_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint64_t(other);
	}

	static inline double to_float_64__(int16_t other)
	{
		return double(other);
	}

	static inline int16_t modulo__(int16_t x, int16_t y)
	{
		return int16_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return true;
	}

	static inline bool is_nan__(int16_t number)
	{
		return false;
	}

	static inline bool is_inf__(int16_t number)
	{
		return false;
	}

	static inline bool is_finite__(int16_t number)
	{
		return true;
	}

	static inline bool is_normal__(int16_t number)
	{
		return true;
	}
};

template <>
class number_u<uint16_t>
{
public:
	static inline uint16_t from_number__(number_a<> const& other)
	{
		return uint16_t(other.to_uint_64__());
	}

	static inline uint16_t from_int_64__(int64_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint16_t(other);
	}

	static inline uint16_t from_uint_64__(uint64_t other)
	{
		return uint16_t(other);
	}

	static inline uint16_t from_float_64__(double other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		auto r = std::llround(other);
		if (r < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
		return uint16_t(r);
#else
		return uint16_t(std::llround(other));
#endif
	}

	static inline int64_t to_int_64__(uint16_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(uint16_t other)
	{
		return other;
	}

	static inline double to_float_64__(uint16_t other)
	{
		return double(other);
	}

	static inline uint16_t modulo__(uint16_t x, uint16_t y)
	{
		return uint16_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return false;
	}

	static inline bool is_nan__(uint16_t number)
	{
		return false;
	}

	static inline bool is_inf__(uint16_t number)
	{
		return false;
	}

	static inline bool is_finite__(uint16_t number)
	{
		return true;
	}

	static inline bool is_normal__(uint16_t number)
	{
		return true;
	}
};

template <>
class number_u<int32_t>
{
public:
	static inline int32_t from_number__(number_a<> const& other)
	{
		return int32_t(other.to_int_64__());
	}

	static inline int32_t from_int_64__(int64_t other)
	{
		return int32_t(other);
	}

	static inline int32_t from_uint_64__(uint64_t other)
	{
		return int32_t(other);
	}

	static inline int32_t from_float_64__(double other)
	{
		return int32_t(std::llround(other));
	}

	static inline int64_t to_int_64__(int32_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(int32_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint64_t(other);
	}

	static inline double to_float_64__(int32_t other)
	{
		return double(other);
	}

	static inline int32_t modulo__(int32_t x, int32_t y)
	{
		return int32_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return true;
	}

	static inline bool is_nan__(int32_t number)
	{
		return false;
	}

	static inline bool is_inf__(int32_t number)
	{
		return false;
	}

	static inline bool is_finite__(int32_t number)
	{
		return true;
	}

	static inline bool is_normal__(int32_t number)
	{
		return true;
	}
};

template <>
class number_u<uint32_t>
{
public:
	static inline uint32_t from_number__(number_a<> const& other)
	{
		return uint32_t(other.to_uint_64__());
	}

	static inline uint32_t from_int_64__(int64_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint32_t(other);
	}

	static inline uint32_t from_uint_64__(uint64_t other)
	{
		return uint32_t(other);
	}

	static inline uint32_t from_float_64__(double other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		auto r = std::llround(other);
		if (r < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
		return uint32_t(r);
#else
		return uint32_t(std::llround(other));
#endif
	}

	static inline int64_t to_int_64__(uint32_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(uint32_t other)
	{
		return other;
	}

	static inline double to_float_64__(uint32_t other)
	{
		return double(other);
	}

	static inline uint32_t modulo__(uint32_t x, uint32_t y)
	{
		return uint32_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return false;
	}

	static inline bool is_nan__(uint32_t number)
	{
		return false;
	}

	static inline bool is_inf__(uint32_t number)
	{
		return false;
	}

	static inline bool is_finite__(uint32_t number)
	{
		return true;
	}

	static inline bool is_normal__(uint32_t number)
	{
		return true;
	}
};

template <>
class number_u<int64_t>
{
public:
	static inline int64_t from_number__(number_a<> const& other)
	{
		return other.to_int_64__();
	}

	static inline int64_t from_int_64__(int64_t other)
	{
		return other;
	}

	static inline int64_t from_uint_64__(uint64_t other)
	{
		return int64_t(other);
	}

	static inline int64_t from_float_64__(double other)
	{
		return int64_t(std::llround(other));
	}

	static inline int64_t to_int_64__(int64_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64__(int64_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint64_t(other);
	}

	static inline double to_float_64__(int64_t other)
	{
		return double(other);
	}

	static inline int64_t modulo__(int64_t x, int64_t y)
	{
		return int64_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return true;
	}

	static inline bool is_nan__(int64_t number)
	{
		return false;
	}

	static inline bool is_inf__(int64_t number)
	{
		return false;
	}

	static inline bool is_finite__(int64_t number)
	{
		return true;
	}

	static inline bool is_normal__(int64_t number)
	{
		return true;
	}
};

template <>
class number_u<uint64_t>
{
public:
	static inline uint64_t from_number__(number_a<> const& other)
	{
		return other.to_uint_64__();
	}

	static inline uint64_t from_int_64__(int64_t other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		if (other < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
#endif
		return uint64_t(other);
	}

	static inline uint64_t from_uint_64__(uint64_t other)
	{
		return other;
	}

	static inline uint64_t from_float_64__(double other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		auto r = std::llround(other);
		if (r < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
		return uint64_t(r);
#else
		return uint64_t(std::llround(other));
#endif
	}

	static inline int64_t to_int_64__(uint64_t other)
	{
		return int64_t(other);
	}

	static inline uint64_t to_uint_64__(uint64_t other)
	{
		return other;
	}

	static inline double to_float_64__(uint64_t other)
	{
		return double(other);
	}

	static inline uint64_t modulo__(uint64_t x, uint64_t y)
	{
		return uint64_t(x % y);
	}

	static inline bool is_int__()
	{
		return true;
	}

	static inline bool is_signed__()
	{
		return false;
	}

	static inline bool is_nan__(uint64_t number)
	{
		return false;
	}

	static inline bool is_inf__(uint64_t number)
	{
		return false;
	}

	static inline bool is_finite__(uint64_t number)
	{
		return true;
	}

	static inline bool is_normal__(uint64_t number)
	{
		return true;
	}
};

template <>
class number_u<float>
{
public:
	static inline float from_number__(number_a<> const& other)
	{
		return float(other.to_float_64__());
	}

	static inline float from_int_64__(int64_t other)
	{
		return float(other);
	}

	static inline float from_uint_64__(uint64_t other)
	{
		return float(other);
	}

	static inline float from_float_64__(double other)
	{
		return float(other);
	}

	static inline int64_t to_int_64__(float other)
	{
		return std::llround(other);
	}

	static inline uint64_t to_uint_64__(float other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		auto r = std::llround(other);
		if (r < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
		return uint64_t(r);
#else
		return uint64_t(std::llround(other));
#endif
	}

	static inline double to_float_64__(float other)
	{
		return other;
	}

	static inline float modulo__(float x, float y)
	{
		return std::fmodf(x, y);
	}

	static inline bool is_int__()
	{
		return false;
	}

	static inline bool is_signed__()
	{
		return true;
	}

	static inline bool is_nan__(float number)
	{
		return std::isnan(number);
	}

	static inline bool is_inf__(float number)
	{
		return std::isinf(number);
	}

	static inline bool is_finite__(float number)
	{
		return std::isfinite(number);
	}

	static inline bool is_normal__(float number)
	{
		return std::isnormal(number);
	}
};

template <>
class number_u<double>
{
public:
	static inline double from_number__(number_a<> const& other)
	{
		return other.to_float_64__();
	}

	static inline double from_int_64__(int64_t other)
	{
		return double(other);
	}

	static inline double from_uint_64__(uint64_t other)
	{
		return double(other);
	}

	static inline double from_float_64__(double other)
	{
		return other;
	}

	static inline int64_t to_int_64__(double other)
	{
		return std::llround(other);
	}

	static inline uint64_t to_uint_64__(double other)
	{
#ifdef STRANGE_CHECK_UNSIGNED_CONVERSIONS
		auto r = std::llround(other);
		if (r < 0)
		{
			throw dis("conversion of negative number to unsigned integer");
		}
		return uint64_t(r);
#else
		return uint64_t(std::llround(other));
#endif
	}

	static inline double to_float_64__(double other)
	{
		return other;
	}

	static inline double modulo__(double x, double y)
	{
		return std::fmod(x, y);
	}

	static inline bool is_int__()
	{
		return false;
	}

	static inline bool is_signed__()
	{
		return true;
	}

	static inline bool is_nan__(double number)
	{
		return std::isnan(number);
	}

	static inline bool is_inf__(double number)
	{
		return std::isinf(number);
	}

	static inline bool is_finite__(double number)
	{
		return std::isfinite(number);
	}

	static inline bool is_normal__(double number)
	{
		return std::isnormal(number);
	}
};

} // namespace strange

#endif
