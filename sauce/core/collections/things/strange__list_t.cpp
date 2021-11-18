#include "../../strange__core.h"

namespace strange
{
	// list_t
	// list_o
	template <typename collection_d, typename element_d>
	list_o<element_d> const* list_t<collection_d, element_d>::_operations()
	{
		static list_o<element_d> operations =
		{
			{
				{
					{
						// any_a
						list_a<element_d>::cat,
						list_t<collection_d, element_d>::is,
						list_t<collection_d, element_d>::as,
						list_t<collection_d, element_d>::type,
						list_t<collection_d, element_d>::set_error,
						list_t<collection_d, element_d>::error,
						list_t<collection_d, element_d>::hash,
						list_t<collection_d, element_d>::equal,
						list_t<collection_d, element_d>::less,
						list_t<collection_d, element_d>::less_or_equal,
						list_t<collection_d, element_d>::pack,
						list_t<collection_d, element_d>::_free,
						list_t<collection_d, element_d>::_copy,
						list_t<collection_d, element_d>::_set_pointer,
						list_t<collection_d, element_d>::_pointer,
					},
					// collection_a
					reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::range)>(list_t<collection_d, element_d>::range),
					reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::begin)>(list_t<collection_d, element_d>::begin),
					reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::end)>(list_t<collection_d, element_d>::end),
					list_t<collection_d, element_d>::read_lock,
					list_t<collection_d, element_d>::write_lock,
					list_t<collection_d, element_d>::has,
					list_t<collection_d, element_d>::at,
					list_t<collection_d, element_d>::update,
					list_t<collection_d, element_d>::insert,
					list_t<collection_d, element_d>::erase,
					list_t<collection_d, element_d>::clear,
					list_t<collection_d, element_d>::size,
					list_t<collection_d, element_d>::empty,
					list_t<collection_d, element_d>::push_front,
					list_t<collection_d, element_d>::pop_front,
					list_t<collection_d, element_d>::push_back,
					list_t<collection_d, element_d>::pop_back,
					list_t<collection_d, element_d>::self_assign,
					list_t<collection_d, element_d>::self_add,
					list_t<collection_d, element_d>::add,
					list_t<collection_d, element_d>::self_subtract,
					list_t<collection_d, element_d>::subtract,
				},
				// queue_a
				reinterpret_cast<decltype(queue_o<element_d>::range)>(list_t<collection_d, element_d>::range),
				reinterpret_cast<decltype(queue_o<element_d>::begin)>(list_t<collection_d, element_d>::begin),
				reinterpret_cast<decltype(queue_o<element_d>::end)>(list_t<collection_d, element_d>::end),
				reinterpret_cast<decltype(queue_o<element_d>::mutator_range)>(list_t<collection_d, element_d>::mutator_range),
				reinterpret_cast<decltype(queue_o<element_d>::mutator_begin)>(list_t<collection_d, element_d>::mutator_begin),
				reinterpret_cast<decltype(queue_o<element_d>::mutator_end)>(list_t<collection_d, element_d>::mutator_end),
			},
			// list_a
			list_t<collection_d, element_d>::range,
			list_t<collection_d, element_d>::begin,
			list_t<collection_d, element_d>::end,
			list_t<collection_d, element_d>::mutator_range,
			list_t<collection_d, element_d>::mutator_begin,
			list_t<collection_d, element_d>::mutator_end,
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	list_o<element_d> const* list_t<collection_d, element_d>::_pointer_operations()
	{
		static list_o<element_d> operations = []()
		{
			list_o<element_d> ops = *list_t<collection_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename element_d>
	bool list_t<collection_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<int64_t, element_d, element_d>::cat ||
			abc == queue_a<element_d>::cat ||
			abc == list_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool list_t<collection_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!list_t<collection_d, element_d>::is(me, abstraction))
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
	var<symbol_a> list_t<collection_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::list");
		return r;
	}

	template <typename collection_d, typename element_d>
	void list_t<collection_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new list_t<collection_d, element_d>{ copy, me };
		list_t<collection_d, element_d>::_clone(me, copy);
	}

	template <typename collection_d, typename element_d>
	void list_t<collection_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? list_t<collection_d, element_d>::_pointer_operations() : list_t<collection_d, element_d>::_operations();
	}

	// list_a
	template <typename collection_d, typename element_d>
	var<contiguous_range_a<element_d>> list_t<collection_d, element_d>::range(con<list_a<element_d>> const& me)
	{
		contiguous_range_a<element_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = list_t<collection_d, element_d>::_range_operations();
		return var<contiguous_range_a<element_d>>{ abstraction };
	}

	template <typename collection_d, typename element_d>
	rat<contiguous_extractor_a<element_d>> list_t<collection_d, element_d>::begin(con<list_a<element_d>> const& me)
	{
		return contiguous_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<list_t<collection_d, element_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename element_d>
	rat<contiguous_extractor_a<element_d>> list_t<collection_d, element_d>::end(con<list_a<element_d>> const& me)
	{
		return contiguous_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<list_t<collection_d, element_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename element_d>
	var<contiguous_mutator_range_a<element_d>> list_t<collection_d, element_d>::mutator_range(var<list_a<element_d>> const& me)
	{
		me.mut();
		contiguous_mutator_range_a<element_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = list_t<collection_d, element_d>::_mutator_range_operations();
		return var<contiguous_mutator_range_a<element_d>>{ abstraction };
	}

	template <typename collection_d, typename element_d>
	rat<contiguous_mutator_a<element_d>> list_t<collection_d, element_d>::mutator_begin(var<list_a<element_d>> const& me)
	{
		me.mut();
		return contiguous_mutator_t<typename collection_d::iterator, element_d>::create(static_cast<list_t<collection_d, element_d>*>(me.t)->collection_.begin());
	}

	template <typename collection_d, typename element_d>
	rat<contiguous_mutator_a<element_d>> list_t<collection_d, element_d>::mutator_end(var<list_a<element_d>> const& me)
	{
		me.mut();
		return contiguous_mutator_t<typename collection_d::iterator, element_d>::create(static_cast<list_t<collection_d, element_d>*>(me.t)->collection_.end());
	}

	// contiguous_range_a
	template <typename collection_d, typename element_d>
	contiguous_range_o<element_d> const* list_t<collection_d, element_d>::_range_operations()
	{
		static contiguous_range_o<element_d> operations =
		{
			{
				{
					{
						{
							// any_a
							contiguous_range_a<element_d>::cat,
							list_t<collection_d, element_d>::_range_is,
							list_t<collection_d, element_d>::_range_as,
							list_t<collection_d, element_d>::type,
							list_t<collection_d, element_d>::set_error,
							list_t<collection_d, element_d>::error,
							list_t<collection_d, element_d>::hash,
							list_t<collection_d, element_d>::equal,
							list_t<collection_d, element_d>::less,
							list_t<collection_d, element_d>::less_or_equal,
							list_t<collection_d, element_d>::pack,
							list_t<collection_d, element_d>::_free,
							list_t<collection_d, element_d>::_range_copy,
							list_t<collection_d, element_d>::_range_set_pointer,
							list_t<collection_d, element_d>::_pointer,
						},
						// range_a
						reinterpret_cast<decltype(range_o<element_d>::begin)>(list_t<collection_d, element_d>::begin),
						reinterpret_cast<decltype(range_o<element_d>::end)>(list_t<collection_d, element_d>::end),
					},
					// bidirectional_range_a
					reinterpret_cast<decltype(bidirectional_range_o<element_d>::begin)>(list_t<collection_d, element_d>::begin),
					reinterpret_cast<decltype(bidirectional_range_o<element_d>::end)>(list_t<collection_d, element_d>::end),
				},
				// random_access_range_a
				reinterpret_cast<decltype(random_access_range_o<element_d>::begin)>(list_t<collection_d, element_d>::begin),
				reinterpret_cast<decltype(random_access_range_o<element_d>::end)>(list_t<collection_d, element_d>::end),
			},
			// contiguous_range_a
			reinterpret_cast<decltype(contiguous_range_o<element_d>::begin)>(list_t<collection_d, element_d>::begin),
			reinterpret_cast<decltype(contiguous_range_o<element_d>::end)>(list_t<collection_d, element_d>::end),
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	contiguous_range_o<element_d> const* list_t<collection_d, element_d>::_range_pointer_operations()
	{
		static contiguous_range_o<element_d> operations = []()
		{
			contiguous_range_o<element_d> ops = *list_t<collection_d, element_d>::_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename element_d>
	bool list_t<collection_d, element_d>::_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<element_d>::cat ||
			abc == bidirectional_range_a<element_d>::cat ||
			abc == random_access_range_a<element_d>::cat ||
			abc == contiguous_range_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool list_t<collection_d, element_d>::_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!list_t<collection_d, element_d>::_range_is(me, abstraction))
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
	void list_t<collection_d, element_d>::_range_copy(con<> const& me,
		var<> const& copy)
	{
		new list_t<collection_d, element_d>{ copy, me };
		list_t<collection_d, element_d>::_clone(me, copy);
		copy.o = list_t<collection_d, element_d>::_range_operations();
	}

	template <typename collection_d, typename element_d>
	void list_t<collection_d, element_d>::_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? list_t<collection_d, element_d>::_range_pointer_operations() : list_t<collection_d, element_d>::_range_operations();
	}

	// contiguous_mutator_range_a
	template <typename collection_d, typename element_d>
	contiguous_mutator_range_o<element_d> const* list_t<collection_d, element_d>::_mutator_range_operations()
	{
		static contiguous_mutator_range_o<element_d> operations =
		{
			{
				{
					{
						{
							// any_a
							contiguous_mutator_range_a<element_d>::cat,
							list_t<collection_d, element_d>::_mutator_range_is,
							list_t<collection_d, element_d>::_mutator_range_as,
							list_t<collection_d, element_d>::type,
							list_t<collection_d, element_d>::set_error,
							list_t<collection_d, element_d>::error,
							list_t<collection_d, element_d>::hash,
							list_t<collection_d, element_d>::equal,
							list_t<collection_d, element_d>::less,
							list_t<collection_d, element_d>::less_or_equal,
							list_t<collection_d, element_d>::pack,
							list_t<collection_d, element_d>::_free,
							list_t<collection_d, element_d>::_mutator_range_copy,
							list_t<collection_d, element_d>::_mutator_range_set_pointer,
							list_t<collection_d, element_d>::_pointer,
						},
						// mutator_range_a
						reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_begin)>(list_t<collection_d, element_d>::mutator_begin),
						reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_end)>(list_t<collection_d, element_d>::mutator_end),
					},
					// bidirectional_mutator_range_a
					reinterpret_cast<decltype(bidirectional_mutator_range_o<element_d>::mutator_begin)>(list_t<collection_d, element_d>::mutator_begin),
					reinterpret_cast<decltype(bidirectional_mutator_range_o<element_d>::mutator_end)>(list_t<collection_d, element_d>::mutator_end),
				},
				// random_access_mutator_range_a
				reinterpret_cast<decltype(random_access_mutator_range_o<element_d>::mutator_begin)>(list_t<collection_d, element_d>::mutator_begin),
				reinterpret_cast<decltype(random_access_mutator_range_o<element_d>::mutator_end)>(list_t<collection_d, element_d>::mutator_end),
			},
			// contiguous_mutator_range_a
			reinterpret_cast<decltype(contiguous_mutator_range_o<element_d>::mutator_begin)>(list_t<collection_d, element_d>::mutator_begin),
			reinterpret_cast<decltype(contiguous_mutator_range_o<element_d>::mutator_end)>(list_t<collection_d, element_d>::mutator_end),
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	contiguous_mutator_range_o<element_d> const* list_t<collection_d, element_d>::_mutator_range_pointer_operations()
	{
		static contiguous_mutator_range_o<element_d> operations = []()
		{
			contiguous_mutator_range_o<element_d> ops = *list_t<collection_d, element_d>::_mutator_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename element_d>
	bool list_t<collection_d, element_d>::_mutator_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == mutator_range_a<element_d>::cat ||
			abc == bidirectional_mutator_range_a<element_d>::cat ||
			abc == random_access_mutator_range_a<element_d>::cat ||
			abc == contiguous_mutator_range_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool list_t<collection_d, element_d>::_mutator_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!list_t<collection_d, element_d>::_mutator_range_is(me, abstraction))
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
	void list_t<collection_d, element_d>::_mutator_range_copy(con<> const& me,
		var<> const& copy)
	{
		new list_t<collection_d, element_d>{ copy, me };
		list_t<collection_d, element_d>::_clone(me, copy);
		copy.o = list_t<collection_d, element_d>::_mutator_range_operations();
	}

	template <typename collection_d, typename element_d>
	void list_t<collection_d, element_d>::_mutator_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? list_t<collection_d, element_d>::_mutator_range_pointer_operations() : list_t<collection_d, element_d>::_mutator_range_operations();
	}

	// instantiation
	template struct list_t<std::vector<int64_t>, int64_t>;
	template struct list_t<std::vector<var<>>, var<>>;
}
