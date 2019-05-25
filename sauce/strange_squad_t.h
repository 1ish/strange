#ifndef COM_ONEISH_STRANGE_SQUAD_T_H
#define COM_ONEISH_STRANGE_SQUAD_T_H

namespace strange
{

template <typename _ABSTRACTION_ = squad_a<>>
class squad_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_iterator_data_a<ITERATOR>>
	class iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline random_access_iterator_data_a<ITERATOR> val(squad_a<> const& squad, F&& it)
		{
			return random_access_iterator_data_a<ITERATOR>{ iterator_t(squad, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::squad::iterator");
			return TYPE;
		}

		static inline void share(shoal_a<> const& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast<random_access_iterator_data_a<ITERATOR>>(thing).extract();
		}

		inline bool operator!=(any_a<> const& thing) const
		{
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast<random_access_iterator_data_a<ITERATOR>>(thing).extract();
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

		inline any_a<> set__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::iterator set passed empty range");
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

		// random access iterator
		inline _ABSTRACTION_ self_add__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator+=(thing);
			}
			return me_();
		}

		inline _ABSTRACTION_ self_add_(number_a<> const& number)
		{
			_it += number.to_int_64();
			return me_();
		}

		inline iterator_t& operator+=(any_a<> const& thing)
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::squad::iterator += passed non-number");
			}
			_it += cast<number_a<>>(thing).to_int_64();
			return *this;
		}

		inline random_access_iterator_a<> add__(range_a<> const& range) const
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
			result.reference() += number.to_int_64();
			return result;
		}

		inline _ABSTRACTION_ self_subtract__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator-=(thing);
			}
			return me_();
		}

		inline _ABSTRACTION_ self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64();
			return me_();
		}

		inline iterator_t& operator-=(any_a<> const& thing)
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::squad::iterator -= passed non-number");
			}
			_it -= cast<number_a<>>(thing).to_int_64();
			return *this;
		}

		inline random_access_iterator_a<> subtract__(range_a<> const& range) const
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
			result.reference() -= number.to_int_64();
			return result;
		}

		inline any_a<> less_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::iterator::less_than passed incompatible thing");
			}
			return boole(_it < cast<random_access_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> less_than_(random_access_iterator_a<> const& it) const
		{
			return boole(operator<(it));
		}

		inline bool operator<(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::iterator < passed incompatible thing");
			}
			return _it < cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::iterator::greater_than passed incompatible thing");
			}
			return boole(_it > cast<random_access_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> greater_than_(random_access_iterator_a<> const& it) const
		{
			return boole(operator>(it));
		}

		inline bool operator>(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::iterator > passed incompatible thing");
			}
			return _it > cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> less_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::iterator::less_or_equal passed incompatible thing");
			}
			return boole(_it <= cast<random_access_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> less_or_equal_(random_access_iterator_a<> const& it) const
		{
			return boole(operator<=(it));
		}

		inline bool operator<=(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::iterator <= passed incompatible thing");
			}
			return _it <= cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::iterator::greater_or_equal passed incompatible thing");
			}
			return boole(_it >= cast<random_access_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const
		{
			return boole(operator>=(it));
		}

		inline bool operator>=(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::iterator >= passed incompatible thing");
			}
			return _it >= cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
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
		squad_a<> _squad;

		template <typename F>
		inline iterator_t(squad_a<> const& squad, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _squad(squad, true)
		{}
	};

	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline random_access_const_iterator_data_a<ITERATOR> val(squad_a<> const& squad, F&& it)
		{
			return random_access_const_iterator_data_a<ITERATOR>{ const_iterator_t(squad, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::squad::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<> const& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast<random_access_const_iterator_data_a<ITERATOR>>(thing).extract();
		}

		inline bool operator!=(any_a<> const& thing) const
		{
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast<random_access_const_iterator_data_a<ITERATOR>>(thing).extract();
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

		// random access iterator
		inline _ABSTRACTION_ self_add__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator+=(thing);
			}
			return me_();
		}

		inline _ABSTRACTION_ self_add_(number_a<> const& number)
		{
			_it += number.to_int_64();
			return me_();
		}

		inline const_iterator_t& operator+=(any_a<> const& thing)
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::squad::const_iterator += passed non-number");
			}
			_it += cast<number_a<>>(thing).to_int_64();
			return *this;
		}

		inline random_access_const_iterator_a<> add__(range_a<> const& range) const
		{
			random_access_const_iterator_a<> result = me_();
			for (auto const& thing : range)
			{
				result += thing;
			}
			return result;
		}

		inline random_access_const_iterator_a<> add_(number_a<> const& number) const
		{
			return operator+(number);
		}

		inline random_access_const_iterator_a<> operator+(number_a<> const& number) const
		{
			_ABSTRACTION_ result = me_();
			result.reference() += number.to_int_64();
			return result;
		}

		inline _ABSTRACTION_ self_subtract__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator-=(thing);
			}
			return me_();
		}

		inline _ABSTRACTION_ self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64();
			return me_();
		}

		inline const_iterator_t& operator-=(any_a<> const& thing)
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::squad::const_iterator -= passed non-number");
			}
			_it -= cast<number_a<>>(thing).to_int_64();
			return *this;
		}

		inline random_access_const_iterator_a<> subtract__(range_a<> const& range) const
		{
			random_access_const_iterator_a<> result = me_();
			for (auto const& thing : range)
			{
				result -= thing;
			}
			return result;
		}

		inline random_access_const_iterator_a<> subtract_(number_a<> const& number) const
		{
			return operator-(number);
		}

		inline random_access_const_iterator_a<> operator-(number_a<> const& number) const
		{
			_ABSTRACTION_ result = me_();
			result.reference() -= number.to_int_64();
			return result;
		}

		inline any_a<> less_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::const_iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::const_iterator::less_than passed incompatible thing");
			}
			return boole(_it < cast<random_access_const_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> less_than_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator<(it));
		}

		inline bool operator<(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::const_iterator < passed incompatible thing");
			}
			return _it < cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::const_iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::const_iterator::greater_than passed incompatible thing");
			}
			return boole(_it > cast<random_access_const_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> greater_than_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator>(it));
		}

		inline bool operator>(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::const_iterator > passed incompatible thing");
			}
			return _it > cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> less_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::const_iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::const_iterator::less_or_equal passed incompatible thing");
			}
			return boole(_it <= cast<random_access_const_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator<=(it));
		}

		inline bool operator<=(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::const_iterator <= passed incompatible thing");
			}
			return _it <= cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis("strange::squad::const_iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::squad::const_iterator::greater_or_equal passed incompatible thing");
			}
			return boole(_it >= cast<random_access_const_iterator_data_a<ITERATOR>>(thing).extract());
		}

		inline any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator>=(it));
		}

		inline bool operator>=(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis("strange::squad::const_iterator >= passed incompatible thing");
			}
			return _it >= cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
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
		squad_a<> _squad;

		template <typename F>
		inline const_iterator_t(squad_a<> const& squad, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _squad(squad, true)
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_deque_any = std::deque<any_a<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return val_() += range;
	}

	static inline squad_a<> val_()
	{
		return val(std_deque_any{});
	}

	template <typename F>
	static inline squad_a<> val(F&& init)
	{
		return squad_a<>{ squad_t{ std::forward<F>(init) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<squad_t<>>::type();
	}

	static inline void share(shoal_a<> const& shoal)
	{
		reflection<squad_t<>>::share(shoal);
	}

	inline any_a<> feeder__(range_a<> const& range) const // return range of parameter values
	{
		return no(); //TODO
	}

	// visitor pattern
	static inline any_a<> visit__(range_a<> const& range)
	{
		return no(); //TODO
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return false;
		}
		return _deque == cast<squad_a<>>(thing).extract();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return true;
		}
		return _deque != cast<squad_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		std::size_t seed = std::hash<std::size_t>{}(_deque.size());
		for (auto const& item : _deque)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline random_access_const_iterator_a<> cbegin() const
	{
		return const_iterator_t<std_deque_any::const_iterator>::val(me_(), _deque.cbegin());
	}

	inline random_access_const_iterator_a<> begin() const
	{
		return const_iterator_t<std_deque_any::const_iterator>::val(me_(), _deque.cbegin());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline random_access_iterator_a<> begin_()
	{
		return begin();
	}

	inline random_access_iterator_a<> begin()
	{
		return iterator_t<std_deque_any::iterator>::val(me_(), _deque.begin());
	}

	inline random_access_const_iterator_a<> cend() const
	{
		return const_iterator_t<std_deque_any::const_iterator>::val(me_(), _deque.cend());
	}

	inline random_access_const_iterator_a<> end() const
	{
		return const_iterator_t<std_deque_any::const_iterator>::val(me_(), _deque.cend());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline random_access_iterator_a<> end_()
	{
		return end();
	}

	inline random_access_iterator_a<> end()
	{
		return iterator_t<std_deque_any::iterator>::val(me_(), _deque.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		return check<number_a<>>(key) && has(cast<number_a<>>(key).to_int_64());
	}

	inline bool has(int64_t index) const
	{
		return index >= 0 && index < size();
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		if (check<number_a<>>(key))
		{
			return at(cast<number_a<>>(key).to_int_64());
		}
		return misunderstanding_t<>::val("strange::squad::at index is not a number");
	}

	inline any_a<> at(int64_t index) const
	{
		if (index >= 0 && index < size())
		{
			return _deque[std::size_t(index)];
		}
		return misunderstanding_t<>::val("strange::squad::at index out of bounds");
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		if (check<number_a<>>(key))
		{
			update(cast<number_a<>>(key).to_int_64(), value);
		}
	}

	inline void update(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			int64_t const siz = size();
			if (index == siz)
			{
				push_back(value);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std::size_t(index) + 1, no());
				}
				_deque[std::size_t(index)] = value;
			}
		}
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		return check<number_a<>>(key) && insert(cast<number_a<>>(key).to_int_64(), value);
	}

	inline bool insert(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			int64_t const siz = size();
			if (index == siz)
			{
				push_back(value);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std::size_t(index) + 1, no());
					_deque[std::size_t(index)] = value;
				}
				else
				{
					_deque.insert(_deque.cbegin() + index, value);
				}
			}
			return true;
		}
		return false;
	}

	inline bool erase(any_a<> const& key)
	{
		return check<number_a<>>(key) && erase(cast<number_a<>>(key).to_int_64());
	}

	inline bool erase(int64_t index)
	{
		if (index >= 0 && index < size())
		{
			_deque.erase(_deque.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear()
	{
		_deque.clear();
	}

	inline int64_t size() const
	{
		return int64_t(_deque.size());
	}

	inline bool empty() const
	{
		return _deque.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		_deque.push_front(thing);
	}

	inline any_a<> pop_front_()
	{
		if (_deque.empty())
		{
			return no();
		}
		any_a<> result = _deque.front();
		_deque.pop_front();
		return result;
	}

	inline void push_back(any_a<> const& thing)
	{
		_deque.push_back(thing);
	}

	inline any_a<> pop_back_()
	{
		if (_deque.empty())
		{
			return no();
		}
		any_a<> result = _deque.back();
		_deque.pop_back();
		return result;
	}

	inline squad_t& operator+=(any_a<> const& range)
	{
		if (check<squad_a<>>(range))
		{
			auto other = cast<squad_a<>>(range).extract();
			_deque.insert(_deque.cend(), other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::squad += passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				_deque.push_back(thing);
			}
		}
		return *this;
	}

	inline squad_t& operator-=(any_a<> const& range)
	{
		if (check<collection_a<>>(range))
		{
			_deque.resize(std::size_t(std::max<int64_t>(0, int64_t(_deque.size()) - cast<collection_a<>>(range).size())));
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::squad -= passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				if (_deque.empty())
				{
					break;
				}
				_deque.pop_back();
			}
		}
		return *this;
	}

	// data
	inline std_deque_any const& extract() const
	{
		return _deque;
	}

	inline void mutate(std_deque_any const& data)
	{
		_deque = data;
	}

	inline std_deque_any& reference()
	{
		return _deque;
	}

protected:
	std_deque_any _deque;

	template <typename F>
	inline squad_t(F&& init)
		: thing_t{}
		, _deque{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
