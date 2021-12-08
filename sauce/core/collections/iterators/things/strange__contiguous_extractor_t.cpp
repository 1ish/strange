#include "../../../strange__core.h"

namespace strange
{
	// contiguous_extractor_t
	// contiguous_extractor_o
	template <typename iterator_d, typename element_d>
	contiguous_extractor_o<element_d> const* contiguous_extractor_t<iterator_d, element_d>::_operations()
	{
		static contiguous_extractor_o<element_d> operations =
		{
			{
				{
					{
						{
							// any_a
							contiguous_extractor_a<element_d>::cat,
							contiguous_extractor_t<iterator_d, element_d>::is,
							contiguous_extractor_t<iterator_d, element_d>::as,
							contiguous_extractor_t<iterator_d, element_d>::type,
							contiguous_extractor_t<iterator_d, element_d>::set_error,
							contiguous_extractor_t<iterator_d, element_d>::error,
							contiguous_extractor_t<iterator_d, element_d>::hash,
							contiguous_extractor_t<iterator_d, element_d>::equal,
							contiguous_extractor_t<iterator_d, element_d>::less,
							contiguous_extractor_t<iterator_d, element_d>::less_or_equal,
							contiguous_extractor_t<iterator_d, element_d>::pack,
							contiguous_extractor_t<iterator_d, element_d>::_free,
							contiguous_extractor_t<iterator_d, element_d>::_copy,
							contiguous_extractor_t<iterator_d, element_d>::_set_pointer,
							contiguous_extractor_t<iterator_d, element_d>::_pointer,
						},
						// forward_extractor_a
						contiguous_extractor_t<iterator_d, element_d>::equal_iterator,
						contiguous_extractor_t<iterator_d, element_d>::get,
						contiguous_extractor_t<iterator_d, element_d>::increment,
						contiguous_extractor_t<iterator_d, element_d>::_operator_star,
						contiguous_extractor_t<iterator_d, element_d>::_operator_arrow,
					},
					// bidirectional_extractor_a
					contiguous_extractor_t<iterator_d, element_d>::decrement,
				},
				// random_access_extractor_a
				contiguous_extractor_t<iterator_d, element_d>::less_iterator,
				contiguous_extractor_t<iterator_d, element_d>::less_or_equal_iterator,
				contiguous_extractor_t<iterator_d, element_d>::self_add,
				contiguous_extractor_t<iterator_d, element_d>::add,
			},
			// contiguous_extractor_a
			reinterpret_cast<decltype(contiguous_extractor_o<element_d>::add)>(contiguous_extractor_t<iterator_d, element_d>::add),
		};
		return &operations;
	}

	template <typename iterator_d, typename element_d>
	contiguous_extractor_o<element_d> const* contiguous_extractor_t<iterator_d, element_d>::_pointer_operations()
	{
		static contiguous_extractor_o<element_d> operations = []()
		{
			contiguous_extractor_o<element_d> ops = *contiguous_extractor_t<iterator_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename element_d>
	bool contiguous_extractor_t<iterator_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_extractor_a<element_d>::cat ||
			abc == bidirectional_extractor_a<element_d>::cat ||
			abc == random_access_extractor_a<element_d>::cat ||
			abc == contiguous_extractor_a<element_d>::cat;
	}

	template <typename iterator_d, typename element_d>
	bool contiguous_extractor_t<iterator_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!contiguous_extractor_t<iterator_d, element_d>::is(me, abstraction))
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
	var<symbol_a> contiguous_extractor_t<iterator_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::contiguous_extractor");
		return r;
	}

	template <typename iterator_d, typename element_d>
	void contiguous_extractor_t<iterator_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new contiguous_extractor_t<iterator_d, element_d>{ copy, me };
		contiguous_extractor_t<iterator_d, element_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename element_d>
	void contiguous_extractor_t<iterator_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? contiguous_extractor_t<iterator_d, element_d>::_pointer_operations() : contiguous_extractor_t<iterator_d, element_d>::_operations();
	}

	// instantiation
	template struct contiguous_extractor_t<std::vector<int64_t>::const_iterator, int64_t>;
	template struct contiguous_extractor_t<std::vector<var<>>::const_iterator, var<>>;
	template struct contiguous_extractor_t<std::vector<uint8_t>::const_iterator, uint8_t>;
	template struct contiguous_extractor_t<std::deque<int64_t>::const_iterator, int64_t>;
}
