#include "../../strange__core.h"

namespace strange
{
	// collection_t
	// any_a
	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	var<symbol_a> collection_t<collection_d, key_d, value_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::collection");
		return r;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oc = other.dynamic<con<collection_a<key_d, value_d, element_d>>>();
		if (oc.o->something(oc))
		{
			return collection_t<collection_d, key_d, value_d, element_d>::equal_collection(me.reference<con<collection_a<key_d, value_d, element_d>>>(), oc);
		}
		return thing_t::equal(me, other);
	}

	// collection_a
	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	var<range_a<element_d>> collection_t<collection_d, key_d, value_d, element_d>::range(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		range_a<element_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = collection_t<collection_d, key_d, value_d, element_d>::_range_operations();
		return var<range_a<element_d>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	fit<forward_extractor_a<element_d>> collection_t<collection_d, key_d, value_d, element_d>::begin(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return forward_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<collection_t<collection_d, key_d, value_d, element_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	fit<forward_extractor_a<element_d>> collection_t<collection_d, key_d, value_d, element_d>::end(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return forward_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<collection_t<collection_d, key_d, value_d, element_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	ptr<> collection_t<collection_d, key_d, value_d, element_d>::read_lock(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return ptr<>{};
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	ptr<> collection_t<collection_d, key_d, value_d, element_d>::write_lock(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		return ptr<>{};
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::clear(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_.clear();
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	int64_t collection_t<collection_d, key_d, value_d, element_d>::size(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return static_cast<int64_t>(static_cast<collection_t<collection_d, key_d, value_d, element_d> const*>(me.t)->collection_.size());
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::empty(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return static_cast<collection_t<collection_d, key_d, value_d, element_d> const*>(me.t)->collection_.empty();
	}

	// range_a
	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	range_o<element_d> const* collection_t<collection_d, key_d, value_d, element_d>::_range_operations()
	{
		static range_o<element_d> operations =
		{
			{
				// any_a
				collection_a<key_d, value_d, element_d>::cat,
				collection_t<collection_d, key_d, value_d, element_d>::_range_is,
				collection_t<collection_d, key_d, value_d, element_d>::_range_as,
				collection_t<collection_d, key_d, value_d, element_d>::type,
				collection_t<collection_d, key_d, value_d, element_d>::set_error,
				collection_t<collection_d, key_d, value_d, element_d>::error,
				collection_t<collection_d, key_d, value_d, element_d>::hash,
				collection_t<collection_d, key_d, value_d, element_d>::equal,
				collection_t<collection_d, key_d, value_d, element_d>::less,
				collection_t<collection_d, key_d, value_d, element_d>::less_or_equal,
				collection_t<collection_d, key_d, value_d, element_d>::pack,
				collection_t<collection_d, key_d, value_d, element_d>::_free,
				collection_t<collection_d, key_d, value_d, element_d>::_range_copy,
				collection_t<collection_d, key_d, value_d, element_d>::_range_set_pointer,
				collection_t<collection_d, key_d, value_d, element_d>::_pointer,
			},
			// range_a
			reinterpret_cast<decltype(range_o<element_d>::begin)>(collection_t<collection_d, key_d, value_d, element_d>::begin),
			reinterpret_cast<decltype(range_o<element_d>::end)>(collection_t<collection_d, key_d, value_d, element_d>::end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	range_o<element_d> const* collection_t<collection_d, key_d, value_d, element_d>::_range_pointer_operations()
	{
		static range_o<element_d> operations = []()
		{
			range_o<element_d> ops = *collection_t<collection_d, key_d, value_d, element_d>::_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<element_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!collection_t<collection_d, key_d, value_d, element_d>::_range_is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::_range_copy(con<> const& me,
		var<> const& copy)
	{
		new collection_t<collection_d, key_d, value_d, element_d>{ copy, me };
		collection_t<collection_d, key_d, value_d, element_d>::_clone(me, copy);
		copy.o = collection_t<collection_d, key_d, value_d, element_d>::_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? collection_t<collection_d, key_d, value_d, element_d>::_range_pointer_operations() : collection_t<collection_d, key_d, value_d, element_d>::_range_operations();
	}

	// instantiation
	template struct collection_t<std::vector<int64_t>, int64_t, int64_t, int64_t>;
	template struct collection_t<std::vector<var<>>, int64_t, var<>, var<>>;
	template struct collection_t<std::deque<int64_t>, int64_t, int64_t, int64_t>;
	template struct collection_t<std::unordered_set<int64_t>, int64_t, int64_t, int64_t>;
	template struct collection_t<std::set<int64_t>, int64_t, int64_t, int64_t>;
	template struct collection_t<std::set<var<>>, var<>, var<>, var<>>;
}
