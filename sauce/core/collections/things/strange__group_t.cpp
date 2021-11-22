#include "../../strange__core.h"

namespace strange
{
	// group_t
	// group_o
	template <typename collection_d, typename element_d>
	group_o<element_d> const* group_t<collection_d, element_d>::_operations()
	{
		static group_o<element_d> operations =
		{
			{
				{
					// any_a
					group_a<element_d>::cat,
					group_t<collection_d, element_d>::is,
					group_t<collection_d, element_d>::as,
					group_t<collection_d, element_d>::type,
					group_t<collection_d, element_d>::set_error,
					group_t<collection_d, element_d>::error,
					group_t<collection_d, element_d>::hash,
					group_t<collection_d, element_d>::equal,
					group_t<collection_d, element_d>::less,
					group_t<collection_d, element_d>::less_or_equal,
					group_t<collection_d, element_d>::pack,
					group_t<collection_d, element_d>::_free,
					group_t<collection_d, element_d>::_copy,
					group_t<collection_d, element_d>::_set_pointer,
					group_t<collection_d, element_d>::_pointer,
				},
				// collection_a
				group_t<collection_d, element_d>::range,
				group_t<collection_d, element_d>::begin,
				group_t<collection_d, element_d>::end,
				group_t<collection_d, element_d>::read_lock,
				group_t<collection_d, element_d>::write_lock,
				group_t<collection_d, element_d>::has,
				group_t<collection_d, element_d>::at,
				group_t<collection_d, element_d>::update,
				group_t<collection_d, element_d>::insert,
				group_t<collection_d, element_d>::erase,
				group_t<collection_d, element_d>::clear,
				group_t<collection_d, element_d>::size,
				group_t<collection_d, element_d>::empty,
				group_t<collection_d, element_d>::push_front,
				group_t<collection_d, element_d>::pop_front,
				group_t<collection_d, element_d>::push_back,
				group_t<collection_d, element_d>::pop_back,
				group_t<collection_d, element_d>::self_assign,
				group_t<collection_d, element_d>::self_add,
				group_t<collection_d, element_d>::add,
				group_t<collection_d, element_d>::self_subtract,
				group_t<collection_d, element_d>::subtract,
			},
			// group_a
			group_t<collection_d, element_d>::update_element,
			group_t<collection_d, element_d>::insert_element,
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	group_o<element_d> const* group_t<collection_d, element_d>::_pointer_operations()
	{
		static group_o<element_d> operations = []()
		{
			group_o<element_d> ops = *group_t<collection_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename element_d>
	bool group_t<collection_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<element_d, element_d, element_d>::cat ||
			abc == group_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool group_t<collection_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!group_t<collection_d, element_d>::is(me, abstraction))
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
	var<symbol_a> group_t<collection_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::group");
		return r;
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new group_t<collection_d, element_d>{ copy, me };
		group_t<collection_d, element_d>::_clone(me, copy);
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? group_t<collection_d, element_d>::_pointer_operations() : group_t<collection_d, element_d>::_operations();
	}

	// collection_a
	template <typename collection_d, typename element_d>
	bool group_t<collection_d, element_d>::has(con<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& key)
	{
		auto const& collection = static_cast<group_t<collection_d, element_d> const*>(me.t)->collection_;
		return collection.find(key) != collection.cend();
	}

	template <typename collection_d, typename element_d>
	element_d group_t<collection_d, element_d>::at(con<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& key)
	{
		auto const& collection = static_cast<group_t<collection_d, element_d> const*>(me.t)->collection_;
		auto const it = collection.find(key);
		if (it != collection.cend())
		{
			return *it;
		}
		return element_d{};
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::update(var<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& key,
		element_d const& value)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		collection.erase(key);
		collection.insert(key);
	}

	template <typename collection_d, typename element_d>
	bool group_t<collection_d, element_d>::insert(var<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& key,
		element_d const& value)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		return collection.insert(key).second;
	}

	template <typename collection_d, typename element_d>
	bool group_t<collection_d, element_d>::erase(var<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& key)
	{
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		return collection.erase(key) != 0;
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::push_front(var<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& element)
	{
		group_t<collection_d, element_d>::insert(me, element, element);
	}

	template <typename collection_d, typename element_d>
	element_d group_t<collection_d, element_d>::pop_front(var<collection_a<element_d, element_d, element_d>> const& me)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		if (collection.empty())
		{
			return element_d{};
		}
		auto front = *(collection.cbegin());
		collection.erase(collection.cbegin());
		return front;
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::push_back(var<collection_a<element_d, element_d, element_d>> const& me,
		element_d const& element)
	{
		push_front(me, element);
	}

	template <typename collection_d, typename element_d>
	element_d group_t<collection_d, element_d>::pop_back(var<collection_a<element_d, element_d, element_d>> const& me)
	{
		return pop_front(me);
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::self_assign(var<collection_a<element_d, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		if (me.o->identity(me) != range.o->identity(range))
		{
			auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
			collection.clear();
			for (element_d const& element : range)
			{
				collection.insert(element);
			}
		}
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::self_add(var<collection_a<element_d, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		if (me.o->identity(me) != range.o->identity(range))
		{
			for (element_d const& element : range)
			{
				collection.insert(element);
			}
		}
	}

	template <typename collection_d, typename element_d>
	var<collection_a<element_d, element_d, element_d>> group_t<collection_d, element_d>::add(con<collection_a<element_d, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<element_d, element_d, element_d>> result{ me };
		self_add(result, range);
		return result;
	}

	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::self_subtract(var<collection_a<element_d, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		if (me.o->identity(me) == range.o->identity(range))
		{
			collection.clear();
		}
		else
		{
			for (auto it = range.o->begin(range), end = range.o->end(range); it != end; ++it)
			{
				if (collection.empty())
				{
					break;
				}
				collection.erase(*it);
			}
		}
	}

	template <typename collection_d, typename element_d>
	var<collection_a<element_d, element_d, element_d>> group_t<collection_d, element_d>::subtract(con<collection_a<element_d, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<element_d, element_d, element_d>> result{ me };
		self_subtract(result, range);
		return result;
	}

	// group_a
	template <typename collection_d, typename element_d>
	void group_t<collection_d, element_d>::update_element(var<group_a<element_d>> const& me,
		element_d const& element)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		collection.erase(element);
		collection.insert(element);
	}

	template <typename collection_d, typename element_d>
	bool group_t<collection_d, element_d>::insert_element(var<group_a<element_d>> const& me,
		element_d const& element)
	{
		me.mut();
		auto& collection = static_cast<group_t<collection_d, element_d>*>(me.t)->collection_;
		return collection.insert(element).second;
	}

	// instantiation
	template struct group_t<std::unordered_set<int64_t>, int64_t>;
	template struct group_t<std::set<int64_t>, int64_t>;
}
