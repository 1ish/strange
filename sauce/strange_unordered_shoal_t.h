#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H

namespace strange
{

// template <typename _key = any_a<>, typename _value = any_a<>, bool _concurrent_ = false, typename ___ego___ = unordered_shoal_a<_key, _value>>
template <typename _key, typename _value, bool _concurrent_, typename ___ego___>
class unordered_shoal_t : public thing_t<___ego___>
{
	template <typename _element_it, typename _iterator_, typename ___ego_it___ = forward_mutator_data_a<_element_it, _iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_mutator_data_a<_element_it, _iterator_> create(F&& it)
		{
			return forward_mutator_data_a<_element_it, _iterator_>::template create<mutator_t<_element_it, _iterator_>>(std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::unordered_shoal::mutator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<forward_mutator_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<forward_mutator_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward mutator
		inline _element_it get_() const
		{
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline _element_it set_(_element_it const& thing) const
		{
			_it->second = cast<typename _iterator_::value_type::second_type>(thing.at_index(1));
			return thing;
		}

		inline _element_it* operator->() const
		{
			return &operator*();
		}

		inline _element_it& operator*() const
		{
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline void increment_()
		{
			++_it;
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		_element_it mutable _pair; // stashing iterator

		friend class any_a<>;

		template <typename F>
		inline mutator_t(F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _pair{ flock_create() }
		{}
	};

	template <typename _element_it, typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_element_it, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_extractor_data_a<_element_it, _iterator_> create(unordered_shoal_a<> const& unordered_shoal, F&& it)
		{
			return forward_extractor_data_a<_element_it, _iterator_>::template create<extractor_t<_element_it, _iterator_>>(unordered_shoal, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::unordered_shoal::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<forward_extractor_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<forward_extractor_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward extractor
		inline _element_it get_() const
		{
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline _element_it const* operator->() const
		{
			return &operator*();
		}

		inline _element_it const& operator*() const
		{
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline void increment_()
		{
			++_it;
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		unordered_shoal_a<> const _unordered_shoal;
		_element_it mutable _pair; // stashing iterator

		friend class any_a<>;

		template <typename F>
		inline extractor_t(unordered_shoal_a<> const& unordered_shoal, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _unordered_shoal{ unordered_shoal }
			, _pair{ flock_create() }
		{}
	};

public:
	using std_unordered_map_key_value = std::unordered_map<_key, _value>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		auto result = create_();
		if (check<range_a<flock_a<>>>(range))
		{
			result += fast<range_a<flock_a<>>>(range);
		}
		return result;
	}

	static inline unordered_shoal_a<_key, _value> create_()
	{
		return create(std_unordered_map_key_value{});
	}

	template <typename... Args>
	static inline unordered_shoal_a<_key, _value> create_(Args&&... args)
	{
		return create(variadic_pair_u<_key, _value>::unordered_map(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline unordered_shoal_a<_key, _value> create(F&& init)
	{
		return unordered_shoal_a<_key, _value>::template create<unordered_shoal_t<_key, _value, _concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::unordered_shoal" + 
			std::string{ _concurrent_ ? "_concurrent" : "" } +
			kind_of<_key>().to_string() + "_" + kind_of<_value>().to_string());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym(type_().to_string() + "::create"), native_function_create(&unordered_shoal_t<_key, _value, _concurrent_>::create__));
	}

	// visitor pattern
	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& visited : _map)
			{
				inventory.update_index(last, visited.first);
				visited.first.visit_(inventory);
				inventory.update_index(last, visited.second);
				visited.second.visit_(inventory);
			}
		}
		return result;
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<unordered_shoal_a<_key, _value>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map == fast<unordered_shoal_a<_key, _value>>(thing).extract_map();
	}

	inline bool operator==(unordered_shoal_a<_key, _value> const& shoal) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map == shoal.extract_map();
	}

	inline bool operator!=(unordered_shoal_a<_key, _value> const& shoal) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map != shoal.extract_map();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		std::map<any_a<>, std::size_t> ordered;
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		for (auto const& pair : _map)
		{
			std::size_t seed = pair.first.hash();
			seed ^= pair.second.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			ordered.emplace(pair.first, seed);
		}
		std::size_t seed = std::hash<std::size_t>{}(_map.size());
		for (auto const& pair : ordered)
		{
			seed ^= pair.second + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline forward_extractor_a<flock_a<>> extract_begin_() const
	{
		return extractor_t<flock_a<>, typename std_unordered_map_key_value::const_iterator>::create(thing_t<___ego___>::me_(), _map.cbegin());
	}

	inline forward_extractor_data_a<flock_a<>, typename std_unordered_map_key_value::const_iterator> extract_begin() const
	{
		return extractor_t<flock_a<>, typename std_unordered_map_key_value::const_iterator>::create(thing_t<___ego___>::me_(), _map.cbegin());
	}

	inline forward_extractor_a<flock_a<>> extract_end_() const
	{
		return extractor_t<flock_a<>, typename std_unordered_map_key_value::const_iterator>::create(thing_t<___ego___>::me_(), _map.cend());
	}

	inline forward_extractor_data_a<flock_a<>, typename std_unordered_map_key_value::const_iterator> extract_end() const
	{
		return extractor_t<flock_a<>, typename std_unordered_map_key_value::const_iterator>::create(thing_t<___ego___>::me_(), _map.cend());
	}

	inline forward_mutator_a<flock_a<>> mutate_begin_()
	{
		return mutator_t<flock_a<>, typename std_unordered_map_key_value::iterator>::create(_map.begin());
	}

	inline forward_mutator_data_a<flock_a<>, typename std_unordered_map_key_value::iterator> mutate_begin()
	{
		return mutator_t<flock_a<>, typename std_unordered_map_key_value::iterator>::create(_map.begin());
	}

	inline forward_mutator_a<flock_a<>> mutate_end_()
	{
		return mutator_t<flock_a<>, typename std_unordered_map_key_value::iterator>::create(_map.end());
	}

	inline forward_mutator_data_a<flock_a<>, typename std_unordered_map_key_value::iterator> mutate_end()
	{
		return mutator_t<flock_a<>, typename std_unordered_map_key_value::iterator>::create(_map.end());
	}

	// collection
	inline any_a<> has_(_key const& key) const
	{
		return boole(has(key));
	}

	inline bool has(_key const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		typename std_unordered_map_key_value::const_iterator const it = _map.find(key);
		return it != _map.cend();
	}

	inline _value at_(_key const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		typename std_unordered_map_key_value::const_iterator const it = _map.find(key);
		if (it == _map.cend())
		{
			return mis("strange::unordered_shoal::at key not found");
		}
		return it->second;
	}

	inline _value update_(_key const& key, _value const& value)
	{
		update(key, value);
		return value;
	}

	inline void update(_key const& key, _value const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[key] = value;
	}

	inline void update_string(std::string const& s, _value const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[sym(s)] = value;
	}

	inline any_a<> insert_(_key const& key, _value const& value)
	{
		return boole(insert(key, value));
	}

	inline bool insert(_key const& key, _value const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.emplace(key, value).second;
	}

	inline bool insert_string(std::string const& s, _value const& value)
	{
		return insert(sym(s), value);
	}

	inline any_a<> erase_(_key const& key)
	{
		return boole(erase(key));
	}

	inline bool erase(_key const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.erase(key);
	}

	inline bool erase_string(std::string const& s)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.erase(sym(s));
	}

	inline ___ego___ clear_()
	{
		clear();
		return thing_t<___ego___>::me_();
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map.clear();
	}

	inline number_data_a<int64_t> size_() const
	{
		return num(size());
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_map.size());
	}

	inline any_a<> empty_() const
	{
		return boole(empty());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map.empty();
	}

	inline ___ego___ push_front_(flock_a<> const& pair)
	{
		push_front(pair);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(flock_a<> const& pair)
	{
		push_back(pair);
	}

	inline flock_a<> pop_front_()
	{
		return pop_back_();
	}

	inline ___ego___ push_back_(flock_a<> const& pair)
	{
		push_back(pair);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(flock_a<> const& pair)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[cast<_key>(pair.at_index(0))] = cast<_value>(pair.at_index(1));
	}

	inline flock_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		typename std_unordered_map_key_value::const_iterator const it = _map.cbegin();
		if (it == _map.cend())
		{
			throw dis("strange::unordered_shoal::pop_back called on empty unordered_shoal");
		}
		auto result = flock_vals(it->first, it->second);
		_map.erase(it);
		return result;
	}

	inline void self_assign_(range_a<flock_a<>> const& range)
	{
		if (check<unordered_shoal_a<_key, _value>>(range))
		{
			auto const other = fast<unordered_shoal_a<_key, _value>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map = other.extract_map();
		}
		else if (check<ordered_shoal_a<_key, _value>>(range))
		{
			auto const other = fast<ordered_shoal_a<_key, _value>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.clear();
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			auto read_lock = check<collection_a<_key, _value, flock_a<>>>(range) ? fast<collection_a<_key, _value, flock_a<>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.clear();
			for (auto const& pair : range)
			{
				if (pair.size() != 2)
				{
					throw dis("strange::unordered_shoal self_assign passed range containing flock of wrong size");
				}
				_map.emplace(cast<_key>(pair.at_index(0)), cast<_value>(pair.at_index(1)));
			}
		}
	}

	inline void self_add_(range_a<flock_a<>> const& range)
	{
		if (check<unordered_shoal_a<_key, _value>>(range))
		{
			auto const other = fast<unordered_shoal_a<_key, _value>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else if (check<ordered_shoal_a<_key, _value>>(range))
		{
			auto const other = fast<ordered_shoal_a<_key, _value>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			auto read_lock = check<collection_a<_key, _value, flock_a<>>>(range) ? fast<collection_a<_key, _value, flock_a<>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : range)
			{
				if (pair.size() != 2)
				{
					throw dis("strange::unordered_shoal += passed range containing flock of wrong size");
				}
				_map.emplace(cast<_key>(pair.at_index(0)), cast<_value>(pair.at_index(1)));
			}
		}
	}

	inline ___ego___ add_(range_a<flock_a<>> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result += range;
		return result;
	}

	inline void self_subtract_(range_a<flock_a<>> const& range)
	{
		if (check<unordered_shoal_a<_key, _value>>(range))
		{
			auto const other = fast<unordered_shoal_a<_key, _value>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else if (check<ordered_shoal_a<_key, _value>>(range))
		{
			auto const other = fast<ordered_shoal_a<_key, _value>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else
		{
			auto read_lock = check<collection_a<_key, _value, flock_a<>>>(range) ? fast<collection_a<_key, _value, flock_a<>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : range)
			{
				if (pair.empty())
				{
					throw dis("strange::unordered_shoal -= passed range containing empty flock");
				}
				_map.erase(cast<_key>(pair.at_index(0)));
			}
		}
	}

	inline ___ego___ subtract_(range_a<flock_a<>> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result -= range;
		return result;
	}

	inline any_a<> read_lock_() const
	{
		return data_t<read_lock_ptr<_concurrent_>>::create(make_read_lock_ptr<_concurrent_>(_mutex));
	}

	inline any_a<> write_lock_() const
	{
		return data_t<write_lock_ptr<_concurrent_>>::create(make_write_lock_ptr<_concurrent_>(_mutex));
	}

	// data
	inline std_unordered_map_key_value const& extract_map() const
	{
		return _map;
	}

	inline std_unordered_map_key_value& mutate_map()
	{
		return _map;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_unordered_map_key_value _map;

	friend class any_a<>;

	template <typename F>
	inline unordered_shoal_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _map{ std::forward<F>(init) }
	{}

public:
	inline unordered_shoal_t(unordered_shoal_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _map{ other._map }
	{}

	inline unordered_shoal_t(unordered_shoal_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _map{ std::move(other._map) }
	{}

private:
	static bool const ___share___;
	friend class ___unordered_shoal_t_share___;
};

template <typename _key, typename _value, bool _concurrent_, typename ___ego___>
bool const unordered_shoal_t<_key, _value, _concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	unordered_shoal_t<_key, _value, _concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___unordered_shoal_t_share___
{
	static inline bool ___share___()
	{
		return unordered_shoal_t<>::___share___
			&& unordered_shoal_t<any_a<>, any_a<>, true>::___share___;
	}
};

// template <typename _key = any_a<>, typename _value = any_a<>, bool _concurrent_ = false, typename ___unordered_shoal_a___ = unordered_shoal_a<_key, _value>>
template <typename _key, typename _value, bool _concurrent_, typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ unordered_shoal_create()
{
	return unordered_shoal_t<_key, _value, _concurrent_>::create_();
}

template <typename... Args>
inline unordered_shoal_a<> unordered_shoal_vals(Args&&... args)
{
	return unordered_shoal_t<>::create_(std::forward<Args>(args)...);
}

} // namespace strange

#endif
