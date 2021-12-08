#include "../../strange__core.h"

namespace strange
{
	// lake_o
	lake_o const* lake_t::_operations()
	{
		static lake_o operations =
		{
			{
				{
					{
						{
							// any_a
							lake_a::cat,
							lake_t::is,
							lake_t::as,
							lake_t::type,
							lake_t::set_error,
							lake_t::error,
							lake_t::hash,
							lake_t::equal,
							lake_t::less,
							lake_t::less_or_equal,
							lake_t::pack,
							lake_t::_free,
							lake_t::_copy,
							lake_t::_set_pointer,
							lake_t::_pointer,
						},
						// collection_a
						reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::range)>(lake_t::range),
						reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::begin)>(lake_t::begin),
						reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::end)>(lake_t::end),
						lake_t::read_lock,
						lake_t::write_lock,
						lake_t::has,
						lake_t::at,
						lake_t::update,
						lake_t::insert,
						lake_t::erase,
						lake_t::clear,
						lake_t::size,
						lake_t::empty,
						lake_t::push_front,
						lake_t::pop_front,
						lake_t::push_back,
						lake_t::pop_back,
						lake_t::self_assign,
						lake_t::self_add,
						lake_t::add,
						lake_t::self_subtract,
						lake_t::subtract,
					},
					// queue_a
					reinterpret_cast<decltype(queue_o<element_d>::range)>(lake_t::range),
					reinterpret_cast<decltype(queue_o<element_d>::begin)>(lake_t::begin),
					reinterpret_cast<decltype(queue_o<element_d>::end)>(lake_t::end),
					reinterpret_cast<decltype(queue_o<element_d>::mutator_range)>(lake_t::mutator_range),
					reinterpret_cast<decltype(queue_o<element_d>::mutator_begin)>(lake_t::mutator_begin),
					reinterpret_cast<decltype(queue_o<element_d>::mutator_end)>(lake_t::mutator_end),
				},
				// list_a
				lake_t::range,
				lake_t::begin,
				lake_t::end,
				lake_t::mutator_range,
				lake_t::mutator_begin,
				lake_t::mutator_end,
			},
			// lake_a
		};
		return &operations;
	}

	lake_o const* lake_t::_pointer_operations()
	{
		static lake_o operations = []()
		{
			lake_o ops = *lake_t::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool lake_t::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<int64_t, element_d, element_d>::cat ||
			abc == queue_a<element_d>::cat ||
			abc == list_a<element_d>::cat ||
			abc == lake_a::cat;
	}

	bool lake_t::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!lake_t::is(me, abstraction))
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

	var<symbol_a> lake_t::type(con<> const& me)
	{
		static auto r = sym("strange::lake");
		return r;
	}

	void lake_t::_copy(con<> const& me,
		var<> const& copy)
	{
		new lake_t{ copy, me };
		lake_t::_clone(me, copy);
	}

	void lake_t::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? lake_t::_pointer_operations() : lake_t::_operations();
	}

	// lake_a
	// ...
}
