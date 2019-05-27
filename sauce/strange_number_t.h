#ifndef COM_ONEISH_STRANGE_NUMBER_T_H
#define COM_ONEISH_STRANGE_NUMBER_T_H

namespace strange
{

template <typename PRIMITIVE, typename _ABSTRACTION_ = number_data_a<PRIMITIVE>>
class number_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline number_data_a<PRIMITIVE> val_()
	{
		return val(PRIMITIVE{});
	}

	static inline number_data_a<PRIMITIVE> val(PRIMITIVE primitive)
	{
		return number_data_a<PRIMITIVE>{ number_t<PRIMITIVE, _ABSTRACTION_>{ primitive } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<number_t<PRIMITIVE>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<number_t<PRIMITIVE>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<number_a<>>(thing))
		{
			return false;
		}
		return _number == number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
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

	inline number_t& operator++()
	{
		++_number;
		return *this;
	}

	inline number_t operator++(int)
	{
		number_t result = *this;
		operator++();
		return result;
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

	inline number_t& operator--()
	{
		--_number;
		return *this;
	}

	inline number_t operator--(int)
	{
		number_t result = *this;
		operator--();
		return result;
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator+=(thing);
		}
		return me_();
	}

	inline number_a<> self_add_(number_a<> const& number)
	{
		_number += number_u<PRIMITIVE>::from_number(number);
		return me_();
	}

	inline number_t& operator+=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number += passed non-number");
		}
		_number += number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
		return *this;
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		number_a<> result = me_();
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
		_ABSTRACTION_ result = me_();
		result.reference() += number_u<PRIMITIVE>::from_number(number);
		return result;
	}

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator-=(thing);
		}
		return me_();
	}

	inline number_a<> self_subtract_(number_a<> const& number)
	{
		_number -= number_u<PRIMITIVE>::from_number(number);
		return me_();
	}

	inline number_t& operator-=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number -= passed non-number");
		}
		_number -= number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
		return *this;
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		number_a<> result = me_();
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
		_ABSTRACTION_ result = me_();
		result.reference() -= number_u<PRIMITIVE>::from_number(number);
		return result;
	}

	inline any_a<> self_multiply__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator*=(thing);
		}
		return me_();
	}

	inline number_a<> self_multiply_(number_a<> const& number)
	{
		_number *= number_u<PRIMITIVE>::from_number(number);
		return me_();
	}

	inline number_t& operator*=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number *= passed non-number");
		}
		_number *= number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
		return *this;
	}

	inline any_a<> multiply__(range_a<> const& range) const
	{
		number_a<> result = me_();
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
		_ABSTRACTION_ result = me_();
		result.reference() *= number_u<PRIMITIVE>::from_number(number);
		return result;
	}

	inline any_a<> self_divide__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator/=(thing);
		}
		return me_();
	}

	inline number_a<> self_divide_(number_a<> const& number)
	{
		PRIMITIVE num = number_u<PRIMITIVE>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number self_divide division by zero");
		}
		_number /= num;
		return me_();
	}

	inline number_t& operator/=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number /= passed non-number");
		}
		PRIMITIVE num = number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
		if (num == 0)
		{
			throw dis("strange::number /= division by zero");
		}
		_number /= num;
		return *this;
	}

	inline any_a<> divide__(range_a<> const& range) const
	{
		number_a<> result = me_();
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
		PRIMITIVE num = number_u<PRIMITIVE>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number / division by zero");
		}
		_ABSTRACTION_ result = me_();
		result.reference() /= num;
		return result;
	}

	inline any_a<> self_modulo__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator%=(thing);
		}
		return me_();
	}

	inline number_a<> self_modulo_(number_a<> const& number)
	{
		PRIMITIVE num = number_u<PRIMITIVE>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number self_modulo division by zero");
		}
		_number = number_u<PRIMITIVE>::modulo(_number, num);
		return me_();
	}

	inline number_t& operator%=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number %= passed non-number");
		}
		PRIMITIVE num = number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
		if (num == 0)
		{
			throw dis("strange::number %= division by zero");
		}
		_number = number_u<PRIMITIVE>::modulo(_number, num);
		return *this;
	}

	inline any_a<> modulo__(range_a<> const& range) const
	{
		number_a<> result = me_();
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
		PRIMITIVE num = number_u<PRIMITIVE>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number % division by zero");
		}
		return val(number_u<PRIMITIVE>::modulo(_number, num));
	}

	inline any_a<> to_int_64__(range_a<> const& _) const
	{
		return to_int_64_();
	}

	inline number_data_a<int64_t> to_int_64_() const
	{
		return number_t<int64_t>::val(to_int_64());
	}

	inline int64_t to_int_64() const
	{
		return number_u<PRIMITIVE>::to_int_64(_number);
	}

	inline any_a<> from_int_64__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::from_int_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_data_a<int64_t>>(thing))
		{
			throw dis("strange::number::from_int_64 passed wrong type of thing");
		}
		return from_int_64_(cast<number_data_a<int64_t>>(thing));
	}

	inline any_a<> from_int_64_(number_data_a<int64_t> const& int_64)
	{
		from_int_64(int_64.extract());
		return me_();
	}

	inline void from_int_64(int64_t int_64)
	{
		_number = number_u<PRIMITIVE>::from_int_64(int_64);
	}

	inline any_a<> to_uint_64__(range_a<> const& _) const
	{
		return to_uint_64_();
	}

	inline number_data_a<uint64_t> to_uint_64_() const
	{
		return number_t<uint64_t>::val(to_uint_64());
	}

	inline uint64_t to_uint_64() const
	{
		return number_u<PRIMITIVE>::to_uint_64(_number);
	}

	inline any_a<> from_uint_64__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::from_uint_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_data_a<uint64_t>>(thing))
		{
			throw dis("strange::number::from_uint_64 passed wrong type of thing");
		}
		return from_uint_64_(cast<number_data_a<uint64_t>>(thing));
	}

	inline any_a<> from_uint_64_(number_data_a<uint64_t> const& uint_64)
	{
		from_uint_64(uint_64.extract());
		return me_();
	}

	inline void from_uint_64(uint64_t uint_64)
	{
		_number = number_u<PRIMITIVE>::from_uint_64(uint_64);
	}

	inline any_a<> to_float_64__(range_a<> const& _) const
	{
		return to_float_64_();
	}

	inline number_data_a<double> to_float_64_() const
	{
		return number_t<double>::val(to_float_64());
	}

	inline double to_float_64() const
	{
		return number_u<PRIMITIVE>::to_float_64(_number);
	}

	inline any_a<> from_float_64__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::from_float_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_data_a<double>>(thing))
		{
			throw dis("strange::number::from_float_64 passed wrong type of thing");
		}
		return from_float_64_(cast<number_data_a<double>>(thing));
	}

	inline any_a<> from_float_64_(number_data_a<double> const& float_64)
	{
		from_float_64(float_64.extract());
		return me_();
	}

	inline void from_float_64(double float_64)
	{
		_number = number_u<PRIMITIVE>::from_float_64(float_64);
	}

	inline any_a<> less_than__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::less_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number::less_than passed non-number");
		}
		return less_than_(cast<number_a<>>(thing));
	}

	inline any_a<> less_than_(number_a<> const& number) const
	{
		return boole(operator<(number));
	}

	inline bool operator<(number_a<> const& number) const
	{
		return _number < number_u<PRIMITIVE>::from_number(number);
	}

	inline any_a<> greater_than__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::greater_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number::greater_than passed non-number");
		}
		return greater_than_(cast<number_a<>>(thing));
	}

	inline any_a<> greater_than_(number_a<> const& number) const
	{
		return boole(operator>(number));
	}

	inline bool operator>(number_a<> const& number) const
	{
		return _number > number_u<PRIMITIVE>::from_number(number);
	}

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::less_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number::less_or_equal passed non-number");
		}
		return less_or_equal_(cast<number_a<>>(thing));
	}

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{
		return boole(operator<=(number));
	}

	inline bool operator<=(number_a<> const& number) const
	{
		return _number <= number_u<PRIMITIVE>::from_number(number);
	}

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number::greater_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number::greater_or_equal passed non-number");
		}
		return greater_or_equal_(cast<number_a<>>(thing));
	}

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{
		return boole(operator>=(number));
	}

	inline bool operator>=(number_a<> const& number) const
	{
		return _number >= number_u<PRIMITIVE>::from_number(number);
	}

	static inline any_a<> byte_size__(range_a<> const& _)
	{
		return byte_size_();
	}

	static inline number_data_a<int64_t> byte_size_()
	{
		return number_t<int64_t>::val(byte_size());
	}

	static inline int64_t byte_size()
	{
		return int64_t(sizeof(_number));
	}

	static inline any_a<> is_int__(range_a<> const& _)
	{
		return is_int_();
	}

	static inline any_a<> is_int_()
	{
		return boole(is_int());
	}

	static inline bool is_int()
	{
		return number_u<PRIMITIVE>::is_int();
	}

	static inline any_a<> is_signed__(range_a<> const& _)
	{
		return is_signed_();
	}

	static inline any_a<> is_signed_()
	{
		return boole(is_signed());
	}

	static inline bool is_signed()
	{
		return number_u<PRIMITIVE>::is_signed();
	}

	inline any_a<> is_nan__(range_a<> const& _) const
	{
		return is_nan_();
	}

	inline any_a<> is_nan_() const
	{
		return boole(is_nan());
	}

	inline bool is_nan() const
	{
		return number_u<PRIMITIVE>::is_nan(_number);
	}

	inline any_a<> is_inf__(range_a<> const& _) const
	{
		return is_inf_();
	}

	inline any_a<> is_inf_() const
	{
		return boole(is_inf());
	}

	inline bool is_inf() const
	{
		return number_u<PRIMITIVE>::is_inf(_number);
	}

	inline any_a<> is_finite__(range_a<> const& _) const
	{
		return is_finite_();
	}

	inline any_a<> is_finite_() const
	{
		return boole(is_finite());
	}

	inline bool is_finite() const
	{
		return number_u<PRIMITIVE>::is_finite(_number);
	}

	inline any_a<> is_normal__(range_a<> const& _) const
	{
		return is_normal_();
	}

	inline any_a<> is_normal_() const
	{
		return boole(is_normal());
	}

	inline bool is_normal() const
	{
		return number_u<PRIMITIVE>::is_normal(_number);
	}

	static inline any_a<> little_endian__(range_a<> const& _)
	{
		return little_endian_();
	}

	static inline any_a<> little_endian_()
	{
		return boole(little_endian());
	}

	static inline bool little_endian()
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
	PRIMITIVE _number;

	inline number_t(PRIMITIVE number)
		: thing_t{}
		, _number(number)
	{}
};

template <typename _ABSTRACTION_ = number_data_a<int8_t>>
using number_int_8_t = number_t<int8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint8_t>>
using number_uint_8_t = number_t<uint8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<int16_t>>
using number_int_16_t = number_t<int16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint16_t>>
using number_uint_16_t = number_t<uint16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<int32_t>>
using number_int_32_t = number_t<int32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint32_t>>
using number_uint_32_t = number_t<uint32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<int64_t>>
using number_int_64_t = number_t<int64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<uint64_t>>
using number_uint_64_t = number_t<uint64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<float>>
using number_float_32_t = number_t<float, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = number_data_a<double>>
using number_float_64_t = number_t<double, _ABSTRACTION_>;

} // namespace strange

#endif
