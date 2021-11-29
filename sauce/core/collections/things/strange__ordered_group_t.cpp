#include "../../strange__core.h"

namespace strange
{
	// ordered_group_t
	// ordered_group_o
	template <typename collection_d, typename element_d>
	ordered_group_o<element_d> const* ordered_group_t<collection_d, element_d>::_operations()
	{
		static ordered_group_o<element_d> operations =
		{
			{
				{
					{
						// any_a
						ordered_group_a<element_d>::cat,
						ordered_group_t<collection_d, element_d>::is,
						ordered_group_t<collection_d, element_d>::as,
						ordered_group_t<collection_d, element_d>::type,
						ordered_group_t<collection_d, element_d>::set_error,
						ordered_group_t<collection_d, element_d>::error,
						ordered_group_t<collection_d, element_d>::hash,
						ordered_group_t<collection_d, element_d>::equal,
						ordered_group_t<collection_d, element_d>::less,
						ordered_group_t<collection_d, element_d>::less_or_equal,
						ordered_group_t<collection_d, element_d>::pack,
						ordered_group_t<collection_d, element_d>::_free,
						ordered_group_t<collection_d, element_d>::_copy,
						ordered_group_t<collection_d, element_d>::_set_pointer,
						ordered_group_t<collection_d, element_d>::_pointer,
					},
					// collection_a
					reinterpret_cast<decltype(collection_o<element_d, element_d, element_d>::range)>(ordered_group_t<collection_d, element_d>::range),
					reinterpret_cast<decltype(collection_o<element_d, element_d, element_d>::begin)>(ordered_group_t<collection_d, element_d>::begin),
					reinterpret_cast<decltype(collection_o<element_d, element_d, element_d>::end)>(ordered_group_t<collection_d, element_d>::end),
					ordered_group_t<collection_d, element_d>::read_lock,
					ordered_group_t<collection_d, element_d>::write_lock,
					ordered_group_t<collection_d, element_d>::has,
					ordered_group_t<collection_d, element_d>::at,
					ordered_group_t<collection_d, element_d>::update,
					ordered_group_t<collection_d, element_d>::insert,
					ordered_group_t<collection_d, element_d>::erase,
					ordered_group_t<collection_d, element_d>::clear,
					ordered_group_t<collection_d, element_d>::size,
					ordered_group_t<collection_d, element_d>::empty,
					ordered_group_t<collection_d, element_d>::push_front,
					ordered_group_t<collection_d, element_d>::pop_front,
					ordered_group_t<collection_d, element_d>::push_back,
					ordered_group_t<collection_d, element_d>::pop_back,
					ordered_group_t<collection_d, element_d>::self_assign,
					ordered_group_t<collection_d, element_d>::self_add,
					ordered_group_t<collection_d, element_d>::add,
					ordered_group_t<collection_d, element_d>::self_subtract,
					ordered_group_t<collection_d, element_d>::subtract,
				},
				// group_a
				ordered_group_t<collection_d, element_d>::update_element,
				ordered_group_t<collection_d, element_d>::insert_element,
			},
			// ordered_group_a
			ordered_group_t<collection_d, element_d>::range,
			ordered_group_t<collection_d, element_d>::begin,
			ordered_group_t<collection_d, element_d>::end,
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	ordered_group_o<element_d> const* ordered_group_t<collection_d, element_d>::_pointer_operations()
	{
		static ordered_group_o<element_d> operations = []()
		{
			ordered_group_o<element_d> ops = *ordered_group_t<collection_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename element_d>
	bool ordered_group_t<collection_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<element_d, element_d, element_d>::cat ||
			abc == group_a<element_d>::cat ||
			abc == ordered_group_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool ordered_group_t<collection_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_group_t<collection_d, element_d>::is(me, abstraction))
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

	template <typename collection_d, typename element_d>
	var<symbol_a> ordered_group_t<collection_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::ordered_group");
		return r;
	}

	template <typename collection_d, typename element_d>
	void ordered_group_t<collection_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_group_t<collection_d, element_d>{ copy, me };
		ordered_group_t<collection_d, element_d>::_clone(me, copy);
	}

	template <typename collection_d, typename element_d>
	void ordered_group_t<collection_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_group_t<collection_d, element_d>::_pointer_operations() : ordered_group_t<collection_d, element_d>::_operations();
	}

