#include "../../strange__core.h"

namespace strange
{
	// data_t
	// data_o
	template <typename type_d>
	data_o<std::remove_reference_t<type_d>> const* data_t<type_d>::_operations()
	{
		static data_o<std::remove_reference_t<type_d>> operations =
		{
			{
				// any_a
				data_a<std::remove_reference_t<type_d>>::cat,
				is,
				as,
				type,
				set_error,
				error,
				hash,
				equal,
				less,
				less_or_equal,
				pack,
				_free,
				_copy,
				_set_pointer,
				_pointer,
			},
			// data_a
			read_lock,
			write_lock,
			extract,
			mutate,
		};
		return &operations;
	}

	template <typename type_d>
	data_o<std::remove_reference_t<type_d>> const* data_t<type_d>::_pointer_operations()
	{
		static data_o<std::remove_reference_t<type_d>> operations = []()
		{
			data_o<std::remove_reference_t<type_d>> ops = *data_t<type_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename type_d>
	bool data_t<type_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat || abc == data_a<std::remove_reference_t<type_d>>::cat;
	}

	template <typename type_d>
	bool data_t<type_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!data_t<type_d>::is(me, abstraction))
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
	var<symbol_a> data_t<type_d>::type(con<> const& me)
	{
		static auto r = sym("strange::data");
		return r;
	}

	template <typename type_d>
	void data_t<type_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new data_t<type_d>{ copy, me };
		data_t<type_d>::_clone(me, copy);
	}

	template <typename type_d>
	void data_t<type_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? data_t<type_d>::_pointer_operations() : data_t<type_d>::_operations();
	}

	// data_a
	template <typename type_d>
	ptr<> data_t<type_d>::read_lock(con<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		return ptr<>{};
	}

	template <typename type_d>
	ptr<> data_t<type_d>::write_lock(var<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		me.mut();
		return ptr<>{};
	}

	template <typename type_d>
	std::remove_reference_t<type_d> const& data_t<type_d>::extract(con<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		return static_cast<data_t<type_d>*>(me.t)->data_;
	}

	template <typename type_d>
	std::remove_reference_t<type_d>& data_t<type_d>::mutate(var<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		me.mut();
		return static_cast<data_t<type_d>*>(me.t)->data_;
	}

	// instantiation
	template struct data_t<int64_t>;
	template struct data_t<int64_t&>;
	template struct data_t<uint64_t>;
	template struct data_t<uint64_t&>;
	template struct data_t<double>;
	template struct data_t<double&>;
	template struct data_t<default_copy<std::shared_mutex>>;
	template struct data_t<default_copy<std::string>>;

	template struct data_t<int64_t*>;
	template struct data_t<std::shared_lock<std::shared_mutex>*>;
	template struct data_t<std::unique_lock<std::shared_mutex>*>;
}
