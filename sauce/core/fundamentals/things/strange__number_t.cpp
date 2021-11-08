#include "../../../strange.h"

namespace strange
{
	// number_o
	template <typename type_d>
	number_o<std::remove_reference_t<type_d>> const* number_t<type_d>::_operations()
	{
		static number_o<std::remove_reference_t<type_d>> operations =
		{
			{
				{
					{
						// any_a
						number_a<std::remove_reference_t<type_d>>::cat,
						number_t<type_d>::is,
						number_t<type_d>::as,
						number_t<type_d>::type,
						number_t<type_d>::set_error,
						number_t<type_d>::error,
						number_t<type_d>::hash,
						number_t<type_d>::equal,
						number_t<type_d>::less,
						number_t<type_d>::less_or_equal,
						number_t<type_d>::pack,
						number_t<type_d>::_free,
						number_t<type_d>::_copy,
						number_t<type_d>::_set_pointer,
						number_t<type_d>::_pointer,
					},
					// numeric_a
					number_t<type_d>::int64,
					number_t<type_d>::uint64,
					number_t<type_d>::float64,
					number_t<type_d>::byte_size,
					number_t<type_d>::is_int,
					number_t<type_d>::is_signed,
					number_t<type_d>::is_nan,
					number_t<type_d>::is_inf,
					number_t<type_d>::is_finite,
					number_t<type_d>::is_normal,
				},
				// mutable_numeric_a
				number_t<type_d>::from_int64,
				number_t<type_d>::from_uint64,
				number_t<type_d>::from_float64,
			},
			// number_a
			number_t<type_d>::equal_number,
			number_t<type_d>::less_number,
			number_t<type_d>::less_or_equal_number,
			number_t<type_d>::data,
			number_t<type_d>::extract,
			number_t<type_d>::mutate,
			number_t<type_d>::extractor,
		};
		return &operations;
	}

