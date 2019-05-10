#ifndef COM_ONEISH_STRANGE_NUMBER_REFERENCE_T_H
#define COM_ONEISH_STRANGE_NUMBER_REFERENCE_T_H

namespace strange
{

template <typename PRIMITIVE, typename _ABSTRACTION_ = number_data_a<PRIMITIVE>>
class number_reference_t : public something_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline number_data_a<PRIMITIVE> val(PRIMITIVE& primitive)
	{
		return number_data_a<PRIMITIVE>{ number_reference_t<PRIMITIVE, _ABSTRACTION_>{ primitive } };
	}

	static inline number_data_a<PRIMITIVE> ref(PRIMITIVE& primitive)
	{
		return number_data_a<PRIMITIVE>(number_reference_t<PRIMITIVE, _ABSTRACTION_>{ primitive }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::number_reference");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check_<number_a<>>(thing))
		{
			return false;
		}
		return _number == number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<number_a<>>(thing))
		{
			return true;
		}
		return _number != number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
	}

	inline std::size_t hash() const
	{
		return std::hash<PRIMITIVE>{}(_number);
	}

	// number
	inline _ABSTRACTION_ increment__(range_a<> const&)
	{
		return increment_();
	}

	inline _ABSTRACTION_ increment_()
	{
		operator++();
		return me_();
	}

	inline number_reference_t& operator++()
	{
		++_number;
		return *this;
	}

	inline void operator++(int)
	{
		++_number;
	}

	inline any_a<> decrement__(range_a<> const& _)
	{
		return decrement_();
	}

	inline number_a<> decrement_()
	{
		operator--();
		return me_();
	}

	inline number_reference_t& operator--()
	{
		--_number;
		return *this;
	}

	inline void operator--(int)
	{
		--_number;
	}

