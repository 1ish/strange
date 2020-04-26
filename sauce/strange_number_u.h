#ifndef COM_ONEISH_STRANGE_NUMBER_U_H
#define COM_ONEISH_STRANGE_NUMBER_U_H

namespace strange
{

template <typename _primitive_>
class number_u
{
public:
	static inline std_string category();
	static inline _primitive_ from_number(number_a<> const& other);
	static inline _primitive_ from_int_64(int64_t other);
	static inline _primitive_ from_uint_64(uint64_t other);
	static inline _primitive_ from_float_64(double other);
	static inline int64_t to_int_64(_primitive_ other);
	static inline uint64_t to_uint_64(_primitive_ other);
	static inline double to_float_64(_primitive_ other);
	static inline _primitive_ modulo(_primitive_ x, _primitive_ y);
	static inline bool is_int();
	static inline bool is_signed();
	static inline bool is_nan(_primitive_ number);
	static inline bool is_inf(_primitive_ number);
	static inline bool is_finite(_primitive_ number);
	static inline bool is_normal(_primitive_ number);
};

template <>
class number_u<int8_t>
{
public:
	static inline std_string category()
	{
		return "int_8";
	}

	static inline int8_t from_number(number_a<> const& other)
	{
		return static_cast<int8_t>(other.to_int_64());
	}

	static inline int8_t from_int_64(int64_t other)
	{
		return static_cast<int8_t>(other);
	}

	static inline int8_t from_uint_64(uint64_t other)
	{
		return static_cast<int8_t>(other);
	}

	static inline int8_t from_float_64(double other)
	{
		return static_cast<int8_t>(std_llround(other));
	}

	static inline int64_t to_int_64(int8_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(int8_t other)
	{
		return static_cast<uint64_t>(other);
	}

	static inline double to_float_64(int8_t other)
	{
		return static_cast<double>(other);
	}

	static inline int8_t modulo(int8_t x, int8_t y)
	{
		return static_cast<int8_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return true;
	}

	static inline bool is_nan(int8_t number)
	{
		return false;
	}

	static inline bool is_inf(int8_t number)
	{
		return false;
	}

	static inline bool is_finite(int8_t number)
	{
		return true;
	}

	static inline bool is_normal(int8_t number)
	{
		return true;
	}
};

template <>
class number_u<uint8_t>
{
public:
	static inline std_string category()
	{
		return "uint_8";
	}

	static inline uint8_t from_number(number_a<> const& other)
	{
		return static_cast<uint8_t>(other.to_uint_64());
	}

	static inline uint8_t from_int_64(int64_t other)
	{
		return static_cast<uint8_t>(other);
	}

	static inline uint8_t from_uint_64(uint64_t other)
	{
		return static_cast<uint8_t>(other);
	}

	static inline uint8_t from_float_64(double other)
	{
		return static_cast<uint8_t>(std_llround(other));
	}

	static inline int64_t to_int_64(uint8_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(uint8_t other)
	{
		return other;
	}

	static inline double to_float_64(uint8_t other)
	{
		return static_cast<double>(other);
	}

	static inline uint8_t modulo(uint8_t x, uint8_t y)
	{
		return static_cast<uint8_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return false;
	}

	static inline bool is_nan(uint8_t number)
	{
		return false;
	}

	static inline bool is_inf(uint8_t number)
	{
		return false;
	}

	static inline bool is_finite(uint8_t number)
	{
		return true;
	}

	static inline bool is_normal(uint8_t number)
	{
		return true;
	}
};

template <>
class number_u<int16_t>
{
public:
	static inline std_string category()
	{
		return "int_16";
	}

	static inline int16_t from_number(number_a<> const& other)
	{
		return static_cast<int16_t>(other.to_int_64());
	}

	static inline int16_t from_int_64(int64_t other)
	{
		return static_cast<int16_t>(other);
	}

	static inline int16_t from_uint_64(uint64_t other)
	{
		return static_cast<int16_t>(other);
	}

	static inline int16_t from_float_64(double other)
	{
		return static_cast<int16_t>(std_llround(other));
	}

	static inline int64_t to_int_64(int16_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(int16_t other)
	{
		return static_cast<uint64_t>(other);
	}

	static inline double to_float_64(int16_t other)
	{
		return static_cast<double>(other);
	}

	static inline int16_t modulo(int16_t x, int16_t y)
	{
		return static_cast<int16_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return true;
	}

	static inline bool is_nan(int16_t number)
	{
		return false;
	}

	static inline bool is_inf(int16_t number)
	{
		return false;
	}

	static inline bool is_finite(int16_t number)
	{
		return true;
	}

	static inline bool is_normal(int16_t number)
	{
		return true;
	}
};

template <>
class number_u<uint16_t>
{
public:
	static inline std_string category()
	{
		return "uint_16";
	}

