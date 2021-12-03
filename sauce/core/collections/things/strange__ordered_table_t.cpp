#include "../../strange__core.h"

namespace strange
{
	// ordered_table_t
	// ordered_table_o
	template <typename collection_d, typename key_d, typename value_d>
	ordered_table_o<key_d, value_d> const* ordered_table_t<collection_d, key_d, value_d>::_operations()
	{
		static ordered_table_o<key_d, value_d> operations =
		{
			{
				{
					{
						// any_a
						ordered_table_a<key_d, value_d>::cat,
						ordered_table_t<collection_d, key_d, value_d>::is,
						ordered_table_t<collection_d, key_d, value_d>::as,
						ordered_table_t<collection_d, key_d, value_d>::type,
						ordered_table_t<collection_d, key_d, value_d>::set_error,
						ordered_table_t<collection_d, key_d, value_d>::error,
						ordered_table_t<collection_d, key_d, value_d>::hash,
						ordered_table_t<collection_d, key_d, value_d>::equal,
						ordered_table_t<collection_d, key_d, value_d>::less,
						ordered_table_t<collection_d, key_d, value_d>::less_or_equal,
						ordered_table_t<collection_d, key_d, value_d>::pack,
						ordered_table_t<collection_d, key_d, value_d>::_free,
						ordered_table_t<collection_d, key_d, value_d>::_copy,
						ordered_table_t<collection_d, key_d, value_d>::_set_pointer,
						ordered_table_t<collection_d, key_d, value_d>::_pointer,
					},
					// collection_a
					reinterpret_cast<decltype(collection_o<key_d, value_d, element_d>::range)>(ordered_table_t<collection_d, key_d, value_d>::range),
					reinterpret_cast<decltype(collection_o<key_d, value_d, element_d>::begin)>(ordered_table_t<collection_d, key_d, value_d>::begin),
					reinterpret_cast<decltype(collection_o<key_d, value_d, element_d>::end)>(ordered_table_t<collection_d, key_d, value_d>::end),
					ordered_table_t<collection_d, key_d, value_d>::read_lock,
					ordered_table_t<collection_d, key_d, value_d>::write_lock,
					ordered_table_t<collection_d, key_d, value_d>::has,
					ordered_table_t<collection_d, key_d, value_d>::at,
					ordered_table_t<collection_d, key_d, value_d>::update,
					ordered_table_t<collection_d, key_d, value_d>::insert,
					ordered_table_t<collection_d, key_d, value_d>::erase,
					ordered_table_t<collection_d, key_d, value_d>::clear,
					ordered_table_t<collection_d, key_d, value_d>::size,
					ordered_table_t<collection_d, key_d, value_d>::empty,
					ordered_table_t<collection_d, key_d, value_d>::push_front,
					ordered_table_t<collection_d, key_d, value_d>::pop_front,
					ordered_table_t<collection_d, key_d, value_d>::push_back,
					ordered_table_t<collection_d, key_d, value_d>::pop_back,
					ordered_table_t<collection_d, key_d, value_d>::self_assign,
					ordered_table_t<collection_d, key_d, value_d>::self_add,
					ordered_table_t<collection_d, key_d, value_d>::add,
					ordered_table_t<collection_d, key_d, value_d>::self_subtract,
					ordered_table_t<collection_d, key_d, value_d>::subtract,
				},
				// table_a
				reinterpret_cast<decltype(table_o<key_d, value_d>::range)>(ordered_table_t<collection_d, key_d, value_d>::range),
				reinterpret_cast<decltype(table_o<key_d, value_d>::begin)>(ordered_table_t<collection_d, key_d, value_d>::begin),
				reinterpret_cast<decltype(table_o<key_d, value_d>::end)>(ordered_table_t<collection_d, key_d, value_d>::end),
				reinterpret_cast<decltype(table_o<key_d, value_d>::mutator_range)>(ordered_table_t<collection_d, key_d, value_d>::mutator_range),
				reinterpret_cast<decltype(table_o<key_d, value_d>::mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::mutator_begin),
				reinterpret_cast<decltype(table_o<key_d, value_d>::mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::mutator_end),
				reinterpret_cast<decltype(table_o<key_d, value_d>::pair_range)>(ordered_table_t<collection_d, key_d, value_d>::pair_range),
				reinterpret_cast<decltype(table_o<key_d, value_d>::pair_begin)>(ordered_table_t<collection_d, key_d, value_d>::pair_begin),
				reinterpret_cast<decltype(table_o<key_d, value_d>::pair_end)>(ordered_table_t<collection_d, key_d, value_d>::pair_end),
				reinterpret_cast<decltype(table_o<key_d, value_d>::pair_mutator_range)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_range),
				reinterpret_cast<decltype(table_o<key_d, value_d>::pair_mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_begin),
				reinterpret_cast<decltype(table_o<key_d, value_d>::pair_mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_end),
			},
			// ordered_table_a
			ordered_table_t<collection_d, key_d, value_d>::range,
			ordered_table_t<collection_d, key_d, value_d>::begin,
			ordered_table_t<collection_d, key_d, value_d>::end,
			ordered_table_t<collection_d, key_d, value_d>::mutator_range,
			ordered_table_t<collection_d, key_d, value_d>::mutator_begin,
			ordered_table_t<collection_d, key_d, value_d>::mutator_end,
			ordered_table_t<collection_d, key_d, value_d>::pair_range,
			ordered_table_t<collection_d, key_d, value_d>::pair_begin,
			ordered_table_t<collection_d, key_d, value_d>::pair_end,
			ordered_table_t<collection_d, key_d, value_d>::pair_mutator_range,
			ordered_table_t<collection_d, key_d, value_d>::pair_mutator_begin,
			ordered_table_t<collection_d, key_d, value_d>::pair_mutator_end,
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	ordered_table_o<key_d, value_d> const* ordered_table_t<collection_d, key_d, value_d>::_pointer_operations()
	{
		static ordered_table_o<key_d, value_d> operations = []()
		{
			ordered_table_o<key_d, value_d> ops = *ordered_table_t<collection_d, key_d, value_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<key_d, value_d, element_d>::cat ||
			abc == table_a<key_d, value_d>::cat ||
			abc == ordered_table_a<key_d, value_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_table_t<collection_d, key_d, value_d>::is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d>
	var<symbol_a> ordered_table_t<collection_d, key_d, value_d>::type(con<> const& me)
	{
		static auto r = sym("strange::ordered_table");
		return r;
	}

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_table_t<collection_d, key_d, value_d>{ copy, me };
		ordered_table_t<collection_d, key_d, value_d>::_clone(me, copy);
	}

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_table_t<collection_d, key_d, value_d>::_pointer_operations() : ordered_table_t<collection_d, key_d, value_d>::_operations();
	}

	// ordered_table_a
	template <typename collection_d, typename key_d, typename value_d>
	var<bidirectional_tuple_range_a<key_d, value_d>> ordered_table_t<collection_d, key_d, value_d>::range(con<ordered_table_a<key_d, value_d>> const& me)
	{
		bidirectional_tuple_range_a<key_d, value_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = ordered_table_t<collection_d, key_d, value_d>::_range_operations();
		return var<bidirectional_tuple_range_a<key_d, value_d>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_tuple_extractor_a<key_d, value_d>> ordered_table_t<collection_d, key_d, value_d>::begin(con<ordered_table_a<key_d, value_d>> const& me)
	{
		return bidirectional_tuple_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_tuple_extractor_a<key_d, value_d>> ordered_table_t<collection_d, key_d, value_d>::end(con<ordered_table_a<key_d, value_d>> const& me)
	{
		return bidirectional_tuple_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<bidirectional_tuple_mutator_range_a<key_d, value_d>> ordered_table_t<collection_d, key_d, value_d>::mutator_range(var<ordered_table_a<key_d, value_d>> const& me)
	{
		me.mut();
		bidirectional_tuple_mutator_range_a<key_d, value_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = ordered_table_t<collection_d, key_d, value_d>::_mutator_range_operations();
		return var<bidirectional_tuple_mutator_range_a<key_d, value_d>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_tuple_mutator_a<key_d, value_d>> ordered_table_t<collection_d, key_d, value_d>::mutator_begin(var<ordered_table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return bidirectional_tuple_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d>*>(me.t)->collection_.begin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_tuple_mutator_a<key_d, value_d>> ordered_table_t<collection_d, key_d, value_d>::mutator_end(var<ordered_table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return bidirectional_tuple_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d>*>(me.t)->collection_.end());
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<bidirectional_range_a<std::pair<key_d const, value_d>>> ordered_table_t<collection_d, key_d, value_d>::pair_range(con<ordered_table_a<key_d, value_d>> const& me)
	{
		bidirectional_range_a<std::pair<key_d const, value_d>> abstraction;
		abstraction.t = me.t;
		abstraction.o = ordered_table_t<collection_d, key_d, value_d>::_pair_range_operations();
		return var<bidirectional_range_a<std::pair<key_d const, value_d>>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_extractor_a<std::pair<key_d const, value_d>>> ordered_table_t<collection_d, key_d, value_d>::pair_begin(con<ordered_table_a<key_d, value_d>> const& me)
	{
		return bidirectional_pair_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_extractor_a<std::pair<key_d const, value_d>>> ordered_table_t<collection_d, key_d, value_d>::pair_end(con<ordered_table_a<key_d, value_d>> const& me)
	{
		return bidirectional_pair_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<bidirectional_mutator_range_a<std::pair<key_d const, value_d>>> ordered_table_t<collection_d, key_d, value_d>::pair_mutator_range(var<ordered_table_a<key_d, value_d>> const& me)
	{
		me.mut();
		bidirectional_mutator_range_a<std::pair<key_d const, value_d>> abstraction;
		abstraction.t = me.t;
		abstraction.o = ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
		return var<bidirectional_mutator_range_a<std::pair<key_d const, value_d>>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_mutator_a<std::pair<key_d const, value_d>>> ordered_table_t<collection_d, key_d, value_d>::pair_mutator_begin(var<ordered_table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return bidirectional_pair_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d>*>(me.t)->collection_.begin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	bit<bidirectional_mutator_a<std::pair<key_d const, value_d>>> ordered_table_t<collection_d, key_d, value_d>::pair_mutator_end(var<ordered_table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return bidirectional_pair_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<ordered_table_t<collection_d, key_d, value_d>*>(me.t)->collection_.end());
	}

	// bidirectional_tuple_range_a
	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_tuple_range_o<key_d, value_d> const* ordered_table_t<collection_d, key_d, value_d>::_range_operations()
	{
		static bidirectional_tuple_range_o<key_d, value_d> operations =
		{
			{
				{
					{
						// any_a
						bidirectional_tuple_range_a<key_d, value_d>::cat,
						ordered_table_t<collection_d, key_d, value_d>::_range_is,
						ordered_table_t<collection_d, key_d, value_d>::_range_as,
						ordered_table_t<collection_d, key_d, value_d>::type,
						ordered_table_t<collection_d, key_d, value_d>::set_error,
						ordered_table_t<collection_d, key_d, value_d>::error,
						ordered_table_t<collection_d, key_d, value_d>::hash,
						ordered_table_t<collection_d, key_d, value_d>::equal,
						ordered_table_t<collection_d, key_d, value_d>::less,
						ordered_table_t<collection_d, key_d, value_d>::less_or_equal,
						ordered_table_t<collection_d, key_d, value_d>::pack,
						ordered_table_t<collection_d, key_d, value_d>::_free,
						ordered_table_t<collection_d, key_d, value_d>::_range_copy,
						ordered_table_t<collection_d, key_d, value_d>::_range_set_pointer,
						ordered_table_t<collection_d, key_d, value_d>::_pointer,
					},
					// range_a
					reinterpret_cast<decltype(range_o<element_d>::begin)>(ordered_table_t<collection_d, key_d, value_d>::begin),
					reinterpret_cast<decltype(range_o<element_d>::end)>(ordered_table_t<collection_d, key_d, value_d>::end),
				},
				// tuple_range_a
				reinterpret_cast<decltype(tuple_range_o<key_d, value_d>::begin)>(ordered_table_t<collection_d, key_d, value_d>::begin),
				reinterpret_cast<decltype(tuple_range_o<key_d, value_d>::end)>(ordered_table_t<collection_d, key_d, value_d>::end),
			},
			// bidirectional_tuple_range_a
			reinterpret_cast<decltype(bidirectional_tuple_range_o<key_d, value_d>::begin)>(ordered_table_t<collection_d, key_d, value_d>::begin),
			reinterpret_cast<decltype(bidirectional_tuple_range_o<key_d, value_d>::end)>(ordered_table_t<collection_d, key_d, value_d>::end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_tuple_range_o<key_d, value_d> const* ordered_table_t<collection_d, key_d, value_d>::_range_pointer_operations()
	{
		static bidirectional_tuple_range_o<key_d, value_d> operations = []()
		{
			bidirectional_tuple_range_o<key_d, value_d> ops = *ordered_table_t<collection_d, key_d, value_d>::_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<element_d>::cat ||
			abc == tuple_range_a<key_d, value_d>::cat ||
			abc == bidirectional_tuple_range_a<key_d, value_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_table_t<collection_d, key_d, value_d>::_range_is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_range_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_table_t<collection_d, key_d, value_d>{ copy, me };
		ordered_table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = ordered_table_t<collection_d, key_d, value_d>::_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_table_t<collection_d, key_d, value_d>::_range_pointer_operations() : ordered_table_t<collection_d, key_d, value_d>::_range_operations();
	}

	// bidirectional_tuple_mutator_range_a
	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_tuple_mutator_range_o<key_d, value_d> const* ordered_table_t<collection_d, key_d, value_d>::_mutator_range_operations()
	{
		static bidirectional_tuple_mutator_range_o<key_d, value_d> operations =
		{
			{
				{
					{
						// any_a
						bidirectional_tuple_mutator_range_a<key_d, value_d>::cat,
						ordered_table_t<collection_d, key_d, value_d>::_mutator_range_is,
						ordered_table_t<collection_d, key_d, value_d>::_mutator_range_as,
						ordered_table_t<collection_d, key_d, value_d>::type,
						ordered_table_t<collection_d, key_d, value_d>::set_error,
						ordered_table_t<collection_d, key_d, value_d>::error,
						ordered_table_t<collection_d, key_d, value_d>::hash,
						ordered_table_t<collection_d, key_d, value_d>::equal,
						ordered_table_t<collection_d, key_d, value_d>::less,
						ordered_table_t<collection_d, key_d, value_d>::less_or_equal,
						ordered_table_t<collection_d, key_d, value_d>::pack,
						ordered_table_t<collection_d, key_d, value_d>::_free,
						ordered_table_t<collection_d, key_d, value_d>::_mutator_range_copy,
						ordered_table_t<collection_d, key_d, value_d>::_mutator_range_set_pointer,
						ordered_table_t<collection_d, key_d, value_d>::_pointer,
					},
					// mutator_range_a
					reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::mutator_begin),
					reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::mutator_end),
				},
				// tuple_mutator_range_a
				reinterpret_cast<decltype(tuple_mutator_range_o<key_d, value_d>::mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::mutator_begin),
				reinterpret_cast<decltype(tuple_mutator_range_o<key_d, value_d>::mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::mutator_end),
			},
			// bidirectional_tuple_mutator_range_a
			reinterpret_cast<decltype(bidirectional_tuple_mutator_range_o<key_d, value_d>::mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::mutator_begin),
			reinterpret_cast<decltype(bidirectional_tuple_mutator_range_o<key_d, value_d>::mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::mutator_end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_tuple_mutator_range_o<key_d, value_d> const* ordered_table_t<collection_d, key_d, value_d>::_mutator_range_pointer_operations()
	{
		static bidirectional_tuple_mutator_range_o<key_d, value_d> operations = []()
		{
			bidirectional_tuple_mutator_range_o<key_d, value_d> ops = *ordered_table_t<collection_d, key_d, value_d>::_mutator_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_mutator_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == mutator_range_a<element_d>::cat ||
			abc == tuple_mutator_range_a<key_d, value_d>::cat ||
			abc == bidirectional_tuple_mutator_range_a<key_d, value_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_mutator_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_table_t<collection_d, key_d, value_d>::_mutator_range_is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_mutator_range_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_table_t<collection_d, key_d, value_d>{ copy, me };
		ordered_table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = ordered_table_t<collection_d, key_d, value_d>::_mutator_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_mutator_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_table_t<collection_d, key_d, value_d>::_mutator_range_pointer_operations() : ordered_table_t<collection_d, key_d, value_d>::_mutator_range_operations();
	}

	// bidirectional_range_a
	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_range_o<std::pair<key_d const, value_d>> const* ordered_table_t<collection_d, key_d, value_d>::_pair_range_operations()
	{
		static bidirectional_range_o<std::pair<key_d const, value_d>> operations =
		{
			{
				{
					// any_a
					bidirectional_range_a<std::pair<key_d const, value_d>>::cat,
					ordered_table_t<collection_d, key_d, value_d>::_pair_range_is,
					ordered_table_t<collection_d, key_d, value_d>::_pair_range_as,
					ordered_table_t<collection_d, key_d, value_d>::type,
					ordered_table_t<collection_d, key_d, value_d>::set_error,
					ordered_table_t<collection_d, key_d, value_d>::error,
					ordered_table_t<collection_d, key_d, value_d>::hash,
					ordered_table_t<collection_d, key_d, value_d>::equal,
					ordered_table_t<collection_d, key_d, value_d>::less,
					ordered_table_t<collection_d, key_d, value_d>::less_or_equal,
					ordered_table_t<collection_d, key_d, value_d>::pack,
					ordered_table_t<collection_d, key_d, value_d>::_free,
					ordered_table_t<collection_d, key_d, value_d>::_pair_range_copy,
					ordered_table_t<collection_d, key_d, value_d>::_pair_range_set_pointer,
					ordered_table_t<collection_d, key_d, value_d>::_pointer,
				},
				// range_a
				reinterpret_cast<decltype(range_o<std::pair<key_d const, value_d>>::begin)>(ordered_table_t<collection_d, key_d, value_d>::pair_begin),
				reinterpret_cast<decltype(range_o<std::pair<key_d const, value_d>>::end)>(ordered_table_t<collection_d, key_d, value_d>::pair_end),
			},
			// bidirectional_range_a
			reinterpret_cast<decltype(bidirectional_range_o<std::pair<key_d const, value_d>>::begin)>(ordered_table_t<collection_d, key_d, value_d>::pair_begin),
			reinterpret_cast<decltype(bidirectional_range_o<std::pair<key_d const, value_d>>::end)>(ordered_table_t<collection_d, key_d, value_d>::pair_end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_range_o<std::pair<key_d const, value_d>> const* ordered_table_t<collection_d, key_d, value_d>::_pair_range_pointer_operations()
	{
		static bidirectional_range_o<std::pair<key_d const, value_d>> operations = []()
		{
			bidirectional_range_o<std::pair<key_d const, value_d>> ops = *ordered_table_t<collection_d, key_d, value_d>::_pair_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_pair_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<std::pair<key_d const, value_d>>::cat ||
			abc == bidirectional_range_a<std::pair<key_d const, value_d>>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_pair_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_table_t<collection_d, key_d, value_d>::_pair_range_is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_pair_range_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_table_t<collection_d, key_d, value_d>{ copy, me };
		ordered_table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = ordered_table_t<collection_d, key_d, value_d>::_pair_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_pair_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_table_t<collection_d, key_d, value_d>::_pair_range_pointer_operations() : ordered_table_t<collection_d, key_d, value_d>::_pair_range_operations();
	}

	// bidirectional_mutator_range_a
	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_mutator_range_o<std::pair<key_d const, value_d>> const* ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations()
	{
		static bidirectional_mutator_range_o<std::pair<key_d const, value_d>> operations =
		{
			{
				{
					// any_a
					bidirectional_mutator_range_a<std::pair<key_d const, value_d>>::cat,
					ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_is,
					ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_as,
					ordered_table_t<collection_d, key_d, value_d>::type,
					ordered_table_t<collection_d, key_d, value_d>::set_error,
					ordered_table_t<collection_d, key_d, value_d>::error,
					ordered_table_t<collection_d, key_d, value_d>::hash,
					ordered_table_t<collection_d, key_d, value_d>::equal,
					ordered_table_t<collection_d, key_d, value_d>::less,
					ordered_table_t<collection_d, key_d, value_d>::less_or_equal,
					ordered_table_t<collection_d, key_d, value_d>::pack,
					ordered_table_t<collection_d, key_d, value_d>::_free,
					ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_copy,
					ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_set_pointer,
					ordered_table_t<collection_d, key_d, value_d>::_pointer,
				},
				// mutator_range_a
				reinterpret_cast<decltype(mutator_range_o<std::pair<key_d const, value_d>>::mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_begin),
				reinterpret_cast<decltype(mutator_range_o<std::pair<key_d const, value_d>>::mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_end),
			},
			// bidirectional_mutator_range_a
			reinterpret_cast<decltype(bidirectional_mutator_range_o<std::pair<key_d const, value_d>>::mutator_begin)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_begin),
			reinterpret_cast<decltype(bidirectional_mutator_range_o<std::pair<key_d const, value_d>>::mutator_end)>(ordered_table_t<collection_d, key_d, value_d>::pair_mutator_end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bidirectional_mutator_range_o<std::pair<key_d const, value_d>> const* ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_pointer_operations()
	{
		static bidirectional_mutator_range_o<std::pair<key_d const, value_d>> operations = []()
		{
			bidirectional_mutator_range_o<std::pair<key_d const, value_d>> ops = *ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == mutator_range_a<std::pair<key_d const, value_d>>::cat ||
			abc == bidirectional_mutator_range_a<std::pair<key_d const, value_d>>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_copy(con<> const& me,
		var<> const& copy)
	{
		new ordered_table_t<collection_d, key_d, value_d>{ copy, me };
		ordered_table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_pointer_operations() : ordered_table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
	}

	// instantiation
	template struct ordered_table_t<std::map<int64_t, table_value_tuple_u<int64_t, int64_t, std::pair<int64_t const, int64_t>>>, int64_t, int64_t>;
}
