#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H

namespace strange
{

// template <bool _concurrent_ = false, typename ___ego___ = unordered_shoal_a<>>
template <bool _concurrent_, typename ___ego___>
class unordered_shoal_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = forward_mutator_data_a<_element, _iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_mutator_data_a<_element, _iterator_> create(unordered_shoal_t const& unordered_shoal_thing, F&& it)
		{
			return forward_mutator_data_a<_element, _iterator_>::template create<mutator_t<_element, _iterator_>>(unordered_shoal_thing, std::forward<F>(it));
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
			return check<forward_mutator_data_a<_element, _iterator_>>(thing) &&
				_it == fast<forward_mutator_data_a<_element, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward mutator
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check<flock_a<>>(thing))
			{
				throw dis("strange::unordered_shoal::mutator set passed non-flock");
			}
			typename concurrent_u<_concurrent_>::write_lock lock(_unordered_shoal_thing._mutex);
			return _it->second = fast<flock_a<>>(thing).at_index(1);
		}

		inline any_a<>* operator->() const
		{
			return &operator*();
		}

		inline any_a<>& operator*() const
		{
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
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
		flock_a<> mutable _pair; // stashing mutator
		unordered_shoal_t const& _unordered_shoal_thing;

		friend class any_a<>;

		template <typename F>
		inline mutator_t(unordered_shoal_t const& unordered_shoal_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _pair{ flock_create() }
			, _unordered_shoal_thing{ unordered_shoal_thing }
		{}
	};

	template <typename _element, typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_extractor_data_a<_element, _iterator_> create(unordered_shoal_a<> const& unordered_shoal, unordered_shoal_t const& unordered_shoal_thing, F&& it)
		{
			return forward_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(unordered_shoal, unordered_shoal_thing, std::forward<F>(it));
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
			return check<forward_extractor_data_a<_element, _iterator_>>(thing) &&
				_it == fast<forward_extractor_data_a<_element, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward extractor
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
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
		flock_a<> mutable _pair; // stashing mutator
		unordered_shoal_t const& _unordered_shoal_thing;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(unordered_shoal_a<> const& unordered_shoal, unordered_shoal_t const& unordered_shoal_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _unordered_shoal{ unordered_shoal }
			, _pair{ flock_create() }
			, _unordered_shoal_thing{ unordered_shoal_thing }
		{}
	};

public:
	using std_unordered_map_any_any = std::unordered_map<any_a<>, any_a<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline unordered_shoal_a<> create_()
	{
		return create(std_unordered_map_any_any{});
	}

	template <typename... Args>
	static inline unordered_shoal_a<> create_(Args&&... args)
	{
		return create(variadic_pair_u<>::unordered_map(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline unordered_shoal_a<> create(F&& init)
	{
		return unordered_shoal_a<>::create<unordered_shoal_t<_concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::unordered_shoal" + std::string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&unordered_shoal_t<_concurrent_>::create__));
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
		if (!check<unordered_shoal_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map == fast<unordered_shoal_a<>>(thing).extract_map();
	}

	inline bool operator==(unordered_shoal_a<> const& shoal) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map == shoal.extract_map();
	}

	inline bool operator!=(unordered_shoal_a<> const& shoal) const
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
	inline forward_extractor_a<any_a<>> extract_begin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_map_any_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _map.cbegin());
	}

	inline forward_extractor_data_a<any_a<>, typename std_unordered_map_any_any::const_iterator> extract_begin() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_map_any_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _map.cbegin());
	}

	inline forward_extractor_a<any_a<>> extract_end_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_map_any_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _map.cend());
	}

	inline forward_extractor_data_a<any_a<>, typename std_unordered_map_any_any::const_iterator> extract_end() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_map_any_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _map.cend());
	}

	inline forward_mutator_a<any_a<>> mutate_begin_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_unordered_map_any_any::iterator>::create(*this, _map.begin());
	}

	inline forward_mutator_data_a<any_a<>, typename std_unordered_map_any_any::iterator> mutate_begin()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_unordered_map_any_any::iterator>::create(*this, _map.begin());
	}

	inline forward_mutator_a<any_a<>> mutate_end_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_unordered_map_any_any::iterator>::create(*this, _map.end());
	}

	inline forward_mutator_data_a<any_a<>, typename std_unordered_map_any_any::iterator> mutate_end()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_unordered_map_any_any::iterator>::create(*this, _map.end());
	}

	// collection
	inline any_a<> has_(any_a<> const& key) const
	{
		return boole(has(key));
	}

	inline bool has(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_unordered_map_any_any::const_iterator const it = _map.find(key);
		return it != _map.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_unordered_map_any_any::const_iterator const it = _map.find(key);
		if (it == _map.cend())
		{
			return mis("strange::unordered_shoal::at key not found");
		}
		return it->second;
	}

	inline any_a<> at_string(std::string const& s) const
	{
		return at_(sym(s));
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = no())
	{
		update(key, value);
		return value;
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[key] = value;
	}

	inline void update_string(std::string const& s, any_a<> const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[sym(s)] = value;
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = no())
	{
		return boole(insert(key, value));
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.emplace(key, value).second;
	}

	inline bool insert_string(std::string const& s, any_a<> const& value)
	{
		return insert(sym(s), value);
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(erase(key));
	}

	inline bool erase(any_a<> const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.erase(key);
	}

	inline bool erase_string(std::string const& s)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.erase(sym(s));
	}

	inline collection_a<> clear_()
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

	inline collection_a<> push_front_(any_a<> const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(any_a<> const& thing)
	{
		push_back(thing);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline collection_a<> push_back_(any_a<> const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[thing] = thing;
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		std_unordered_map_any_any::const_iterator const it = _map.cbegin();
		if (it == _map.cend())
		{
			return no();
		}
		any_a<> result = it->second;
		_map.erase(it);
		return result;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto const other = fast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map = other.extract_map();
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto const other = fast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.clear();
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.clear();
			for (auto const& thing : range)
			{
				if (!check<flock_a<>>(thing))
				{
					throw dis("strange::unordered_shoal self_assign passed range containing non-flock");
				}
				flock_a<> pair = fast<flock_a<>>(thing);
				if (pair.size() != 2)
				{
					throw dis("strange::unordered_shoal self_assign passed range containing flock of wrong size");
				}
				_map.emplace(pair.at_index(0), pair.at_index(1));
			}
		}
	}

	inline void self_add_(range_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto const other = fast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto const other = fast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				if (!check<flock_a<>>(thing))
				{
					throw dis("strange::unordered_shoal += passed range containing non-flock");
				}
				flock_a<> pair = fast<flock_a<>>(thing);
				if (pair.size() != 2)
				{
					throw dis("strange::unordered_shoal += passed range containing flock of wrong size");
				}
				_map.emplace(pair.at_index(0), pair.at_index(1));
			}
		}
	}

	inline collection_a<> add_(range_a<> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result += range;
		return result;
	}

	inline void self_subtract_(range_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto const other = fast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto const other = fast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_map.erase(thing);
			}
		}
	}

	inline collection_a<> subtract_(range_a<> const& range) const
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
	inline std_unordered_map_any_any const& extract_map() const
	{
		return _map;
	}

	inline std_unordered_map_any_any& mutate_map()
	{
		return _map;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_unordered_map_any_any _map;

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

template <bool _concurrent_, typename ___ego___>
bool const unordered_shoal_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	unordered_shoal_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___unordered_shoal_t_share___
{
	static inline bool ___share___()
	{
		return unordered_shoal_t<>::___share___
			&& unordered_shoal_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false, typename ___unordered_shoal_a___ = unordered_shoal_a<>>
template <bool _concurrent_, typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ unordered_shoal_create()
{
	return unordered_shoal_t<_concurrent_>::create_();
}

template <typename... Args>
inline unordered_shoal_a<> unordered_shoal_vals(Args&&... args)
{
	return unordered_shoal_t<>::create_(std::forward<Args>(args)...);
}

} // namespace strange

#endif
