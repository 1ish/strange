#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_T_H

namespace strange
{

template <bool CONCURRENT = false, typename _ABSTRACTION_ = unordered_shoal_a<>>
class unordered_shoal_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = forward_iterator_data_a<ITERATOR>>
	class iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline forward_iterator_data_a<ITERATOR> val(unordered_shoal_a<> const& unordered_shoal, F&& it)
		{
			return forward_iterator_data_a<ITERATOR>{ iterator_t(unordered_shoal, std::forward<F>(it)) };
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
			if (!check<forward_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast<forward_iterator_data_a<ITERATOR>>(thing).extract();
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			_pair.update(0, _it->first);
			_pair.update(1, _it->second);
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
			return _it->second = cast<flock_a<>>(thing).at(1);
		}

		inline any_a<>* operator->() const
		{
			throw dis("strange::unordered_shoal::iterator cannot be dereferenced");
		}

		inline any_a<>& operator*() const
		{
			throw dis("strange::unordered_shoal::iterator cannot be dereferenced");
		}

		inline _ABSTRACTION_ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline _ABSTRACTION_ increment_()
		{
			operator++();
			return me_();
		}

		inline iterator_t& operator++()
		{
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
		inline ITERATOR const& extract() const
		{
			return _it;
		}

		inline void mutate(ITERATOR const& it)
		{
			_it = it;
		}

		inline ITERATOR& reference()
		{
			return _it;
		}

	protected:
		ITERATOR _it;
		unordered_shoal_a<> _unordered_shoal;
		mutable flock_a<> _pair;

		template <typename F>
		inline iterator_t(unordered_shoal_a<> const& unordered_shoal, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _unordered_shoal(unordered_shoal, true)
			, _pair{ flock_t<>::val_() }
		{}
	};

	template <typename ITERATOR, typename _ABSTRACTION_ = forward_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
			static inline forward_const_iterator_data_a<ITERATOR> val(unordered_shoal_a<> const& unordered_shoal, F&& it)
			{
				return forward_const_iterator_data_a<ITERATOR>{ const_iterator_t(unordered_shoal, std::forward<F>(it)) };
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
				if (!check<forward_const_iterator_data_a<ITERATOR>>(thing))
				{
					return false;
				}
				return _it == cast<forward_const_iterator_data_a<ITERATOR>>(thing).extract();
			}

			inline std::size_t hash() const
			{
				return std::hash<void const*>{}(&*_it);
			}

			// forward iterator
			inline any_a<> get__(range_a<> const&) const
			{
				return get_();
			}

			inline any_a<> get_() const
			{
				_pair.update(0, _it->first);
				_pair.update(1, _it->second);
				return _pair;
			}

			inline any_a<> const* operator->() const
			{
				return &operator*();
			}

			inline any_a<> const& operator*() const
			{
				_pair.update(0, _it->first);
				_pair.update(1, _it->second);
				return _pair;
			}

			inline _ABSTRACTION_ increment__(range_a<> const&)
			{
				return increment_();
			}

			inline _ABSTRACTION_ increment_()
			{
				operator++();
				return me_();
			}

			inline const_iterator_t& operator++()
			{
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
			inline ITERATOR const& extract() const
			{
				return _it;
			}

			inline void mutate(ITERATOR const& it)
			{
				_it = it;
			}

			inline ITERATOR& reference()
			{
				return _it;
			}

	protected:
		ITERATOR _it;
		unordered_shoal_a<> _unordered_shoal;
		mutable flock_a<> _pair;

		template <typename F>
		inline const_iterator_t(unordered_shoal_a<> const& unordered_shoal, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _unordered_shoal(unordered_shoal, true)
			, _pair{ flock_t<>::val_() }
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_unordered_map_any_any = std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return val_() += range;
	}

	static inline unordered_shoal_a<> val_()
	{
		return val(std_unordered_map_any_any{});
	}

	template <typename... Args>
	static inline unordered_shoal_a<> val_(Args&&... args)
	{
		return val(variadic_pair_u<>::unordered_map(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline unordered_shoal_a<> val(F&& init)
	{
		return unordered_shoal_a<>{ unordered_shoal_t{ std::forward<F>(init) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<unordered_shoal_t<CONCURRENT>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<unordered_shoal_t<CONCURRENT>>::share(shoal);
	}

	inline any_a<> feeder__(range_a<> const& range) const // return range of parameter values
	{
		auto values = flock_t<>::val_();
		for (auto const& param : range)
		{
			auto p = at_(param);
			values.push_back(p ? p : no());
		}
		return values;
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<flock_a<>>(range))
		{
			throw dis("strange::unordered_shoal::visit passed non-flock");
		}
		return visit_(cast<flock_a<>>(range, true));
	}

	inline any_a<> visit_(flock_a<>& flock) const
	{
		auto result = thing_t<>::visit_(flock);
		if (result)
		{
			auto last = flock.size() - 1;
			typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
			for (auto const& visited : _map)
			{
				flock.update(last, visited.first);
				visited.first.visit_(flock);
				flock.update(last, visited.second);
				visited.second.visit_(flock);
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
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		return _map == cast<unordered_shoal_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		std::map<any_a<>, std::size_t> ordered;
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
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
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::val(me_(), _map.cbegin());
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::val(me_(), _map.cend());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline forward_iterator_a<> begin_()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val(me_(), _map.begin());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline forward_iterator_a<> end_()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val(me_(), _map.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		std_unordered_map_any_any::const_iterator const it = _map.find(key);
		return it != _map.cend();
	}

	inline bool has(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		std_unordered_map_any_any::const_iterator const it = _map.find(key);
		if (it == _map.cend())
		{
			return misunderstanding_t<>::val("strange::unordered_shoal::at key not found");
		}
		return it->second;
	}

	inline any_a<> at(std::string const& s) const
	{
		return at_(sym(s));
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_map[key] = value;
	}

	inline void update(std::string const& s, any_a<> const& value)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_map[sym(s)] = value;
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _map.emplace(key, value).second;
	}

	inline bool insert(std::string const& s, any_a<> const& value)
	{
		return insert(sym(s), value);
	}

	inline bool erase(any_a<> const& key)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _map.erase(key);
	}

	inline bool erase(std::string const& s)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _map.erase(sym(s));
	}

	inline void clear()
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_map.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		return int64_t(_map.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
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
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_map[thing] = thing;
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		std_unordered_map_any_any::const_iterator const it = _map.cbegin();
		if (it == _map.cend())
		{
			return no();
		}
		any_a<> result = it->second;
		_map.erase(it);
		return result;
	}

	inline unordered_shoal_t& operator+=(any_a<> const& range)
	{
		if (check<unordered_shoal_a<>>(range))
		{
			auto other = cast<unordered_shoal_a<>>(range).extract();
			typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
			_map.insert(other.cbegin(), other.cend());
		}
		else if (check<ordered_shoal_a<>>(range))
		{
			auto other = cast<ordered_shoal_a<>>(range).extract();
			typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
			_map.insert(other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::unordered_shoal += passed non-range");
			}
			typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
			for (auto const& thing : cast<range_a<>>(range))
			{
				_map.emplace(thing, thing);
			}
		}
		return *this;
	}

	inline unordered_shoal_t& operator-=(any_a<> const& range)
	{
		if (!check<range_a<>>(range))
		{
			throw dis("strange::unordered_shoal -= passed non-range");
		}
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		for (auto const& thing : cast<range_a<>>(range))
		{
			_map.erase(thing);
		}
		return *this;
	}

	// data
	inline std_unordered_map_any_any const& extract() const
	{
		return _map;
	}

	inline void mutate(std_unordered_map_any_any const& data)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_map = data;
	}

	inline std_unordered_map_any_any& reference()
	{
		return _map;
	}

protected:
	mutable typename concurrent_u<CONCURRENT>::mutex _mutex;
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
};

} // namespace strange

#endif