	static inline uint16_t from_number(number_a<> const& other)
	{
		return static_cast<uint16_t>(other.to_uint_64());
	}

	static inline uint16_t from_int_64(int64_t other)
	{
		return static_cast<uint16_t>(other);
	}

	static inline uint16_t from_uint_64(uint64_t other)
	{
		return static_cast<uint16_t>(other);
	}

	static inline uint16_t from_float_64(double other)
	{
		return static_cast<uint16_t>(std_llround(other));
	}

	static inline int64_t to_int_64(uint16_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(uint16_t other)
	{
		return other;
	}

	static inline double to_float_64(uint16_t other)
	{
		return static_cast<double>(other);
	}

	static inline uint16_t modulo(uint16_t x, uint16_t y)
	{
		return static_cast<uint16_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return false;
	}

	static inline bool is_nan(uint16_t number)
	{
		return false;
	}

	static inline bool is_inf(uint16_t number)
	{
		return false;
	}

	static inline bool is_finite(uint16_t number)
	{
		return true;
	}

	static inline bool is_normal(uint16_t number)
	{
		return true;
	}
};

template <>
class number_u<int32_t>
{
public:
	static inline std_string category()
	{
		return "int_32";
	}

	static inline int32_t from_number(number_a<> const& other)
	{
		return static_cast<int32_t>(other.to_int_64());
	}

	static inline int32_t from_int_64(int64_t other)
	{
		return static_cast<int32_t>(other);
	}

	static inline int32_t from_uint_64(uint64_t other)
	{
		return static_cast<int32_t>(other);
	}

	static inline int32_t from_float_64(double other)
	{
		return static_cast<int32_t>(std_llround(other));
	}

	static inline int64_t to_int_64(int32_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(int32_t other)
	{
		return static_cast<uint64_t>(other);
	}

	static inline double to_float_64(int32_t other)
	{
		return static_cast<double>(other);
	}

	static inline int32_t modulo(int32_t x, int32_t y)
	{
		return static_cast<int32_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return true;
	}

	static inline bool is_nan(int32_t number)
	{
		return false;
	}

	static inline bool is_inf(int32_t number)
	{
		return false;
	}

	static inline bool is_finite(int32_t number)
	{
		return true;
	}

	static inline bool is_normal(int32_t number)
	{
		return true;
	}
};

template <>
class number_u<uint32_t>
{
public:
	static inline std_string category()
	{
		return "uint_32";
	}

	static inline uint32_t from_number(number_a<> const& other)
	{
		return static_cast<uint32_t>(other.to_uint_64());
	}

	static inline uint32_t from_int_64(int64_t other)
	{
		return static_cast<uint32_t>(other);
	}

	static inline uint32_t from_uint_64(uint64_t other)
	{
		return static_cast<uint32_t>(other);
	}

	static inline uint32_t from_float_64(double other)
	{
		return static_cast<uint32_t>(std_llround(other));
	}

	static inline int64_t to_int_64(uint32_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(uint32_t other)
	{
		return other;
	}

	static inline double to_float_64(uint32_t other)
	{
		return static_cast<double>(other);
	}

	static inline uint32_t modulo(uint32_t x, uint32_t y)
	{
		return static_cast<uint32_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return false;
	}

	static inline bool is_nan(uint32_t number)
	{
		return false;
	}

	static inline bool is_inf(uint32_t number)
	{
		return false;
	}

	static inline bool is_finite(uint32_t number)
	{
		return true;
	}

	static inline bool is_normal(uint32_t number)
	{
		return true;
	}
};

template <>
class number_u<int64_t>
{
public:
	static inline std_string category()
	{
		return "int_64";
	}

	static inline int64_t from_number(number_a<> const& other)
	{
		return other.to_int_64();
	}

	static inline int64_t from_int_64(int64_t other)
	{
		return other;
	}

	static inline int64_t from_uint_64(uint64_t other)
	{
		return static_cast<int64_t>(other);
	}

	static inline int64_t from_float_64(double other)
	{
		return static_cast<int64_t>(std_llround(other));
	}

	static inline int64_t to_int_64(int64_t other)
	{
		return other;
	}

	static inline uint64_t to_uint_64(int64_t other)
	{
		return static_cast<uint64_t>(other);
	}

