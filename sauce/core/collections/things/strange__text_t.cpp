#include "../../strange__core.h"

namespace strange
{
	// text_o
	text_o const* text_t::_operations()
	{
		static text_o operations =
		{
			{
				{
					{
						{
							{
								// any_a
								text_a::cat,
								text_t::is,
								text_t::as,
								text_t::type,
								text_t::set_error,
								text_t::error,
								text_t::hash,
								text_t::equal,
								text_t::less,
								text_t::less_or_equal,
								text_t::pack,
								text_t::_free,
								text_t::_copy,
								text_t::_set_pointer,
								text_t::_pointer,
							},
							// collection_a
							reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::range)>(text_t::range),
							reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::begin)>(text_t::begin),
							reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::end)>(text_t::end),
							text_t::read_lock,
							text_t::write_lock,
							text_t::has,
							text_t::at,
							text_t::update,
							text_t::insert,
							text_t::erase,
							text_t::clear,
							text_t::size,
							text_t::empty,
							text_t::push_front,
							text_t::pop_front,
							text_t::push_back,
							text_t::pop_back,
							text_t::self_assign,
							text_t::self_add,
							text_t::add,
							text_t::self_subtract,
							text_t::subtract,
						},
						// queue_a
						reinterpret_cast<decltype(queue_o<element_d>::range)>(text_t::range),
						reinterpret_cast<decltype(queue_o<element_d>::begin)>(text_t::begin),
						reinterpret_cast<decltype(queue_o<element_d>::end)>(text_t::end),
						reinterpret_cast<decltype(queue_o<element_d>::mutator_range)>(text_t::mutator_range),
						reinterpret_cast<decltype(queue_o<element_d>::mutator_begin)>(text_t::mutator_begin),
						reinterpret_cast<decltype(queue_o<element_d>::mutator_end)>(text_t::mutator_end),
					},
					// list_a
					text_t::range,
					text_t::begin,
					text_t::end,
					text_t::mutator_range,
					text_t::mutator_begin,
					text_t::mutator_end,
				},
				// lake_a
			},
			// text_a
		};
		return &operations;
	}

	text_o const* text_t::_pointer_operations()
	{
		static text_o operations = []()
		{
			text_o ops = *text_t::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool text_t::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<int64_t, element_d, element_d>::cat ||
			abc == queue_a<element_d>::cat ||
			abc == list_a<element_d>::cat ||
			abc == lake_a::cat ||
			abc == text_a::cat;
	}

	bool text_t::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!text_t::is(me, abstraction))
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

	var<symbol_a> text_t::type(con<> const& me)
	{
		static auto r = sym("strange::text");
		return r;
	}

	void text_t::_copy(con<> const& me,
		var<> const& copy)
	{
		new text_t{ copy, me };
		text_t::_clone(me, copy);
	}

	void text_t::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? text_t::_pointer_operations() : text_t::_operations();
	}

	// lake_a
	// ...

	// text_a
	// ...
}
