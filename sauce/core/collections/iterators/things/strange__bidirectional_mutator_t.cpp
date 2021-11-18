#include "../../../strange__core.h"

namespace strange
{
	// bidirectional_mutator_t
	// bidirectional_mutator_o
	template <typename iterator_d, typename element_d>
	bidirectional_mutator_o<element_d> const* bidirectional_mutator_t<iterator_d, element_d>::_operations()
	{
		static bidirectional_mutator_o<element_d> operations =
		{
			{
				{
					// any_a
					bidirectional_mutator_a<element_d>::cat,
					bidirectional_mutator_t<iterator_d, element_d>::is,
					bidirectional_mutator_t<iterator_d, element_d>::as,
					bidirectional_mutator_t<iterator_d, element_d>::type,
					bidirectional_mutator_t<iterator_d, element_d>::set_error,
					bidirectional_mutator_t<iterator_d, element_d>::error,
					bidirectional_mutator_t<iterator_d, element_d>::hash,
					bidirectional_mutator_t<iterator_d, element_d>::equal,
					bidirectional_mutator_t<iterator_d, element_d>::less,
					bidirectional_mutator_t<iterator_d, element_d>::less_or_equal,
					bidirectional_mutator_t<iterator_d, element_d>::pack,
					bidirectional_mutator_t<iterator_d, element_d>::_free,
					bidirectional_mutator_t<iterator_d, element_d>::_copy,
					bidirectional_mutator_t<iterator_d, element_d>::_set_pointer,
					bidirectional_mutator_t<iterator_d, element_d>::_pointer,
				},
				// forward_mutator_a
				bidirectional_mutator_t<iterator_d, element_d>::equal_iterator,
				bidirectional_mutator_t<iterator_d, element_d>::get,
				bidirectional_mutator_t<iterator_d, element_d>::set,
				bidirectional_mutator_t<iterator_d, element_d>::increment,
				bidirectional_mutator_t<iterator_d, element_d>::_operator_star,
				bidirectional_mutator_t<iterator_d, element_d>::_operator_arrow,
			},
			// bidirectional_mutator_a
			bidirectional_mutator_t<iterator_d, element_d>::decrement,
		};
		return &operations;
	}

	template <typename iterator_d, typename element_d>
	bidirectional_mutator_o<element_d> const* bidirectional_mutator_t<iterator_d, element_d>::_pointer_operations()
	{
		static bidirectional_mutator_o<element_d> operations = []()
		{
			bidirectional_mutator_o<element_d> ops = *bidirectional_mutator_t<iterator_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename element_d>
	bool bidirectional_mutator_t<iterator_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat ||
			abc == bidirectional_mutator_a<element_d>::cat;
	}

	template <typename iterator_d, typename element_d>
	bool bidirectional_mutator_t<iterator_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!bidirectional_mutator_t<iterator_d, element_d>::is(me, abstraction))
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
	var<symbol_a> bidirectional_mutator_t<iterator_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::bidirectional_mutator");
		return r;
	}

	template <typename iterator_d, typename element_d>
	void bidirectional_mutator_t<iterator_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new bidirectional_mutator_t<iterator_d, element_d>{ copy, me };
		bidirectional_mutator_t<iterator_d, element_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename element_d>
	void bidirectional_mutator_t<iterator_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? bidirectional_mutator_t<iterator_d, element_d>::_pointer_operations() : bidirectional_mutator_t<iterator_d, element_d>::_operations();
	}

	// bidirectional_mutator_a
	template <typename iterator_d, typename element_d>
	void bidirectional_mutator_t<iterator_d, element_d>::decrement(var<bidirectional_mutator_a<element_d>> const& me)
	{
		me.mut();
		--(static_cast<bidirectional_mutator_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	// instantiation
	template struct bidirectional_mutator_t<std::vector<int64_t>::iterator, int64_t>;
	template struct bidirectional_mutator_t<std::vector<var<>>::iterator, var<>>;
	template struct bidirectional_mutator_t<std::deque<int64_t>::iterator, int64_t>;
}
