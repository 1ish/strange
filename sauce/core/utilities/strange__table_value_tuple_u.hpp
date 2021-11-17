#ifndef COM_ONEISH__STRANGE__TABLE_VALUE_TUPLE_U_H
#define COM_ONEISH__STRANGE__TABLE_VALUE_TUPLE_U_H

namespace strange
{
	// wrapper for table values to support non-stashing tuple iterators
	template <typename key_d, typename value_d, typename pair_d>
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
				? pair_pointer_tuple_t<key_d, value_d, pair_d>::create_offset(original.tuple_, reinterpret_cast<std::uintptr_t>(&original) - reinterpret_cast<std::uintptr_t>(this))
				: original.tuple_ }
		{
		}

		table_value_tuple_u& operator=(table_value_tuple_u const& original) // copy assignment operator
		{
			value_ = original.value_;
			tuple_ = original.tuple_.o->something(original.tuple_)
				? pair_pointer_tuple_t<key_d, value_d, pair_d>::create_offset(original.tuple_, reinterpret_cast<std::uintptr_t>(&original) - reinterpret_cast<std::uintptr_t>(this))
				: original.tuple_;
			return *this;
		}

		static inline var<tuple_a<key_d, value_d>> const& tuple(std::pair<key_d const, table_value_tuple_u<key_d, value_d, pair_d>> const& pair)
		{
			auto& tuple = pair.second.tuple_;
			if (!tuple.o->something(tuple))
			{
				tuple = pair_pointer_tuple_t<key_d, value_d, pair_d>::create(reinterpret_cast<pair_d*>(&pair));
			}
			return tuple;
		}

		static inline var<tuple_a<key_d, value_d>>& tuple(std::pair<key_d const, table_value_tuple_u<key_d, value_d, pair_d>>& pair)
		{
			auto& tuple = pair.second.tuple_;
			if (!tuple.o->something(tuple))
			{
				tuple = pair_pointer_tuple_t<key_d, value_d, pair_d>::create(reinterpret_cast<pair_d*>(&pair));
			}
			return tuple;
		}
	};
}

#endif
