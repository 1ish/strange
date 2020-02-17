#ifndef COM_ONEISH_STRANGE_NUMBER_REFERENCE_T_H
#define COM_ONEISH_STRANGE_NUMBER_REFERENCE_T_H

namespace strange
{

template <typename _primitive_, typename ___ego___ = number_data_a<_primitive_>>
class number_reference_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<number_reference_t<_primitive_>>;

	// construction
	static inline number_data_a<_primitive_> create(_primitive_& primitive)
	{
		return number_data_a<_primitive_>{ over{ number_reference_t<_primitive_>{ primitive } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<number_reference_t<_primitive_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<number_a<>>(thing))
		{
			return false;
		}
		return _number == number_u<_primitive_>::from_number(cast<number_a<>>(thing));
	}

	inline std::size_t hash() const
	{
		return std::hash<_primitive_>{}(_number);
	}

	// number
	inline ___ego___ increment__(range_a<> const&)
	{
		return increment_();
	}

	inline ___ego___ increment_()
	{
		operator++();
		return thing_t<___ego___>::me_();
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
		return thing_t<___ego___>::me_();
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

	inline any_a<> self_assign__(range_a<> const& range)
	{
		auto const it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference self_assign passed empty range");
		}
		auto const number = *it;
		if (!check<number_a<>>(number))
		{
			throw dis("strange::number_reference self_assign passed non-number");
		}
		return self_assign_(cast<number_a<>>(number));
	}
	
	inline number_a<> self_assign_(number_a<> const& number)
	{
		_number = number_u<_primitive_>::from_number(number);
		return thing_t<___ego___>::me_();
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator+=(thing);
		}
		return thing_t<___ego___>::me_();
	}

	inline number_a<> self_add_(number_a<> const& number)
	{
		_number += number_u<_primitive_>::from_number(number);
		return thing_t<___ego___>::me_();
	}