	static inline double to_float_64(int64_t other)
	{
		return static_cast<double>(other);
	}

	static inline int64_t modulo(int64_t x, int64_t y)
	{
		return static_cast<int64_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return true;
	}

	static inline bool is_nan(int64_t number)
	{
		return false;
	}

	static inline bool is_inf(int64_t number)
	{
		return false;
	}

	static inline bool is_finite(int64_t number)
	{
		return true;
	}

	static inline bool is_normal(int64_t number)
	{
		return true;
	}
};

template <>
class number_u<uint64_t>
{
public:
	static inline std_string category()
	{
		return "uint_64";
	}

	static inline uint64_t from_number(number_a<> const& other)
	{
		return other.to_uint_64();
	}

	static inline uint64_t from_int_64(int64_t other)
	{
		return static_cast<uint64_t>(other);
	}

	static inline uint64_t from_uint_64(uint64_t other)
	{
		return other;
	}

	static inline uint64_t from_float_64(double other)
	{
		return static_cast<uint64_t>(std_llround(other));
	}

	static inline int64_t to_int_64(uint64_t other)
	{
		return static_cast<int64_t>(other);
	}

	static inline uint64_t to_uint_64(uint64_t other)
	{
		return other;
	}

	static inline double to_float_64(uint64_t other)
	{
		return static_cast<double>(other);
	}

	static inline uint64_t modulo(uint64_t x, uint64_t y)
	{
		return static_cast<uint64_t>(x % y);
	}

	static inline bool is_int()
	{
		return true;
	}

	static inline bool is_signed()
	{
		return false;
	}

	static inline bool is_nan(uint64_t number)
	{
		return false;
	}

	static inline bool is_inf(uint64_t number)
	{
		return false;
	}

	static inline bool is_finite(uint64_t number)
	{
		return true;
	}

	static inline bool is_normal(uint64_t number)
	{
		return true;
	}
};

template <>
class number_u<float>
{
public:
	static inline std_string category()
	{
		return "float_32";
	}

	static inline float from_number(number_a<> const& other)
	{
		return static_cast<float>(other.to_float_64());
	}

	static inline float from_int_64(int64_t other)
	{
		return static_cast<float>(other);
	}

	static inline float from_uint_64(uint64_t other)
	{
		return static_cast<float>(other);
	}

	static inline float from_float_64(double other)
	{
		return static_cast<float>(other);
	}

	static inline int64_t to_int_64(float other)
	{
		return std_llround(other);
	}

	static inline uint64_t to_uint_64(float other)
	{
		return static_cast<uint64_t>(std_llround(other));
	}

	static inline double to_float_64(float other)
	{
		return other;
	}

	static inline float modulo(float x, float y)
	{
		return std::fmod(x, y);
	}

	static inline bool is_int()
	{
		return false;
	}

	static inline bool is_signed()
	{
		return true;
	}

	static inline bool is_nan(float number)
	{
		return std::isnan(number);
	}

	static inline bool is_inf(float number)
	{
		return std::isinf(number);
	}

	static inline bool is_finite(float number)
	{
		return std::isfinite(number);
	}

	static inline bool is_normal(float number)
	{
		return std::isnormal(number);
	}
};

template <>
class number_u<double>
{
public:
	static inline std_string category()
	{
		return "float_64";
	}

	static inline double from_number(number_a<> const& other)
	{
		return other.to_float_64();
	}

	static inline double from_int_64(int64_t other)
	{
		return static_cast<double>(other);
	}

	static inline double from_uint_64(uint64_t other)
	{
		return static_cast<double>(other);
	}

	static inline double from_float_64(double other)
	{
		return other;
	}

	static inline int64_t to_int_64(double other)
	{
		return std_llround(other);
	}

	static inline uint64_t to_uint_64(double other)
	{
		return static_cast<uint64_t>(std_llround(other));
	}

	static inline double to_float_64(double other)
	{
		return other;
	}

	static inline double modulo(double x, double y)
	{
		return std::fmod(x, y);
	}

	static inline bool is_int()
	{
		return false;
	}

	static inline bool is_signed()
	{
		return true;
	}

	static inline bool is_nan(double number)
	{
		return std::isnan(number);
	}

	static inline bool is_inf(double number)
	{
		return std::isinf(number);
	}

	static inline bool is_finite(double number)
	{
		return std::isfinite(number);
	}

	static inline bool is_normal(double number)
	{
		return std::isnormal(number);
	}
};

} // namespace strange

#endif