	inline any_a<> self_add(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator+=(thing);
		}
		return me_();
	}

	inline number_a<> self_add_(number_a<> const& number)
	{
		_number += number_u<PRIMITIVE>::from_number__(number);
		return me_();
	}

	inline number_reference_t& operator+=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference += passed non-number");
		}
		_number += number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		return *this;
	}

	inline any_a<> add(range_a<> const& range) const
	{
		number_a<> result = number_t<PRIMITIVE>::val(_number);
		for (auto const& thing : range)
		{
			result += thing;
		}
		return result;
	}

	inline number_a<> add_(number_a<> const& number) const
	{
		return operator+(number);
	}

	inline number_a<> operator+(number_a<> const& number) const
	{
		number_data_a<PRIMITIVE> result = number_t<PRIMITIVE>::val(_number);
		result.reference() += number_u<PRIMITIVE>::from_number__(number);
		return result;
	}

	inline any_a<> self_subtract(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator-=(thing);
		}
		return me_();
	}

	inline number_a<> self_subtract_(number_a<> const& number)
	{
		_number -= number_u<PRIMITIVE>::from_number__(number);
		return me_();
	}

	inline number_reference_t& operator-=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference -= passed non-number");
		}
		_number -= number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		return *this;
	}

	inline any_a<> subtract(range_a<> const& range) const
	{
		number_a<> result = number_t<PRIMITIVE>::val(_number);
		for (auto const& thing : range)
		{
			result -= thing;
		}
		return result;
	}

	inline number_a<> subtract_(number_a<> const& number) const
	{
		return operator-(number);
	}

	inline number_a<> operator-(number_a<> const& number) const
	{
		number_data_a<PRIMITIVE> result = number_t<PRIMITIVE>::val(_number);
		result.reference() -= number_u<PRIMITIVE>::from_number__(number);
		return result;
	}

	inline any_a<> self_multiply(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator*=(thing);
		}
		return me_();
	}

	inline number_a<> self_multiply_(number_a<> const& number)
	{
		_number *= number_u<PRIMITIVE>::from_number__(number);
		return me_();
	}

	inline number_reference_t& operator*=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference *= passed non-number");
		}
		_number *= number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		return *this;
	}

	inline any_a<> multiply(range_a<> const& range) const
	{
		number_a<> result = number_t<PRIMITIVE>::val(_number);
		for (auto const& thing : range)
		{
			result *= thing;
		}
		return result;
	}

	inline number_a<> multiply_(number_a<> const& number) const
	{
		return operator*(number);
	}

	inline number_a<> operator*(number_a<> const& number) const
	{
		number_data_a<PRIMITIVE> result = number_t<PRIMITIVE>::val(_number);
		result.reference() *= number_u<PRIMITIVE>::from_number__(number);
		return result;
	}

	inline any_a<> self_divide(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator/=(thing);
		}
		return me_();
	}

	inline number_a<> self_divide_(number_a<> const& number)
	{
		PRIMITIVE num = number_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis("strange::number_reference self_divide division by zero");
		}
		_number /= num;
		return me_();
	}

	inline number_reference_t& operator/=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference /= passed non-number");
		}
		PRIMITIVE num = number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		if (num == 0)
		{
			throw dis("strange::number_reference /= division by zero");
		}
		_number /= num;
		return *this;
	}

	inline any_a<> divide(range_a<> const& range) const
	{
		number_a<> result = number_t<PRIMITIVE>::val(_number);
		for (auto const& thing : range)
		{
			result /= thing;
		}
		return result;
	}

	inline number_a<> divide_(number_a<> const& number) const
	{
		return operator/(number);
	}

	inline number_a<> operator/(number_a<> const& number) const
	{
		PRIMITIVE num = number_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis("strange::number_reference / division by zero");
		}
		_ABSTRACTION_ result = number_t<PRIMITIVE>::val(_number);
		result.reference() /= num;
		return result;
	}

	inline any_a<> self_modulo(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator%=(thing);
		}
		return me_();
	}

	inline number_a<> self_modulo_(number_a<> const& number)
	{
		PRIMITIVE num = number_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis("strange::number_reference self_modulo division by zero");
		}
		_number = number_u<PRIMITIVE>::modulo__(_number, num);
		return me_();
	}

	inline number_reference_t& operator%=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference %= passed non-number");
		}
		PRIMITIVE num = number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		if (num == 0)
		{
			throw dis("strange::number_reference %= division by zero");
		}
		_number = number_u<PRIMITIVE>::modulo__(_number, num);
		return *this;
	}

	inline any_a<> modulo(range_a<> const& range) const
	{
		number_a<> result = number_t<PRIMITIVE>::val(_number);
		for (auto const& thing : range)
		{
			result %= thing;
		}
		return result;
	}

	inline number_a<> modulo_(number_a<> const& number) const
	{
		return operator%(number);
	}

	inline number_a<> operator%(number_a<> const& number) const
	{
		PRIMITIVE num = number_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis("strange::number_reference % division by zero");
		}
		return number_t<PRIMITIVE>::val(number_u<PRIMITIVE>::modulo__(_number, num));
	}

	inline any_a<> to_int_64(range_a<> const& _) const
	{
		return to_int_64_();
	}

	inline number_data_a<int64_t> to_int_64_() const
	{
		return number_t<int64_t>::val(to_int_64__());
	}

	inline int64_t to_int_64__() const
	{
		return number_u<PRIMITIVE>::to_int_64__(_number);
	}

	inline any_a<> from_int_64(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::from_int_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_data_a<int64_t>>(thing))
		{
			throw dis("strange::number_reference::from_int_64 passed wrong type of thing");
		}
		return from_int_64_(cast_<number_data_a<int64_t>>(thing));
	}

	inline any_a<> from_int_64_(number_data_a<int64_t> const& int_64)
	{
		from_int_64__(int_64.extract());
		return me_();
	}

	inline void from_int_64__(int64_t int_64)
	{
		_number = number_u<PRIMITIVE>::from_int_64__(int_64);
	}

	inline any_a<> to_uint_64(range_a<> const& _) const
	{
		return to_uint_64_();
	}

	inline number_data_a<uint64_t> to_uint_64_() const
	{
		return number_t<uint64_t>::val(to_uint_64__());
	}

	inline uint64_t to_uint_64__() const
	{
		return number_u<PRIMITIVE>::to_uint_64__(_number);
	}

	inline any_a<> from_uint_64(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::from_uint_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_data_a<uint64_t>>(thing))
		{
			throw dis("strange::number_reference::from_uint_64 passed wrong type of thing");
		}
		return from_uint_64_(cast_<number_data_a<uint64_t>>(thing));
	}

	inline any_a<> from_uint_64_(number_data_a<uint64_t> const& uint_64)
	{
		from_uint_64__(uint_64.extract());
		return me_();
	}

	inline void from_uint_64__(uint64_t uint_64)
	{
		_number = number_u<PRIMITIVE>::from_uint_64__(uint_64);
	}

	inline any_a<> to_float_64(range_a<> const& _) const
	{
		return to_float_64_();
	}

	inline number_data_a<double> to_float_64_() const
	{
		return number_t<double>::val(to_float_64__());
	}

	inline double to_float_64__() const
	{
		return number_u<PRIMITIVE>::to_float_64__(_number);
	}

	inline any_a<> from_float_64(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::from_float_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_data_a<double>>(thing))
		{
			throw dis("strange::number_reference::from_float_64 passed wrong type of thing");
		}
		return from_float_64_(cast_<number_data_a<double>>(thing));
	}

	inline any_a<> from_float_64_(number_data_a<double> const& float_64)
	{
		from_float_64__(float_64.extract());
		return me_();
	}

	inline void from_float_64__(double float_64)
	{
		_number = number_u<PRIMITIVE>::from_float_64__(float_64);
	}

	inline any_a<> less_than(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::less_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference::less_than passed non-number");
		}
		return less_than_(cast_<number_a<>>(thing));
	}

	inline any_a<> less_than_(number_a<> const& number) const
	{
		return _boole_(operator<(number));
	}

	inline bool operator<(number_a<> const& number) const
	{
		return _number < number_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> greater_than(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::greater_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference::greater_than passed non-number");
		}
		return greater_than_(cast_<number_a<>>(thing));
	}

	inline any_a<> greater_than_(number_a<> const& number) const
	{
		return _boole_(operator>(number));
	}

	inline bool operator>(number_a<> const& number) const
	{
		return _number > number_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> less_or_equal(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::less_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference::less_or_equal passed non-number");
		}
		return less_or_equal_(cast_<number_a<>>(thing));
	}

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{
		return _boole_(operator<=(number));
	}

	inline bool operator<=(number_a<> const& number) const
	{
		return _number <= number_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> greater_or_equal(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::number_reference::greater_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis("strange::number_reference::greater_or_equal passed non-number");
		}
		return greater_or_equal_(cast_<number_a<>>(thing));
	}

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{
		return _boole_(operator>=(number));
	}

	inline bool operator>=(number_a<> const& number) const
	{
		return _number >= number_u<PRIMITIVE>::from_number__(number);
	}

	static inline any_a<> byte_size(range_a<> const& _)
	{
		return byte_size_();
	}

	static inline number_data_a<int64_t> byte_size_()
	{
		return number_t<int64_t>::val(byte_size__());
	}

	static inline int64_t byte_size__()
	{
		return int64_t(sizeof(_number));
	}

	static inline any_a<> is_int(range_a<> const& _)
	{
		return is_int_();
	}

	static inline any_a<> is_int_()
	{
		return _boole_(is_int__());
	}

	static inline bool is_int__()
	{
		return number_u<PRIMITIVE>::is_int__();
	}

	static inline any_a<> is_signed(range_a<> const& _)
	{
		return is_signed_();
	}

	static inline any_a<> is_signed_()
	{
		return _boole_(is_signed__());
	}

	static inline bool is_signed__()
	{
		return number_u<PRIMITIVE>::is_signed__();
	}

	inline any_a<> is_nan(range_a<> const& _) const
	{
		return is_nan_();
	}

	inline any_a<> is_nan_() const
	{
		return _boole_(is_nan__());
	}

	inline bool is_nan__() const
	{
		return number_u<PRIMITIVE>::is_nan__(_number);
	}

	inline any_a<> is_inf(range_a<> const& _) const
	{
		return is_inf_();
	}

	inline any_a<> is_inf_() const
	{
		return _boole_(is_inf__());
	}

	inline bool is_inf__() const
	{
		return number_u<PRIMITIVE>::is_inf__(_number);
	}

	inline any_a<> is_finite(range_a<> const& _) const
	{
		return is_finite_();
	}

	inline any_a<> is_finite_() const
	{
		return _boole_(is_finite__());
	}

	inline bool is_finite__() const
	{
		return number_u<PRIMITIVE>::is_finite__(_number);
	}

	inline any_a<> is_normal(range_a<> const& _) const
	{
		return is_normal_();
	}

	inline any_a<> is_normal_() const
	{
		return _boole_(is_normal__());
	}

	inline bool is_normal__() const
	{
		return number_u<PRIMITIVE>::is_normal__(_number);
	}

	static inline any_a<> little_endian(range_a<> const& _)
	{
		return little_endian_();
	}

	static inline any_a<> little_endian_()
	{
		return _boole_(little_endian__());
	}

	static inline bool little_endian__()
	{
		union
		{
			uint32_t i;
			char c[4];
		} bint = { 0x01020304 };
		return bint.c[0] != 1;
	}

	// data
	inline PRIMITIVE const& extract() const
	{
		return _number;
	}

	inline void mutate(PRIMITIVE const& data)
	{
		_number = data;
	}

	inline PRIMITIVE& reference()
	{
		return _number;
	}

protected:
	PRIMITIVE& _number;

	inline number_reference_t(PRIMITIVE& number)
		: something_t{}
		, _number(number)
	{}
};

template <typename _ABSTRACTION_ = number_data_a<int8_t>>
using number_reference_int_8_t = number_reference_t<int8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint8_t>>
using number_reference_uint_8_t = number_reference_t<uint8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<int16_t>>
using number_reference_int_16_t = number_reference_t<int16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint16_t>>
using number_reference_uint_16_t = number_reference_t<uint16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<int32_t>>
using number_reference_int_32_t = number_reference_t<int32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint32_t>>
using number_reference_uint_32_t = number_reference_t<uint32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<int64_t>>
using number_reference_int_64_t = number_reference_t<int64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint64_t>>
using number_reference_uint_64_t = number_reference_t<uint64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<float>>
using number_reference_float_32_t = number_reference_t<float, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<double>>
using number_reference_float_64_t = number_reference_t<double, _ABSTRACTION_>;

} // namespace strange

#endif
