#include "../../../strange.h"

namespace strange
{
	// data_pointer_t
	// data_o
	template <typename type_d>
	data_o<type_d> const* data_pointer_t<type_d>::_operations()
	{
		static data_o<type_d> operations =
		{
			{
				// any_a
				data_a<type_d>::cat,
				data_pointer_t<type_d>::is,
				data_pointer_t<type_d>::as,
				data_pointer_t<type_d>::type,
				data_pointer_t<type_d>::set_error,
				data_pointer_t<type_d>::error,
				data_pointer_t<type_d>::hash,
				data_pointer_t<type_d>::equal,
				data_pointer_t<type_d>::less,
				data_pointer_t<type_d>::less_or_equal,
				data_pointer_t<type_d>::pack,
				data_pointer_t<type_d>::_free,
				data_pointer_t<type_d>::_copy,
				data_pointer_t<type_d>::_set_pointer,
				data_pointer_t<type_d>::_pointer,
			},
			// data_a
			data_pointer_t<type_d>::read_lock,
			data_pointer_t<type_d>::write_lock,
			data_pointer_t<type_d>::extract,
			data_pointer_t<type_d>::mutate,
		};
		return &operations;
	}

	template <typename type_d>
	data_o<type_d> const* data_pointer_t<type_d>::_pointer_operations()
	{
		static data_o<type_d> operations = []()
		{
			data_o<type_d> ops = *data_pointer_t<type_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename type_d>
	var<symbol_a> data_pointer_t<type_d>::type(con<> const& me)
	{
		static auto r = sym("strange::data_pointer");
		return r;
	}

	template <typename type_d>
	void data_pointer_t<type_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new data_pointer_t<type_d>{ copy, me };
		data_pointer_t<type_d>::_clone(me, copy);
	}

	template <typename type_d>
	void data_pointer_t<type_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? data_pointer_t<type_d>::_pointer_operations() : data_pointer_t<type_d>::_operations();
	}

	// instantiation
	template struct data_pointer_t<int64_t*>;
	template struct data_pointer_t<std::shared_lock<std::shared_mutex>*>;
	template struct data_pointer_t<std::unique_lock<std::shared_mutex>*>;
}
