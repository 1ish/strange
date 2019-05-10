#ifndef COM_ONEISH_STRANGE_SHOAL_T_H
#define COM_ONEISH_STRANGE_SHOAL_T_H

namespace strange
{

template <typename _ABSTRACTION_ = shoal_a<>>
class shoal_t : public something_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_iterator_data_a<ITERATOR>>
	class iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline bidirectional_iterator_data_a<ITERATOR> val__(shoal_a<> const& shoal, F&& it)
		{
			return bidirectional_iterator_data_a<ITERATOR>{ iterator_t(shoal, std::forward<F>(it)) };
		}

		template <typename F>
		static inline bidirectional_iterator_data_a<ITERATOR> ref__(shoal_a<> const& shoal, F&& it)
		{
			return bidirectional_iterator_data_a<ITERATOR>(iterator_t(shoal, std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym__("strange::shoal::iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check_<bidirectional_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast_<bidirectional_iterator_data_a<ITERATOR>>(thing).extract__();
		}

		inline bool operator!=(any_a<> const& thing) const
		{
			if (!check_<bidirectional_iterator_data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast_<bidirectional_iterator_data_a<ITERATOR>>(thing).extract__();
		}

		inline std::size_t hash__() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			_pair.update__(0, _it->first);
			_pair.update__(1, _it->second);
			return _pair;
		}

		inline any_a<> set(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::shoal::iterator set passed empty range");
			}
			return set_(*it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check_<flock_a<>>(thing))
			{
				throw dis__("strange::shoal::iterator set passed non-flock");
			}
			return _it->second = cast_<flock_a<>>(thing).at__(1);
		}

		inline any_a<>* operator->() const
		{
			throw dis__("strange::shoal::iterator cannot be dereferenced");
		}

		inline any_a<>& operator*() const
		{
			throw dis__("strange::shoal::iterator cannot be dereferenced");
		}

		inline _ABSTRACTION_ increment(range_a<> const&)
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

		// bidirectional iterator
		inline _ABSTRACTION_ decrement(range_a<> const& _)
		{
			return decrement_();
		}

		inline _ABSTRACTION_ decrement_()
		{
			operator--();
			return me_();
		}

		inline iterator_t& operator--()
		{
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
		inline ITERATOR const& extract__() const
		{
			return _it;
		}

		inline void mutate__(ITERATOR const& it)
		{
			_it = it;
		}

		inline ITERATOR& reference__()
		{
			return _it;
		}

	protected:
		ITERATOR _it;
		shoal_a<> _shoal;
		mutable flock_a<> _pair;

		template <typename F>
		inline iterator_t(shoal_a<> const& shoal, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _shoal(shoal, true)
			, _pair{ flock_t<>::val_() }
		{}
	};

	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
			static inline bidirectional_const_iterator_data_a<ITERATOR> val__(shoal_a<> const& shoal, F&& it)
			{
				return bidirectional_const_iterator_data_a<ITERATOR>{ const_iterator_t(shoal, std::forward<F>(it)) };
			}

			template <typename F>
			static inline bidirectional_const_iterator_data_a<ITERATOR> ref__(shoal_a<> const& shoal, F&& it)
			{
				return bidirectional_const_iterator_data_a<ITERATOR>(const_iterator_t(shoal, std::forward<F>(it)), true);
			}

			// reflection
			static inline symbol_a<> type_()
			{
				static symbol_a<> TYPE = sym__("strange::shoal::const_iterator");
				return TYPE;
			}

			// comparison
			inline bool operator==(any_a<> const& thing) const
			{
				if (!check_<bidirectional_const_iterator_data_a<ITERATOR>>(thing))
				{
					return false;
				}
				return _it == cast_<bidirectional_const_iterator_data_a<ITERATOR>>(thing).extract__();
			}

			inline bool operator!=(any_a<> const& thing) const
			{
				if (!check_<bidirectional_const_iterator_data_a<ITERATOR>>(thing))
				{
					return true;
				}
				return _it != cast_<bidirectional_const_iterator_data_a<ITERATOR>>(thing).extract__();
			}

			inline std::size_t hash__() const
			{
				return std::hash<void const*>{}(&*_it);
			}

			// forward iterator
			inline any_a<> get(range_a<> const&) const
			{
				return get_();
			}

			inline any_a<> get_() const
			{
				_pair.update__(0, _it->first);
				_pair.update__(1, _it->second);
				return _pair;
			}

			inline any_a<> const* operator->() const
			{
				return &operator*();
			}

			inline any_a<> const& operator*() const
			{
				_pair.update__(0, _it->first);
				_pair.update__(1, _it->second);
				return _pair;
			}

			inline _ABSTRACTION_ increment(range_a<> const&)
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

			// bidirectional iterator
			inline _ABSTRACTION_ decrement(range_a<> const& _)
			{
				return decrement_();
			}

			inline _ABSTRACTION_ decrement_()
			{
				operator--();
				return me_();
			}

			inline const_iterator_t& operator--()
			{
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
			inline ITERATOR const& extract__() const
			{
				return _it;
			}

			inline void mutate__(ITERATOR const& it)
			{
				_it = it;
			}

			inline ITERATOR& reference__()
			{
				return _it;
			}

	protected:
		ITERATOR _it;
		shoal_a<> _shoal;
		mutable flock_a<> _pair;

		template <typename F>
		inline const_iterator_t(shoal_a<> const& shoal, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _shoal(shoal, true)
			, _pair{ flock_t<>::val_() }
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_unordered_map_any_any = std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>;

	// construction
	static inline shoal_a<> val(range_a<> const& range)
	{
		return cast_<shoal_a<>>(val_() += range);
	}

	static inline shoal_a<> val_()
	{
		return val__(std_unordered_map_any_any{});
	}

	template <typename F>
	static inline shoal_a<> val__(F&& init)
	{
		return shoal_a<>{ shoal_t{ std::forward<F>(init) } };
	}

	static inline shoal_a<> ref(range_a<> const& range)
	{
		return cast_<shoal_a<>>(ref_() += range, true);
	}

	static inline shoal_a<> ref_()
	{
		return ref__(std_unordered_map_any_any{});
	}

	template <typename F>
	static inline shoal_a<> ref__(F&& init)
	{
		return shoal_a<>(shoal_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::shoal");
		return TYPE;
	}

	inline any_a<> feeder(range_a<> const& range) const // return range of parameter values
	{
		return nothing_t<>::val_(); //TODO
	}

	// visitor pattern
	static inline any_a<> visit(range_a<> const& range)
	{
		return nothing_t<>::val_(); //TODO
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check_<shoal_a<>>(thing))
		{
			return false;
		}
		return _map == cast_<shoal_a<>>(thing).extract__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<shoal_a<>>(thing))
		{
			return true;
		}
		return _map != cast_<shoal_a<>>(thing).extract__();
	}

	inline std::size_t hash__() const
	{
		std::map<any_a<>, std::size_t> ordered;
		for (auto const& pair : _map)
		{
			std::size_t seed = pair.first.hash__();
			seed ^= pair.second.hash__() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
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
	inline bidirectional_const_iterator_a<> cbegin() const
	{
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::val__(me_(), _map.cbegin());
	}

	inline bidirectional_const_iterator_a<> begin() const
	{
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::val__(me_(), _map.cbegin());
	}

	inline any_a<> beset(range_a<> const&)
	{
		return beset_();
	}

	inline bidirectional_iterator_a<> beset_()
	{
		return begin();
	}

	inline bidirectional_iterator_a<> begin()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val__(me_(), _map.begin());
	}

	inline bidirectional_const_iterator_a<> cend() const
	{
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::val__(me_(), _map.cend());
	}

	inline bidirectional_const_iterator_a<> end() const
	{
		return const_iterator_t<std_unordered_map_any_any::const_iterator>::val__(me_(), _map.cend());
	}

	inline any_a<> enset(range_a<> const&)
	{
		return enset_();
	}

	inline bidirectional_iterator_a<> enset_()
	{
		return end();
	}

	inline bidirectional_iterator_a<> end()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val__(me_(), _map.end());
	}

	// collection
	inline bool has__(any_a<> const& key) const
	{
		std_unordered_map_any_any::const_iterator const it = _map.find(key);
		return it != _map.cend();
	}

	inline bool has__(std::string const& s) const
	{
		return has__(sym__(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		std_unordered_map_any_any::const_iterator const it = _map.find(key);
		if (it == _map.cend())
		{
			return nothing_t<>::val_();
		}
		return it->second;
	}

	inline any_a<> at__(std::string const& s) const
	{
		return at_(sym__(s));
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value)
	{
		return _map[key] = value;
	}

	inline void update__(std::string const& s, any_a<> const& value)
	{
		_map[sym__(s)] = value;
	}

	inline bool insert__(any_a<> const& key, any_a<> const& value)
	{
		return _map.emplace(key, value).second;
	}

	inline bool insert__(std::string const& s, any_a<> const& value)
	{
		return insert__(sym__(s), value);
	}

	inline bool erase__(any_a<> const& key)
	{
		return _map.erase(key);
	}

	inline bool erase__(std::string const& s)
	{
		return _map.erase(sym__(s));
	}

	inline void clear__()
	{
		_map.clear();
	}

	inline int64_t size__() const
	{
		return int64_t(_map.size());
	}

	inline bool empty__() const
	{
		return _map.empty();
	}

	inline void push_front__(any_a<> const& thing)
	{
		push_back__(thing);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline void push_back__(any_a<> const& thing)
	{
		_map[thing] = thing;
	}

	inline any_a<> pop_back_()
	{
		std_unordered_map_any_any::const_iterator const it = _map.cbegin();
		if (it == _map.cend())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = it->second;
		_map.erase(it);
		return result;
	}

	inline shoal_t& operator+=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline shoal_t& operator-=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			erase(thing);
		}
		return *this;
	}

	// data
	inline std_unordered_map_any_any const& extract__() const
	{
		return _map;
	}

	inline void mutate__(std_unordered_map_any_any const& data)
	{
		_map = data;
	}

	inline std_unordered_map_any_any& reference__()
	{
		return _map;
	}

protected:
	std_unordered_map_any_any _map;

	template <typename F>
	inline shoal_t(F&& init)
		: something_t{}
		, _map{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
