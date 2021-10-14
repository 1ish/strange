#include "../../../strange.h"

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
	void data_t<type_d>::_copy(any_a const& me,
		any_a& copy)
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
	ptr<> data_t<type_d>::read_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		return ptr<>{};
	}

	template <typename type_d>
	ptr<> data_t<type_d>::write_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me)
	{
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
	void data_pointer_t<type_d>::_copy(any_a const& me,
		any_a& copy)
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
	void locked_data_t<type_d, lock_d>::_copy(any_a const& me,
		any_a& copy)
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
	ptr<> locked_data_t<type_d, lock_d>::read_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		auto t = static_cast<locked_data_t<type_d, lock_d>*>(me.t);
		return t->lock_.o->read_lock(t->lock_);
	}

	template <typename type_d, typename lock_d>
	ptr<> locked_data_t<type_d, lock_d>::write_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me)
	{
		auto t = static_cast<locked_data_t<type_d, lock_d>*>(me.t);
		return t->lock_.o->write_lock(t->lock_);
	}

	// locked_data_pointer_t
	// data_o
	template <typename type_d, typename lock_d>
	data_o<type_d> const* locked_data_pointer_t<type_d, lock_d>::_operations()
	{
		static data_o<type_d> operations =
		{
			{
				// any_a
				data_a<type_d>::cat,
				locked_data_pointer_t<type_d, lock_d>::is,
				locked_data_pointer_t<type_d, lock_d>::as,
				locked_data_pointer_t<type_d, lock_d>::type,
				locked_data_pointer_t<type_d, lock_d>::set_error,
				locked_data_pointer_t<type_d, lock_d>::error,
				locked_data_pointer_t<type_d, lock_d>::hash,
				locked_data_pointer_t<type_d, lock_d>::equal,
				locked_data_pointer_t<type_d, lock_d>::less,
				locked_data_pointer_t<type_d, lock_d>::less_or_equal,
				locked_data_pointer_t<type_d, lock_d>::pack,
				locked_data_pointer_t<type_d, lock_d>::_free,
				locked_data_pointer_t<type_d, lock_d>::_copy,
				locked_data_pointer_t<type_d, lock_d>::_set_pointer,
				locked_data_pointer_t<type_d, lock_d>::_pointer,
			},
			// data_a
			locked_data_pointer_t<type_d, lock_d>::read_lock,
			locked_data_pointer_t<type_d, lock_d>::write_lock,
			locked_data_pointer_t<type_d, lock_d>::extract,
			locked_data_pointer_t<type_d, lock_d>::mutate,
		};
		return &operations;
	}

	template <typename type_d, typename lock_d>
	data_o<type_d> const* locked_data_pointer_t<type_d, lock_d>::_pointer_operations()
	{
		static data_o<type_d> operations = []()
		{
			data_o<type_d> ops = *locked_data_pointer_t<type_d, lock_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename type_d, typename lock_d>
	var<symbol_a> locked_data_pointer_t<type_d, lock_d>::type(con<> const& me)
	{
		static auto r = sym("strange::locked_data_pointer");
		return r;
	}

	template <typename type_d, typename lock_d>
	void locked_data_pointer_t<type_d, lock_d>::_copy(any_a const& me,
		any_a& copy)
	{
		new locked_data_pointer_t<type_d, lock_d>{ copy, me };
		locked_data_pointer_t<type_d, lock_d>::_clone(me, copy);
	}

	template <typename type_d, typename lock_d>
	void locked_data_pointer_t<type_d, lock_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? locked_data_pointer_t<type_d, lock_d>::_pointer_operations() : locked_data_pointer_t<type_d, lock_d>::_operations();
	}

	// data_a
	template <typename type_d, typename lock_d>
	ptr<> locked_data_pointer_t<type_d, lock_d>::read_lock(ptr<data_a<type_d>> const& me)
	{
		auto t = static_cast<locked_data_pointer_t<type_d, lock_d>*>(me.t);
		return t->lock_.o->read_lock(t->lock_);
	}

	template <typename type_d, typename lock_d>
	ptr<> locked_data_pointer_t<type_d, lock_d>::write_lock(ptr<data_a<type_d>> const& me)
	{
		auto t = static_cast<locked_data_pointer_t<type_d, lock_d>*>(me.t);
		return t->lock_.o->write_lock(t->lock_);
	}

	// instantiation
	template struct data_t<int64_t>;
	template struct data_t<int64_t&>;
	template struct data_t<uint64_t>;
	template struct data_t<uint64_t&>;
	template struct data_t<double>;
	template struct data_t<double&>;
	template struct data_t<default_copy<std::shared_timed_mutex>>;
	template struct data_t<default_copy<std::string>>;

	template struct data_pointer_t<int64_t*>;
	template struct data_pointer_t<std::shared_lock<std::shared_timed_mutex>*>;
	template struct data_pointer_t<std::unique_lock<std::shared_timed_mutex>*>;
}
