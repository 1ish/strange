#ifndef COM_ONEISH_STRANGE_HERD_T_H
#define COM_ONEISH_STRANGE_HERD_T_H

namespace strange
{

template <typename _ABSTRACTION_ = herd_a<>>
class herd_t : public something_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline bidirectional_const_iterator_data_a<ITERATOR> val__(herd_a<> const& herd, F&& it)
		{
			return bidirectional_const_iterator_data_a<ITERATOR>{ const_iterator_t(herd, std::forward<F>(it)) };
		}

		template <typename F>
		static inline bidirectional_const_iterator_data_a<ITERATOR> ref__(herd_a<> const& herd, F&& it)
		{
			return bidirectional_const_iterator_data_a<ITERATOR>(const_iterator_t(herd, std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym__("strange::herd::const_iterator");
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
		inline any_a<> get(any_a<> const&) const
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

		inline _ABSTRACTION_ increment(any_a<> const&)
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
		inline _ABSTRACTION_ decrement(any_a<> const& _)
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
		herd_a<> _herd;

		template <typename F>
		inline const_iterator_t(herd_a<> const& herd, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _herd(herd, true)
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_unordered_set_any = std::unordered_set<any_a<>, any_a<>::hash_f>;

	// construction
	static inline herd_a<> val(any_a<> const& range)
	{
		return cast_<herd_a<>>(val_() += range);
	}

	static inline herd_a<> val_()
	{
		return val__(std_unordered_set_any{});
	}

	template <typename F>
	static inline herd_a<> val__(F&& init)
	{
		return herd_a<>{ herd_t{ std::forward<F>(init) } };
	}

	static inline herd_a<> ref(any_a<> const& range)
	{
		return cast_<herd_a<>>(ref_() += range, true);
	}

	static inline herd_a<> ref_()
	{
		return ref__(std_unordered_set_any{});
	}

	template <typename F>
	static inline herd_a<> ref__(F&& init)
	{
		return herd_a<>(herd_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::herd");
		return TYPE;
	}

	inline any_a<> feeder(any_a<> const& range) const // return range of parameter values
	{
		return nothing_t<>::val_(); //TODO
	}

	// visitor pattern
	static inline any_a<> visit(any_a<> const& range)
	{
		return nothing_t<>::val_(); //TODO
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check_<herd_a<>>(thing))
		{
			return false;
		}
		return _set == cast_<herd_a<>>(thing).extract__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<herd_a<>>(thing))
		{
			return true;
		}
		return _set != cast_<herd_a<>>(thing).extract__();
	}

	inline std::size_t hash__() const
	{
		std::set<any_a<>> const ordered(_set.cbegin(), _set.cend());
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (auto const& item : ordered)
		{
			seed ^= item.hash__() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline bidirectional_const_iterator_a<> cbegin() const
	{
		return const_iterator_t<std_unordered_set_any::const_iterator>::val__(me_(), _set.cbegin());
	}

	inline bidirectional_const_iterator_a<> begin() const
	{
		return const_iterator_t<std_unordered_set_any::const_iterator>::val__(me_(), _set.cbegin());
	}

	inline bidirectional_const_iterator_a<> cend() const
	{
		return const_iterator_t<std_unordered_set_any::const_iterator>::val__(me_(), _set.cend());
	}

	inline bidirectional_const_iterator_a<> end() const
	{
		return const_iterator_t<std_unordered_set_any::const_iterator>::val__(me_(), _set.cend());
	}

	// collection
	inline bool has__(any_a<> const& key) const
	{
		std_unordered_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has__(std::string const& s) const
	{
		return has__(sym__(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		std_unordered_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return nothing_t<>::val_();
		}
		return *it;
	}

	inline bool at__(std::string const& s) const
	{
		std_unordered_set_any::const_iterator const it = _set.find(sym__(s));
		return it != _set.cend();
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value)
	{
		_set.insert(key);
		return value;
	}

	inline bool insert__(any_a<> const& key, any_a<> const&)
	{
		return _set.insert(key).second;
	}

	inline bool insert__(std::string const& s)
	{
		return _set.insert(sym__(s)).second;
	}

	inline bool erase__(any_a<> const& key)
	{
		return _set.erase(key);
	}

	inline bool erase__(std::string const& s)
	{
		return _set.erase(sym__(s));
	}

	inline void clear__()
	{
		_set.clear();
	}

	inline int64_t size__() const
	{
		return int64_t(_set.size());
	}

	inline bool empty__() const
	{
		return _set.empty();
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
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		std_unordered_set_any::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = *it;
		_set.erase(it);
		return result;
	}

	inline herd_t& operator+=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline herd_t& operator-=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			erase(thing);
		}
		return *this;
	}

	// data
	inline std_unordered_set_any const& extract__() const
	{
		return _set;
	}

	inline void mutate__(std_unordered_set_any const& data)
	{
		_set = data;
	}

	inline std_unordered_set_any& reference__()
	{
		return _set;
	}

protected:
	std_unordered_set_any _set;

	template <typename F>
	inline herd_t(F&& init)
		: something_t{}
		, _set{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
