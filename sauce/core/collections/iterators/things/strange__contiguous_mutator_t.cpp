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
						contiguous_mutator_t<iterator_d, element_d>::equal_iterator,
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
				contiguous_mutator_t<iterator_d, element_d>::less_iterator,
				contiguous_mutator_t<iterator_d, element_d>::less_or_equal_iterator,
				contiguous_mutator_t<iterator_d, element_d>::self_add,
				contiguous_mutator_t<iterator_d, element_d>::add,
			},
			// contiguous_mutator_a
			reinterpret_cast<decltype(contiguous_mutator_o<element_d>::add)>(contiguous_mutator_t<iterator_d, element_d>::add),
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

	// instantiation
	template struct contiguous_mutator_t<std::vector<int64_t>::iterator, int64_t>;
}
