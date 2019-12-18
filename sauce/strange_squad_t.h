#ifndef COM_ONEISH_STRANGE_SQUAD_T_H
#define COM_ONEISH_STRANGE_SQUAD_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = squad_a<>>
class squad_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego___ = random_access_iterator_data_a<_iterator_>>
	class iterator_t : public thing_t<___ego___>
	{
	public:
		// override
		using over = thing_o<iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline random_access_iterator_data_a<_iterator_> create(F&& it)
		{
			return random_access_iterator_data_a<_iterator_>{ over{ iterator_t<_iterator_>(std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::squad::iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<random_access_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<random_access_iterator_data_a<_iterator_>>(thing).extract();
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
			//TODO concurrent
			return *_it;
		}

		inline any_a<> set__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
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
		inline ___ego___ decrement__(range_a<> const& _)
		{
			return decrement_();
		}

		inline ___ego___ decrement_()
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
		inline ___ego___ self_add__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator+=(thing);
			}
			return me_();
		}

		inline ___ego___ self_add_(number_a<> const& number)
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
			___ego___ result = me_();
			result.reference() += number.to_int_64();
			return result;
		}

		inline ___ego___ self_subtract__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator-=(thing);
			}
			return me_();
		}

		inline ___ego___ self_subtract_(number_a<> const& number)
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
			___ego___ result = me_();
			result.reference() -= number.to_int_64();
			return result;
		}

		inline any_a<> less_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::iterator::less_than passed incompatible thing");
			}
			return boole(_it < cast<random_access_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> less_than_(random_access_iterator_a<> const& it) const
		{
			return boole(operator<(it));
		}

		inline bool operator<(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::iterator < passed incompatible thing");
			}
			return _it < cast<random_access_iterator_data_a<_iterator_>>(it).extract();
		}

		inline any_a<> greater_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::iterator::greater_than passed incompatible thing");
			}
			return boole(_it > cast<random_access_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> greater_than_(random_access_iterator_a<> const& it) const
		{
			return boole(operator>(it));
		}

		inline bool operator>(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::iterator > passed incompatible thing");
			}
			return _it > cast<random_access_iterator_data_a<_iterator_>>(it).extract();
		}

		inline any_a<> less_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::iterator::less_or_equal passed incompatible thing");
			}
			return boole(_it <= cast<random_access_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> less_or_equal_(random_access_iterator_a<> const& it) const
		{
			return boole(operator<=(it));
		}

		inline bool operator<=(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::iterator <= passed incompatible thing");
			}
			return _it <= cast<random_access_iterator_data_a<_iterator_>>(it).extract();
		}

		inline any_a<> greater_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::iterator::greater_or_equal passed incompatible thing");
			}
			return boole(_it >= cast<random_access_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const
		{
			return boole(operator>=(it));
		}

		inline bool operator>=(random_access_iterator_a<> const& it) const
		{
			if (!check<random_access_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::iterator >= passed incompatible thing");
			}
			return _it >= cast<random_access_iterator_data_a<_iterator_>>(it).extract();
		}

		// data
		inline _iterator_ const& extract() const
		{
			return _it;
		}

		inline void mutate(_iterator_ const& it)
		{
			_it = it;
		}

		inline _iterator_& reference()
		{
			return _it;
		}

	protected:
		_iterator_ _it;

		template <typename F>
		inline iterator_t(F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
		{}
	};

	template <typename _iterator_, typename ___ego___ = random_access_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline random_access_const_iterator_data_a<_iterator_> create(squad_a<> const& squad, F&& it)
		{
			return random_access_const_iterator_data_a<_iterator_>{ over{ const_iterator_t<_iterator_>(squad, std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::squad::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<random_access_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<random_access_const_iterator_data_a<_iterator_>>(thing).extract();
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
		inline ___ego___ decrement__(range_a<> const& _)
		{
			return decrement_();
		}

		inline ___ego___ decrement_()
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
		inline ___ego___ self_add__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator+=(thing);
			}
			return me_();
		}

		inline ___ego___ self_add_(number_a<> const& number)
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
			___ego___ result = me_();
			result.reference() += number.to_int_64();
			return result;
		}

		inline ___ego___ self_subtract__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				operator-=(thing);
			}
			return me_();
		}

		inline ___ego___ self_subtract_(number_a<> const& number)
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
			___ego___ result = me_();
			result.reference() -= number.to_int_64();
			return result;
		}

		inline any_a<> less_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::const_iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::const_iterator::less_than passed incompatible thing");
			}
			return boole(_it < cast<random_access_const_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> less_than_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator<(it));
		}

		inline bool operator<(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::const_iterator < passed incompatible thing");
			}
			return _it < cast<random_access_const_iterator_data_a<_iterator_>>(it).extract();
		}

		inline any_a<> greater_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::const_iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::const_iterator::greater_than passed incompatible thing");
			}
			return boole(_it > cast<random_access_const_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> greater_than_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator>(it));
		}

		inline bool operator>(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::const_iterator > passed incompatible thing");
			}
			return _it > cast<random_access_const_iterator_data_a<_iterator_>>(it).extract();
		}

		inline any_a<> less_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::const_iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::const_iterator::less_or_equal passed incompatible thing");
			}
			return boole(_it <= cast<random_access_const_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator<=(it));
		}

		inline bool operator<=(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::const_iterator <= passed incompatible thing");
			}
			return _it <= cast<random_access_const_iterator_data_a<_iterator_>>(it).extract();
		}

		inline any_a<> greater_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::squad::const_iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<_iterator_>>(thing))
			{
				throw dis("strange::squad::const_iterator::greater_or_equal passed incompatible thing");
			}
			return boole(_it >= cast<random_access_const_iterator_data_a<_iterator_>>(thing).extract());
		}

		inline any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const
		{
			return boole(operator>=(it));
		}

		inline bool operator>=(random_access_const_iterator_a<> const& it) const
		{
			if (!check<random_access_const_iterator_data_a<_iterator_>>(it))
			{
				throw dis("strange::squad::const_iterator >= passed incompatible thing");
			}
			return _it >= cast<random_access_const_iterator_data_a<_iterator_>>(it).extract();
		}

		// data
		inline _iterator_ const& extract() const
		{
			return _it;
		}

		inline void mutate(_iterator_ const& it)
		{
			_it = it;
		}

		inline _iterator_& reference()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		squad_a<> const _squad;

		template <typename F>
		inline const_iterator_t(squad_a<> const& squad, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _squad{ squad }
		{}
	};

