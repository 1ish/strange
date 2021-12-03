#include "../../../strange__core.h"

namespace strange
{
	// forward_mutator_t
	// forward_mutator_o
	template <typename iterator_d, typename element_d>
	forward_mutator_o<element_d> const* forward_mutator_t<iterator_d, element_d>::_operations()
	{
		static forward_mutator_o<element_d> operations =
		{
			{
				// any_a
				forward_mutator_a<element_d>::cat,
				forward_mutator_t<iterator_d, element_d>::is,
				forward_mutator_t<iterator_d, element_d>::as,
				forward_mutator_t<iterator_d, element_d>::type,
				forward_mutator_t<iterator_d, element_d>::set_error,
				forward_mutator_t<iterator_d, element_d>::error,
				forward_mutator_t<iterator_d, element_d>::hash,
				forward_mutator_t<iterator_d, element_d>::equal,
				forward_mutator_t<iterator_d, element_d>::less,
				forward_mutator_t<iterator_d, element_d>::less_or_equal,
				forward_mutator_t<iterator_d, element_d>::pack,
				forward_mutator_t<iterator_d, element_d>::_free,
				forward_mutator_t<iterator_d, element_d>::_copy,
				forward_mutator_t<iterator_d, element_d>::_set_pointer,
				forward_mutator_t<iterator_d, element_d>::_pointer,
			},
			// forward_mutator_a
			forward_mutator_t<iterator_d, element_d>::equal_iterator,
			forward_mutator_t<iterator_d, element_d>::get,
			forward_mutator_t<iterator_d, element_d>::set,
			forward_mutator_t<iterator_d, element_d>::increment,
			forward_mutator_t<iterator_d, element_d>::_operator_star,
			forward_mutator_t<iterator_d, element_d>::_operator_arrow,
		};
		return &operations;
	}

	template <typename iterator_d, typename element_d>
	forward_mutator_o<element_d> const* forward_mutator_t<iterator_d, element_d>::_pointer_operations()
	{
		static forward_mutator_o<element_d> operations = []()
		{
			forward_mutator_o<element_d> ops = *forward_mutator_t<iterator_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename element_d>
	bool forward_mutator_t<iterator_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat;
	}

	template <typename iterator_d, typename element_d>
	bool forward_mutator_t<iterator_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!forward_mutator_t<iterator_d, element_d>::is(me, abstraction))
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

	template <typename iterator_d, typename element_d>
	var<symbol_a> forward_mutator_t<iterator_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::forward_mutator");
		return r;
	}

	template <typename iterator_d, typename element_d>
	bool forward_mutator_t<iterator_d, element_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<forward_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return forward_mutator_t<iterator_d, element_d>::equal_iterator(me.reference<con<forward_mutator_a<element_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename iterator_d, typename element_d>
	void forward_mutator_t<iterator_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new forward_mutator_t<iterator_d, element_d>{ copy, me };
		forward_mutator_t<iterator_d, element_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename element_d>
	void forward_mutator_t<iterator_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? forward_mutator_t<iterator_d, element_d>::_pointer_operations() : forward_mutator_t<iterator_d, element_d>::_operations();
	}

	// forward_mutator_a
	template <typename iterator_d, typename element_d>
	element_d forward_mutator_t<iterator_d, element_d>::get(con<forward_mutator_a<element_d>> const& me)
	{
		return *(static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename element_d>
	void forward_mutator_t<iterator_d, element_d>::set(con<forward_mutator_a<element_d>> const& me,
		element_d const& element)
	{
		if constexpr (std::is_class_v<element_d> && !std::is_assignable_v<element_d, element_d>)
		{
			(*(static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_)).second = element.second;
		}
		else
		{
			*(static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_) = element;
		}
	}

	template <typename iterator_d, typename element_d>
	void forward_mutator_t<iterator_d, element_d>::increment(var<forward_mutator_a<element_d>> const& me)
	{
		me.mut();
		++(static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename element_d>
	element_d& forward_mutator_t<iterator_d, element_d>::_operator_star(con<forward_mutator_a<element_d>> const& me)
	{
		return (static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_).operator*();
	}

	template <typename iterator_d, typename element_d>
	element_d* forward_mutator_t<iterator_d, element_d>::_operator_arrow(con<forward_mutator_a<element_d>> const& me)
	{
		return (static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_).operator->();
	}

	// instantiation
	template struct forward_mutator_t<std::vector<int64_t>::iterator, int64_t>;
	template struct forward_mutator_t<std::vector<var<>>::iterator, var<>>;
	template struct forward_mutator_t<std::deque<int64_t>::iterator, int64_t>;
}
