#include "../../../strange.h"

namespace strange
{
	// queue_t
	// queue_o
	template <typename collection_d, typename element_d>
	queue_o<element_d> const* queue_t<collection_d, element_d>::_operations()
	{
		static queue_o<element_d> operations =
		{
			{
				{
					// any_a
					queue_a<element_d>::cat,
					queue_t<collection_d, element_d>::is,
					queue_t<collection_d, element_d>::as,
					queue_t<collection_d, element_d>::type,
					queue_t<collection_d, element_d>::set_error,
					queue_t<collection_d, element_d>::error,
					queue_t<collection_d, element_d>::hash,
					queue_t<collection_d, element_d>::equal,
					queue_t<collection_d, element_d>::less,
					queue_t<collection_d, element_d>::less_or_equal,
					queue_t<collection_d, element_d>::pack,
					queue_t<collection_d, element_d>::_free,
					queue_t<collection_d, element_d>::_copy,
					queue_t<collection_d, element_d>::_set_pointer,
					queue_t<collection_d, element_d>::_pointer,
				},
				// collection_a
				reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::range)>(queue_t<collection_d, element_d>::range),
				reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::begin)>(queue_t<collection_d, element_d>::begin),
				reinterpret_cast<decltype(collection_o<int64_t, element_d, element_d>::end)>(queue_t<collection_d, element_d>::end),
				queue_t<collection_d, element_d>::read_lock,
				queue_t<collection_d, element_d>::write_lock,
				queue_t<collection_d, element_d>::has,
				queue_t<collection_d, element_d>::at,
				queue_t<collection_d, element_d>::update,
				queue_t<collection_d, element_d>::insert,
				queue_t<collection_d, element_d>::erase,
				queue_t<collection_d, element_d>::clear,
				queue_t<collection_d, element_d>::size,
				queue_t<collection_d, element_d>::empty,
				queue_t<collection_d, element_d>::push_front,
				queue_t<collection_d, element_d>::pop_front,
				queue_t<collection_d, element_d>::push_back,
				queue_t<collection_d, element_d>::pop_back,
				queue_t<collection_d, element_d>::self_assign,
				queue_t<collection_d, element_d>::self_add,
				queue_t<collection_d, element_d>::add,
				queue_t<collection_d, element_d>::self_subtract,
				queue_t<collection_d, element_d>::subtract,
			},
			// queue_a
			queue_t<collection_d, element_d>::range,
			queue_t<collection_d, element_d>::begin,
			queue_t<collection_d, element_d>::end,
			queue_t<collection_d, element_d>::mutator_range,
			queue_t<collection_d, element_d>::mutator_begin,
			queue_t<collection_d, element_d>::mutator_end,
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	queue_o<element_d> const* queue_t<collection_d, element_d>::_pointer_operations()
	{
		static queue_o<element_d> operations = []()
		{
			queue_o<element_d> ops = *queue_t<collection_d, element_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<int64_t, element_d, element_d>::cat ||
			abc == queue_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!queue_t<collection_d, element_d>::is(me, abstraction))
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
	var<symbol_a> queue_t<collection_d, element_d>::type(con<> const& me)
	{
		static auto r = sym("strange::queue");
		return r;
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new queue_t<collection_d, element_d>{ copy, me };
		queue_t<collection_d, element_d>::_clone(me, copy);
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? queue_t<collection_d, element_d>::_pointer_operations() : queue_t<collection_d, element_d>::_operations();
	}

	// collection_a
	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::has(con<collection_a<int64_t, element_d, element_d>> const& me,
		int64_t const& key)
	{
		return key >= 0 &&
			static_cast<std::size_t>(key) < static_cast<queue_t<collection_d, element_d> const*>(me.t)->collection_.size();
	}

	template <typename collection_d, typename element_d>
	element_d queue_t<collection_d, element_d>::at(con<collection_a<int64_t, element_d, element_d>> const& me,
		int64_t const& key)
	{
		if (queue_t<collection_d, element_d>::has(me, key))
		{
			return static_cast<queue_t<collection_d, element_d> const*>(me.t)->collection_.at(static_cast<std::size_t>(key));
		}
		return element_d{};
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::update(var<collection_a<int64_t, element_d, element_d>> const& me,
		int64_t const& key,
		element_d const& value)
	{
		me.mut();
		if (key < 0)
		{
			return;
		}
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		if (static_cast<std::size_t>(key) >= collection.size())
		{
			collection.resize(static_cast<std::size_t>(key) + 1);
		}
		collection.at(static_cast<std::size_t>(key)) = value;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::insert(var<collection_a<int64_t, element_d, element_d>> const& me,
		int64_t const& key,
		element_d const& value)
	{
		me.mut();
		if (key < 0)
		{
			return false;
		}
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		if (static_cast<std::size_t>(key) > collection.size())
		{
			collection.resize(static_cast<std::size_t>(key));
		}
		collection.insert(collection.cbegin() + static_cast<std::size_t>(key), value);
		return true;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::erase(var<collection_a<int64_t, element_d, element_d>> const& me,
		int64_t const& key)
	{
		me.mut();
		if (key < 0)
		{
			return false;
		}
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		if (static_cast<std::size_t>(key) >= collection.size())
		{
			return false;
		}
		collection.erase(collection.cbegin() + static_cast<std::size_t>(key));
		return true;
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::clear(var<collection_a<int64_t, element_d, element_d>> const& me)
	{
		me.mut();
		static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_.clear();
	}

	template <typename collection_d, typename element_d>
	int64_t queue_t<collection_d, element_d>::size(con<collection_a<int64_t, element_d, element_d>> const& me)
	{
		return static_cast<int64_t>(static_cast<queue_t<collection_d, element_d> const*>(me.t)->collection_.size());
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::empty(con<collection_a<int64_t, element_d, element_d>> const& me)
	{
		return static_cast<queue_t<collection_d, element_d> const*>(me.t)->collection_.empty();
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::push_front(var<collection_a<int64_t, element_d, element_d>> const& me,
		element_d const& element)
	{
		queue_t<collection_d, element_d>::insert(me, 0, element);
	}

	template <typename collection_d, typename element_d>
	element_d queue_t<collection_d, element_d>::pop_front(var<collection_a<int64_t, element_d, element_d>> const& me)
	{
		me.mut();
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		if (collection.empty())
		{
			return element_d{};
		}
		auto front = collection.front();
		collection.erase(collection.cbegin());
		return front;
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::push_back(var<collection_a<int64_t, element_d, element_d>> const& me,
		element_d const& element)
	{
		me.mut();
		static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_.push_back(element);
	}

	template <typename collection_d, typename element_d>
	element_d queue_t<collection_d, element_d>::pop_back(var<collection_a<int64_t, element_d, element_d>> const& me)
	{
		me.mut();
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		if (collection.empty())
		{
			return element_d{};
		}
		auto back = collection.back();
		collection.pop_back();
		return back;
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::self_assign(var<collection_a<int64_t, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		collection.clear();
		for (element_d const& element : range)
		{
			collection.push_back(element);
		}
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::self_add(var<collection_a<int64_t, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		for (element_d const& element : range)
		{
			collection.push_back(element);
		}
	}

	template <typename collection_d, typename element_d>
	var<collection_a<int64_t, element_d, element_d>> queue_t<collection_d, element_d>::add(con<collection_a<int64_t, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<int64_t, element_d, element_d>> result{ me };
		self_add(result, range);
		return result;
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::self_subtract(var<collection_a<int64_t, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_;
		for (auto it = range.o->begin(range), end = range.o->end(range); it != end; ++it)
		{
			collection.pop_back();
		}
	}

	template <typename collection_d, typename element_d>
	var<collection_a<int64_t, element_d, element_d>> queue_t<collection_d, element_d>::subtract(con<collection_a<int64_t, element_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<int64_t, element_d, element_d>> result{ me };
		self_subtract(result, range);
		return result;
	}

	// queue_a
	template <typename collection_d, typename element_d>
	var<random_access_range_a<element_d>> queue_t<collection_d, element_d>::range(con<queue_a<element_d>> const& me)
	{
		random_access_range_a<element_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = queue_t<collection_d, element_d>::_range_operations();
		return var<random_access_range_a<element_d>>{ abstraction };
	}

	template <typename collection_d, typename element_d>
	rat<random_access_extractor_a<element_d>> queue_t<collection_d, element_d>::begin(con<queue_a<element_d>> const& me)
	{
		return random_access_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<queue_t<collection_d, element_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename element_d>
	rat<random_access_extractor_a<element_d>> queue_t<collection_d, element_d>::end(con<queue_a<element_d>> const& me)
	{
		return random_access_extractor_t<typename collection_d::const_iterator, element_d>::create(static_cast<queue_t<collection_d, element_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename element_d>
	var<random_access_mutator_range_a<element_d>> queue_t<collection_d, element_d>::mutator_range(var<queue_a<element_d>> const& me)
	{
		me.mut();
		random_access_mutator_range_a<element_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = queue_t<collection_d, element_d>::_mutator_range_operations();
		return var<random_access_mutator_range_a<element_d>>{ abstraction };
	}

	template <typename collection_d, typename element_d>
	rat<random_access_mutator_a<element_d>> queue_t<collection_d, element_d>::mutator_begin(var<queue_a<element_d>> const& me)
	{
		me.mut();
		return random_access_mutator_t<typename collection_d::iterator, element_d>::create(static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_.begin());
	}

	template <typename collection_d, typename element_d>
	rat<random_access_mutator_a<element_d>> queue_t<collection_d, element_d>::mutator_end(var<queue_a<element_d>> const& me)
	{
		me.mut();
		return random_access_mutator_t<typename collection_d::iterator, element_d>::create(static_cast<queue_t<collection_d, element_d>*>(me.t)->collection_.end());
	}

	// random_access_range_a
	template <typename collection_d, typename element_d>
	random_access_range_o<element_d> const* queue_t<collection_d, element_d>::_range_operations()
	{
		static random_access_range_o<element_d> operations =
		{
			{
				{
					{
						// any_a
						random_access_range_a<element_d>::cat,
						queue_t<collection_d, element_d>::_range_is,
						queue_t<collection_d, element_d>::_range_as,
						queue_t<collection_d, element_d>::type,
						queue_t<collection_d, element_d>::set_error,
						queue_t<collection_d, element_d>::error,
						queue_t<collection_d, element_d>::hash,
						queue_t<collection_d, element_d>::equal,
						queue_t<collection_d, element_d>::less,
						queue_t<collection_d, element_d>::less_or_equal,
						queue_t<collection_d, element_d>::pack,
						queue_t<collection_d, element_d>::_free,
						queue_t<collection_d, element_d>::_range_copy,
						queue_t<collection_d, element_d>::_range_set_pointer,
						queue_t<collection_d, element_d>::_pointer,
					},
					// range_a
					reinterpret_cast<decltype(range_o<element_d>::begin)>(queue_t<collection_d, element_d>::begin),
					reinterpret_cast<decltype(range_o<element_d>::end)>(queue_t<collection_d, element_d>::end),
				},
				// bidirectional_range_a
				reinterpret_cast<decltype(bidirectional_range_o<element_d>::begin)>(queue_t<collection_d, element_d>::begin),
				reinterpret_cast<decltype(bidirectional_range_o<element_d>::end)>(queue_t<collection_d, element_d>::end),
			},
			// random_access_range_a
			reinterpret_cast<decltype(random_access_range_o<element_d>::begin)>(queue_t<collection_d, element_d>::begin),
			reinterpret_cast<decltype(random_access_range_o<element_d>::end)>(queue_t<collection_d, element_d>::end),
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	random_access_range_o<element_d> const* queue_t<collection_d, element_d>::_range_pointer_operations()
	{
		static random_access_range_o<element_d> operations = []()
		{
			random_access_range_o<element_d> ops = *queue_t<collection_d, element_d>::_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<element_d>::cat ||
			abc == bidirectional_range_a<element_d>::cat ||
			abc == random_access_range_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!queue_t<collection_d, element_d>::_range_is(me, abstraction))
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
	void queue_t<collection_d, element_d>::_range_copy(con<> const& me,
		var<> const& copy)
	{
		new queue_t<collection_d, element_d>{ copy, me };
		queue_t<collection_d, element_d>::_clone(me, copy);
		copy.o = queue_t<collection_d, element_d>::_range_operations();
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? queue_t<collection_d, element_d>::_range_pointer_operations() : queue_t<collection_d, element_d>::_range_operations();
	}

	// random_access_mutator_range_a
	template <typename collection_d, typename element_d>
	random_access_mutator_range_o<element_d> const* queue_t<collection_d, element_d>::_mutator_range_operations()
	{
		static random_access_mutator_range_o<element_d> operations =
		{
			{
				{
					{
						// any_a
						random_access_mutator_range_a<element_d>::cat,
						queue_t<collection_d, element_d>::_mutator_range_is,
						queue_t<collection_d, element_d>::_mutator_range_as,
						queue_t<collection_d, element_d>::type,
						queue_t<collection_d, element_d>::set_error,
						queue_t<collection_d, element_d>::error,
						queue_t<collection_d, element_d>::hash,
						queue_t<collection_d, element_d>::equal,
						queue_t<collection_d, element_d>::less,
						queue_t<collection_d, element_d>::less_or_equal,
						queue_t<collection_d, element_d>::pack,
						queue_t<collection_d, element_d>::_free,
						queue_t<collection_d, element_d>::_mutator_range_copy,
						queue_t<collection_d, element_d>::_mutator_range_set_pointer,
						queue_t<collection_d, element_d>::_pointer,
					},
					// mutator_range_a
					reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_begin)>(queue_t<collection_d, element_d>::mutator_begin),
					reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_end)>(queue_t<collection_d, element_d>::mutator_end),
				},
				// bidirectional_mutator_range_a
				reinterpret_cast<decltype(bidirectional_mutator_range_o<element_d>::mutator_begin)>(queue_t<collection_d, element_d>::mutator_begin),
				reinterpret_cast<decltype(bidirectional_mutator_range_o<element_d>::mutator_end)>(queue_t<collection_d, element_d>::mutator_end),
			},
			// random_access_mutator_range_a
			reinterpret_cast<decltype(random_access_mutator_range_o<element_d>::mutator_begin)>(queue_t<collection_d, element_d>::mutator_begin),
			reinterpret_cast<decltype(random_access_mutator_range_o<element_d>::mutator_end)>(queue_t<collection_d, element_d>::mutator_end),
		};
		return &operations;
	}

	template <typename collection_d, typename element_d>
	random_access_mutator_range_o<element_d> const* queue_t<collection_d, element_d>::_mutator_range_pointer_operations()
	{
		static random_access_mutator_range_o<element_d> operations = []()
		{
			random_access_mutator_range_o<element_d> ops = *queue_t<collection_d, element_d>::_mutator_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::_mutator_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == mutator_range_a<element_d>::cat ||
			abc == bidirectional_mutator_range_a<element_d>::cat ||
			abc == random_access_mutator_range_a<element_d>::cat;
	}

	template <typename collection_d, typename element_d>
	bool queue_t<collection_d, element_d>::_mutator_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!queue_t<collection_d, element_d>::_mutator_range_is(me, abstraction))
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
	void queue_t<collection_d, element_d>::_mutator_range_copy(con<> const& me,
		var<> const& copy)
	{
		new queue_t<collection_d, element_d>{ copy, me };
		queue_t<collection_d, element_d>::_clone(me, copy);
		copy.o = queue_t<collection_d, element_d>::_mutator_range_operations();
	}

	template <typename collection_d, typename element_d>
	void queue_t<collection_d, element_d>::_mutator_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? queue_t<collection_d, element_d>::_mutator_range_pointer_operations() : queue_t<collection_d, element_d>::_mutator_range_operations();
	}

	// instantiation
	template struct queue_t<std::vector<int64_t>, int64_t>;
	template struct queue_t<std::deque<int64_t>, int64_t>;
}
