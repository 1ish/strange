#include "../../../../strange.h"

namespace strange
{
	// forward_tuple_mutator_t
	// forward_tuple_mutator_o
	template <typename iterator_d, typename key_d, typename value_d>
	forward_tuple_mutator_o<key_d, value_d> const* forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operations()
	{
		static forward_tuple_mutator_o<key_d, value_d> operations =
		{
			{
				{
					// any_a
					forward_tuple_mutator_a<key_d, value_d>::cat,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::is,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::as,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::type,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::set_error,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::error,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::hash,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::equal,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::less,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::less_or_equal,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::pack,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::_free,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::_copy,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::_set_pointer,
					forward_tuple_mutator_t<iterator_d, key_d, value_d>::_pointer,
				},
				// forward_mutator_a
				forward_tuple_mutator_t<iterator_d, key_d, value_d>::equal_iterator,
				forward_tuple_mutator_t<iterator_d, key_d, value_d>::get,
				forward_tuple_mutator_t<iterator_d, key_d, value_d>::set,
				forward_tuple_mutator_t<iterator_d, key_d, value_d>::increment,
				forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operator_star,
				forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operator_arrow,
			},
			// forward_tuple_mutator_a
			forward_tuple_mutator_t<iterator_d, key_d, value_d>::list,
			forward_tuple_mutator_t<iterator_d, key_d, value_d>::destruct,
			forward_tuple_mutator_t<iterator_d, key_d, value_d>::restruct,
		};
		return &operations;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	forward_tuple_mutator_o<key_d, value_d> const* forward_tuple_mutator_t<iterator_d, key_d, value_d>::_pointer_operations()
	{
		static forward_tuple_mutator_o<key_d, value_d> operations = []()
		{
			forward_tuple_mutator_o<key_d, value_d> ops = *forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename key_d, typename value_d>
	bool forward_tuple_mutator_t<iterator_d, key_d, value_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat ||
			abc == forward_tuple_mutator_a<key_d, value_d>::cat;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	bool forward_tuple_mutator_t<iterator_d, key_d, value_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!forward_tuple_mutator_t<iterator_d, key_d, value_d>::is(me, abstraction))
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
	var<symbol_a> forward_tuple_mutator_t<iterator_d, key_d, value_d>::type(con<> const& me)
	{
		static auto r = sym("strange::forward_tuple_mutator");
		return r;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	bool forward_tuple_mutator_t<iterator_d, key_d, value_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<forward_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return forward_tuple_mutator_t<iterator_d, key_d, value_d>::equal_iterator(me.reference<con<forward_mutator_a<element_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_tuple_mutator_t<iterator_d, key_d, value_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new forward_tuple_mutator_t<iterator_d, key_d, value_d>{ copy, me };
		forward_tuple_mutator_t<iterator_d, key_d, value_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_tuple_mutator_t<iterator_d, key_d, value_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? forward_tuple_mutator_t<iterator_d, key_d, value_d>::_pointer_operations() : forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operations();
	}

	// forward_mutator_a
	template <typename iterator_d, typename key_d, typename value_d>
	typename forward_tuple_mutator_t<iterator_d, key_d, value_d>::element_d forward_tuple_mutator_t<iterator_d, key_d, value_d>::get(con<forward_mutator_a<element_d>> const& me)
	{
		auto& pair = *(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		return tuple_t<key_d, value_d>::create(strange::list<>(box<>(pair.first), box<>(pair.second.value_)));
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_tuple_mutator_t<iterator_d, key_d, value_d>::set(con<forward_mutator_a<element_d>> const& me,
		element_d const& element)
	{
		key_d key;
		auto& pair = *(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		element.o->destruct(element, key, pair.second.value_);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_tuple_mutator_t<iterator_d, key_d, value_d>::increment(var<forward_mutator_a<element_d>> const& me)
	{
		me.mut();
		++(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	typename forward_tuple_mutator_t<iterator_d, key_d, value_d>::element_d& forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operator_star(con<forward_mutator_a<element_d>> const& me)
	{
		auto& pair = static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_.operator*();
		auto& tuple = pair.second.tuple_;
		if (!tuple.o->something(tuple))
		{
			tuple = pair_pointer_tuple_t<key_d, value_d, std::pair<key_d, value_d>>::create(reinterpret_cast<std::pair<key_d, value_d>*>(&pair));
		}
		return tuple;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	typename forward_tuple_mutator_t<iterator_d, key_d, value_d>::element_d* forward_tuple_mutator_t<iterator_d, key_d, value_d>::_operator_arrow(con<forward_mutator_a<element_d>> const& me)
	{
		auto& pair = *(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_.operator->());
		auto& tuple = pair.second.tuple_;
		if (!tuple.o->something(tuple))
		{
			tuple = pair_pointer_tuple_t<key_d, value_d, std::pair<key_d, value_d>>::create(reinterpret_cast<std::pair<key_d, value_d>*>(&pair));
		}
		return &tuple;
	}

	// forward_tuple_mutator_a
	template <typename iterator_d, typename key_d, typename value_d>
	var<list_a<>> forward_tuple_mutator_t<iterator_d, key_d, value_d>::list(con<forward_tuple_mutator_a<key_d, value_d>> const& me)
	{
		auto& pair = *(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		return strange::list<>(box<>(pair.first), box<>(pair.second.value_));
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_tuple_mutator_t<iterator_d, key_d, value_d>::destruct(con<forward_tuple_mutator_a<key_d, value_d>> const& me,
		key_d& key,
		value_d& value)
	{
		auto& pair = *(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		key = pair.first;
		value = pair.second.value_;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void forward_tuple_mutator_t<iterator_d, key_d, value_d>::restruct(con<forward_tuple_mutator_a<key_d, value_d>> const& me,
		key_d const& key,
		value_d const& value)
	{
		auto& pair = *(static_cast<forward_tuple_mutator_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_);
		pair.second.value_ = value;
	}

	// instantiation
	template struct forward_tuple_mutator_t<std::unordered_map<int64_t, table_value_tuple_u<int64_t, int64_t>>::iterator, int64_t, int64_t>;
	template struct forward_tuple_mutator_t<std::map<int64_t, table_value_tuple_u<int64_t, int64_t>>::iterator, int64_t, int64_t>;
}
