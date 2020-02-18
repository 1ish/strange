#ifndef COM_ONEISH_STRANGE_ORDERED_SHOAL_T_H
#define COM_ONEISH_STRANGE_ORDERED_SHOAL_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = ordered_shoal_a<>>
class ordered_shoal_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego_it___ = bidirectional_iterator_data_a<_iterator_>>
	class iterator_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline bidirectional_iterator_data_a<_iterator_> create(ordered_shoal_t const& ordered_shoal_thing, F&& it)
		{
			return bidirectional_iterator_data_a<_iterator_>{ over{ iterator_t<_iterator_>(ordered_shoal_thing, std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::ordered_shoal::iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<bidirectional_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<bidirectional_iterator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			_pair.update_index(0, _it->first);
			_pair.update_index(1, _it->second);
			return _pair;
		}

		inline any_a<> set__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::ordered_shoal::iterator set passed empty range");
			}
			return set_(*it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check<flock_a<>>(thing))
			{
				throw dis("strange::ordered_shoal::iterator set passed non-flock");
			}
			typename concurrent_u<_concurrent_>::write_lock lock(_ordered_shoal_thing._mutex);
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

		inline ___ego_it___ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline ___ego_it___ increment_()
		{
			operator++();
			return thing_t<___ego_it___>::me_();
		}

		inline iterator_t& operator++()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			++_it;
			return *this;
		}

		inline iterator_t operator++(int)
		{
			iterator_t result = *this;
			operator++();
			return result;
		}

		// bidirectional iterator
		inline ___ego_it___ decrement__(range_a<> const& _)
		{
			return decrement_();
		}

		inline ___ego_it___ decrement_()
		{
			operator--();
			return thing_t<___ego_it___>::me_();
		}

		inline iterator_t& operator--()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			--_it;
			return *this;
		}

		inline iterator_t operator--(int)
		{
			iterator_t result = *this;
			operator--();
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
		ordered_shoal_t const& _ordered_shoal_thing;

		template <typename F>
		inline iterator_t(ordered_shoal_t const& ordered_shoal_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _pair{ flock_create() }
			, _ordered_shoal_thing{ ordered_shoal_thing }
		{}
	};

	template <typename _iterator_, typename ___ego_it___ = bidirectional_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline bidirectional_const_iterator_data_a<_iterator_> create(ordered_shoal_a<> const& ordered_shoal, ordered_shoal_t const& ordered_shoal_thing, F&& it)
		{
			return bidirectional_const_iterator_data_a<_iterator_>{ over{ const_iterator_t<_iterator_>(ordered_shoal, ordered_shoal_thing, std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::ordered_shoal::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<bidirectional_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<bidirectional_const_iterator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
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

		inline ___ego_it___ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline ___ego_it___ increment_()
		{
			operator++();
			return thing_t<___ego_it___>::me_();
		}

		inline const_iterator_t& operator++()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			++_it;
			return *this;
		}

		inline const_iterator_t operator++(int)
		{
			const_iterator_t result = *this;
			operator++();
			return result;
		}

		// bidirectional iterator
		inline ___ego_it___ decrement__(range_a<> const& _)
		{
			return decrement_();
		}

		inline ___ego_it___ decrement_()
		{
			operator--();
			return thing_t<___ego_it___>::me_();
		}

		inline const_iterator_t& operator--()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_shoal_thing._mutex);
			--_it;
			return *this;
		}

		inline const_iterator_t operator--(int)
		{
			const_iterator_t result = *this;
			operator--();
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
		ordered_shoal_a<> const _ordered_shoal;
		flock_a<> mutable _pair; // stashing iterator
		ordered_shoal_t const& _ordered_shoal_thing;

		template <typename F>
		inline const_iterator_t(ordered_shoal_a<> const& ordered_shoal, ordered_shoal_t const& ordered_shoal_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _ordered_shoal{ ordered_shoal }
			, _pair{ flock_create() }
			, _ordered_shoal_thing{ ordered_shoal_thing }
		{}
	};

public:
	using std_map_any_any = std::map<any_a<>, any_a<>>;

	// override
	using over = collection_o<ordered_shoal_t<_concurrent_>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline ordered_shoal_a<> create_()
	{
		return create(std_map_any_any{});
	}

	template <typename... Args>
	static inline ordered_shoal_a<> create_(Args&&... args)
	{
		return create(variadic_pair_u<>::map(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline ordered_shoal_a<> create(F&& init)
	{
		return ordered_shoal_a<>{ over{ ordered_shoal_t<_concurrent_>{ std::forward<F>(init) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::ordered_shoal" + std::string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&ordered_shoal_t<_concurrent_>::create__));
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<inventory_a<>>(range))
		{
			throw dis("strange::ordered_shoal::visit passed non-inventory");
		}
		auto inventory = cast_dup<inventory_a<>>(const_cast<range_a<>&>(range));
		return visit_(inventory);
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
		if (!check<ordered_shoal_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _map == cast<ordered_shoal_a<>>(thing).extract_map();
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_map.size());
		for (auto const& pair : _map)
		{
			std::size_t pseed = pair.first.hash();
			pseed ^= pair.second.hash() + 0x9e3779b9 + (pseed << 6) + (pseed >> 2);
			seed ^= pseed + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline bidirectional_const_iterator_a<> cbegin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return const_iterator_t<std_map_any_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _map.cbegin());
	}

	inline bidirectional_const_iterator_a<> cend_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return const_iterator_t<std_map_any_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _map.cend());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline bidirectional_iterator_a<> begin_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return iterator_t<std_map_any_any::iterator>::create(*this, _map.begin());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline bidirectional_iterator_a<> end_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return iterator_t<std_map_any_any::iterator>::create(*this, _map.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_map_any_any::const_iterator const it = _map.find(key);
		return it != _map.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_map_any_any::const_iterator const it = _map.find(key);
		if (it == _map.cend())
		{
			return mis("strange::ordered_shoal::at key not found");
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
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[thing] = thing;
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		std_map_any_any::const_iterator const it = _map.cbegin();
		if (it == _map.cend())
		{
			return no();
		}
		any_a<> result = it->second;
		_map.erase(it);
		return result;
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_map[thing] = thing;
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		std_map_any_any::const_iterator it = _map.cend();
		if (it == _map.cbegin())
		{
			return no();
		}
		any_a<> result = (--it)->second;
		_map.erase(it);
		return result;
	}

	inline ordered_shoal_a<> self_assign_(range_a<> const& range)
	{
		if (check<ordered_shoal_a<>>(range))
		{
			auto const other = cast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map = other.extract_map();
		}
		else if (check<unordered_shoal_a<>>(range))
		{
			auto const other = cast<unordered_shoal_a<>>(range);
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
					throw dis("strange::ordered_shoal self_assign passed range containing non-flock");
				}
				flock_a<> pair = cast<flock_a<>>(thing);
				if (pair.size() != 2)
				{
					throw dis("strange::ordered_shoal self_assign passed range containing flock of wrong size");
				}
				_map.emplace(pair.at_index(0), pair.at_index(1));
			}
		}
		return thing_t<___ego___>::me_();
	}
	
	inline ordered_shoal_t& operator+=(any_a<> const& range)
	{
		if (check<ordered_shoal_a<>>(range))
		{
			auto const other = cast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else if (check<unordered_shoal_a<>>(range))
		{
			auto const other = cast<unordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_map = other.extract_map();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_map.insert(other_map.cbegin(), other_map.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::ordered_shoal += passed non-range");
			}
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : cast<range_a<> const>(range))
			{
				if (!check<flock_a<>>(thing))
				{
					throw dis("strange::ordered_shoal += passed range containing non-flock");
				}
				flock_a<> pair = cast<flock_a<>>(thing);
				if (pair.size() != 2)
				{
					throw dis("strange::ordered_shoal += passed range containing flock of wrong size");
				}
				_map.emplace(pair.at_index(0), pair.at_index(1));
			}
		}
		return *this;
	}

	inline ordered_shoal_t& operator-=(any_a<> const& range)
	{
		if (check<ordered_shoal_a<>>(range))
		{
			auto const other = cast<ordered_shoal_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& pair : other.extract_map())
			{
				_map.erase(pair.first);
			}
		}
		else if (check<unordered_shoal_a<>>(range))
		{
			auto const other = cast<unordered_shoal_a<>>(range);
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
				throw dis("strange::ordered_shoal -= passed non-range");
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
	inline std_map_any_any const& extract_map() const
	{
		return _map;
	}

	inline std_map_any_any& mutate_map()
	{
		return _map;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_map_any_any _map;

	template <typename F>
	inline ordered_shoal_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _map{ std::forward<F>(init) }
	{}

public:
	inline ordered_shoal_t(ordered_shoal_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _map{ other._map }
	{}

	inline ordered_shoal_t(ordered_shoal_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _map{ std::move(other._map) }
	{}

private:
	static bool const ___share___;
	friend class ___ordered_shoal_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const ordered_shoal_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	ordered_shoal_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___ordered_shoal_t_share___
{
	static inline bool ___share___()
	{
		return ordered_shoal_t<>::___share___
			&& ordered_shoal_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false>
template <bool _concurrent_>
inline ordered_shoal_a<> ordered_shoal_create()
{
	return ordered_shoal_t<_concurrent_>::create_();
}

} // namespace strange

#endif
