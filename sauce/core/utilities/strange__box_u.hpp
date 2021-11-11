#ifndef COM_ONEISH__STRANGE__BOX_U_H
#define COM_ONEISH__STRANGE__BOX_U_H

namespace strange
{
	template <typename value_d>
	inline var<> box(value_d const& value)
	{
		if constexpr (std::is_convertible_v<value_d, var<>>)
		{
			return value;
		}
		else if constexpr (std::is_arithmetic_v<value_d>)
		{
			return num<value_d>(value);
		}
		else
		{
			return dat<value_d>(value);
		}
	}

	template <typename value_d>
	inline value_d unbox(var<> const& value)
	{
		if constexpr (std::is_convertible_v<value_d, var<>>)
		{
			return value.dynamic<value_d>();
		}
		else if constexpr (std::is_arithmetic_v<value_d>)
		{
			auto const number = value.dynamic<con<number_a<value_d>>>();
			if (number.o->something(number))
			{
				return number.o->extract(number);
			}
			else
			{
				return 0;
			}
			return number.o->extract(number);
		}
		else
		{
			auto const data = value.dynamic<con<data_a<value_d>>>();
			if (data.o->something(data))
			{
				return data.o->extract(data);
			}
			else
			{
				return value_d{};
			}
		}
	}
}

#endif
