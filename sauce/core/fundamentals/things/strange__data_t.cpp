#include "../../../strange.h"

namespace strange
{
	// data_t
	// data_o
	template <typename type_d>
	data_o<type_d> const* data_t<type_d>::_operations()
	{
		static data_o<type_d> operations =
		{
			{
				// any_a
				data_a<type_d>::cat,
				is,
				as,
				type,
				set_error,
				error,
				hash,
				equal,
				less,
				less_or_equal,
				_free,
				_copy,
				_set_pointer,
				_pointer,
			},
			// data_a
			extract_data,
			mutate_data,
		};
		return &operations;
	}

	template <typename type_d>
	data_o<type_d> const* data_t<type_d>::_pointer_operations()
	{
		static data_o<type_d> operations = []()
		{
			data_o<type_d> ops = *data_t<type_d>::_operations();
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
		return abc == any_a::cat || abc == data_a<type_d>::cat;
	}

	template <typename type_d>
	bool data_t<type_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!data_t<type_d>::is(me, abstraction))
		{
			return false;
		}
		abstraction = me;
		return true;
	}

	template <typename type_d>
	var<symbol_a> data_t<type_d>::type(con<> const& me)
	{
		static auto r = sym("strange::data");
		return r;
	}

	// data_a
	template <typename type_d>
	type_d const& data_t<type_d>::extract_data(con<data_a<type_d>> const& me)
	{
		return static_cast<data_t<type_d>*>(me.t)->data_;
	}

	template <typename type_d>
	type_d& data_t<type_d>::mutate_data(var<data_a<type_d>> const& me)
	{
		me.mut();
		return static_cast<data_t<type_d>*>(me.t)->data_;
	}

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
				data_pointer_t<type_d>::_free,
				data_pointer_t<type_d>::_copy,
				data_pointer_t<type_d>::_set_pointer,
				data_pointer_t<type_d>::_pointer,
			},
			// data_a
			extract_data,
			mutate_data,
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

	// data_a
	template <typename type_d>
	type_d const& data_pointer_t<type_d>::extract_data(con<data_a<type_d>> const& me)
	{
		return *(static_cast<data_pointer_t<type_d>*>(me.t)->data_);
	}

	template <typename type_d>
	type_d& data_pointer_t<type_d>::mutate_data(var<data_a<type_d>> const& me)
	{
		return *(static_cast<data_pointer_t<type_d>*>(me.t)->data_);
	}

	// instantiation
	template struct data_t<int64_t>;
	template struct data_t<int64_t&>;
	template struct data_t<default_copy<std::shared_timed_mutex>>;
	template struct data_t<default_copy<std::string>>;

	template struct data_pointer_t<int64_t>;
}