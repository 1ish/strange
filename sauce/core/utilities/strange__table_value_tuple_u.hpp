#ifndef COM_ONEISH__STRANGE__TABLE_VALUE_TUPLE_U_H
#define COM_ONEISH__STRANGE__TABLE_VALUE_TUPLE_U_H

namespace strange
{
	// wrapper for table values to support non-stashing tuple iterators
	template <typename key_d, typename value_d>
	struct table_value_tuple_u
	{
		value_d value_;
		var<tuple_a<key_d, value_d>> tuple_;

		table_value_tuple_u(value_d const& value)
			: value_{ value }
			, tuple_{}
		{
		}

		table_value_tuple_u(table_value_tuple_u const& original) // copy constructor
			: value_{ original.value_ }
			, tuple_{ original.tuple_.o->something(original.tuple_)
				? pair_pointer_tuple_t<key_d, value_d>::create_offset(original.tuple_, reinterpret_cast<std::uintptr_t>(&original) - reinterpret_cast<std::uintptr_t>(this))
				: original.tuple_ }
		{
		}

		table_value_tuple_u& operator=(table_value_tuple_u const& original) // copy assignment operator
		{
			value_ = original.value_;
			tuple_ = original.tuple_.o->something(original.tuple_)
				? pair_pointer_tuple_t<key_d, value_d>::create_offset(original.tuple_, reinterpret_cast<std::uintptr_t>(&original) - reinterpret_cast<std::uintptr_t>(this))
				: original.tuple_;
			return *this;
		}
	};
}

#endif