	template <typename type_d>
	number_o<std::remove_reference_t<type_d>> const* number_t<type_d>::_pointer_operations()
	{
		static number_o<std::remove_reference_t<type_d>> operations = []()
		{
			number_o<std::remove_reference_t<type_d>> ops = *number_t<type_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename type_d>
	bool number_t<type_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat || abc == numeric_a::cat || abc == number_a<std::remove_reference_t<type_d>>::cat;
	}

	template <typename type_d>
	bool number_t<type_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!number_t<type_d>::is(me, abstraction))
		{
			return false;
		}
		bool const as_pointer = abstraction.o->_pointer(abstraction);
		abstraction = me;
		if (abstraction.o->_pointer(abstraction) != as_pointer)
		{
			if (as_pointer)
			{
				abstraction.mut();
			}
			abstraction.o->_set_pointer(abstraction, as_pointer);
			if (!as_pointer)
			{
				abstraction.mut();
			}
		}
		return true;
	}

	template <typename type_d>
	var<symbol_a> number_t<type_d>::type(con<> const& me)
	{
		static auto r = sym("strange::number");
		return r;
	}

	template <typename type_d>
	uint64_t number_t<type_d>::hash(con<> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		return std::hash<std::remove_reference_t<type_d>>{}(nt->data_);
	}

	template <typename type_d>
	bool number_t<type_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const on = other.dynamic<con<number_a<std::remove_reference_t<type_d>>>>();
		if (on.o->something(on))
		{
			return number_t<type_d>::equal_number(me.reference<con<number_a<std::remove_reference_t<type_d>>>>(), on);
		}
		return data_t<type_d>::equal(me, other);
	}

	template <typename type_d>
	bool number_t<type_d>::less(con<> const& me,
		con<> const& other)
	{
		auto const on = other.dynamic<con<number_a<std::remove_reference_t<type_d>>>>();
		if (on.o->something(on))
		{
			return number_t<type_d>::less_number(me.reference<con<number_a<std::remove_reference_t<type_d>>>>(), on);
		}
		return data_t<type_d>::less(me, other);
	}

	template <typename type_d>
	bool number_t<type_d>::less_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const on = other.dynamic<con<number_a<std::remove_reference_t<type_d>>>>();
		if (on.o->something(on))
		{
			return number_t<type_d>::less_or_equal_number(me.reference<con<number_a<std::remove_reference_t<type_d>>>>(), on);
		}
		return data_t<type_d>::less_or_equal(me, other);
	}

	template <typename type_d>
	void number_t<type_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new number_t<type_d>{ copy, me };
		number_t<type_d>::_clone(me, copy);
	}

	template <typename type_d>
	void number_t<type_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? number_t<type_d>::_pointer_operations() : number_t<type_d>::_operations();
	}

	// numeric_a
	template <typename type_d>
	int64_t number_t<type_d>::int64(con<numeric_a> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			return static_cast<int64_t>(std::llround(nt->data_));
		}
		else
		{
			return static_cast<int64_t>(nt->data_);
		}
	}

	template <typename type_d>
	uint64_t number_t<type_d>::uint64(con<numeric_a> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			return static_cast<uint64_t>(std::llround(nt->data_));
		}
		else
		{
			return static_cast<uint64_t>(nt->data_);
		}
	}

	template <typename type_d>
	double number_t<type_d>::float64(con<numeric_a> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		return static_cast<double>(nt->data_);
	}

	template <typename type_d>
	int64_t number_t<type_d>::byte_size(con<numeric_a> const& me)
	{
		return static_cast<int64_t>(sizeof(std::remove_reference_t<type_d>));
	}

	template <typename type_d>
	bool number_t<type_d>::is_int(con<numeric_a> const& me)
	{
		return std::is_integral_v<std::remove_reference_t<type_d>>;
	}

	template <typename type_d>
	bool number_t<type_d>::is_signed(con<numeric_a> const& me)
	{
		return std::is_signed_v<std::remove_reference_t<type_d>>;
	}

	template <typename type_d>
	bool number_t<type_d>::is_nan(con<numeric_a> const& me)
	{
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			auto const nt = static_cast<number_t<type_d> const* const>(me.t);
			return std::isnan(nt->data_);
		}
		else
		{
			return false;
		}
	}

	template <typename type_d>
	bool number_t<type_d>::is_inf(con<numeric_a> const& me)
	{
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			auto const nt = static_cast<number_t<type_d> const* const>(me.t);
			return std::isinf(nt->data_);
		}
		else
		{
			return false;
		}
	}

	template <typename type_d>
	bool number_t<type_d>::is_finite(con<numeric_a> const& me)
	{
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			auto const nt = static_cast<number_t<type_d> const* const>(me.t);
			return std::isfinite(nt->data_);
		}
		else
		{
			return true;
		}
	}

	template <typename type_d>
	bool number_t<type_d>::is_normal(con<numeric_a> const& me)
	{
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			auto const nt = static_cast<number_t<type_d> const* const>(me.t);
			return std::isnormal(nt->data_);
		}
		else
		{
			return true;
		}
	}

	// mutable_numeric_a
	template <typename type_d>
	void number_t<type_d>::from_int64(var<mutable_numeric_a> const& me,
		int64_t number)
	{
		me.mut();
		auto const nt = static_cast<number_t<type_d>* const>(me.t);
		nt->data_ = static_cast<std::remove_reference_t<type_d>>(number);
	}

	template <typename type_d>
	void number_t<type_d>::from_uint64(var<mutable_numeric_a> const& me,
		uint64_t number)
	{
		me.mut();
		auto const nt = static_cast<number_t<type_d>* const>(me.t);
		nt->data_ = static_cast<std::remove_reference_t<type_d>>(number);
	}

	template <typename type_d>
	void number_t<type_d>::from_float64(var<mutable_numeric_a> const& me,
		double number)
	{
		me.mut();
		auto const nt = static_cast<number_t<type_d>* const>(me.t);
		if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			nt->data_ = static_cast<std::remove_reference_t<type_d>>(number);
		}
		else
		{
			nt->data_ = static_cast<std::remove_reference_t<type_d>>(std::llround(number));
		}
	}

	// number_a
	template <typename type_d>
	var<data_a<std::remove_reference_t<type_d>>> number_t<type_d>::data(con<number_a<std::remove_reference_t<type_d>>> const& me)
	{
		data_a<std::remove_reference_t<type_d>> abstraction;
		abstraction.t = me.t;
		abstraction.o = number_t<type_d>::_data_operations();
		return var<data_a<std::remove_reference_t<type_d>>>{ abstraction };
	}

	template <typename type_d>
	std::remove_reference_t<type_d> const& number_t<type_d>::extract(con<number_a<std::remove_reference_t<type_d>>> const& me)
	{
		return static_cast<number_t<type_d>*>(me.t)->data_;
	}

	template <typename type_d>
	std::remove_reference_t<type_d>& number_t<type_d>::mutate(var<number_a<std::remove_reference_t<type_d>>> const& me)
	{
		me.mut();
		return static_cast<number_t<type_d>*>(me.t)->data_;
	}

	// data_a
	template <typename type_d>
	data_o<std::remove_reference_t<type_d>> const* number_t<type_d>::_data_operations()
	{
		static data_o<std::remove_reference_t<type_d>> operations =
		{
			{
				// any_a
				data_a<std::remove_reference_t<type_d>>::cat,
				number_t<type_d>::_data_is,
				number_t<type_d>::_data_as,
				number_t<type_d>::type,
				number_t<type_d>::set_error,
				number_t<type_d>::error,
				number_t<type_d>::hash,
				number_t<type_d>::equal,
				number_t<type_d>::less,
				number_t<type_d>::less_or_equal,
				number_t<type_d>::pack,
				number_t<type_d>::_free,
				number_t<type_d>::_data_copy,
				number_t<type_d>::_data_set_pointer,
				number_t<type_d>::_pointer,
			},
			// data_a
			reinterpret_cast<decltype(data_o<std::remove_reference_t<type_d>>::read_lock)>(number_t<type_d>::read_lock),
			reinterpret_cast<decltype(data_o<std::remove_reference_t<type_d>>::write_lock)>(number_t<type_d>::write_lock),
			reinterpret_cast<decltype(data_o<std::remove_reference_t<type_d>>::extract)>(number_t<type_d>::extract),
			reinterpret_cast<decltype(data_o<std::remove_reference_t<type_d>>::mutate)>(number_t<type_d>::mutate),
		};
		return &operations;
	}

	template <typename type_d>
	data_o<std::remove_reference_t<type_d>> const* number_t<type_d>::_data_pointer_operations()
	{
		static data_o<std::remove_reference_t<type_d>> operations = []()
		{
			data_o<std::remove_reference_t<type_d>> ops = *number_t<type_d>::_data_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename type_d>
	bool number_t<type_d>::_data_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat || abc == data_a<std::remove_reference_t<type_d>>::cat;
	}

	template <typename type_d>
	bool number_t<type_d>::_data_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!number_t<type_d>::_data_is(me, abstraction))
		{
			return false;
		}
		bool const as_pointer = abstraction.o->_pointer(abstraction);
		abstraction = me;
		if (abstraction.o->_pointer(abstraction) != as_pointer)
		{
			if (as_pointer)
			{
				abstraction.mut();
			}
			abstraction.o->_set_pointer(abstraction, as_pointer);
			if (!as_pointer)
			{
				abstraction.mut();
			}
		}
		return true;
	}

	template <typename type_d>
	void number_t<type_d>::_data_copy(con<> const& me,
		var<> const& copy)
	{
		new number_t<type_d>{ copy, me };
		number_t<type_d>::_clone(me, copy);
		copy.o = number_t<type_d>::_data_operations();
	}

	template <typename type_d>
	void number_t<type_d>::_data_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? number_t<type_d>::_data_pointer_operations() : number_t<type_d>::_data_operations();
	}

	// extractor_a
	template <typename type_d>
	rat<random_access_extractor_a<std::remove_reference_t<type_d>>> number_t<type_d>::extractor(con<number_a<std::remove_reference_t<type_d>>> const& me)
	{
		random_access_extractor_a<std::remove_reference_t<type_d>> abstraction;
		abstraction.t = me.t;
		abstraction.o = number_t<type_d>::_extractor_operations();
		return rat<random_access_extractor_a<std::remove_reference_t<type_d>>>{ abstraction };
	}

	template <typename type_d>
	std::remove_reference_t<type_d> number_t<type_d>::_extractor_get(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me)
	{
		return static_cast<number_t<type_d>*>(me.t)->data_;
	}

	template <typename type_d>
	void number_t<type_d>::_extractor_increment(var<forward_extractor_a<std::remove_reference_t<type_d>>> const& me)
	{
		me.mut();
		++(static_cast<number_t<type_d>*>(me.t)->data_);
	}

	template <typename type_d>
	void number_t<type_d>::_extractor_decrement(var<bidirectional_extractor_a<std::remove_reference_t<type_d>>> const& me)
	{
		me.mut();
		--(static_cast<number_t<type_d>*>(me.t)->data_);
	}

	template <typename type_d>
	std::remove_reference_t<type_d> const& number_t<type_d>::_extractor_operator_star(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me)
	{
		return static_cast<number_t<type_d>*>(me.t)->data_;
	}

	template <typename type_d>
	std::remove_reference_t<type_d> const* number_t<type_d>::_extractor_operator_arrow(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me)
	{
		return &(static_cast<number_t<type_d>*>(me.t)->data_);
	}

	template <typename type_d>
	void number_t<type_d>::_extractor_self_add(var<random_access_extractor_a<std::remove_reference_t<type_d>>> const& me,
		int64_t offset)
	{
		me.mut();
		static_cast<number_t<type_d>*>(me.t)->data_ += offset;
	}

	template <typename type_d>
	rat<random_access_extractor_a<std::remove_reference_t<type_d>>> number_t<type_d>::_extractor_add(con<random_access_extractor_a<std::remove_reference_t<type_d>>> const& me,
		int64_t offset)
	{
		rat<random_access_extractor_a<std::remove_reference_t<type_d>>> result{ me };
		number_t<type_d>::_extractor_self_add(result, offset);
		return result;
	}

	template <typename type_d>
	random_access_extractor_o<std::remove_reference_t<type_d>> const* number_t<type_d>::_extractor_operations()
	{
		static random_access_extractor_o<std::remove_reference_t<type_d>> operations =
		{
			{
				{
					{
						// any_a
						random_access_extractor_a<std::remove_reference_t<type_d>>::cat,
						number_t<type_d>::_extractor_is,
						number_t<type_d>::_extractor_as,
						number_t<type_d>::type,
						number_t<type_d>::set_error,
						number_t<type_d>::error,
						number_t<type_d>::hash,
						number_t<type_d>::_extractor_equal,
						number_t<type_d>::_extractor_less,
						number_t<type_d>::_extractor_less_or_equal,
						number_t<type_d>::pack,
						number_t<type_d>::_free,
						number_t<type_d>::_extractor_copy,
						number_t<type_d>::_extractor_set_pointer,
						number_t<type_d>::_pointer,
					},
					// forward_extractor_o
					number_t<type_d>::_extractor_equal_extractor,
					number_t<type_d>::_extractor_get,
					number_t<type_d>::_extractor_increment,
					number_t<type_d>::_extractor_operator_star,
					number_t<type_d>::_extractor_operator_arrow,
				},
				// bidirectional_extractor_o
				number_t<type_d>::_extractor_decrement,
			},
			// random_access_extractor_o
			number_t<type_d>::_extractor_less_extractor,
			number_t<type_d>::_extractor_less_or_equal_extractor,
			number_t<type_d>::_extractor_self_add,
			number_t<type_d>::_extractor_add,
		};
		return &operations;
	}

	template <typename type_d>
	random_access_extractor_o<std::remove_reference_t<type_d>> const* number_t<type_d>::_extractor_pointer_operations()
	{
		static random_access_extractor_o<std::remove_reference_t<type_d>> operations = []()
		{
			random_access_extractor_o<std::remove_reference_t<type_d>> ops = *number_t<type_d>::_extractor_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename type_d>
	bool number_t<type_d>::_extractor_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_extractor_a<std::remove_reference_t<type_d>>::cat ||
			abc == bidirectional_extractor_a<std::remove_reference_t<type_d>>::cat ||
			abc == random_access_extractor_a<std::remove_reference_t<type_d>>::cat;
	}

	template <typename type_d>
	bool number_t<type_d>::_extractor_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!number_t<type_d>::_extractor_is(me, abstraction))
		{
			return false;
		}
		bool const as_pointer = abstraction.o->_pointer(abstraction);
		abstraction = me;
		if (abstraction.o->_pointer(abstraction) != as_pointer)
		{
			if (as_pointer)
			{
				abstraction.mut();
			}
			abstraction.o->_set_pointer(abstraction, as_pointer);
			if (!as_pointer)
			{
				abstraction.mut();
			}
		}
		return true;
	}

	template <typename type_d>
	bool number_t<type_d>::_extractor_equal(con<> const& me,
		con<> const& other)
	{
		auto const on = other.dynamic<con<random_access_extractor_a<std::remove_reference_t<type_d>>>>();
		if (on.o->something(on))
		{
			return number_t<type_d>::_extractor_equal_extractor(me.reference<con<random_access_extractor_a<std::remove_reference_t<type_d>>>>(), on);
		}
		return data_t<type_d>::equal(me, other);
	}

	template <typename type_d>
	bool number_t<type_d>::_extractor_less(con<> const& me,
		con<> const& other)
	{
		auto const on = other.dynamic<con<random_access_extractor_a<std::remove_reference_t<type_d>>>>();
		if (on.o->something(on))
		{
			return number_t<type_d>::_extractor_less_extractor(me.reference<con<random_access_extractor_a<std::remove_reference_t<type_d>>>>(), on);
		}
		return data_t<type_d>::less(me, other);
	}

	template <typename type_d>
	bool number_t<type_d>::_extractor_less_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const on = other.dynamic<con<random_access_extractor_a<std::remove_reference_t<type_d>>>>();
		if (on.o->something(on))
		{
			return number_t<type_d>::_extractor_less_or_equal_extractor(me.reference<con<random_access_extractor_a<std::remove_reference_t<type_d>>>>(), on);
		}
		return data_t<type_d>::less_or_equal(me, other);
	}

	template <typename type_d>
	void number_t<type_d>::_extractor_copy(con<> const& me,
		var<> const& copy)
	{
		new number_t<type_d>{ copy, me };
		number_t<type_d>::_clone(me, copy);
		copy.o = number_t<type_d>::_extractor_operations();
	}

	template <typename type_d>
	void number_t<type_d>::_extractor_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? number_t<type_d>::_extractor_pointer_operations() : number_t<type_d>::_extractor_operations();
	}

	// instantiation
	template struct number_t<int64_t>;
	template struct number_t<int64_t&>;
	template struct number_t<uint64_t>;
	template struct number_t<uint64_t&>;
	template struct number_t<double>;
	template struct number_t<double&>;
}
