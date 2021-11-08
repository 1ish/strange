#include "../../../strange.h"

namespace strange
{
	// collection_t
	// collection_o
	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	collection_o<key_d, value_d, element_d> const* collection_t<collection_d, key_d, value_d, element_d>::_operations()
	{
		static collection_o<key_d, value_d, element_d> operations =
		{
			{
				// any_a
				collection_a<key_d, value_d, element_d>::cat,
				collection_t<collection_d, key_d, value_d, element_d>::is,
				collection_t<collection_d, key_d, value_d, element_d>::as,
				collection_t<collection_d, key_d, value_d, element_d>::type,
				collection_t<collection_d, key_d, value_d, element_d>::set_error,
				collection_t<collection_d, key_d, value_d, element_d>::error,
				collection_t<collection_d, key_d, value_d, element_d>::hash,
				collection_t<collection_d, key_d, value_d, element_d>::equal,
				collection_t<collection_d, key_d, value_d, element_d>::less,
				collection_t<collection_d, key_d, value_d, element_d>::less_or_equal,
				collection_t<collection_d, key_d, value_d, element_d>::pack,
				collection_t<collection_d, key_d, value_d, element_d>::_free,
				collection_t<collection_d, key_d, value_d, element_d>::_copy,
				collection_t<collection_d, key_d, value_d, element_d>::_set_pointer,
				collection_t<collection_d, key_d, value_d, element_d>::_pointer,
			},
			// collection_a
			collection_t<collection_d, key_d, value_d, element_d>::range,
			collection_t<collection_d, key_d, value_d, element_d>::begin,
			collection_t<collection_d, key_d, value_d, element_d>::end,
			collection_t<collection_d, key_d, value_d, element_d>::read_lock,
			collection_t<collection_d, key_d, value_d, element_d>::write_lock,
			collection_t<collection_d, key_d, value_d, element_d>::has,
			collection_t<collection_d, key_d, value_d, element_d>::at,
			collection_t<collection_d, key_d, value_d, element_d>::update,
			collection_t<collection_d, key_d, value_d, element_d>::insert,
			collection_t<collection_d, key_d, value_d, element_d>::erase,
			collection_t<collection_d, key_d, value_d, element_d>::clear,
			collection_t<collection_d, key_d, value_d, element_d>::size,
			collection_t<collection_d, key_d, value_d, element_d>::empty,
			collection_t<collection_d, key_d, value_d, element_d>::push_front,
			collection_t<collection_d, key_d, value_d, element_d>::pop_front,
			collection_t<collection_d, key_d, value_d, element_d>::push_back,
			collection_t<collection_d, key_d, value_d, element_d>::pop_back,
			collection_t<collection_d, key_d, value_d, element_d>::self_assign,
			collection_t<collection_d, key_d, value_d, element_d>::self_add,
			collection_t<collection_d, key_d, value_d, element_d>::add,
			collection_t<collection_d, key_d, value_d, element_d>::self_subtract,
			collection_t<collection_d, key_d, value_d, element_d>::subtract,
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	collection_o<key_d, value_d, element_d> const* collection_t<collection_d, key_d, value_d, element_d>::_pointer_operations()
	{
		static collection_o<key_d, value_d, element_d> operations = []()
		{
			collection_o<key_d, value_d, element_d> ops = *collection_t<collection_d, key_d, value_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<key_d, value_d, element_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!collection_t<collection_d, key_d, value_d, element_d>::is(me, abstraction))
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

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new collection_t<collection_d, key_d, value_d, element_d>{ copy, me };
		collection_t<collection_d, key_d, value_d, element_d>::_clone(me, copy);
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? collection_t<collection_d, key_d, value_d, element_d>::_pointer_operations() : collection_t<collection_d, key_d, value_d, element_d>::_operations();
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
	bool collection_t<collection_d, key_d, value_d, element_d>::has(con<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key)
	{
		return key >= 0 &&
			static_cast<std::size_t>(key) < static_cast<collection_t<collection_d, key_d, value_d, element_d> const*>(me.t)->collection_.size();
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	value_d collection_t<collection_d, key_d, value_d, element_d>::at(con<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key)
	{
		if (collection_t<collection_d, key_d, value_d, element_d>::has(me, key))
		{
			return static_cast<collection_t<collection_d, key_d, value_d, element_d> const*>(me.t)->collection_.at(static_cast<std::size_t>(key));
		}
		return value_d{};
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::update(var<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key,
		value_d const& value)
	{
		me.mut();
		if (key < 0)
		{
			return;
		}
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		if (static_cast<std::size_t>(key) >= collection.size())
		{
			collection.resize(static_cast<std::size_t>(key) + 1);
		}
		collection.at(static_cast<std::size_t>(key)) = value;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::insert(var<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key,
		value_d const& value)
	{
		me.mut();
		if (key < 0)
		{
			return false;
		}
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		if (static_cast<std::size_t>(key) > collection.size())
		{
			collection.resize(static_cast<std::size_t>(key));
		}
		collection.insert(collection.cbegin() + static_cast<std::size_t>(key), value);
		return true;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	bool collection_t<collection_d, key_d, value_d, element_d>::erase(var<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key)
	{
		me.mut();
		if (key < 0)
		{
			return false;
		}
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		if (static_cast<std::size_t>(key) >= collection.size())
		{
			return false;
		}
		collection.erase(collection.cbegin() + static_cast<std::size_t>(key));
		return true;
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

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::push_front(var<collection_a<key_d, value_d, element_d>> const& me,
		element_d const& element)
	{
		collection_t<collection_d, key_d, value_d, element_d>::insert(me, 0, element);
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	element_d collection_t<collection_d, key_d, value_d, element_d>::pop_front(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		if (collection.empty())
		{
			return element_d{};
		}
		auto front = collection.front();
		collection.erase(collection.cbegin());
		return front;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::push_back(var<collection_a<key_d, value_d, element_d>> const& me,
		element_d const& element)
	{
		me.mut();
		static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_.push_back(element);
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	element_d collection_t<collection_d, key_d, value_d, element_d>::pop_back(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		if (collection.empty())
		{
			return element_d{};
		}
		auto back = collection.back();
		collection.pop_back();
		return back;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::self_assign(var<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		collection.clear();
		for (element_d const& element : range)
		{
			collection.push_back(element);
		}
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::self_add(var<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		for (element_d const& element : range)
		{
			collection.push_back(element);
		}
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	var<collection_a<key_d, value_d, element_d>> collection_t<collection_d, key_d, value_d, element_d>::add(con<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<key_d, value_d, element_d>> result{ me };
		self_add(result, range);
		return result;
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	void collection_t<collection_d, key_d, value_d, element_d>::self_subtract(var<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_;
		for (auto it = range.o->begin(range), end = range.o->end(range); it != end; ++it)
		{
			collection.pop_back();
		}
	}

	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	var<collection_a<key_d, value_d, element_d>> collection_t<collection_d, key_d, value_d, element_d>::subtract(con<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<key_d, value_d, element_d>> result{ me };
		self_subtract(result, range);
		return result;
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
	template struct collection_t<std::deque<int64_t>, int64_t, int64_t, int64_t>;
}
