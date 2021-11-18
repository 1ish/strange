#include "../../../strange__core.h"

namespace strange
{
	// random_access_mutator_t
	// random_access_mutator_o
	template <typename iterator_d, typename element_d>
	random_access_mutator_o<element_d> const* random_access_mutator_t<iterator_d, element_d>::_operations()
	{
		static random_access_mutator_o<element_d> operations =
		{
			{
				{
					{
						// any_a
						random_access_mutator_a<element_d>::cat,
						random_access_mutator_t<iterator_d, element_d>::is,
						random_access_mutator_t<iterator_d, element_d>::as,
						random_access_mutator_t<iterator_d, element_d>::type,
						random_access_mutator_t<iterator_d, element_d>::set_error,
						random_access_mutator_t<iterator_d, element_d>::error,
						random_access_mutator_t<iterator_d, element_d>::hash,
						random_access_mutator_t<iterator_d, element_d>::equal,
						random_access_mutator_t<iterator_d, element_d>::less,
						random_access_mutator_t<iterator_d, element_d>::less_or_equal,
						random_access_mutator_t<iterator_d, element_d>::pack,
						random_access_mutator_t<iterator_d, element_d>::_free,
						random_access_mutator_t<iterator_d, element_d>::_copy,
						random_access_mutator_t<iterator_d, element_d>::_set_pointer,
						random_access_mutator_t<iterator_d, element_d>::_pointer,
					},
					// forward_mutator_a
					random_access_mutator_t<iterator_d, element_d>::equal_iterator,
					random_access_mutator_t<iterator_d, element_d>::get,
					random_access_mutator_t<iterator_d, element_d>::set,
					random_access_mutator_t<iterator_d, element_d>::increment,
					random_access_mutator_t<iterator_d, element_d>::_operator_star,
					random_access_mutator_t<iterator_d, element_d>::_operator_arrow,
				},
				// bidirectional_mutator_a
				random_access_mutator_t<iterator_d, element_d>::decrement,
			},
			// random_access_mutator_a
			random_access_mutator_t<iterator_d, element_d>::less_iterator,
			random_access_mutator_t<iterator_d, element_d>::less_or_equal_iterator,
			random_access_mutator_t<iterator_d, element_d>::self_add,
			random_access_mutator_t<iterator_d, element_d>::add,
		};
		return &operations;
	}

	template <typename iterator_d, typename element_d>
	random_access_mutator_o<element_d> const* random_access_mutator_t<iterator_d, element_d>::_pointer_operations()
	{
		static random_access_mutator_o<element_d> operations = []()
		{
			random_access_mutator_o<element_d> ops = *random_access_mutator_t<iterator_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename element_d>
	bool random_access_mutator_t<iterator_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat ||
			abc == bidirectional_mutator_a<element_d>::cat ||
			abc == random_access_mutator_a<element_d>::cat;
	}

	template <typename iterator_d, typename element_d>
	bool random_access_mutator_t<iterator_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!random_access_mutator_t<iterator_d, element_d>::is(me, abstraction))
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
	var<symbol_a> random_access_mutator_t<iterator_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::random_access_mutator");
		return r;
	}

	template <typename iterator_d, typename element_d>
	bool random_access_mutator_t<iterator_d, element_d>::less(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<random_access_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return random_access_mutator_t<iterator_d, element_d>::less_iterator(me.reference<con<random_access_mutator_a<element_d>>>(), oi);
		}
		return thing_t::less(me, other);
	}

	template <typename iterator_d, typename element_d>
	bool random_access_mutator_t<iterator_d, element_d>::less_or_equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<random_access_mutator_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return random_access_mutator_t<iterator_d, element_d>::less_or_equal_iterator(me.reference<con<random_access_mutator_a<element_d>>>(), oi);
		}
		return thing_t::less_or_equal(me, other);
	}

	template <typename iterator_d, typename element_d>
	void random_access_mutator_t<iterator_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new random_access_mutator_t<iterator_d, element_d>{ copy, me };
		random_access_mutator_t<iterator_d, element_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename element_d>
	void random_access_mutator_t<iterator_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? random_access_mutator_t<iterator_d, element_d>::_pointer_operations() : random_access_mutator_t<iterator_d, element_d>::_operations();
	}

	// random_access_mutator_a
	template <typename iterator_d, typename element_d>
	void random_access_mutator_t<iterator_d, element_d>::self_add(var<random_access_mutator_a<element_d>> const& me,
		int64_t offset)
	{
		me.mut();
		(static_cast<random_access_mutator_t<iterator_d, element_d>*>(me.t)->iterator_) += offset;
	}

	template <typename iterator_d, typename element_d>
	rat<random_access_mutator_a<element_d>> random_access_mutator_t<iterator_d, element_d>::add(con<random_access_mutator_a<element_d>> const& me,
		int64_t offset)
	{
		rat<random_access_mutator_a<element_d>> result{ me };
		self_add(result, offset);
		return result;
	}

	// instantiation
	template struct random_access_mutator_t<std::vector<int64_t>::iterator, int64_t>;
	template struct random_access_mutator_t<std::vector<var<>>::iterator, var<>>;
	template struct random_access_mutator_t<std::deque<int64_t>::iterator, int64_t>;
}
