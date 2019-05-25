#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_T_H

namespace strange
{

template <typename _ABSTRACTION_ = ordered_herd_a<>>
class ordered_herd_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline bidirectional_const_iterator_data_a<ITERATOR> val(ordered_herd_a<> const& ordered_herd, F&& it)
		{
			return bidirectional_const_iterator_data_a<ITERATOR>{ const_iterator_t(ordered_herd, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::ordered_herd::const_iterator");
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
			return *_it;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			return *_it;
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
		ordered_herd_a<> _ordered_herd;

		template <typename F>
		inline const_iterator_t(ordered_herd_a<> const& ordered_herd, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _ordered_herd(ordered_herd, true)
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_set_any = std::set<any_a<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return val_() += range;
	}

	static inline ordered_herd_a<> val_()
	{
		return val(std_set_any{});
	}

	template <typename F>
	static inline ordered_herd_a<> val(F&& init)
	{
		return ordered_herd_a<>{ ordered_herd_t{ std::forward<F>(init) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::ordered_herd");
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
		if (!check<ordered_herd_a<>>(thing))
		{
			return false;
		}
		return _set == cast<ordered_herd_a<>>(thing).extract();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check<ordered_herd_a<>>(thing))
		{
			return true;
		}
		return _set != cast<ordered_herd_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (auto const& item : _set)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline bidirectional_const_iterator_a<> cbegin() const
	{
		return const_iterator_t<std_set_any::const_iterator>::val(me_(), _set.cbegin());
	}

	inline bidirectional_const_iterator_a<> begin() const
	{
		return const_iterator_t<std_set_any::const_iterator>::val(me_(), _set.cbegin());
	}

	inline bidirectional_const_iterator_a<> cend() const
	{
		return const_iterator_t<std_set_any::const_iterator>::val(me_(), _set.cend());
	}

	inline bidirectional_const_iterator_a<> end() const
	{
		return const_iterator_t<std_set_any::const_iterator>::val(me_(), _set.cend());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		std_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		std_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return misunderstanding_t<>::val("strange::ordered_herd::at key not found");
		}
		return *it;
	}

	inline bool at(std::string const& s) const
	{
		std_set_any::const_iterator const it = _set.find(sym(s));
		return it != _set.cend();
	}

	inline void update(any_a<> const& key, any_a<> const&)
	{
		_set.insert(key);
	}

	inline bool insert(any_a<> const& key, any_a<> const&)
	{
		return _set.insert(key).second;
	}

	inline bool insert(any_a<> const& key)
	{
		return _set.insert(key).second;
	}

	inline bool insert(std::string const& s)
	{
		return _set.insert(sym(s)).second;
	}

	inline bool erase(any_a<> const& key)
	{
		return _set.erase(key);
	}

	inline bool erase(std::string const& s)
	{
		return _set.erase(sym(s));
	}

	inline void clear()
	{
		_set.clear();
	}

	inline int64_t size() const
	{
		return int64_t(_set.size());
	}

	inline bool empty() const
	{
		return _set.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		_set.insert(thing);
	}

	inline any_a<> pop_front_()
	{
		std_set_any::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = *it;
		_set.erase(it);
		return result;
	}

	inline void push_back(any_a<> const& thing)
	{
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		std_set_any::const_iterator it = _set.cend();
		if (it == _set.cbegin())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = *--it;
		_set.erase(it);
		return result;
	}

	inline ordered_herd_t& operator+=(any_a<> const& range)
	{
		if (check<ordered_herd_a<>>(range))
		{
			auto other = cast<ordered_herd_a<>>(range).extract();
			_set.insert(other.cbegin(), other.cend());
		}
		else if (check<unordered_herd_a<>>(range))
		{
			auto other = cast<unordered_herd_a<>>(range).extract();
			_set.insert(other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::ordered_herd += passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				_set.insert(thing);
			}
		}
		return *this;
	}

	inline ordered_herd_t& operator-=(any_a<> const& range)
	{
		if (!check<range_a<>>(range))
		{
			throw dis("strange::ordered_herd -= passed non-range");
		}
		for (auto const& thing : cast<range_a<>>(range))
		{
			_set.erase(thing);
		}
		return *this;
	}

	// data
	inline std_set_any const& extract() const
	{
		return _set;
	}

	inline void mutate(std_set_any const& data)
	{
		_set = data;
	}

	inline std_set_any& reference()
	{
		return _set;
	}

protected:
	std_set_any _set;

	template <typename F>
	inline ordered_herd_t(F&& init)
		: thing_t{}
		, _set{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