public:
	using std_deque_any = std::deque<any_a<>>;

	// override
	using over = collection_o<squad_t<_concurrent_>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline squad_a<> create_()
	{
		return create(std_deque_any{});
	}

	template <typename... Args>
	static inline squad_a<> create_(Args&&... args)
	{
		return create(variadic_u<>::deque(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline squad_a<> create(F&& init)
	{
		return squad_a<>{ over{ squad_t<_concurrent_>{ std::forward<F>(init) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<squad_t<_concurrent_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<squad_t<_concurrent_>>::share(shoal);
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<inventory_a<>>(range))
		{
			throw dis("strange::squad::visit passed non-inventory");
		}
		return visit_(cast<inventory_a<>>(range, true));
	}

	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& visited : _deque)
			{
				inventory.update_index(last, visited);
				visited.visit_(inventory);
			}
		}
		return result;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == cast<squad_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_deque.size());
		for (auto const& item : _deque)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline random_access_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<std_deque_any::const_iterator>::create(me_(), _deque.cbegin());
	}

	inline random_access_const_iterator_a<> cend_() const
	{
		return const_iterator_t<std_deque_any::const_iterator>::create(me_(), _deque.cend());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline random_access_iterator_a<> begin_()
	{
		return iterator_t<std_deque_any::iterator>::create(_deque.begin());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline random_access_iterator_a<> end_()
	{
		return iterator_t<std_deque_any::iterator>::create(_deque.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		return check<number_a<>>(key) && has_index(cast<number_a<>>(key).to_int_64());
	}

	inline bool has_index(int64_t index) const
	{
		return index >= 0 && index < size();
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		if (check<number_a<>>(key))
		{
			return at_index(cast<number_a<>>(key).to_int_64());
		}
		return misunderstanding_t<>::create("strange::squad::at index is not a number");
	}

	inline any_a<> at_index(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			return _deque[std::size_t(index)];
		}
		return misunderstanding_t<>::create("strange::squad::at index out of bounds");
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		if (check<number_a<>>(key))
		{
			update_index(cast<number_a<>>(key).to_int_64(), value);
		}
	}

	inline void update_index(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(value);
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
		return check<number_a<>>(key) && insert_index(cast<number_a<>>(key).to_int_64(), value);
	}

	inline bool insert_index(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(value);
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
		return check<number_a<>>(key) && erase_index(cast<number_a<>>(key).to_int_64());
	}

	inline bool erase_index(int64_t index)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			_deque.erase(_deque.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_deque.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_front(thing);
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
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
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_back(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			return no();
		}
		any_a<> result = _deque.back();
		_deque.pop_back();
		return result;
	}

	inline squad_a<> self_assign_(range_a<> const& range)
	{
		if (check<squad_a<>>(range))
		{
			auto const other = cast<squad_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque = other.extract();
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.clear();
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
		return me_();
	}

	inline squad_t& operator+=(any_a<> const& range)
	{
		if (check<squad_a<>>(range))
		{
			auto const other = cast<squad_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_deque = other.extract();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.insert(_deque.cend(), other_deque.cbegin(), other_deque.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::squad += passed non-range");
			}
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : cast<range_a<> const>(range))
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
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_deque.resize(std::size_t(std::max<int64_t>(0, int64_t(_deque.size()) - cast<collection_a<>>(range).size())));
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::squad -= passed non-range");
			}
			auto read_lock = check<collection_a<>>(range) ? cast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : cast<range_a<> const>(range))
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

	inline any_a<> read_lock_() const
	{
		return data_t<read_lock_ptr<_concurrent_>>::create(make_read_lock_ptr<_concurrent_>(_mutex));
	}

	inline any_a<> write_lock_() const
	{
		return data_t<write_lock_ptr<_concurrent_>>::create(make_write_lock_ptr<_concurrent_>(_mutex));
	}

	// data
	inline std_deque_any const& extract() const
	{
		return _deque;
	}

	inline void mutate(std_deque_any const& data)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque = data;
	}

	inline std_deque_any& reference()
	{
		return _deque;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_deque_any _deque;

	template <typename F>
	inline squad_t(F&& init)
		: thing_t{}
		, _deque{ std::forward<F>(init) }
	{}

public:
	inline squad_t(squad_t const& other)
		: _deque{ other._deque }
	{}

	inline squad_t(squad_t&& other)
		: _deque{ std::move(other._deque) }
	{}

private:
	static bool const ___share___;
	friend class ___squad_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const squad_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	squad_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
