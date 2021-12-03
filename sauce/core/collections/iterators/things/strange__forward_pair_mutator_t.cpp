#include "../../../strange__core.h"

namespace strange
{
	// forward_pair_mutator_t
	// forward_mutator_o
	template <typename iterator_d, typename key_d, typename value_d>
	forward_mutator_o<typename forward_pair_mutator_t<iterator_d, key_d, value_d>::element_d> const* forward_pair_mutator_t<iterator_d, key_d, value_d>::_operations()
	{
		static forward_mutator_o<element_d> operations =
		{
			{
				// any_a
				forward_mutator_a<element_d>::cat,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::is,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::as,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::type,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::set_error,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::error,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::hash,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::equal,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::less,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::less_or_equal,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::pack,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::_free,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::_copy,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::_set_pointer,
				forward_pair_mutator_t<iterator_d, key_d, value_d>::_pointer,
			},
			// forward_mutator_a
			forward_pair_mutator_t<iterator_d, key_d, value_d>::equal_iterator,
			forward_pair_mutator_t<iterator_d, key_d, value_d>::get,
			forward_pair_mutator_t<iterator_d, key_d, value_d>::set,
			forward_pair_mutator_t<iterator_d, key_d, value_d>::increment,
			forward_pair_mutator_t<iterator_d, key_d, value_d>::_operator_star,
			forward_pair_mutator_t<iterator_d, key_d, value_d>::_operator_arrow,
		};
		return &operations;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	forward_mutator_o<typename forward_pair_mutator_t<iterator_d, key_d, value_d>::element_d> const* forward_pair_mutator_t<iterator_d, key_d, value_d>::_pointer_operations()
	{
		static forward_mutator_o<element_d> operations = []()
		{
			forward_mutator_o<element_d> ops = *forward_pair_mutator_t<iterator_d, key_d, value_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename key_d, typename value_d>
	bool forward_pair_mutator_t<iterator_d, key_d, value_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	bool forward_pair_mutator_t<iterator_d, key_d, value_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!forward_pair_mutator_t<iterator_d, key_d, value_d>::is(me, abstraction))
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

	template <typename iterator_d, typename key_d, typename value_d>
	var<symbol_a> forward_pair_mutator_t<iterator_d, key_d, value_d>::type(con<> const& me)
	{
		static auto r = sym("strange::forward_pair_mutator");
		return r;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	bool forward_pair_mutator_t<iterator_d, key_d, value_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<forward_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return forward_pair_mutator_t<iterator_d, key_d, value_d>::equal_iterator(me.reference<con<forward_mutator_a<element_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_pair_mutator_t<iterator_d, key_d, value_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new forward_pair_mutator_t<iterator_d, key_d, value_d>{ copy, me };
		forward_pair_mutator_t<iterator_d, key_d, value_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_pair_mutator_t<iterator_d, key_d, value_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? forward_pair_mutator_t<iterator_d, key_d, value_d>::_pointer_operations() : forward_pair_mutator_t<iterator_d, key_d, value_d>::_operations();
	}

	// forward_mutator_a
	template <typename iterator_d, typename key_d, typename value_d>
	typename forward_pair_mutator_t<iterator_d, key_d, value_d>::element_d forward_pair_mutator_t<iterator_d, key_d, value_d>::get(con<forward_mutator_a<element_d>> const& me)
	{
		auto& pair = *(static_cast<forward_pair_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		return reinterpret_cast<element_d const&>(pair);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_pair_mutator_t<iterator_d, key_d, value_d>::set(con<forward_mutator_a<element_d>> const& me,
		element_d const& element)
	{
		auto& pair = *(static_cast<forward_pair_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		pair.second.value_ = element.second;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_pair_mutator_t<iterator_d, key_d, value_d>::increment(var<forward_mutator_a<element_d>> const& me)
	{
		me.mut();
		++(static_cast<forward_pair_mutator_t<iterator_d, key_d, value_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	typename forward_pair_mutator_t<iterator_d, key_d, value_d>::element_d& forward_pair_mutator_t<iterator_d, key_d, value_d>::_operator_star(con<forward_mutator_a<element_d>> const& me)
	{
		auto& pair = *(static_cast<forward_pair_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		return reinterpret_cast<element_d&>(pair);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	typename forward_pair_mutator_t<iterator_d, key_d, value_d>::element_d* forward_pair_mutator_t<iterator_d, key_d, value_d>::_operator_arrow(con<forward_mutator_a<element_d>> const& me)
	{
		auto& pair = *(static_cast<forward_pair_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		return reinterpret_cast<element_d*>(&pair);
	}

	// instantiation
	template struct forward_pair_mutator_t<std::unordered_map<int64_t, table_value_tuple_u<int64_t, int64_t, std::pair<int64_t const, int64_t>>>::iterator, int64_t, int64_t>;
	template struct forward_pair_mutator_t<std::map<int64_t, table_value_tuple_u<int64_t, int64_t, std::pair<int64_t const, int64_t>>>::iterator, int64_t, int64_t>;
}
