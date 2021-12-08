#include "../../../strange__core.h"

namespace strange
{
	// forward_extractor_t
	// forward_extractor_o
	template <typename iterator_d, typename element_d>
	forward_extractor_o<element_d> const* forward_extractor_t<iterator_d, element_d>::_operations()
	{
		static forward_extractor_o<element_d> operations =
		{
			{
				// any_a
				forward_extractor_a<element_d>::cat,
				forward_extractor_t<iterator_d, element_d>::is,
				forward_extractor_t<iterator_d, element_d>::as,
				forward_extractor_t<iterator_d, element_d>::type,
				forward_extractor_t<iterator_d, element_d>::set_error,
				forward_extractor_t<iterator_d, element_d>::error,
				forward_extractor_t<iterator_d, element_d>::hash,
				forward_extractor_t<iterator_d, element_d>::equal,
				forward_extractor_t<iterator_d, element_d>::less,
				forward_extractor_t<iterator_d, element_d>::less_or_equal,
				forward_extractor_t<iterator_d, element_d>::pack,
				forward_extractor_t<iterator_d, element_d>::_free,
				forward_extractor_t<iterator_d, element_d>::_copy,
				forward_extractor_t<iterator_d, element_d>::_set_pointer,
				forward_extractor_t<iterator_d, element_d>::_pointer,
			},
			// forward_extractor_a
			forward_extractor_t<iterator_d, element_d>::equal_iterator,
			forward_extractor_t<iterator_d, element_d>::get,
			forward_extractor_t<iterator_d, element_d>::increment,
			forward_extractor_t<iterator_d, element_d>::_operator_star,
			forward_extractor_t<iterator_d, element_d>::_operator_arrow,
		};
		return &operations;
	}

	template <typename iterator_d, typename element_d>
	forward_extractor_o<element_d> const* forward_extractor_t<iterator_d, element_d>::_pointer_operations()
	{
		static forward_extractor_o<element_d> operations = []()
		{
			forward_extractor_o<element_d> ops = *forward_extractor_t<iterator_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename element_d>
	bool forward_extractor_t<iterator_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_extractor_a<element_d>::cat;
	}

	template <typename iterator_d, typename element_d>
	bool forward_extractor_t<iterator_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!forward_extractor_t<iterator_d, element_d>::is(me, abstraction))
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
	var<symbol_a> forward_extractor_t<iterator_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::forward_extractor");
		return r;
	}

	template <typename iterator_d, typename element_d>
	bool forward_extractor_t<iterator_d, element_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<forward_extractor_a<element_d>>>();
		if (oi.o->something(oi))
		{
			return forward_extractor_t<iterator_d, element_d>::equal_iterator(me.reference<con<forward_extractor_a<element_d>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename iterator_d, typename element_d>
	void forward_extractor_t<iterator_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new forward_extractor_t<iterator_d, element_d>{ copy, me };
		forward_extractor_t<iterator_d, element_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename element_d>
	void forward_extractor_t<iterator_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? forward_extractor_t<iterator_d, element_d>::_pointer_operations() : forward_extractor_t<iterator_d, element_d>::_operations();
	}

	// forward_extractor_a
	template <typename iterator_d, typename element_d>
	element_d forward_extractor_t<iterator_d, element_d>::get(con<forward_extractor_a<element_d>> const& me)
	{
		return *(static_cast<forward_extractor_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename element_d>
	void forward_extractor_t<iterator_d, element_d>::increment(var<forward_extractor_a<element_d>> const& me)
	{
		me.mut();
		++(static_cast<forward_extractor_t<iterator_d, element_d>*>(me.t)->iterator_);
	}

	template <typename iterator_d, typename element_d>
	element_d const& forward_extractor_t<iterator_d, element_d>::_operator_star(con<forward_extractor_a<element_d>> const& me)
	{
		return (static_cast<forward_extractor_t<iterator_d, element_d>*>(me.t)->iterator_).operator*();
	}

	template <typename iterator_d, typename element_d>
	element_d const* forward_extractor_t<iterator_d, element_d>::_operator_arrow(con<forward_extractor_a<element_d>> const& me)
	{
		return (static_cast<forward_extractor_t<iterator_d, element_d>*>(me.t)->iterator_).operator->();
	}

	// instantiation
	template struct forward_extractor_t<std::vector<int64_t>::const_iterator, int64_t>;
	template struct forward_extractor_t<std::vector<var<>>::const_iterator, var<>>;
	template struct forward_extractor_t<std::vector<uint8_t>::const_iterator, uint8_t>;
	template struct forward_extractor_t<std::deque<int64_t>::const_iterator, int64_t>;
	template struct forward_extractor_t<std::unordered_set<int64_t>::const_iterator, int64_t>;
	template struct forward_extractor_t<std::set<int64_t>::const_iterator, int64_t>;
	template struct forward_extractor_t<std::set<var<>>::const_iterator, var<>>;
}
