#include "../../../strange.h"

namespace strange
{
	// tuple_t
	// tuple_o
	template <typename... elements_d>
	tuple_o<elements_d...> const* tuple_t<elements_d...>::_operations()
	{
		static tuple_o<elements_d...> operations =
		{
			{
				// any_a
				tuple_a<elements_d...>::cat,
				tuple_t<elements_d...>::is,
				tuple_t<elements_d...>::as,
				tuple_t<elements_d...>::type,
				tuple_t<elements_d...>::set_error,
				tuple_t<elements_d...>::error,
				tuple_t<elements_d...>::hash,
				tuple_t<elements_d...>::equal,
				tuple_t<elements_d...>::less,
				tuple_t<elements_d...>::less_or_equal,
				tuple_t<elements_d...>::pack,
				tuple_t<elements_d...>::_free,
				tuple_t<elements_d...>::_copy,
				tuple_t<elements_d...>::_set_pointer,
				tuple_t<elements_d...>::_pointer,
			},
			// tuple_a
			tuple_t<elements_d...>::list,
			tuple_t<elements_d...>::destruct,
			tuple_t<elements_d...>::restruct,
		};
		return &operations;
	}

	template <typename... elements_d>
	tuple_o<elements_d...> const* tuple_t<elements_d...>::_pointer_operations()
	{
		static tuple_o<elements_d...> operations = []()
		{
			tuple_o<elements_d...> ops = *tuple_t<elements_d...>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename... elements_d>
	bool tuple_t<elements_d...>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == tuple_a<elements_d...>::cat;
	}

	template <typename... elements_d>
	bool tuple_t<elements_d...>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!tuple_t<elements_d...>::is(me, abstraction))
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

	template <typename... elements_d>
	var<symbol_a> tuple_t<elements_d...>::type(con<> const& me)
	{
		static auto r = sym("strange::tuple");
		return r;
	}

	template <typename... elements_d>
	bool tuple_t<elements_d...>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oi = other.dynamic<con<tuple_a<elements_d...>>>();
		if (oi.o->something(oi))
		{
			return tuple_t<elements_d...>::equal_tuple(me.reference<con<tuple_a<elements_d...>>>(), oi);
		}
		return thing_t::equal(me, other);
	}

	template <typename... elements_d>
	void tuple_t<elements_d...>::_copy(con<> const& me,
		var<> const& copy)
	{
		new tuple_t<elements_d...>{ copy, me };
		tuple_t<elements_d...>::_clone(me, copy);
	}

	template <typename... elements_d>
	void tuple_t<elements_d...>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? tuple_t<elements_d...>::_pointer_operations() : tuple_t<elements_d...>::_operations();
	}

	// tuple_a
	template <typename... elements_d>
	var<list_a<>> tuple_t<elements_d...>::list(con<tuple_a<elements_d...>> const& me)
	{
		return reinterpret_cast<tuple_t<elements_d...> const*>(me.t)->list_;
	}

	void _tuple_destruct(var<list_a<>> const& list, int64_t index)
	{
	}

	template <typename element_d, typename... elements_d>
	void _tuple_destruct(var<list_a<>> const& list, int64_t index, element_d& element, elements_d&... elements)
	{
		element = unbox<element_d>(list.o->at(list, index));
		_tuple_destruct(list, index + 1, elements...);
	}

	void _tuple_restruct(var<list_a<>> const& list, int64_t index)
	{
	}

	template <typename element_d, typename... elements_d>
	void _tuple_restruct(var<list_a<>> const& list, int64_t index, element_d const& element, elements_d const&... elements)
	{
		list.o->update(list, index, box<>(element));
		_tuple_restruct(list, index + 1, elements...);
	}

	template <typename... elements_d>
	void tuple_t<elements_d...>::destruct(con<tuple_a<elements_d...>> const& me,
		elements_d&... elements)
	{
		_tuple_destruct(reinterpret_cast<tuple_t<elements_d...> const*>(me.t)->list_, 0, elements...);
	}

	template <typename... elements_d>
	void tuple_t<elements_d...>::restruct(var<tuple_a<elements_d...>> const& me,
		elements_d const&... elements)
	{
		me.mut();
		_tuple_restruct(reinterpret_cast<tuple_t<elements_d...> const*>(me.t)->list_, 0, elements...);
	}

	// instantiation
	template struct tuple_t<int64_t, int64_t>;
}
