#ifndef COM_ONEISH_STRANGE_FLOCK_T_H
#define COM_ONEISH_STRANGE_FLOCK_T_H

namespace strange
{

template <typename _ABSTRACTION_ = flock_a<>>
class flock_t : public something_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_iterator_data_a<ITERATOR>>
	class iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___THING___
		// construction
		template <typename F>
		static inline random_access_iterator_data_a<ITERATOR> val__(flock_a<> const& flock, F&& it)
		{
			return random_access_iterator_data_a<ITERATOR>{ iterator_t(flock, std::forward<F>(it)) };
		}

		template <typename F>
		static inline random_access_iterator_data_a<ITERATOR> ref__(flock_a<> const& flock, F&& it)
		{
			return random_access_iterator_data_a<ITERATOR>(iterator_t(flock, std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym__("strange::flock::iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast_<random_access_iterator_data_a<ITERATOR>>(thing).extract__();
		}

		inline bool operator!=(any_a<> const& thing) const
		{
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast_<random_access_iterator_data_a<ITERATOR>>(thing).extract__();
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
			return operator*();
		}

		inline any_a<> set(any_a<> const& range) const
		{
			forward_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::flock::iterator set passed empty range");
			}
			return set_(*it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			return operator*() = thing;
		}

		inline any_a<>* operator->() const
		{
			return &operator*();
		}

		inline any_a<>& operator*() const
		{
			return const_cast<any_a<>&>(*_it);
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
		inline _ABSTRACTION_ decrement(any_a<> const& _)
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

		// random access iterator
		inline _ABSTRACTION_ self_add(any_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator+=(thing);
			}
			return me_();
		}

		inline _ABSTRACTION_ self_add_(number_a<> const& number)
		{
			_it += number.to_int_64__();
			return me_();
		}

		inline iterator_t& operator+=(any_a<> const& thing)
		{
			if (!check_<number_a<>>(thing))
			{
				throw dis__("strange::flock::iterator += passed non-number");
			}
			_it += cast_<number_a<>>(thing).to_int_64__();
			return *this;
		}

		inline random_access_iterator_a<> add(any_a<> const& range) const
		{
			random_access_iterator_a<> result = me_();
			for (auto const& thing : range)
			{
				result += thing;
			}
			return result;
		}

		inline random_access_iterator_a<> add_(number_a<> const& number) const
		{
			return operator+(number);
		}

		inline random_access_iterator_a<> operator+(number_a<> const& number) const
		{
			_ABSTRACTION_ result = me_();
			result.reference__() += number.to_int_64__();
			return result;
		}

		inline _ABSTRACTION_ self_subtract(any_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator-=(thing);
			}
			return me_();
		}

		inline _ABSTRACTION_ self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64__();
			return me_();
		}

		inline iterator_t& operator-=(any_a<> const& thing)
		{
			if (!check_<number_a<>>(thing))
			{
				throw dis__("strange::flock::iterator -= passed non-number");
			}
			_it -= cast_<number_a<>>(thing).to_int_64__();
			return *this;
		}

		inline random_access_iterator_a<> subtract(any_a<> const& range) const
		{
			random_access_iterator_a<> result = me_();
			for (auto const& thing : range)
			{
				result -= thing;
			}
			return result;
		}

		inline random_access_iterator_a<> subtract_(number_a<> const& number) const
		{
			return operator-(number);
		}

		inline random_access_iterator_a<> operator-(number_a<> const& number) const
		{
			_ABSTRACTION_ result = me_();
			result.reference__() -= number.to_int_64__();
			return result;
		}

		inline any_a<> less_than(any_a<> const& range) const
		{
			forward_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::flock::iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::flock::iterator::less_than passed incompatible thing");
			}
			return _boole_(_it < cast_<random_access_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> less_than_(random_access_iterator_a<> const& it) const
		{
			return _boole_(operator<(it));
		}

		inline bool operator<(random_access_iterator_a<> const& it) const
		{
			if (!check_<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::flock::iterator < passed incompatible thing");
			}
			return _it < cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> greater_than(any_a<> const& range) const
		{
			forward_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::flock::iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::flock::iterator::greater_than passed incompatible thing");
			}
			return _boole_(_it > cast_<random_access_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> greater_than_(random_access_iterator_a<> const& it) const
		{
			return _boole_(operator>(it));
		}

		inline bool operator>(random_access_iterator_a<> const& it) const
		{
			if (!check_<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::flock::iterator > passed incompatible thing");
			}
			return _it > cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> less_or_equal(any_a<> const& range) const
		{
			forward_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::flock::iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::flock::iterator::less_or_equal passed incompatible thing");
			}
			return _boole_(_it <= cast_<random_access_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> less_or_equal_(random_access_iterator_a<> const& it) const
		{
			return _boole_(operator<=(it));
		}

		inline bool operator<=(random_access_iterator_a<> const& it) const
		{
			if (!check_<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::flock::iterator <= passed incompatible thing");
			}
			return _it <= cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> greater_or_equal(any_a<> const& range) const
		{
			forward_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::flock::iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::flock::iterator::greater_or_equal passed incompatible thing");
			}
			return _boole_(_it >= cast_<random_access_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const
		{
			return _boole_(operator>=(it));
		}

		inline bool operator>=(random_access_iterator_a<> const& it) const
		{
			if (!check_<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::flock::iterator >= passed incompatible thing");
			}
			return _it >= cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
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

	private:
		ITERATOR _it;
		flock_a<> _flock;

		template <typename F>
		inline iterator_t(flock_a<> const& flock, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _flock(flock, true)
		{}
	};

public: ___COLLECTION___
	using std_vector_any = std::vector<any_a<>>;

	// construction
	static inline flock_a<> val(any_a<> const& range)
	{
		return cast_<flock_a<>>(val_() += range);
	}

	static inline flock_a<> val_()
	{
		return val__(std_vector_any{});
	}

	template <typename F>
	static inline flock_a<> val__(F&& init)
	{
		return flock_a<>{ flock_t{ std::forward<F>(init) } };
	}

	static inline flock_a<> ref(any_a<> const& range)
	{
		return cast_<flock_a<>>(ref_() += range, true);
	}

	static inline flock_a<> ref_()
	{
		return ref__(std_vector_any{});
	}

	template <typename F>
	static inline flock_a<> ref__(F&& init)
	{
		return flock_a<>(flock_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::flock");
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
		if (!check_<flock_a<>>(thing))
		{
			return false;
		}
		return _vector == cast_<flock_a<>>(thing).extract__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<flock_a<>>(thing))
		{
			return true;
		}
		return _vector != cast_<flock_a<>>(thing).extract__();
	}

	inline std::size_t hash__() const
	{
		std::size_t seed = std::hash<std::size_t>{}(_vector.size());
		for (auto const& item : _vector)
		{
			seed ^= item.hash__() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline random_access_iterator_a<> cbegin() const
	{
		return iterator_t<std_vector_any::const_iterator>::val__(me_(), _vector.cbegin());
	}

	inline random_access_iterator_a<> begin() const
	{
		return iterator_t<std_vector_any::const_iterator>::val__(me_(), _vector.cbegin());
	}

	inline random_access_iterator_a<> begin()
	{
		return iterator_t<std_vector_any::iterator>::val__(me_(), _vector.begin());
	}

	inline random_access_iterator_a<> cend() const
	{
		return iterator_t<std_vector_any::const_iterator>::val__(me_(), _vector.cend());
	}

	inline random_access_iterator_a<> end() const
	{
		return iterator_t<std_vector_any::const_iterator>::val__(me_(), _vector.cend());
	}

	inline random_access_iterator_a<> end()
	{
		return iterator_t<std_vector_any::iterator>::val__(me_(), _vector.end());
	}

	// collection
	inline bool has__(any_a<> const& key) const
	{
		return check_<number_a<>>(key) && has__(cast_<number_a<>>(key).to_int_64__());
	}

	inline bool has__(int64_t index) const
	{
		return index >= 0 && index < size__();
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		if (check_<number_a<>>(key))
		{
			return at__(cast_<number_a<>>(key).to_int_64__());
		}
		return nothing_t<>::val_();
	}

	inline any_a<> at__(int64_t index) const
	{
		if (index >= 0 && index < size__())
		{
			return _vector[std::size_t(index)];
		}
		return nothing_t<>::val_();
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value)
	{
		if (check_<number_a<>>(key))
		{
			update__(cast_<number_a<>>(key).to_int_64__(), value);
		}
		return value;
	}

	inline void update__(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			int64_t const size = size__();
			if (index == size)
			{
				push_back__(value);
			}
			else
			{
				if (index > size)
				{
					_vector.resize(std::size_t(index) + 1, nothing_t<>::val_());
				}
				_vector[std::size_t(index)] = value;
			}
		}
	}

	inline bool insert__(any_a<> const& key, any_a<> const& value)
	{
		return check_<number_a<>>(key) && insert__(cast_<number_a<>>(key).to_int_64__(), value);
	}

	inline bool insert__(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			int64_t const size = size__();
			if (index == size)
			{
				push_back__(value);
			}
			else
			{
				if (index > size)
				{
					_vector.resize(std::size_t(index) + 1, nothing_t<>::val_());
					_vector[std::size_t(index)] = value;
				}
				else
				{
					_vector.insert(_vector.cbegin() + index, value);
				}
			}
			return true;
		}
		return false;
	}

	inline bool erase__(any_a<> const& key)
	{
		return check_<number_a<>>(key) && erase__(cast_<number_a<>>(key).to_int_64__());
	}

	inline bool erase__(int64_t index)
	{
		if (index >= 0 && index < size__())
		{
			_vector.erase(_vector.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear__()
	{
		_vector.clear();
	}

	inline int64_t size__() const
	{
		return int64_t(_vector.size());
	}

	inline bool empty__() const
	{
		return _vector.empty();
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
		_vector.push_back(thing);
	}

	inline any_a<> pop_back_()
	{
		if (_vector.empty())
		{
			return nothing_t<>::val_();
		}
		any_a<> result = _vector.back();
		_vector.pop_back();
		return result;
	}

	inline flock_t& operator+=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline flock_t& operator-=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			erase(thing);
		}
		return *this;
	}

	// data
	inline std_vector_any const& extract__() const
	{
		return _vector;
	}

	inline void mutate__(std_vector_any const& data)
	{
		_vector = data;
	}

	inline std_vector_any& reference__()
	{
		return _vector;
	}

protected:
	std_vector_any _vector;

	template <typename F>
	inline flock_t(F&& init)
		: something_t{}
		, _vector{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
