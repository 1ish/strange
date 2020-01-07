#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = unordered_shoal_a<>>
class unordered_shoal_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego___ = forward_iterator_data_a<_iterator_>>
	class iterator_t : public thing_t<___ego___>
	{
	public:
		// override
		using over = thing_o<iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline forward_iterator_data_a<_iterator_> create(unordered_shoal_t const& unordered_shoal_thing, F&& it)
		{
			return forward_iterator_data_a<_iterator_>{ over{ iterator_t<_iterator_>(unordered_shoal_thing, std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::unordered_shoal::iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<forward_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<forward_iterator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline any_a<> set__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::unordered_shoal::iterator set passed empty range");
			}
			return set_(*it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check<flock_a<>>(thing))
			{
				throw dis("strange::unordered_shoal::iterator set passed non-flock");
			}
			typename concurrent_u<_concurrent_>::write_lock lock(_unordered_shoal_thing._mutex);
			return _it->second = cast<flock_a<>>(thing).at_index(1);
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

		inline ___ego___ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline ___ego___ increment_()
		{
			operator++();
			return me_();
		}

		inline iterator_t& operator++()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			++_it;
			return *this;
		}

		inline iterator_t operator++(int)
		{
			iterator_t result = *this;
			operator++();
			return result;
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
		flock_a<> mutable _pair; // stashing iterator
		unordered_shoal_t const& _unordered_shoal_thing;

		template <typename F>
		inline iterator_t(unordered_shoal_t const& unordered_shoal_thing, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _pair{ flock_t<>::create_() }
			, _unordered_shoal_thing{ unordered_shoal_thing }
		{}
	};

	template <typename _iterator_, typename ___ego___ = forward_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline forward_const_iterator_data_a<_iterator_> create(unordered_shoal_a<> const& unordered_shoal, unordered_shoal_t const& unordered_shoal_thing, F&& it)
		{
			return forward_const_iterator_data_a<_iterator_>{ over{ const_iterator_t<_iterator_>(unordered_shoal, unordered_shoal_thing, std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::unordered_shoal::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<forward_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<forward_const_iterator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

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

		inline ___ego___ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline ___ego___ increment_()
		{
			operator++();
			return me_();
		}

		inline const_iterator_t& operator++()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_shoal_thing._mutex);
			++_it;
			return *this;
		}

		inline const_iterator_t operator++(int)
		{
			const_iterator_t result = *this;
			operator++();
			return result;
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
		flock_a<> mutable _pair; // stashing iterator
		unordered_shoal_t const& _unordered_shoal_thing;

		template <typename F>
		inline const_iterator_t(unordered_shoal_a<> const& unordered_shoal, unordered_shoal_t const& unordered_shoal_thing, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _unordered_shoal{ unordered_shoal }
			, _pair{ flock_t<>::create_() }
			, _unordered_shoal_thing{ unordered_shoal_thing }
		{}
	};

public:
	using std_unordered_map_any_any = std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>;

	// override
	using over = collection_o<unordered_shoal_t<_concurrent_>>;

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
		return unordered_shoal_a<>{ over{ unordered_shoal_t<_concurrent_>{ std::forward<F>(init) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<unordered_shoal_t<_concurrent_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<unordered_shoal_t<_concurrent_>>::share(shoal);
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<inventory_a<>>(range))
		{
			throw dis("strange::unordered_shoal::visit passed non-inventory");
		}
		return visit_(cast<inventory_a<>>(range));
	}

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
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<unordered_shoal_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map == cast<unordered_shoal_a<>>(thing).extract_map();
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
	inline forward_const_iterator_a<> cbegin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::create(me_(), *this, _map.cbegin());
	}

	inline forward_const_iterator_a<> cend_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::create(me_(), *this, _map.cend());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline forward_iterator_a<> begin_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return iterator_t<std_unordered_map_any_any::iterator>::create(*this, _map.begin());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline forward_iterator_a<> end_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return iterator_t<std_unordered_map_any_any::iterator>::create(*this, _map.end());
	}

	// collection
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
			return misunderstanding_t<>::create("strange::unordered_shoal::at key not found");
		}
		return it->second;
	}

	inline any_a<> at_string(std::string const& s) const
	{
		return at_(sym(s));
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

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _map.emplace(key, value).second;
	}

	inline bool insert_string(std::string const& s, any_a<> const& value)
	{
		return insert(sym(s), value);
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

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_map.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		push_back(thing);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
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

	inline unordered_shoal_a<> self_assign_(range_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto const other = cast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map = other.extract_map();
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto const other = cast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.clear();
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.clear();
			for (auto const& thing : range)
			{
				if (!check<flock_a<>>(thing))
				{
					throw dis("strange::unordered_shoal self_assign passed range containing non-flock");
				}
				flock_a<> pair = cast<flock_a<>>(thing);
				if (pair.size() != 2)
				{
					throw dis("strange::unordered_shoal self_assign passed range containing flock of wrong size");
				}
				_map.emplace(pair.at_index(0), pair.at_index(1));
			}
		}
		return me_();
	}

	inline unordered_shoal_t& operator+=(any_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto const other = cast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto const other = cast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::unordered_shoal += passed non-range");
			}
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : cast<range_a<> const>(range))
			{
				if (!check<flock_a<>>(thing))
				{
					throw dis("strange::unordered_shoal += passed range containing non-flock");
				}
				flock_a<> pair = cast<flock_a<>>(thing);
				if (pair.size() != 2)
				{
					throw dis("strange::unordered_shoal += passed range containing flock of wrong size");
				}
				_map.emplace(pair.at_index(0), pair.at_index(1));
			}
		}
		return *this;
	}

	inline unordered_shoal_t& operator-=(any_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto const other = cast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto const other = cast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::unordered_shoal -= passed non-range");
			}
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : cast<range_a<> const>(range))
			{
				_map.erase(thing);
			}
		}
		return *this;
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

	template <typename F>
	inline unordered_shoal_t(F&& init)
		: thing_t{}
		, _map{ std::forward<F>(init) }
	{}

public:
	inline unordered_shoal_t(unordered_shoal_t const& other)
		: _map{ other._map }
	{}

	inline unordered_shoal_t(unordered_shoal_t&& other)
		: _map{ std::move(other._map) }
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
	return shoal.something();
}();

} // namespace strange

#endif
