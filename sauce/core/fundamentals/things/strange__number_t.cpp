#include "../../../strange.h"

namespace strange
{
	// number_o
	template <typename type_d>
	number_o<type_d> const* number_t<type_d>::_operations()
	{
		static number_o<type_d> operations =
		{
			{
				{
					// any_a
					number_a<type_d>::cat,
					number_t<type_d>::is,
					number_t<type_d>::as,
					number_t<type_d>::type,
					number_t<type_d>::set_error,
					number_t<type_d>::error,
					number_t<type_d>::hash,
					number_t<type_d>::equal,
					number_t<type_d>::less,
					number_t<type_d>::less_or_equal,
					number_t<type_d>::contain,
					number_t<type_d>::_free,
					number_t<type_d>::_copy,
					number_t<type_d>::_set_pointer,
					number_t<type_d>::_pointer,
				},
				// numeric_a
				number_t<type_d>::to_int64,
				number_t<type_d>::to_uint64,
				number_t<type_d>::to_float64,
				number_t<type_d>::byte_size,
				number_t<type_d>::is_int,
				number_t<type_d>::is_signed,
				number_t<type_d>::is_nan,
				number_t<type_d>::is_inf,
				number_t<type_d>::is_finite,
				number_t<type_d>::is_normal,
			},
			// number_a
			number_t<type_d>::extract,
			number_t<type_d>::mutate,
		};
		return &operations;
	}

	template <typename type_d>
	number_o<type_d> const* number_t<type_d>::_pointer_operations()
	{
		static number_o<type_d> operations = []()
		{
			number_o<type_d> ops = *number_t<type_d>::_operations();
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
		return abc == any_a::cat || abc == numeric_a::cat || abc == number_a<type_d>::cat;
	}

	template <typename type_d>
	bool number_t<type_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!number_t<type_d>::is(me, abstraction))
		{
			return false;
		}
		abstraction = me;
		return true;
	}

	template <typename type_d>
	var<symbol_a> number_t<type_d>::type(con<> const& me)
	{
		static auto r = sym("strange::number");
		return r;
	}

	template <typename type_d>
	void number_t<type_d>::_copy(any_a const& me,
		any_a& copy)
	{
		new number_t<type_d>{ copy, me };
		number_t<type_d>::_clone(me, copy);
	}

	template <typename type_d>
	void number_t<type_d>::_set_pointer(var<> const& me,
		bool is_pointer)
	{
		me.o = reinterpret_cast<any_o const*>(is_pointer ? number_t<type_d>::_pointer_operations() : number_t<type_d>::_operations());
	}

	// numeric_a
	template <typename type_d>
	int64_t number_t<type_d>::to_int64(con<numeric_a> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		if constexpr (std::is_same_v<std::remove_reference_t<type_d>, int64_t>)
		{
			return nt->data_;
		}
		else if constexpr (std::is_integral_v<std::remove_reference_t<type_d>>)
		{
			return static_cast<int64_t>(nt->data_);
		}
		else if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			return static_cast<int64_t>(std::llround(nt->data_));
		}
	}

	template <typename type_d>
	uint64_t number_t<type_d>::to_uint64(con<numeric_a> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		if constexpr (std::is_same_v<std::remove_reference_t<type_d>, uint64_t>)
		{
			return nt->data_;
		}
		else if constexpr (std::is_integral_v<std::remove_reference_t<type_d>>)
		{
			return static_cast<uint64_t>(nt->data_);
		}
		else if constexpr (std::is_floating_point_v<std::remove_reference_t<type_d>>)
		{
			return static_cast<uint64_t>(std::llround(nt->data_));
		}
	}

	template <typename type_d>
	double number_t<type_d>::to_float64(con<numeric_a> const& me)
	{
		auto const nt = static_cast<number_t<type_d> const* const>(me.t);
		if constexpr (std::is_same_v<std::remove_reference_t<type_d>, double>)
		{
			return nt->data_;
		}
		else
		{
			return static_cast<double>(nt->data_);
		}
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
			return false;
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
			return false;
		}
	}

	// number_a
	template <typename type_d>
	type_d const& number_t<type_d>::extract(con<number_a<type_d>> const& me)
	{
		return static_cast<number_t<type_d>*>(me.t)->data_;
	}

	template <typename type_d>
	type_d& number_t<type_d>::mutate(var<number_a<type_d>> const& me)
	{
		me.mut();
		return static_cast<number_t<type_d>*>(me.t)->data_;
	}

	// instantiation
	template struct number_t<int64_t>;
	template struct number_t<int64_t&>;
}
