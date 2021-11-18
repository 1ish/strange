#include "../../strange__core.h"

namespace strange
{
	// locked_data_t
	// data_o
	template <typename type_d, typename lock_d>
	data_o<std::remove_reference_t<type_d>> const* locked_data_t<type_d, lock_d>::_operations()
	{
		static data_o<std::remove_reference_t<type_d>> operations =
		{
			{
				// any_a
				data_a<std::remove_reference_t<type_d>>::cat,
				locked_data_t<type_d, lock_d>::is,
				locked_data_t<type_d, lock_d>::as,
				locked_data_t<type_d, lock_d>::type,
				locked_data_t<type_d, lock_d>::set_error,
				locked_data_t<type_d, lock_d>::error,
				locked_data_t<type_d, lock_d>::hash,
				locked_data_t<type_d, lock_d>::equal,
				locked_data_t<type_d, lock_d>::less,
				locked_data_t<type_d, lock_d>::less_or_equal,
				locked_data_t<type_d, lock_d>::pack,
				locked_data_t<type_d, lock_d>::_free,
				locked_data_t<type_d, lock_d>::_copy,
				locked_data_t<type_d, lock_d>::_set_pointer,
				locked_data_t<type_d, lock_d>::_pointer,
			},
			// data_a
			locked_data_t<type_d, lock_d>::read_lock,
			locked_data_t<type_d, lock_d>::write_lock,
			locked_data_t<type_d, lock_d>::extract,
			locked_data_t<type_d, lock_d>::mutate,
		};
		return &operations;
	}

	template <typename type_d, typename lock_d>
	data_o<std::remove_reference_t<type_d>> const* locked_data_t<type_d, lock_d>::_pointer_operations()
	{
		static data_o<std::remove_reference_t<type_d>> operations = []()
		{
			data_o<std::remove_reference_t<type_d>> ops = *locked_data_t<type_d, lock_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename type_d, typename lock_d>
	var<symbol_a> locked_data_t<type_d, lock_d>::type(con<> const& me)
	{
		static auto r = sym("strange::locked_data");
		return r;
	}

	template <typename type_d, typename lock_d>
	void locked_data_t<type_d, lock_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new locked_data_t<type_d, lock_d>{ copy, me };
		locked_data_t<type_d, lock_d>::_clone(me, copy);
	}

	template <typename type_d, typename lock_d>
	void locked_data_t<type_d, lock_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? locked_data_t<type_d, lock_d>::_pointer_operations() : locked_data_t<type_d, lock_d>::_operations();
	}

	// data_a
	template <typename type_d, typename lock_d>
	ptr<> locked_data_t<type_d, lock_d>::read_lock(con<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		auto t = static_cast<locked_data_t<type_d, lock_d>*>(me.t);
		return t->lock_.o->read_lock(t->lock_);
	}

	template <typename type_d, typename lock_d>
	ptr<> locked_data_t<type_d, lock_d>::write_lock(var<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		me.mut();
		auto t = static_cast<locked_data_t<type_d, lock_d>*>(me.t);
		return t->lock_.o->write_lock(t->lock_);
	}

	// instantiation
}