	inline number_reference_t& operator+=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference += passed non-number");
		}
		_number += number_u<_primitive_>::from_number(cast<number_a<>>(thing));
		return *this;
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		number_a<> result = number_t<_primitive_>::create(_number);
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
		number_data_a<_primitive_> result = number_t<_primitive_>::create(_number);
		result.mutate_primitive() += number_u<_primitive_>::from_number(number);
		return result;
	}

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator-=(thing);
		}
		return thing_t<___ego___>::me_();
	}

	inline number_a<> self_subtract_(number_a<> const& number)
	{
		_number -= number_u<_primitive_>::from_number(number);
		return thing_t<___ego___>::me_();
	}

	inline number_reference_t& operator-=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference -= passed non-number");
		}
		_number -= number_u<_primitive_>::from_number(cast<number_a<>>(thing));
		return *this;
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		number_a<> result = number_t<_primitive_>::create(_number);
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
		number_data_a<_primitive_> result = number_t<_primitive_>::create(_number);
		result.mutate_primitive() -= number_u<_primitive_>::from_number(number);
		return result;
	}

	inline any_a<> self_multiply__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator*=(thing);
		}
		return thing_t<___ego___>::me_();
	}

	inline number_a<> self_multiply_(number_a<> const& number)
	{
		_number *= number_u<_primitive_>::from_number(number);
		return thing_t<___ego___>::me_();
	}

	inline number_reference_t& operator*=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference *= passed non-number");
		}
		_number *= number_u<_primitive_>::from_number(cast<number_a<>>(thing));
		return *this;
	}

	inline any_a<> multiply__(range_a<> const& range) const
	{
		number_a<> result = number_t<_primitive_>::create(_number);
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
		number_data_a<_primitive_> result = number_t<_primitive_>::create(_number);
		result.mutate_primitive() *= number_u<_primitive_>::from_number(number);
		return result;
	}

	inline any_a<> self_divide__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator/=(thing);
		}
		return thing_t<___ego___>::me_();
	}

	inline number_a<> self_divide_(number_a<> const& number)
	{
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number_reference self_divide division by zero");
		}
		_number /= num;
		return thing_t<___ego___>::me_();
	}

	inline number_reference_t& operator/=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference /= passed non-number");
		}
		_primitive_ num = number_u<_primitive_>::from_number(cast<number_a<>>(thing));
		if (num == 0)
		{
			throw dis("strange::number_reference /= division by zero");
		}
		_number /= num;
		return *this;
	}

	inline any_a<> divide__(range_a<> const& range) const
	{
		number_a<> result = number_t<_primitive_>::create(_number);
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
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number_reference / division by zero");
		}
		___ego___ result = number_t<_primitive_>::create(_number);
		result.mutate_primitive() /= num;
		return result;
	}

	inline any_a<> self_modulo__(range_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator%=(thing);
		}
		return thing_t<___ego___>::me_();
	}

	inline number_a<> self_modulo_(number_a<> const& number)
	{
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number_reference self_modulo division by zero");
		}
		_number = number_u<_primitive_>::modulo(_number, num);
		return thing_t<___ego___>::me_();
	}

	inline number_reference_t& operator%=(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference %= passed non-number");
		}
		_primitive_ num = number_u<_primitive_>::from_number(cast<number_a<>>(thing));
		if (num == 0)
		{
			throw dis("strange::number_reference %= division by zero");
		}
		_number = number_u<_primitive_>::modulo(_number, num);
		return *this;
	}

	inline any_a<> modulo__(range_a<> const& range) const
	{
		number_a<> result = number_t<_primitive_>::create(_number);
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
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number_reference % division by zero");
		}
		return number_t<_primitive_>::create(number_u<_primitive_>::modulo(_number, num));
	}

	inline any_a<> to_int_64__(range_a<> const& _) const
	{
		return to_int_64_();
	}

	inline number_data_a<int64_t> to_int_64_() const
	{
		return number_t<int64_t>::create(to_int_64());
	}

	inline int64_t to_int_64() const
	{
		return number_u<_primitive_>::to_int_64(_number);
	}

	inline any_a<> from_int_64__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::from_int_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_data_a<int64_t>>(thing))
		{
			throw dis("strange::number_reference::from_int_64 passed wrong type of thing");
		}
		return from_int_64_(cast<number_data_a<int64_t>>(thing));
	}

	inline any_a<> from_int_64_(number_data_a<int64_t> const& int_64)
	{
		from_int_64(int_64.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void from_int_64(int64_t int_64)
	{
		_number = number_u<_primitive_>::from_int_64(int_64);
	}

	inline any_a<> to_uint_64__(range_a<> const& _) const
	{
		return to_uint_64_();
	}

	inline number_data_a<uint64_t> to_uint_64_() const
	{
		return number_t<uint64_t>::create(to_uint_64());
	}

	inline uint64_t to_uint_64() const
	{
		return number_u<_primitive_>::to_uint_64(_number);
	}

	inline any_a<> from_uint_64__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::from_uint_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_data_a<uint64_t>>(thing))
		{
			throw dis("strange::number_reference::from_uint_64 passed wrong type of thing");
		}
		return from_uint_64_(cast<number_data_a<uint64_t>>(thing));
	}

	inline any_a<> from_uint_64_(number_data_a<uint64_t> const& uint_64)
	{
		from_uint_64(uint_64.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void from_uint_64(uint64_t uint_64)
	{
		_number = number_u<_primitive_>::from_uint_64(uint_64);
	}

	inline any_a<> to_float_64__(range_a<> const& _) const
	{
		return to_float_64_();
	}

	inline number_data_a<double> to_float_64_() const
	{
		return number_t<double>::create(to_float_64());
	}

	inline double to_float_64() const
	{
		return number_u<_primitive_>::to_float_64(_number);
	}

	inline any_a<> from_float_64__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::from_float_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_data_a<double>>(thing))
		{
			throw dis("strange::number_reference::from_float_64 passed wrong type of thing");
		}
		return from_float_64_(cast<number_data_a<double>>(thing));
	}

	inline any_a<> from_float_64_(number_data_a<double> const& float_64)
	{
		from_float_64(float_64.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void from_float_64(double float_64)
	{
		_number = number_u<_primitive_>::from_float_64(float_64);
	}

	inline any_a<> less_than__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::less_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference::less_than passed non-number");
		}
		return less_than_(cast<number_a<>>(thing));
	}

	inline any_a<> less_than_(number_a<> const& number) const
	{
		return boole(operator<(number));
	}

	inline bool operator<(number_a<> const& number) const
	{
		return _number < number_u<_primitive_>::from_number(number);
	}

	inline any_a<> greater_than__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::greater_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference::greater_than passed non-number");
		}
		return greater_than_(cast<number_a<>>(thing));
	}

	inline any_a<> greater_than_(number_a<> const& number) const
	{
		return boole(operator>(number));
	}

	inline bool operator>(number_a<> const& number) const
	{
		return _number > number_u<_primitive_>::from_number(number);
	}

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::less_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference::less_or_equal passed non-number");
		}
		return less_or_equal_(cast<number_a<>>(thing));
	}

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{
		return boole(operator<=(number));
	}

	inline bool operator<=(number_a<> const& number) const
	{
		return _number <= number_u<_primitive_>::from_number(number);
	}

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::number_reference::greater_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::number_reference::greater_or_equal passed non-number");
		}
		return greater_or_equal_(cast<number_a<>>(thing));
	}

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{
		return boole(operator>=(number));
	}

	inline bool operator>=(number_a<> const& number) const
	{
		return _number >= number_u<_primitive_>::from_number(number);
	}

	static inline any_a<> byte_size__(range_a<> const& _)
	{
		return byte_size_();
	}

	static inline number_data_a<int64_t> byte_size_()
	{
		return number_t<int64_t>::create(byte_size());
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
		return number_u<_primitive_>::is_int();
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
		return number_u<_primitive_>::is_signed();
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
		return number_u<_primitive_>::is_nan(_number);
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
		return number_u<_primitive_>::is_inf(_number);
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
		return number_u<_primitive_>::is_finite(_number);
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
		return number_u<_primitive_>::is_normal(_number);
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
	inline _primitive_ const& extract_primitive() const
	{
		return _number;
	}

	inline _primitive_& mutate_primitive()
	{
		return _number;
	}

protected:
	_primitive_& _number;

	inline number_reference_t(_primitive_& number)
		: thing_t<___ego___>{}
		, _number(number)
	{}
};

template <typename ___ego___ = number_data_a<int8_t>>
using number_reference_int_8_t = number_reference_t<int8_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint8_t>>
using number_reference_uint_8_t = number_reference_t<uint8_t, ___ego___>;

template <typename ___ego___ = number_data_a<int16_t>>
using number_reference_int_16_t = number_reference_t<int16_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint16_t>>
using number_reference_uint_16_t = number_reference_t<uint16_t, ___ego___>;

template <typename ___ego___ = number_data_a<int32_t>>
using number_reference_int_32_t = number_reference_t<int32_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint32_t>>
using number_reference_uint_32_t = number_reference_t<uint32_t, ___ego___>;

template <typename ___ego___ = number_data_a<int64_t>>
using number_reference_int_64_t = number_reference_t<int64_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint64_t>>
using number_reference_uint_64_t = number_reference_t<uint64_t, ___ego___>;

template <typename ___ego___ = number_data_a<float>>
using number_reference_float_32_t = number_reference_t<float, ___ego___>;

template <typename ___ego___ = number_data_a<double>>
using number_reference_float_64_t = number_reference_t<double, ___ego___>;

} // namespace strange

#endif
