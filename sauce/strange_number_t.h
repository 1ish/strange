#ifndef COM_ONEISH_STRANGE_NUMBER_T_H
#define COM_ONEISH_STRANGE_NUMBER_T_H

namespace strange
{

// template <typename _primitive_, typename ___ego___ = number_data_a<_primitive_>>
template <typename _primitive_, typename ___ego___>
class number_t : public thing_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& _)
	{
		return create_();
	}

	static inline number_data_a<_primitive_> create_()
	{
		return create(_primitive_{});
	}

	static inline number_data_a<_primitive_> create(_primitive_ primitive)
	{
		return number_data_a<_primitive_>::template create<number_t<_primitive_>>(primitive);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::number_" + number_u<_primitive_>::category());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&number_t<_primitive_>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		return check<number_a<>>(thing) &&
			_number == number_u<_primitive_>::from_number(fast<number_a<>>(thing));
	}

	inline bool operator==(number_data_a<_primitive_> const& number) const
	{
		return _number == number.extract_primitive();
	}

	inline bool operator!=(number_data_a<_primitive_> const& number) const
	{
		return _number != number.extract_primitive();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		return std::hash<_primitive_>{}(_number);
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		return check<number_a<>>(thing)
			? _number < number_u<_primitive_>::from_number(fast<number_a<>>(thing))
			: one_t::less_than_(thing);
	}

	inline bool operator<(number_data_a<_primitive_> const& number) const
	{
		return _number < number.extract_primitive();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		return check<number_a<>>(thing)
			? _number > number_u<_primitive_>::from_number(fast<number_a<>>(thing))
			: one_t::greater_than_(thing);
	}

	inline bool operator>(number_data_a<_primitive_> const& number) const
	{
		return _number > number.extract_primitive();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		return check<number_a<>>(thing)
			? _number <= number_u<_primitive_>::from_number(fast<number_a<>>(thing))
			: one_t::less_or_equal_(thing);
	}

	inline bool operator<=(number_data_a<_primitive_> const& number) const
	{
		return _number <= number.extract_primitive();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		return check<number_a<>>(thing)
			? _number >= number_u<_primitive_>::from_number(fast<number_a<>>(thing))
			: one_t::greater_or_equal_(thing);
	}

	inline bool operator>=(number_data_a<_primitive_> const& number) const
	{
		return _number >= number.extract_primitive();
	}

	// number
	inline void increment_()
	{
		++_number;
	}

	inline void decrement_()
	{
		--_number;
	}

	inline void self_assign_(number_a<> const& number)
	{
		_number = number_u<_primitive_>::from_number(number);
	}

	inline void self_add_(number_a<> const& number)
	{
		_number += number_u<_primitive_>::from_number(number);
	}

	inline number_a<> add_(number_a<> const& number) const
	{
		return create(_number + number_u<_primitive_>::from_number(number));
	}

	inline void self_subtract_(number_a<> const& number)
	{
		_number -= number_u<_primitive_>::from_number(number);
	}

	inline number_a<> subtract_(number_a<> const& number) const
	{
		return create(_number - number_u<_primitive_>::from_number(number));
	}

	inline void self_multiply_(number_a<> const& number)
	{
		_number *= number_u<_primitive_>::from_number(number);
	}

	inline number_a<> multiply_(number_a<> const& number) const
	{
		return create(_number * number_u<_primitive_>::from_number(number));
	}

	inline void self_divide_(number_a<> const& number)
	{
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number self_divide division by zero");
		}
		_number /= num;
	}

	inline number_a<> divide_(number_a<> const& number) const
	{
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number / division by zero");
		}
		return create(_number / num);
	}

	inline void self_modulo_(number_a<> const& number)
	{
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number self_modulo division by zero");
		}
		_number = number_u<_primitive_>::modulo(_number, num);
	}

	inline number_a<> modulo_(number_a<> const& number) const
	{
		_primitive_ num = number_u<_primitive_>::from_number(number);
		if (num == 0)
		{
			throw dis("strange::number % division by zero");
		}
		return create(number_u<_primitive_>::modulo(_number, num));
	}

	inline number_data_a<int64_t> to_int_64_() const
	{
		return number_t<int64_t>::create(to_int_64());
	}

	inline int64_t to_int_64() const
	{
		return number_u<_primitive_>::to_int_64(_number);
	}

	inline ___ego___ from_int_64_(number_data_a<int64_t> const& int_64)
	{
		from_int_64(int_64.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void from_int_64(int64_t int_64)
	{
		_number = number_u<_primitive_>::from_int_64(int_64);
	}

	inline number_data_a<uint64_t> to_uint_64_() const
	{
		return number_t<uint64_t>::create(to_uint_64());
	}

	inline uint64_t to_uint_64() const
	{
		return number_u<_primitive_>::to_uint_64(_number);
	}

	inline ___ego___ from_uint_64_(number_data_a<uint64_t> const& uint_64)
	{
		from_uint_64(uint_64.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void from_uint_64(uint64_t uint_64)
	{
		_number = number_u<_primitive_>::from_uint_64(uint_64);
	}

	inline number_data_a<double> to_float_64_() const
	{
		return number_t<double>::create(to_float_64());
	}

	inline double to_float_64() const
	{
		return number_u<_primitive_>::to_float_64(_number);
	}

	inline ___ego___ from_float_64_(number_data_a<double> const& float_64)
	{
		from_float_64(float_64.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void from_float_64(double float_64)
	{
		_number = number_u<_primitive_>::from_float_64(float_64);
	}

	static inline number_data_a<int64_t> byte_size_()
	{
		return number_t<int64_t>::create(byte_size());
	}

	static inline int64_t byte_size()
	{
		return int64_t(sizeof(_number));
	}

	static inline any_a<> is_int_()
	{
		return boole(is_int());
	}

	static inline bool is_int()
	{
		return number_u<_primitive_>::is_int();
	}

	static inline any_a<> is_signed_()
	{
		return boole(is_signed());
	}

	static inline bool is_signed()
	{
		return number_u<_primitive_>::is_signed();
	}

	inline any_a<> is_nan_() const
	{
		return boole(is_nan());
	}

	inline bool is_nan() const
	{
		return number_u<_primitive_>::is_nan(_number);
	}

	inline any_a<> is_inf_() const
	{
		return boole(is_inf());
	}

	inline bool is_inf() const
	{
		return number_u<_primitive_>::is_inf(_number);
	}

	inline any_a<> is_finite_() const
	{
		return boole(is_finite());
	}

	inline bool is_finite() const
	{
		return number_u<_primitive_>::is_finite(_number);
	}

	inline any_a<> is_normal_() const
	{
		return boole(is_normal());
	}

	inline bool is_normal() const
	{
		return number_u<_primitive_>::is_normal(_number);
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
	_primitive_ _number;

	friend class any_a<>;

	inline number_t(_primitive_ number)
		: thing_t<___ego___>{}
		, _number(number)
	{}

private:
	static bool const ___share___;
	friend class ___number_t_share___;
};

template <typename _primitive_, typename ___ego___>
bool const number_t<_primitive_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	number_t<_primitive_, ___ego___>::share(shoal);
	return shoal;
}();

template <typename ___ego___ = number_data_a<int8_t>>
using number_int_8_t = number_t<int8_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint8_t>>
using number_uint_8_t = number_t<uint8_t, ___ego___>;

template <typename ___ego___ = number_data_a<int16_t>>
using number_int_16_t = number_t<int16_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint16_t>>
using number_uint_16_t = number_t<uint16_t, ___ego___>;

template <typename ___ego___ = number_data_a<int32_t>>
using number_int_32_t = number_t<int32_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint32_t>>
using number_uint_32_t = number_t<uint32_t, ___ego___>;

template <typename ___ego___ = number_data_a<int64_t>>
using number_int_64_t = number_t<int64_t, ___ego___>;

template <typename ___ego___ = number_data_a<uint64_t>>
using number_uint_64_t = number_t<uint64_t, ___ego___>;

template <typename ___ego___ = number_data_a<float>>
using number_float_32_t = number_t<float, ___ego___>;

template <typename ___ego___ = number_data_a<double>>
using number_float_64_t = number_t<double, ___ego___>;

class ___number_t_share___
{
	static inline bool ___share___()
	{
		return number_int_8_t<>::___share___
			&& number_uint_8_t<>::___share___
			&& number_int_16_t<>::___share___
			&& number_uint_16_t<>::___share___
			&& number_int_32_t<>::___share___
			&& number_uint_32_t<>::___share___
			&& number_int_64_t<>::___share___
			&& number_uint_64_t<>::___share___
			&& number_float_32_t<>::___share___
			&& number_float_64_t<>::___share___;
	}
};

inline number_data_a<int64_t> int_64_from_string(std::string const& str)
{
	return number_int_64_t<>::create(std::stoll(str));
}

inline number_data_a<double> float_64_from_string(std::string const& str)
{
	return number_float_64_t<>::create(std::stod(str));
}

template <typename _primitive_, typename _result_>
inline _result_ num(_primitive_ primitive)
{
	return number_t<_primitive_>::create(primitive);
}

} // namespace strange

#endif
