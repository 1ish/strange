#include "../../../../strange.h"

namespace strange
{
	// contiguous_mutator_t
	// contiguous_mutator_o
	template <typename iterator_d, typename element_d>
	contiguous_mutator_o<element_d> const* contiguous_mutator_t<iterator_d, element_d>::_operations()
	{
		static contiguous_mutator_o<element_d> operations =
		{
			{
				{
					{
						{
							// any_a
							contiguous_mutator_a<element_d>::cat,
							contiguous_mutator_t<iterator_d, element_d>::is,
							contiguous_mutator_t<iterator_d, element_d>::as,
							contiguous_mutator_t<iterator_d, element_d>::type,
							contiguous_mutator_t<iterator_d, element_d>::set_error,
							contiguous_mutator_t<iterator_d, element_d>::error,
							contiguous_mutator_t<iterator_d, element_d>::hash,
							contiguous_mutator_t<iterator_d, element_d>::equal,
							contiguous_mutator_t<iterator_d, element_d>::less,
							contiguous_mutator_t<iterator_d, element_d>::less_or_equal,
							contiguous_mutator_t<iterator_d, element_d>::pack,
							contiguous_mutator_t<iterator_d, element_d>::_free,
							contiguous_mutator_t<iterator_d, element_d>::_copy,
							contiguous_mutator_t<iterator_d, element_d>::_set_pointer,
							contiguous_mutator_t<iterator_d, element_d>::_pointer,
						},
						// forward_mutator_a
						reinterpret_cast<decltype(forward_mutator_o<element_d>::equal)>(contiguous_mutator_t<iterator_d, element_d>::equal_iterator),
						contiguous_mutator_t<iterator_d, element_d>::get,
						contiguous_mutator_t<iterator_d, element_d>::set,
						contiguous_mutator_t<iterator_d, element_d>::increment,
						contiguous_mutator_t<iterator_d, element_d>::_operator_star,
						contiguous_mutator_t<iterator_d, element_d>::_operator_arrow,
					},
					// bidirectional_mutator_a
					contiguous_mutator_t<iterator_d, element_d>::decrement,
				},
				// random_access_mutator_a
				reinterpret_cast<decltype(random_access_mutator_o<element_d>::less)>(contiguous_mutator_t<iterator_d, element_d>::less_iterator),
				reinterpret_cast<decltype(random_access_mutator_o<element_d>::less_or_equal)>(contiguous_mutator_t<iterator_d, element_d>::less_or_equal_iterator),
				contiguous_mutator_t<iterator_d, element_d>::self_add,
				reinterpret_cast<decltype(random_access_mutator_o<element_d>::add)>(contiguous_mutator_t<iterator_d, element_d>::add),
			},
			// contiguous_mutator_a
			contiguous_mutator_t<iterator_d, element_d>::add,
		};
		return &operations;
	}

	template <typename iterator_d, typename element_d>
	contiguous_mutator_o<element_d> const* contiguous_mutator_t<iterator_d, element_d>::_pointer_operations()
	{
		static contiguous_mutator_o<element_d> operations = []()
		{
			contiguous_mutator_o<element_d> ops = *contiguous_mutator_t<iterator_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename element_d>
	bool contiguous_mutator_t<iterator_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat ||
			abc == bidirectional_mutator_a<element_d>::cat ||
			abc == random_access_mutator_a<element_d>::cat ||
			abc == contiguous_mutator_a<element_d>::cat;
	}

	template <typename iterator_d, typename element_d>
	bool contiguous_mutator_t<iterator_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!contiguous_mutator_t<iterator_d, element_d>::is(me, abstraction))
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
	var<symbol_a> contiguous_mutator_t<iterator_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::contiguous_mutator");
		return r;
	}

	template <typename iterator_d, typename element_d>
	bool contiguous_mutator_t<iterator_d, element_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<contiguous_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return contiguous_mutator_t<iterator_d, element_d>::equal_iterator(me.reference<con<contiguous_mutator_a<element_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename iterator_d, typename element_d>
	bool contiguous_mutator_t<iterator_d, element_d>::less(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<contiguous_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return contiguous_mutator_t<iterator_d, element_d>::less_iterator(me.reference<con<contiguous_mutator_a<element_d>>>(), oi);
		}
		return thing_t::less(me, other);
	}

	template <typename iterator_d, typename element_d>
	bool contiguous_mutator_t<iterator_d, element_d>::less_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<contiguous_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return contiguous_mutator_t<iterator_d, element_d>::less_or_equal_iterator(me.reference<con<contiguous_mutator_a<element_d>>>(), oi);
		}
		return thing_t::less_or_equal(me, other);
	}

	template <typename iterator_d, typename element_d>
	void contiguous_mutator_t<iterator_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new contiguous_mutator_t<iterator_d, element_d>{ copy, me };
		contiguous_mutator_t<iterator_d, element_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename element_d>
	void contiguous_mutator_t<iterator_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? contiguous_mutator_t<iterator_d, element_d>::_pointer_operations() : contiguous_mutator_t<iterator_d, element_d>::_operations();
	}

	// forward_mutator_a
	template <typename iterator_d, typename element_d>
	element_d contiguous_mutator_t<iterator_d, element_d>::get(con<forward_mutator_a<element_d>> const& me)
	{
		return *(static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename element_d>
	void contiguous_mutator_t<iterator_d, element_d>::set(con<forward_mutator_a<element_d>> const& me,
		element_d const& element)
	{
		*(static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_) = element;
	}

	template <typename iterator_d, typename element_d>
	void contiguous_mutator_t<iterator_d, element_d>::increment(var<forward_mutator_a<element_d>> const& me)
	{
		me.mut();
		++(static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename element_d>
	element_d& contiguous_mutator_t<iterator_d, element_d>::_operator_star(con<forward_mutator_a<element_d>> const& me)
	{
		return (static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_).operator*();
	}

	template <typename iterator_d, typename element_d>
	element_d* contiguous_mutator_t<iterator_d, element_d>::_operator_arrow(con<forward_mutator_a<element_d>> const& me)
	{
		return (static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_).operator->();
	}

	// bidirectional_mutator_a
	template <typename iterator_d, typename element_d>
	void contiguous_mutator_t<iterator_d, element_d>::decrement(var<bidirectional_mutator_a<element_d>> const& me)
	{
		me.mut();
		--(static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	// random_access_mutator_a
	template <typename iterator_d, typename element_d>
	void contiguous_mutator_t<iterator_d, element_d>::self_add(var<random_access_mutator_a<element_d>> const& me,
		int64_t offset)
	{
		me.mut();
		(static_cast<contiguous_mutator_t<iterator_d, element_d>*>(me.t)->iterator_) += offset;
	}

	// contiguous_mutator_a
	template <typename iterator_d, typename element_d>
	rat<contiguous_mutator_a<element_d>> contiguous_mutator_t<iterator_d, element_d>::add(con<contiguous_mutator_a<element_d>> const& me,
		int64_t offset)
	{
		rat<contiguous_mutator_a<element_d>> result{ me };
		self_add(result, offset);
		return result;
	}

	// instantiation
	template struct contiguous_mutator_t<std::vector<int64_t>::iterator, int64_t>;
}
