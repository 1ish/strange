#include "../../../strange.h"

namespace strange
{
	// pair_pointer_tuple_t
	// tuple_o
	template <typename first_d, typename second_d>
	tuple_o<first_d, second_d> const* pair_pointer_tuple_t<first_d, second_d>::_operations()
	{
		static tuple_o<first_d, second_d> operations =
		{
			{
				// any_a
				tuple_a<first_d, second_d>::cat,
				pair_pointer_tuple_t<first_d, second_d>::is,
				pair_pointer_tuple_t<first_d, second_d>::as,
				pair_pointer_tuple_t<first_d, second_d>::type,
				pair_pointer_tuple_t<first_d, second_d>::set_error,
				pair_pointer_tuple_t<first_d, second_d>::error,
				pair_pointer_tuple_t<first_d, second_d>::hash,
				pair_pointer_tuple_t<first_d, second_d>::equal,
				pair_pointer_tuple_t<first_d, second_d>::less,
				pair_pointer_tuple_t<first_d, second_d>::less_or_equal,
				pair_pointer_tuple_t<first_d, second_d>::pack,
				pair_pointer_tuple_t<first_d, second_d>::_free,
				pair_pointer_tuple_t<first_d, second_d>::_copy,
				pair_pointer_tuple_t<first_d, second_d>::_set_pointer,
				pair_pointer_tuple_t<first_d, second_d>::_pointer,
			},
			// tuple_a
			pair_pointer_tuple_t<first_d, second_d>::list,
			pair_pointer_tuple_t<first_d, second_d>::destruct,
			pair_pointer_tuple_t<first_d, second_d>::restruct,
		};
		return &operations;
	}

	template <typename first_d, typename second_d>
	tuple_o<first_d, second_d> const* pair_pointer_tuple_t<first_d, second_d>::_pointer_operations()
	{
		static tuple_o<first_d, second_d> operations = []()
		{
			tuple_o<first_d, second_d> ops = *pair_pointer_tuple_t<first_d, second_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename first_d, typename second_d>
	bool pair_pointer_tuple_t<first_d, second_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == tuple_a<first_d, second_d>::cat;
	}

	template <typename first_d, typename second_d>
	bool pair_pointer_tuple_t<first_d, second_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!pair_pointer_tuple_t<first_d, second_d>::is(me, abstraction))
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

	template <typename first_d, typename second_d>
	var<symbol_a> pair_pointer_tuple_t<first_d, second_d>::type(con<> const& me)
	{
		static auto r = sym("strange::pair_pointer_tuple");
		return r;
	}

	template <typename first_d, typename second_d>
	bool pair_pointer_tuple_t<first_d, second_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<tuple_a<first_d, second_d>>>();
		if (oi.o->something(oi))
		{
			return pair_pointer_tuple_t<first_d, second_d>::equal_tuple(me.reference<con<tuple_a<first_d, second_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename first_d, typename second_d>
	void pair_pointer_tuple_t<first_d, second_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new pair_pointer_tuple_t<first_d, second_d>{ copy, me };
		pair_pointer_tuple_t<first_d, second_d>::_clone(me, copy);
	}

	template <typename first_d, typename second_d>
	void pair_pointer_tuple_t<first_d, second_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? pair_pointer_tuple_t<first_d, second_d>::_pointer_operations() : pair_pointer_tuple_t<first_d, second_d>::_operations();
	}

	// tuple_a
	template <typename first_d, typename second_d>
	var<list_a<>> pair_pointer_tuple_t<first_d, second_d>::list(con<tuple_a<first_d, second_d>> const& me)
	{
		auto const* thing = reinterpret_cast<pair_pointer_tuple_t<first_d, second_d> const*>(me.t);
		return strange::list<>(box<>(thing->pair_pointer_->first), box<>(thing->pair_pointer_->second));
	}

	template <typename first_d, typename second_d>
	void pair_pointer_tuple_t<first_d, second_d>::destruct(con<tuple_a<first_d, second_d>> const& me,
		first_d& first,
		second_d& second)
	{
		auto const* thing = reinterpret_cast<pair_pointer_tuple_t<first_d, second_d> const*>(me.t);
		first = thing->pair_pointer_->first;
		second = thing->pair_pointer_->second;
	}

	template <typename first_d, typename second_d>
	void pair_pointer_tuple_t<first_d, second_d>::restruct(var<tuple_a<first_d, second_d>> const& me,
		first_d const& first,
		second_d const& second)
	{
		me.mut();
		auto* thing = reinterpret_cast<pair_pointer_tuple_t<first_d, second_d>*>(me.t);
		thing->pair_pointer_->first = first;
		thing->pair_pointer_->second = second;
	}

	// instantiation
	template struct pair_pointer_tuple_t<int64_t, int64_t>;
}
