#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_T_H

namespace strange
{

template <typename _ABSTRACTION_ = unordered_herd_a<>>
class unordered_herd_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = forward_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline forward_const_iterator_data_a<ITERATOR> val(unordered_herd_a<> const& unordered_herd, F&& it)
		{
			return forward_const_iterator_data_a<ITERATOR>{ const_iterator_t(unordered_herd, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::unordered_herd::const_iterator");
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
		unordered_herd_a<> _unordered_herd;

		template <typename F>
		inline const_iterator_t(unordered_herd_a<> const& unordered_herd, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _unordered_herd(unordered_herd, true)
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_unordered_set_any = std::unordered_set<any_a<>, any_a<>::hash_f>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return val_() += range;
	}

	static inline unordered_herd_a<> val_()
	{
		return val(std_unordered_set_any{});
	}

	template <typename F>
	static inline unordered_herd_a<> val(F&& init)
	{
		return unordered_herd_a<>{ unordered_herd_t{ std::forward<F>(init) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<unordered_herd_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<unordered_herd_t<>>::share(shoal);
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<flock_a<>>(range))
		{
			throw dis("strange::unordered_herd::visit passed non-flock");
		}
		return visit_(cast<flock_a<>>(range));
	}

	inline any_a<> visit_(flock_a<> const& flock) const
	{
		auto result = thing_t<>::visit_(flock);
		if (result)
		{
			auto ref = flock_a<>(flock, true);
			auto last = ref.size() - 1;
			for (auto const& visited : _set)
			{
				ref.update(last, visited);
				visited.visit_(ref);
			}
		}
		return result;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<unordered_herd_a<>>(thing))
		{
			return false;
		}
		return _set == cast<unordered_herd_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		std::set<any_a<>> const ordered(_set.cbegin(), _set.cend());
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (auto const& item : ordered)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline forward_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<std_unordered_set_any::const_iterator>::val(me_(), _set.cbegin());
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return const_iterator_t<std_unordered_set_any::const_iterator>::val(me_(), _set.cend());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		std_unordered_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		std_unordered_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return misunderstanding_t<>::val("strange::unordered_herd::at key not found");
		}
		return *it;
	}

	inline bool at(std::string const& s) const
	{
		std_unordered_set_any::const_iterator const it = _set.find(sym(s));
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
		push_back(thing);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline void push_back(any_a<> const& thing)
	{
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		std_unordered_set_any::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			return no();
		}
		any_a<> result = *it;
		_set.erase(it);
		return result;
	}

	inline unordered_herd_t& operator+=(any_a<> const& range)
	{
		if (check<unordered_herd_a<>>(range))
		{
			auto other = cast<unordered_herd_a<>>(range).extract();
			_set.insert(other.cbegin(), other.cend());
		}
		else if (check<ordered_herd_a<>>(range))
		{
			auto other = cast<ordered_herd_a<>>(range).extract();
			_set.insert(other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::unordered_herd += passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				_set.insert(thing);
			}
		}
		return *this;
	}

	inline unordered_herd_t& operator-=(any_a<> const& range)
	{
		if (!check<range_a<>>(range))
		{
			throw dis("strange::unordered_herd -= passed non-range");
		}
		for (auto const& thing : cast<range_a<>>(range))
		{
			_set.erase(thing);
		}
		return *this;
	}

	// data
	inline std_unordered_set_any const& extract() const
	{
		return _set;
	}

	inline void mutate(std_unordered_set_any const& data)
	{
		_set = data;
	}

	inline std_unordered_set_any& reference()
	{
		return _set;
	}

protected:
	std_unordered_set_any _set;

	template <typename F>
	inline unordered_herd_t(F&& init)
		: thing_t{}
		, _set{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
