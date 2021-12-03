#include "../../strange__core.h"

namespace strange
{
	// table_t
	// table_o
	template <typename collection_d, typename key_d, typename value_d>
	table_o<key_d, value_d> const* table_t<collection_d, key_d, value_d>::_operations()
	{
		static table_o<key_d, value_d> operations =
		{
			{
				{
					// any_a
					table_a<key_d, value_d>::cat,
					table_t<collection_d, key_d, value_d>::is,
					table_t<collection_d, key_d, value_d>::as,
					table_t<collection_d, key_d, value_d>::type,
					table_t<collection_d, key_d, value_d>::set_error,
					table_t<collection_d, key_d, value_d>::error,
					table_t<collection_d, key_d, value_d>::hash,
					table_t<collection_d, key_d, value_d>::equal,
					table_t<collection_d, key_d, value_d>::less,
					table_t<collection_d, key_d, value_d>::less_or_equal,
					table_t<collection_d, key_d, value_d>::pack,
					table_t<collection_d, key_d, value_d>::_free,
					table_t<collection_d, key_d, value_d>::_copy,
					table_t<collection_d, key_d, value_d>::_set_pointer,
					table_t<collection_d, key_d, value_d>::_pointer,
				},
				// collection_a
				reinterpret_cast<decltype(collection_o<key_d, value_d, element_d>::range)>(table_t<collection_d, key_d, value_d>::range),
				reinterpret_cast<decltype(collection_o<key_d, value_d, element_d>::begin)>(table_t<collection_d, key_d, value_d>::begin),
				reinterpret_cast<decltype(collection_o<key_d, value_d, element_d>::end)>(table_t<collection_d, key_d, value_d>::end),
				table_t<collection_d, key_d, value_d>::read_lock,
				table_t<collection_d, key_d, value_d>::write_lock,
				table_t<collection_d, key_d, value_d>::has,
				table_t<collection_d, key_d, value_d>::at,
				table_t<collection_d, key_d, value_d>::update,
				table_t<collection_d, key_d, value_d>::insert,
				table_t<collection_d, key_d, value_d>::erase,
				table_t<collection_d, key_d, value_d>::clear,
				table_t<collection_d, key_d, value_d>::size,
				table_t<collection_d, key_d, value_d>::empty,
				table_t<collection_d, key_d, value_d>::push_front,
				table_t<collection_d, key_d, value_d>::pop_front,
				table_t<collection_d, key_d, value_d>::push_back,
				table_t<collection_d, key_d, value_d>::pop_back,
				table_t<collection_d, key_d, value_d>::self_assign,
				table_t<collection_d, key_d, value_d>::self_add,
				table_t<collection_d, key_d, value_d>::add,
				table_t<collection_d, key_d, value_d>::self_subtract,
				table_t<collection_d, key_d, value_d>::subtract,
			},
			// table_a
			table_t<collection_d, key_d, value_d>::range,
			table_t<collection_d, key_d, value_d>::begin,
			table_t<collection_d, key_d, value_d>::end,
			table_t<collection_d, key_d, value_d>::mutator_range,
			table_t<collection_d, key_d, value_d>::mutator_begin,
			table_t<collection_d, key_d, value_d>::mutator_end,
			table_t<collection_d, key_d, value_d>::pair_range,
			table_t<collection_d, key_d, value_d>::pair_begin,
			table_t<collection_d, key_d, value_d>::pair_end,
			table_t<collection_d, key_d, value_d>::pair_mutator_range,
			table_t<collection_d, key_d, value_d>::pair_mutator_begin,
			table_t<collection_d, key_d, value_d>::pair_mutator_end,
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	table_o<key_d, value_d> const* table_t<collection_d, key_d, value_d>::_pointer_operations()
	{
		static table_o<key_d, value_d> operations = []()
		{
			table_o<key_d, value_d> ops = *table_t<collection_d, key_d, value_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == collection_a<key_d, value_d, element_d>::cat ||
			abc == table_a<key_d, value_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!table_t<collection_d, key_d, value_d>::is(me, abstraction))
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
	var<symbol_a> table_t<collection_d, key_d, value_d>::type(con<> const& me)
	{
		static auto r = sym("strange::table");
		return r;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::equal(con<> const& me,
		con<> const& other)
	{
		auto const oc = other.dynamic<con<table_a<key_d, value_d>>>();
		if (oc.o->something(oc))
		{
			return table_t<collection_d, key_d, value_d>::equal_table(me.reference<con<table_a<key_d, value_d>>>(), oc);
		}
		return thing_t::equal(me, other);
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new table_t<collection_d, key_d, value_d>{ copy, me };
		table_t<collection_d, key_d, value_d>::_clone(me, copy);
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? table_t<collection_d, key_d, value_d>::_pointer_operations() : table_t<collection_d, key_d, value_d>::_operations();
	}

	// collection_a
	template <typename collection_d, typename key_d, typename value_d>
	ptr<> table_t<collection_d, key_d, value_d>::read_lock(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return ptr<>{};
	}

	template <typename collection_d, typename key_d, typename value_d>
	ptr<> table_t<collection_d, key_d, value_d>::write_lock(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		return ptr<>{};
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::has(con<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key)
	{
		auto const& collection = static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_;
		return collection.find(key) != collection.cend();
	}

	template <typename collection_d, typename key_d, typename value_d>
	value_d table_t<collection_d, key_d, value_d>::at(con<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key)
	{
		auto const& collection = static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_;
		auto const it = collection.find(key);
		if (it != collection.cend())
		{
			return it->second.value_;
		}
		return value_d{};
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::update(var<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key,
		value_d const& value)
	{
		me.mut();		
		static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.insert_or_assign(key,
			table_value_tuple_u<key_d, value_d, std::pair<key_d const, value_d>>{ value });
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::insert(var<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key,
		value_d const& value)
	{
		me.mut();
		return static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.insert(std::make_pair(key,
			table_value_tuple_u<key_d, value_d, std::pair<key_d const, value_d>>{ value })).second;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::erase(var<collection_a<key_d, value_d, element_d>> const& me,
		key_d const& key)
	{
		me.mut();
		return static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.erase(key) != 0;
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::clear(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.clear();
	}

	template <typename collection_d, typename key_d, typename value_d>
	int64_t table_t<collection_d, key_d, value_d>::size(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return static_cast<int64_t>(static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.size());
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::empty(con<collection_a<key_d, value_d, element_d>> const& me)
	{
		return static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.empty();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::push_front(var<collection_a<key_d, value_d, element_d>> const& me,
		element_d const& element)
	{
		key_d key;
		value_d value;
		element.o->destruct(element, key, value);
		table_t<collection_d, key_d, value_d>::insert(me, key, value);
	}

	template <typename collection_d, typename key_d, typename value_d>
	typename table_t<collection_d, key_d, value_d>::element_d table_t<collection_d, key_d, value_d>::pop_front(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		me.mut();
		auto& collection = static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_;
		if (collection.empty())
		{
			return element_d{};
		}
		auto element = strange::tuple(collection.cbegin()->first, collection.cbegin()->second.value_);
		collection.erase(collection.cbegin());
		return element;
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::push_back(var<collection_a<key_d, value_d, element_d>> const& me,
		element_d const& element)
	{
		table_t<collection_d, key_d, value_d>::push_front(me, element);
	}

	template <typename collection_d, typename key_d, typename value_d>
	typename table_t<collection_d, key_d, value_d>::element_d table_t<collection_d, key_d, value_d>::pop_back(var<collection_a<key_d, value_d, element_d>> const& me)
	{
		return table_t<collection_d, key_d, value_d>::pop_front(me);
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::self_assign(var<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		if (me.o->identity(me) != range.o->identity(range))
		{
			auto& collection = static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_;
			collection.clear();
			for (element_d const& element : range)
			{
				key_d key;
				value_d value;
				element.o->destruct(element, key, value);
				collection.insert_or_assign(key,
					table_value_tuple_u<key_d, value_d, std::pair<key_d const, value_d>>{ value });
			}
		}
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::self_add(var<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_;
		if (me.o->identity(me) != range.o->identity(range))
		{
			for (element_d const& element : range)
			{
				key_d key;
				value_d value;
				element.o->destruct(element, key, value);
				collection.insert_or_assign(key,
					table_value_tuple_u<key_d, value_d, std::pair<key_d const, value_d>>{ value });
			}
		}
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<collection_a<key_d, value_d, typename table_t<collection_d, key_d, value_d>::element_d>> table_t<collection_d, key_d, value_d>::add(con<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<key_d, value_d, element_d>> result{ me };
		self_add(result, range);
		return result;
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::self_subtract(var<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		me.mut();
		auto& collection = static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_;
		if (me.o->identity(me) == range.o->identity(range))
		{
			collection.clear();
		}
		else
		{
			for (element_d const& element : range)
			{
				if (collection.empty())
				{
					break;
				}
				key_d key;
				value_d value;
				element.o->destruct(element, key, value);
				collection.erase(key);
			}
		}
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<collection_a<key_d, value_d, typename table_t<collection_d, key_d, value_d>::element_d>> table_t<collection_d, key_d, value_d>::subtract(con<collection_a<key_d, value_d, element_d>> const& me,
		con<range_a<element_d>> const& range)
	{
		var<collection_a<key_d, value_d, element_d>> result{ me };
		self_subtract(result, range);
		return result;
	}

	// table_a
	template <typename collection_d, typename key_d, typename value_d>
	var<tuple_range_a<key_d, value_d>> table_t<collection_d, key_d, value_d>::range(con<table_a<key_d, value_d>> const& me)
	{
		tuple_range_a<key_d, value_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = table_t<collection_d, key_d, value_d>::_range_operations();
		return var<tuple_range_a<key_d, value_d>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_tuple_extractor_a<key_d, value_d>> table_t<collection_d, key_d, value_d>::begin(con<table_a<key_d, value_d>> const& me)
	{
		return forward_tuple_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_tuple_extractor_a<key_d, value_d>> table_t<collection_d, key_d, value_d>::end(con<table_a<key_d, value_d>> const& me)
	{
		return forward_tuple_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<tuple_mutator_range_a<key_d, value_d>> table_t<collection_d, key_d, value_d>::mutator_range(var<table_a<key_d, value_d>> const& me)
	{
		me.mut();
		tuple_mutator_range_a<key_d, value_d> abstraction;
		abstraction.t = me.t;
		abstraction.o = table_t<collection_d, key_d, value_d>::_mutator_range_operations();
		return var<tuple_mutator_range_a<key_d, value_d>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_tuple_mutator_a<key_d, value_d>> table_t<collection_d, key_d, value_d>::mutator_begin(var<table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return forward_tuple_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.begin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_tuple_mutator_a<key_d, value_d>> table_t<collection_d, key_d, value_d>::mutator_end(var<table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return forward_tuple_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.end());
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<range_a<std::pair<key_d const, value_d>>> table_t<collection_d, key_d, value_d>::pair_range(con<table_a<key_d, value_d>> const& me)
	{
		range_a<std::pair<key_d const, value_d>> abstraction;
		abstraction.t = me.t;
		abstraction.o = table_t<collection_d, key_d, value_d>::_pair_range_operations();
		return var<range_a<std::pair<key_d const, value_d>>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_extractor_a<std::pair<key_d const, value_d>>> table_t<collection_d, key_d, value_d>::pair_begin(con<table_a<key_d, value_d>> const& me)
	{
		return forward_pair_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cbegin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_extractor_a<std::pair<key_d const, value_d>>> table_t<collection_d, key_d, value_d>::pair_end(con<table_a<key_d, value_d>> const& me)
	{
		return forward_pair_extractor_t<typename collection_d::const_iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_.cend());
	}

	template <typename collection_d, typename key_d, typename value_d>
	var<mutator_range_a<std::pair<key_d const, value_d>>> table_t<collection_d, key_d, value_d>::pair_mutator_range(var<table_a<key_d, value_d>> const& me)
	{
		me.mut();
		mutator_range_a<std::pair<key_d const, value_d>> abstraction;
		abstraction.t = me.t;
		abstraction.o = table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
		return var<mutator_range_a<std::pair<key_d const, value_d>>>{ abstraction };
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_mutator_a<std::pair<key_d const, value_d>>> table_t<collection_d, key_d, value_d>::pair_mutator_begin(var<table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return forward_pair_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.begin());
	}

	template <typename collection_d, typename key_d, typename value_d>
	fit<forward_mutator_a<std::pair<key_d const, value_d>>> table_t<collection_d, key_d, value_d>::pair_mutator_end(var<table_a<key_d, value_d>> const& me)
	{
		me.mut();
		return forward_pair_mutator_t<typename collection_d::iterator, key_d, value_d>::create(static_cast<table_t<collection_d, key_d, value_d>*>(me.t)->collection_.end());
	}

	// tuple_range_a
	template <typename collection_d, typename key_d, typename value_d>
	tuple_range_o<key_d, value_d> const* table_t<collection_d, key_d, value_d>::_range_operations()
	{
		static tuple_range_o<key_d, value_d> operations =
		{
			{
				{
					// any_a
					tuple_range_a<key_d, value_d>::cat,
					table_t<collection_d, key_d, value_d>::_range_is,
					table_t<collection_d, key_d, value_d>::_range_as,
					table_t<collection_d, key_d, value_d>::type,
					table_t<collection_d, key_d, value_d>::set_error,
					table_t<collection_d, key_d, value_d>::error,
					table_t<collection_d, key_d, value_d>::hash,
					table_t<collection_d, key_d, value_d>::equal,
					table_t<collection_d, key_d, value_d>::less,
					table_t<collection_d, key_d, value_d>::less_or_equal,
					table_t<collection_d, key_d, value_d>::pack,
					table_t<collection_d, key_d, value_d>::_free,
					table_t<collection_d, key_d, value_d>::_range_copy,
					table_t<collection_d, key_d, value_d>::_range_set_pointer,
					table_t<collection_d, key_d, value_d>::_pointer,
				},
				// range_a
				reinterpret_cast<decltype(range_o<element_d>::begin)>(table_t<collection_d, key_d, value_d>::begin),
				reinterpret_cast<decltype(range_o<element_d>::end)>(table_t<collection_d, key_d, value_d>::end),
			},
			// tuple_range_a
			reinterpret_cast<decltype(tuple_range_o<key_d, value_d>::begin)>(table_t<collection_d, key_d, value_d>::begin),
			reinterpret_cast<decltype(tuple_range_o<key_d, value_d>::end)>(table_t<collection_d, key_d, value_d>::end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	tuple_range_o<key_d, value_d> const* table_t<collection_d, key_d, value_d>::_range_pointer_operations()
	{
		static tuple_range_o<key_d, value_d> operations = []()
		{
			tuple_range_o<key_d, value_d> ops = *table_t<collection_d, key_d, value_d>::_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<element_d>::cat ||
			abc == tuple_range_a<key_d, value_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!table_t<collection_d, key_d, value_d>::_range_is(me, abstraction))
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
	void table_t<collection_d, key_d, value_d>::_range_copy(con<> const& me,
		var<> const& copy)
	{
		new table_t<collection_d, key_d, value_d>{ copy, me };
		table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = table_t<collection_d, key_d, value_d>::_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? table_t<collection_d, key_d, value_d>::_range_pointer_operations() : table_t<collection_d, key_d, value_d>::_range_operations();
	}

	// tuple_mutator_range_a
	template <typename collection_d, typename key_d, typename value_d>
	tuple_mutator_range_o<key_d, value_d> const* table_t<collection_d, key_d, value_d>::_mutator_range_operations()
	{
		static tuple_mutator_range_o<key_d, value_d> operations =
		{
			{
				{
					// any_a
					tuple_mutator_range_a<key_d, value_d>::cat,
					table_t<collection_d, key_d, value_d>::_mutator_range_is,
					table_t<collection_d, key_d, value_d>::_mutator_range_as,
					table_t<collection_d, key_d, value_d>::type,
					table_t<collection_d, key_d, value_d>::set_error,
					table_t<collection_d, key_d, value_d>::error,
					table_t<collection_d, key_d, value_d>::hash,
					table_t<collection_d, key_d, value_d>::equal,
					table_t<collection_d, key_d, value_d>::less,
					table_t<collection_d, key_d, value_d>::less_or_equal,
					table_t<collection_d, key_d, value_d>::pack,
					table_t<collection_d, key_d, value_d>::_free,
					table_t<collection_d, key_d, value_d>::_mutator_range_copy,
					table_t<collection_d, key_d, value_d>::_mutator_range_set_pointer,
					table_t<collection_d, key_d, value_d>::_pointer,
				},
				// mutator_range_a
				reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_begin)>(table_t<collection_d, key_d, value_d>::mutator_begin),
				reinterpret_cast<decltype(mutator_range_o<element_d>::mutator_end)>(table_t<collection_d, key_d, value_d>::mutator_end),
			},
			// tuple_mutator_range_a
			reinterpret_cast<decltype(tuple_mutator_range_o<key_d, value_d>::mutator_begin)>(table_t<collection_d, key_d, value_d>::mutator_begin),
			reinterpret_cast<decltype(tuple_mutator_range_o<key_d, value_d>::mutator_end)>(table_t<collection_d, key_d, value_d>::mutator_end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	tuple_mutator_range_o<key_d, value_d> const* table_t<collection_d, key_d, value_d>::_mutator_range_pointer_operations()
	{
		static tuple_mutator_range_o<key_d, value_d> operations = []()
		{
			tuple_mutator_range_o<key_d, value_d> ops = *table_t<collection_d, key_d, value_d>::_mutator_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_mutator_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == mutator_range_a<element_d>::cat ||
			abc == tuple_mutator_range_a<key_d, value_d>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_mutator_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!table_t<collection_d, key_d, value_d>::_mutator_range_is(me, abstraction))
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
	void table_t<collection_d, key_d, value_d>::_mutator_range_copy(con<> const& me,
		var<> const& copy)
	{
		new table_t<collection_d, key_d, value_d>{ copy, me };
		table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = table_t<collection_d, key_d, value_d>::_mutator_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::_mutator_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? table_t<collection_d, key_d, value_d>::_mutator_range_pointer_operations() : table_t<collection_d, key_d, value_d>::_mutator_range_operations();
	}

	// range_a
	template <typename collection_d, typename key_d, typename value_d>
	range_o<std::pair<key_d const, value_d>> const* table_t<collection_d, key_d, value_d>::_pair_range_operations()
	{
		static range_o<std::pair<key_d const, value_d>> operations =
		{
			{
				// any_a
				range_a<std::pair<key_d const, value_d>>::cat,
				table_t<collection_d, key_d, value_d>::_pair_range_is,
				table_t<collection_d, key_d, value_d>::_pair_range_as,
				table_t<collection_d, key_d, value_d>::type,
				table_t<collection_d, key_d, value_d>::set_error,
				table_t<collection_d, key_d, value_d>::error,
				table_t<collection_d, key_d, value_d>::hash,
				table_t<collection_d, key_d, value_d>::equal,
				table_t<collection_d, key_d, value_d>::less,
				table_t<collection_d, key_d, value_d>::less_or_equal,
				table_t<collection_d, key_d, value_d>::pack,
				table_t<collection_d, key_d, value_d>::_free,
				table_t<collection_d, key_d, value_d>::_pair_range_copy,
				table_t<collection_d, key_d, value_d>::_pair_range_set_pointer,
				table_t<collection_d, key_d, value_d>::_pointer,
			},
			// range_a
			reinterpret_cast<decltype(range_o<std::pair<key_d const, value_d>>::begin)>(table_t<collection_d, key_d, value_d>::pair_begin),
			reinterpret_cast<decltype(range_o<std::pair<key_d const, value_d>>::end)>(table_t<collection_d, key_d, value_d>::pair_end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	range_o<std::pair<key_d const, value_d>> const* table_t<collection_d, key_d, value_d>::_pair_range_pointer_operations()
	{
		static range_o<std::pair<key_d const, value_d>> operations = []()
		{
			range_o<std::pair<key_d const, value_d>> ops = *table_t<collection_d, key_d, value_d>::_pair_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_pair_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == range_a<std::pair<key_d const, value_d>>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_pair_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!table_t<collection_d, key_d, value_d>::_pair_range_is(me, abstraction))
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
	void table_t<collection_d, key_d, value_d>::_pair_range_copy(con<> const& me,
		var<> const& copy)
	{
		new table_t<collection_d, key_d, value_d>{ copy, me };
		table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = table_t<collection_d, key_d, value_d>::_pair_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::_pair_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? table_t<collection_d, key_d, value_d>::_pair_range_pointer_operations() : table_t<collection_d, key_d, value_d>::_pair_range_operations();
	}

	// mutator_range_a
	template <typename collection_d, typename key_d, typename value_d>
	mutator_range_o<std::pair<key_d const, value_d>> const* table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations()
	{
		static mutator_range_o<std::pair<key_d const, value_d>> operations =
		{
			{
				// any_a
				mutator_range_a<std::pair<key_d const, value_d>>::cat,
				table_t<collection_d, key_d, value_d>::_pair_mutator_range_is,
				table_t<collection_d, key_d, value_d>::_pair_mutator_range_as,
				table_t<collection_d, key_d, value_d>::type,
				table_t<collection_d, key_d, value_d>::set_error,
				table_t<collection_d, key_d, value_d>::error,
				table_t<collection_d, key_d, value_d>::hash,
				table_t<collection_d, key_d, value_d>::equal,
				table_t<collection_d, key_d, value_d>::less,
				table_t<collection_d, key_d, value_d>::less_or_equal,
				table_t<collection_d, key_d, value_d>::pack,
				table_t<collection_d, key_d, value_d>::_free,
				table_t<collection_d, key_d, value_d>::_pair_mutator_range_copy,
				table_t<collection_d, key_d, value_d>::_pair_mutator_range_set_pointer,
				table_t<collection_d, key_d, value_d>::_pointer,
			},
			// mutator_range_a
			reinterpret_cast<decltype(mutator_range_o<std::pair<key_d const, value_d>>::mutator_begin)>(table_t<collection_d, key_d, value_d>::pair_mutator_begin),
			reinterpret_cast<decltype(mutator_range_o<std::pair<key_d const, value_d>>::mutator_end)>(table_t<collection_d, key_d, value_d>::pair_mutator_end),
		};
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	mutator_range_o<std::pair<key_d const, value_d>> const* table_t<collection_d, key_d, value_d>::_pair_mutator_range_pointer_operations()
	{
		static mutator_range_o<std::pair<key_d const, value_d>> operations = []()
		{
			mutator_range_o<std::pair<key_d const, value_d>> ops = *table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_pair_mutator_range_is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == mutator_range_a<std::pair<key_d const, value_d>>::cat;
	}

	template <typename collection_d, typename key_d, typename value_d>
	bool table_t<collection_d, key_d, value_d>::_pair_mutator_range_as(con<> const& me,
		var<> const& abstraction)
	{
		if (!table_t<collection_d, key_d, value_d>::_pair_mutator_range_is(me, abstraction))
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
	void table_t<collection_d, key_d, value_d>::_pair_mutator_range_copy(con<> const& me,
		var<> const& copy)
	{
		new table_t<collection_d, key_d, value_d>{ copy, me };
		table_t<collection_d, key_d, value_d>::_clone(me, copy);
		copy.o = table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
	}

	template <typename collection_d, typename key_d, typename value_d>
	void table_t<collection_d, key_d, value_d>::_pair_mutator_range_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? table_t<collection_d, key_d, value_d>::_pair_mutator_range_pointer_operations() : table_t<collection_d, key_d, value_d>::_pair_mutator_range_operations();
	}

	// instantiation
	template struct table_t<std::unordered_map<int64_t, table_value_tuple_u<int64_t, int64_t, std::pair<int64_t const, int64_t>>>, int64_t, int64_t>;
	template struct table_t<std::map<int64_t, table_value_tuple_u<int64_t, int64_t, std::pair<int64_t const, int64_t>>>, int64_t, int64_t>;
}