	// ordered_group_a
	template <typename collection_d, typename element_d>
	var<bidirectional_range_a<element_d>> ordered_group_t<collection_d, element_d>::range(con<ordered_group_a<element_d>> const& me)
	{
		bidirectional_range_a<element_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = ordered_group_t<collection_d, element_d>::_range_operations();
		return var<bidirectional_range_a<element_d>>{ abstraction };
	}

	template <typename collection_d, typename element_d>
	bit<bidirectional_extractor_a<element_d>> ordered_group_t<collection_d, element_d>::begin(con<ordered_group_a<element_d>> const& me)
	{
		return bidirectional_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<ordered_group_t<collection_d, element_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename element_d>
	bit<bidirectional_extractor_a<element_d>> ordered_group_t<collection_d, element_d>::end(con<ordered_group_a<element_d>> const& me)
	{
		return bidirectional_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<ordered_group_t<collection_d, element_d> const*>(me.t)->collection_.cend());
	}

	// bidirectional_range_a
	template <typename collection_d, typename element_d>
	bidirectional_range_o<element_d> const* ordered_group_t<collection_d, element_d>::_range_operations()
	{
		static bidirectional_range_o<element_d> operations =
		{
			{
				{
					// any_a
					bidirectional_range_a<element_d>::cat,
					ordered_group_t<collection_d, element_d>::_range_is,
					ordered_group_t<collection_d, element_d>::_range_as,
					ordered_group_t<collection_d, element_d>::type,
					ordered_group_t<collection_d, element_d>::set_error,
					ordered_group_t<collection_d, element_d>::error,
					ordered_group_t<collection_d, element_d>::hash,
					ordered_group_t<collection_d, element_d>::equal,
					ordered_group_t<collection_d, element_d>::less,
					ordered_group_t<collection_d, element_d>::less_or_equal,
					ordered_group_t<collection_d, element_d>::pack,
					ordered_group_t<collection_d, element_d>::_free,
					ordered_group_t<collection_d, element_d>::_range_copy,
					ordered_group_t<collection_d, element_d>::_range_set_pointer,
					ordered_group_t<collection_d, element_d>::_pointer,
				},
				// range_a
				reinterpret_cast<decltype(range_o<element_d>::begin)>(ordered_group_t<collection_d, element_d>::begin),
				reinterpret_cast<decltype(range_o<element_d>::end)>(ordered_group_t<collection_d, element_d>::end),
			},
			// bidirectional_range_a
			reinterpret_cast<decltype(bidirectional_range_o<element_d>::begin)>(ordered_group_t<collection_d, element_d>::begin),
			reinterpret_cast<decltype(bidirectional_range_o<element_d>::end)>(ordered_group_t<collection_d, element_d>::end),
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	bidirectional_range_o<element_d> const* ordered_group_t<collection_d, element_d>::_range_pointer_operations()
	{
		static bidirectional_range_o<element_d> operations = []()
		{
			bidirectional_range_o<element_d> ops = *ordered_group_t<collection_d, element_d>::_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename element_d>
	bool ordered_group_t<collection_d, element_d>::_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<element_d>::cat ||
			abc == bidirectional_range_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool ordered_group_t<collection_d, element_d>::_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_group_t<collection_d, element_d>::_range_is(me, abstraction))
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

	template <typename collection_d, typename element_d>
	void ordered_group_t<collection_d, element_d>::_range_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_group_t<collection_d, element_d>{ copy, me };
		ordered_group_t<collection_d, element_d>::_clone(me, copy);
		copy.o = ordered_group_t<collection_d, element_d>::_range_operations();
	}

	template <typename collection_d, typename element_d>
	void ordered_group_t<collection_d, element_d>::_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_group_t<collection_d, element_d>::_range_pointer_operations() : ordered_group_t<collection_d, element_d>::_range_operations();
	}

	// instantiation
	template struct ordered_group_t<std::set<int64_t>, int64_t>;
	template struct ordered_group_t<std::set<var<>>, var<>>;
}
