#include "../../../strange.h"

namespace strange
{
	// pair_pointer_tuple_t
	// tuple_o
	template <typename first_d, typename second_d, typename pair_d>
	tuple_o<first_d, second_d> const* pair_pointer_tuple_t<first_d, second_d, pair_d>::_operations()
	{
		static tuple_o<first_d, second_d> operations =
		{
			{
				// any_a
				tuple_a<first_d, second_d>::cat,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::is,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::as,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::type,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::set_error,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::error,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::hash,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::equal,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::less,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::less_or_equal,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::pack,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::_free,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::_copy,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::_set_pointer,
				pair_pointer_tuple_t<first_d, second_d, pair_d>::_pointer,
			},
			// tuple_a
			pair_pointer_tuple_t<first_d, second_d, pair_d>::list,
			pair_pointer_tuple_t<first_d, second_d, pair_d>::destruct,
			pair_pointer_tuple_t<first_d, second_d, pair_d>::restruct,
		};
		return &operations;
	}

	template <typename first_d, typename second_d, typename pair_d>
	tuple_o<first_d, second_d> const* pair_pointer_tuple_t<first_d, second_d, pair_d>::_pointer_operations()
	{
		static tuple_o<first_d, second_d> operations = []()
		{
			tuple_o<first_d, second_d> ops = *pair_pointer_tuple_t<first_d, second_d, pair_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename first_d, typename second_d, typename pair_d>
	bool pair_pointer_tuple_t<first_d, second_d, pair_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == tuple_a<first_d, second_d>::cat;
	}

	template <typename first_d, typename second_d, typename pair_d>
	bool pair_pointer_tuple_t<first_d, second_d, pair_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!pair_pointer_tuple_t<first_d, second_d, pair_d>::is(me, abstraction))
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

	template <typename first_d, typename second_d, typename pair_d>
	var<symbol_a> pair_pointer_tuple_t<first_d, second_d, pair_d>::type(con<> const& me)
	{
		static auto r = sym("strange::pair_pointer_tuple");
		return r;
	}

	template <typename first_d, typename second_d, typename pair_d>
	bool pair_pointer_tuple_t<first_d, second_d, pair_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<tuple_a<first_d, second_d>>>();
		if (oi.o->something(oi))
		{
			return pair_pointer_tuple_t<first_d, second_d, pair_d>::equal_tuple(me.reference<con<tuple_a<first_d, second_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	// new tuple_t instead of pair_pointer_tuple_t
	template <typename first_d, typename second_d, typename pair_d>
	void pair_pointer_tuple_t<first_d, second_d, pair_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		tuple_t<first_d, second_d>::create(pair_pointer_tuple_t<first_d, second_d, pair_d>::list(me.reference<con<tuple_a<first_d, second_d>>>()));
	}

	template <typename first_d, typename second_d, typename pair_d>
	void pair_pointer_tuple_t<first_d, second_d, pair_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? pair_pointer_tuple_t<first_d, second_d, pair_d>::_pointer_operations() : pair_pointer_tuple_t<first_d, second_d, pair_d>::_operations();
	}

	// tuple_a
	template <typename first_d, typename second_d, typename pair_d>
	var<list_a<>> pair_pointer_tuple_t<first_d, second_d, pair_d>::list(con<tuple_a<first_d, second_d>> const& me)
	{
		auto const* thing = static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d> const*>(me.t);
		return strange::list<>(box<>(thing->pair_pointer_->first), box<>(thing->pair_pointer_->second));
	}

	template <typename first_d, typename second_d, typename pair_d>
	void pair_pointer_tuple_t<first_d, second_d, pair_d>::destruct(con<tuple_a<first_d, second_d>> const& me,
		first_d& first,
		second_d& second)
	{
		auto const* thing = static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d> const*>(me.t);
		first = thing->pair_pointer_->first;
		second = thing->pair_pointer_->second;
	}

	template <typename first_d, typename second_d, typename pair_d>
	void pair_pointer_tuple_t<first_d, second_d, pair_d>::restruct(var<tuple_a<first_d, second_d>> const& me,
		first_d const& first,
		second_d const& second)
	{
		me.mut();
		if constexpr (!std::is_const_v<pair_d>)
		{
			static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d>*>(me.t)->pair_pointer_->second = second;
		}
	}

	// instantiation
	template struct pair_pointer_tuple_t<int64_t, int64_t, std::pair<int64_t const, int64_t> const>;
	template struct pair_pointer_tuple_t<int64_t, int64_t, std::pair<int64_t const, int64_t>>;
}
