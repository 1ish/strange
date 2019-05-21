#ifndef COM_ONEISH_STRANGE_ORDERED_SHOAL_T_H
#define COM_ONEISH_STRANGE_ORDERED_SHOAL_T_H

namespace strange
{

template <typename _ABSTRACTION_ = ordered_shoal_a<>>
class ordered_shoal_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_iterator_data_a<ITERATOR>>
	class iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline bidirectional_iterator_data_a<ITERATOR> val(ordered_shoal_a<> const& ordered_shoal, F&& it)
		{
			return bidirectional_iterator_data_a<ITERATOR>{ iterator_t(ordered_shoal, std::forward<F>(it)) };
		}

		template <typename F>
		static inline bidirectional_iterator_data_a<ITERATOR> ref(ordered_shoal_a<> const& ordered_shoal, F&& it)
		{
			return bidirectional_iterator_data_a<ITERATOR>(iterator_t(ordered_shoal, std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::ordered_shoal::iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<bidirectional_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast<bidirectional_iterator_data_a<ITERATOR>>(thing).extract();
		}

		inline bool operator!=(any_a<> const& thing) const
		{
			if (!check<bidirectional_iterator_data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast<bidirectional_iterator_data_a<ITERATOR>>(thing).extract();
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
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
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
			return _it->second = cast<flock_a<>>(thing).at(1);
		}

		inline any_a<>* operator->() const
		{
			throw dis("strange::ordered_shoal::iterator cannot be dereferenced");
		}

		inline any_a<>& operator*() const
		{
			throw dis("strange::ordered_shoal::iterator cannot be dereferenced");
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

		// bidirectional iterator
		inline _ABSTRACTION_ decrement__(range_a<> const& _)
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
		ordered_shoal_a<> _ordered_shoal;
		mutable flock_a<> _pair;

		template <typename F>
		inline iterator_t(ordered_shoal_a<> const& ordered_shoal, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _ordered_shoal(ordered_shoal, true)
			, _pair{ flock_t<>::val_() }
		{}
	};

	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
			static inline bidirectional_const_iterator_data_a<ITERATOR> val(ordered_shoal_a<> const& ordered_shoal, F&& it)
			{
				return bidirectional_const_iterator_data_a<ITERATOR>{ const_iterator_t(ordered_shoal, std::forward<F>(it)) };
			}

			template <typename F>
			static inline bidirectional_const_iterator_data_a<ITERATOR> ref(ordered_shoal_a<> const& ordered_shoal, F&& it)
			{
				return bidirectional_const_iterator_data_a<ITERATOR>(const_iterator_t(ordered_shoal, std::forward<F>(it)), true);
			}

			// reflection
			static inline symbol_a<> type_()
			{
				static symbol_a<> TYPE = sym("strange::ordered_shoal::const_iterator");
				return TYPE;
			}

			// comparison
			inline bool operator==(any_a<> const& thing) const
			{
				if (!check<bidirectional_const_iterator_data_a<ITERATOR>>(thing))
				{
					return false;
				}
				return _it == cast<bidirectional_const_iterator_data_a<ITERATOR>>(thing).extract();
			}

			inline bool operator!=(any_a<> const& thing) const
			{
				if (!check<bidirectional_const_iterator_data_a<ITERATOR>>(thing))
				{
					return true;
				}
				return _it != cast<bidirectional_const_iterator_data_a<ITERATOR>>(thing).extract();
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

			// bidirectional iterator
			inline _ABSTRACTION_ decrement__(range_a<> const& _)
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
		ordered_shoal_a<> _ordered_shoal;
		mutable flock_a<> _pair;

		template <typename F>
		inline const_iterator_t(ordered_shoal_a<> const& ordered_shoal, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _ordered_shoal(ordered_shoal, true)
			, _pair{ flock_t<>::val_() }
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_map_any_any = std::map<any_a<>, any_a<>>;

	// construction
	static inline ordered_shoal_a<> val__(range_a<> const& range)
	{
		return cast<ordered_shoal_a<>>(val_() += range);
	}

	static inline ordered_shoal_a<> val_()
	{
		return val(std_map_any_any{});
	}

	template <typename F>
	static inline ordered_shoal_a<> val(F&& init)
	{
		return ordered_shoal_a<>{ ordered_shoal_t{ std::forward<F>(init) } };
	}

	static inline ordered_shoal_a<> ref__(range_a<> const& range)
	{
		return cast<ordered_shoal_a<>>(ref_() += range, true);
	}

	static inline ordered_shoal_a<> ref_()
	{
		return ref(std_map_any_any{});
	}

	template <typename F>
	static inline ordered_shoal_a<> ref(F&& init)
	{
		return ordered_shoal_a<>(ordered_shoal_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::ordered_shoal");
		return TYPE;
	}

	inline any_a<> feeder__(range_a<> const& range) const // return range of parameter values
	{
		return nothing_t<>::val_(); //TODO
	}

	// visitor pattern
	static inline any_a<> visit__(range_a<> const& range)
	{
		return nothing_t<>::val_(); //TODO
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<ordered_shoal_a<>>(thing))
		{
			return false;
		}
		return _map == cast<ordered_shoal_a<>>(thing).extract();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check<ordered_shoal_a<>>(thing))
		{
			return true;
		}
		return _map != cast<ordered_shoal_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
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
	inline bidirectional_const_iterator_a<> cbegin() const
	{
		return const_iterator_t<std_map_any_any::const_iterator>::val(me_(), _map.cbegin());
	}

	inline bidirectional_const_iterator_a<> begin() const
	{
		return const_iterator_t<std_map_any_any::const_iterator>::val(me_(), _map.cbegin());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline bidirectional_iterator_a<> begin_()
	{
		return begin();
	}

	inline bidirectional_iterator_a<> begin()
	{
		return iterator_t<std_map_any_any::iterator>::val(me_(), _map.begin());
	}

	inline bidirectional_const_iterator_a<> cend() const
	{
		return const_iterator_t<std_map_any_any::const_iterator>::val(me_(), _map.cend());
	}

	inline bidirectional_const_iterator_a<> end() const
	{
		return const_iterator_t<std_map_any_any::const_iterator>::val(me_(), _map.cend());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline bidirectional_iterator_a<> end_()
	{
		return end();
	}

	inline bidirectional_iterator_a<> end()
	{
		return iterator_t<std_map_any_any::iterator>::val(me_(), _map.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		std_map_any_any::const_iterator const it = _map.find(key);
		return it != _map.cend();
	}

	inline bool has(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		std_map_any_any::const_iterator const it = _map.find(key);
		if (it == _map.cend())
		{
			return misunderstanding_t<>::val("strange::ordered_shoal::at key not found");
		}
		return it->second;
	}

	inline any_a<> at(std::string const& s) const
	{
		return at_(sym(s));
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		_map[key] = value;
	}

	inline void update(std::string const& s, any_a<> const& value)
	{
		_map[sym(s)] = value;
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		return _map.emplace(key, value).second;
	}

	inline bool insert(std::string const& s, any_a<> const& value)
	{
		return insert(sym(s), value);
	}

	inline bool erase(any_a<> const& key)
	{
		return _map.erase(key);
	}

	inline bool erase(std::string const& s)
	{
		return _map.erase(sym(s));
	}

	inline void clear()
	{
		_map.clear();
	}

	inline int64_t size() const
	{
		return int64_t(_map.size());
	}

	inline bool empty() const
	{
		return _map.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		_map[thing] = thing;
	}

	inline any_a<> pop_front_()
	{
		std_map_any_any::const_iterator const it = _map.cbegin();
		if (it == _map.cend())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = it->second;
		_map.erase(it);
		return result;
	}

	inline void push_back(any_a<> const& thing)
	{
		_map[thing] = thing;
	}

	inline any_a<> pop_back_()
	{
		std_map_any_any::const_iterator it = _map.cend();
		if (it == _map.cbegin())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = (--it)->second;
		_map.erase(it);
		return result;
	}

	inline ordered_shoal_t& operator+=(any_a<> const& range)
	{
		if (check<ordered_shoal_a<>>(range))
		{
			auto other = cast<ordered_shoal_a<>>(range).extract();
			_map.insert(other.cbegin(), other.cend());
		}
		else if (check<unordered_shoal_a<>>(range))
		{
			auto other = cast<unordered_shoal_a<>>(range).extract();
			_map.insert(other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::ordered_shoal += passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				_map.emplace(thing, thing);
			}
		}
		return *this;
	}

	inline ordered_shoal_t& operator-=(any_a<> const& range)
	{
		if (!check<range_a<>>(range))
		{
			throw dis("strange::ordered_shoal -= passed non-range");
		}
		for (auto const& thing : cast<range_a<>>(range))
		{
			_map.erase(thing);
		}
		return *this;
	}

	// data
	inline std_map_any_any const& extract() const
	{
		return _map;
	}

	inline void mutate(std_map_any_any const& data)
	{
		_map = data;
	}

	inline std_map_any_any& reference()
	{
		return _map;
	}

protected:
	std_map_any_any _map;

	template <typename F>
	inline ordered_shoal_t(F&& init)
		: thing_t{}
		, _map{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
