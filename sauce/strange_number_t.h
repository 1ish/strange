#ifndef COM_ONEISH_STRANGE_NUMBER_T_H
#define COM_ONEISH_STRANGE_NUMBER_T_H

namespace strange
{

template <typename PRIMITIVE>
class conversion_u
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
};

template <typename PRIMITIVE, typename _ABSTRACTION_ = number_data_a<PRIMITIVE>>
class number_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline number_data_a<PRIMITIVE> val(any_a<> const& _)
	{
		return val_();
	}

	static inline number_data_a<PRIMITIVE> val_()
	{
		return val__(PRIMITIVE{});
	}

	static inline number_data_a<PRIMITIVE> val__(PRIMITIVE const& primitive)
	{
		return number_data_a<PRIMITIVE>{ number_t<PRIMITIVE, _ABSTRACTION_>{ primitive } };
	}

	static inline number_data_a<PRIMITIVE> ref(any_a<> const& _)
	{
		return ref_();
	}

	static inline number_data_a<PRIMITIVE> ref_()
	{
		return ref__(PRIMITIVE{});
	}

	static inline number_data_a<PRIMITIVE> ref__(PRIMITIVE const& primitive)
	{
		return number_data_a<PRIMITIVE>(number_t<PRIMITIVE, _ABSTRACTION_>{ primitive }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::number");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check_<number_a<>>(thing))
		{
			return false;
		}
		return _number == conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<number_a<>>(thing))
		{
			return true;
		}
		return _number != conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
	}

	inline std::size_t hash__() const
	{
		return std::hash<PRIMITIVE>{}(_number);
	}

	// number
	inline _ABSTRACTION_ increment(any_a<> const&)
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

	inline any_a<> decrement(any_a<> const& _)
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

	inline any_a<> self_add(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator+=(thing);
		}
		return me_();
	}

	inline number_a<> self_add_(number_a<> const& number)
	{
		_number += conversion_u<PRIMITIVE>::from_number__(number);
		return me_();
	}

	inline number_t& operator+=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number += passed non-number");
		}
		_number += conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		return *this;
	}

	inline any_a<> add(any_a<> const& range) const
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
		result.reference__() += conversion_u<PRIMITIVE>::from_number__(number);
		return result;
	}

	inline any_a<> self_subtract(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator-=(thing);
		}
		return me_();
	}

	inline number_a<> self_subtract_(number_a<> const& number)
	{
		_number -= conversion_u<PRIMITIVE>::from_number__(number);
		return me_();
	}

	inline number_t& operator-=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number -= passed non-number");
		}
		_number -= conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		return *this;
	}

	inline any_a<> subtract(any_a<> const& range) const
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
		result.reference__() -= conversion_u<PRIMITIVE>::from_number__(number);
		return result;
	}

	inline any_a<> self_multiply(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator*=(thing);
		}
		return me_();
	}

	inline number_a<> self_multiply_(number_a<> const& number)
	{
		_number *= conversion_u<PRIMITIVE>::from_number__(number);
		return me_();
	}

	inline number_t& operator*=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number *= passed non-number");
		}
		_number *= conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		return *this;
	}

	inline any_a<> multiply(any_a<> const& range) const
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
		result.reference__() *= conversion_u<PRIMITIVE>::from_number__(number);
		return result;
	}

	inline any_a<> self_divide(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator/=(thing);
		}
		return me_();
	}

	inline number_a<> self_divide_(number_a<> const& number)
	{
		PRIMITIVE num = conversion_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis__("strange::number self_divide division by zero");
		}
		_number /= num;
		return me_();
	}

	inline number_t& operator/=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number /= passed non-number");
		}
		PRIMITIVE num = conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		if (num == 0)
		{
			throw dis__("strange::number /= division by zero");
		}
		_number /= num;
		return *this;
	}

	inline any_a<> divide(any_a<> const& range) const
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
		PRIMITIVE num = conversion_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis__("strange::number / division by zero");
		}
		_ABSTRACTION_ result = me_();
		result.reference__() /= num;
		return result;
	}

	inline any_a<> self_modulo(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			operator%=(thing);
		}
		return me_();
	}

	inline number_a<> self_modulo_(number_a<> const& number)
	{
		PRIMITIVE num = conversion_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis__("strange::number self_modulo division by zero");
		}
		_number = conversion_u<PRIMITIVE>::modulo__(_number, num);
		return me_();
	}

	inline number_t& operator%=(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number %= passed non-number");
		}
		PRIMITIVE num = conversion_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
		if (num == 0)
		{
			throw dis__("strange::number %= division by zero");
		}
		_number = conversion_u<PRIMITIVE>::modulo__(_number, num);
		return *this;
	}

	inline any_a<> modulo(any_a<> const& range) const
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
		PRIMITIVE num = conversion_u<PRIMITIVE>::from_number__(number);
		if (num == 0)
		{
			throw dis__("strange::number % division by zero");
		}
		return val__(conversion_u<PRIMITIVE>::modulo__(_number, num));
	}

	inline any_a<> to_int_64(any_a<> const& _) const
	{
		return to_int_64_();
	}

	inline number_data_a<int64_t> to_int_64_() const
	{
		return number_t<int64_t>::val__(to_int_64__());
	}

	inline int64_t to_int_64__() const
	{
		return conversion_u<PRIMITIVE>::to_int_64__(_number);
	}

	inline any_a<> from_int_64(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::from_int_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_data_a<int64_t>>(thing))
		{
			throw dis__("strange::number::from_int_64 passed wrong type of thing");
		}
		return from_int_64_(cast_<number_data_a<int64_t>>(thing));
	}

	inline any_a<> from_int_64_(number_data_a<int64_t> const& int_64)
	{
		from_int_64__(int_64.extract__());
		return me_();
	}

	inline void from_int_64__(int64_t int_64)
	{
		_number = conversion_u<PRIMITIVE>::from_int_64__(int_64);
	}

	inline any_a<> to_uint_64(any_a<> const& _) const
	{
		return to_uint_64_();
	}

	inline number_data_a<uint64_t> to_uint_64_() const
	{
		return number_t<uint64_t>::val__(to_uint_64__());
	}

	inline uint64_t to_uint_64__() const
	{
		return conversion_u<PRIMITIVE>::to_uint_64__(_number);
	}

	inline any_a<> from_uint_64(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::from_uint_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_data_a<uint64_t>>(thing))
		{
			throw dis__("strange::number::from_uint_64 passed wrong type of thing");
		}
		return from_uint_64_(cast_<number_data_a<uint64_t>>(thing));
	}

	inline any_a<> from_uint_64_(number_data_a<uint64_t> const& uint_64)
	{
		from_uint_64__(uint_64.extract__());
		return me_();
	}

	inline void from_uint_64__(uint64_t uint_64)
	{
		_number = conversion_u<PRIMITIVE>::from_uint_64__(uint_64);
	}

	inline any_a<> to_float_64(any_a<> const& _) const
	{
		return to_float_64_();
	}

	inline number_data_a<double> to_float_64_() const
	{
		return number_t<double>::val__(to_float_64__());
	}

	inline double to_float_64__() const
	{
		return conversion_u<PRIMITIVE>::to_float_64__(_number);
	}

	inline any_a<> from_float_64(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::from_float_64 passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_data_a<double>>(thing))
		{
			throw dis__("strange::number::from_float_64 passed wrong type of thing");
		}
		return from_float_64_(cast_<number_data_a<double>>(thing));
	}

	inline any_a<> from_float_64_(number_data_a<double> const& float_64)
	{
		from_float_64__(float_64.extract__());
		return me_();
	}

	inline void from_float_64__(double float_64)
	{
		_number = conversion_u<PRIMITIVE>::from_float_64__(float_64);
	}

	inline any_a<> less_than(any_a<> const& range) const
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::less_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number::less_than passed non-number");
		}
		return less_than_(cast_<number_a<>>(thing));
	}

	inline any_a<> less_than_(number_a<> const& number) const
	{
		return _boole_(operator<(number));
	}

	inline bool operator<(number_a<> const& number) const
	{
		return _number < conversion_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> greater_than(any_a<> const& range) const
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::greater_than passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number::greater_than passed non-number");
		}
		return greater_than_(cast_<number_a<>>(thing));
	}

	inline any_a<> greater_than_(number_a<> const& number) const
	{
		return _boole_(operator>(number));
	}

	inline bool operator>(number_a<> const& number) const
	{
		return _number > conversion_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> less_or_equal(any_a<> const& range) const
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::less_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number::less_or_equal passed non-number");
		}
		return less_or_equal_(cast_<number_a<>>(thing));
	}

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{
		return _boole_(operator<=(number));
	}

	inline bool operator<=(number_a<> const& number) const
	{
		return _number <= conversion_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> greater_or_equal(any_a<> const& range) const
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::number::greater_or_equal passed empty range");
		}
		any_a<> thing = *it;
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::number::greater_or_equal passed non-number");
		}
		return greater_or_equal_(cast_<number_a<>>(thing));
	}

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{
		return _boole_(operator>=(number));
	}

	inline bool operator>=(number_a<> const& number) const
	{
		return _number >= conversion_u<PRIMITIVE>::from_number__(number);
	}

	inline any_a<> byte_size(any_a<> const& range) const;
	inline number_a<> byte_size_() const;
	inline int64_t byte_size__() const;

	inline any_a<> is_int(any_a<> const& range) const;
	inline any_a<> is_int_() const;
	inline bool is_int__() const;

	inline any_a<> is_signed(any_a<> const& range) const;
	inline any_a<> is_signed_() const;
	inline bool is_signed__() const;

	inline any_a<> is_nan(any_a<> const& range) const;
	inline any_a<> is_nan_() const;
	inline bool is_nan__() const;

	inline any_a<> is_inf(any_a<> const& range) const;
	inline any_a<> is_inf_() const;
	inline bool is_inf__() const;

	inline any_a<> is_finite(any_a<> const& range) const;
	inline any_a<> is_finite_() const;
	inline bool is_finite__() const;

	inline any_a<> is_normal(any_a<> const& range) const;
	inline any_a<> is_normal_() const;
	inline bool is_normal__() const;

	inline any_a<> little_endian(any_a<> const& range) const;
	inline any_a<> little_endian_() const;
	inline bool little_endian__() const;

	// data
	inline PRIMITIVE const& extract__() const;
	inline void mutate__(PRIMITIVE const& data);
	inline PRIMITIVE& reference__();

protected:
	PRIMITIVE _number;

	inline number_t(PRIMITIVE const& number)
		: something_t{}
		, _number(number)
	{}
};

} // namespace strange

#endif
