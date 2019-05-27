#ifndef COM_ONEISH_STRANGE_LAKE_T_H
#define COM_ONEISH_STRANGE_LAKE_T_H

namespace strange
{

template <typename PRIMITIVE, typename _ABSTRACTION_ = lake_a<PRIMITIVE>>
class lake_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_iterator_data_a<ITERATOR>>
	class iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline random_access_iterator_data_a<ITERATOR> val(lake_a<PRIMITIVE> const& lake, F&& it)
		{
			return random_access_iterator_data_a<ITERATOR>{ iterator_t(lake, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::lake::iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
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
			return number_t<PRIMITIVE>::val(*_it);
		}

		inline any_a<> set__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::iterator set passed empty range");
			}
			return set_(*it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::lake::iterator set passed non-number");
			}
			*_it = number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing));
			return thing;
		}

		inline any_a<>* operator->() const
		{
			_number = number_reference_t<PRIMITIVE>::val(*_it);
			return &_number;
		}

		inline any_a<>& operator*() const
		{
			throw dis("strange::lake::iterator cannot be dereferenced directly");
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
				throw dis("strange::lake::iterator += passed non-number");
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
				throw dis("strange::lake::iterator -= passed non-number");
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
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::iterator::less_than passed incompatible thing");
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
				throw dis("strange::lake::iterator < passed incompatible thing");
			}
			return _it < cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::iterator::greater_than passed incompatible thing");
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
				throw dis("strange::lake::iterator > passed incompatible thing");
			}
			return _it > cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> less_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::iterator::less_or_equal passed incompatible thing");
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
				throw dis("strange::lake::iterator <= passed incompatible thing");
			}
			return _it <= cast<random_access_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::iterator::greater_or_equal passed incompatible thing");
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
				throw dis("strange::lake::iterator >= passed incompatible thing");
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
		lake_a<PRIMITIVE> _lake;
		mutable number_data_a<PRIMITIVE> _number;

		template <typename F>
		inline iterator_t(lake_a<PRIMITIVE> const& lake, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _lake(lake, true)
			, _number{ number_t<PRIMITIVE>::val_() }
		{}
	};

	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline random_access_const_iterator_data_a<ITERATOR> val(lake_a<PRIMITIVE> const& lake, F&& it)
		{
			return random_access_const_iterator_data_a<ITERATOR>{ const_iterator_t(lake, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::lake::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
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
			_number = number_t<PRIMITIVE>::val(*_it);
			return _number;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			_number = number_t<PRIMITIVE>::val(*_it);
			return _number;
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
				throw dis("strange::lake::const_iterator += passed non-number");
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
				throw dis("strange::lake::const_iterator -= passed non-number");
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
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::const_iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::const_iterator::less_than passed incompatible thing");
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
				throw dis("strange::lake::const_iterator < passed incompatible thing");
			}
			return _it < cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_than__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::const_iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::const_iterator::greater_than passed incompatible thing");
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
				throw dis("strange::lake::const_iterator > passed incompatible thing");
			}
			return _it > cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> less_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::const_iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::const_iterator::less_or_equal passed incompatible thing");
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
				throw dis("strange::lake::const_iterator <= passed incompatible thing");
			}
			return _it <= cast<random_access_const_iterator_data_a<ITERATOR>>(it).extract();
		}

		inline any_a<> greater_or_equal__(range_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin_();
			if (it == range.cend_())
			{
				throw dis("strange::lake::const_iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis("strange::lake::const_iterator::greater_or_equal passed incompatible thing");
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
				throw dis("strange::lake::const_iterator >= passed incompatible thing");
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
		lake_a<PRIMITIVE> _lake;
		mutable number_data_a<PRIMITIVE> _number;

		template <typename F>
		inline const_iterator_t(lake_a<PRIMITIVE> const& lake, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _lake(lake, true)
			, _number{ number_t<PRIMITIVE>::val_() }
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_vector_number = std::vector<PRIMITIVE>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return val_() += range;
	}

	static inline lake_a<PRIMITIVE> val_()
	{
		return val(std_vector_number{});
	}

	template <typename F>
	static inline lake_a<PRIMITIVE> val(F&& init)
	{
		return lake_a<PRIMITIVE>{ lake_t{ std::forward<F>(init) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<lake_t<PRIMITIVE>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<lake_t<PRIMITIVE>>::share(shoal);
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
		if (!check<lake_a<PRIMITIVE>>(thing))
		{
			return false;
		}
		return _vector == cast<lake_a<PRIMITIVE>>(thing).extract();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check<lake_a<PRIMITIVE>>(thing))
		{
			return true;
		}
		return _vector != cast<lake_a<PRIMITIVE>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		std::size_t seed = std::hash<std::size_t>{}(_vector.size());
		for (auto item : _vector)
		{
			seed ^= std::hash<PRIMITIVE>{}(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline random_access_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<std_vector_number::const_iterator>::val(me_(), _vector.cbegin());
	}

	inline random_access_const_iterator_a<> cend_() const
	{
		return const_iterator_t<std_vector_number::const_iterator>::val(me_(), _vector.cend());
	}

	inline any_a<> begin__(range_a<> const&)
	{
		return begin_();
	}

	inline random_access_iterator_a<> begin_()
	{
		return iterator_t<std_vector_number::iterator>::val(me_(), _vector.begin());
	}

	inline any_a<> end__(range_a<> const&)
	{
		return end_();
	}

	inline random_access_iterator_a<> end_()
	{
		return iterator_t<std_vector_number::iterator>::val(me_(), _vector.end());
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
		return at(-1);
	}

	inline any_a<> at(int64_t index) const
	{
		return number_t<PRIMITIVE>::val(pat(index));
	}

	inline PRIMITIVE pat(int64_t index) const
	{
		if (index >= 0 && index < size())
		{
			return _vector[std::size_t(index)];
		}
		return PRIMITIVE{};
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
		if (!check<number_a<>>(value))
		{
			throw dis("strange::lake::update passed non-number value");
		}
		return update(index, number_u<PRIMITIVE>::from_number(cast<number_a<>>(value)));
	}

	inline void update(int64_t index, PRIMITIVE number)
	{
		if (index >= 0)
		{
			int64_t const siz = size();
			if (index == siz)
			{
				push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_vector.resize(std::size_t(index) + 1, no());
				}
				_vector[std::size_t(index)] = number;
			}
		}
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		return check<number_a<>>(key) && insert(cast<number_a<>>(key).to_int_64(), value);
	}

	inline bool insert(int64_t index, any_a<> const& value)
	{
		if (!check<number_a<>>(value))
		{
			throw dis("strange::lake::insert passed non-number value");
		}
		return insert(index, number_u<PRIMITIVE>::from_number(cast<number_a<>>(value)));
	}

	inline bool insert(int64_t index, PRIMITIVE number)
	{
		if (index >= 0)
		{
			int64_t const siz = size();
			if (index == siz)
			{
				push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_vector.resize(std::size_t(index) + 1, no());
					_vector[std::size_t(index)] = number;
				}
				else
				{
					_vector.insert(_vector.cbegin() + index, number);
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
			_vector.erase(_vector.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear()
	{
		_vector.clear();
	}

	inline int64_t size() const
	{
		return int64_t(_vector.size());
	}

	inline bool empty() const
	{
		return _vector.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		push_back(thing);
	}

	inline void push_front(PRIMITIVE number)
	{
		push_back(number);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline PRIMITIVE pop_front()
	{
		return pop_back();
	}

	inline void push_back(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::lake::push_back passed non-number");
		}
		push_back(number_u<PRIMITIVE>::from_number(cast<number_a<>>(thing)));
	}

	inline void push_back(PRIMITIVE number)
	{
		_vector.push_back(number);
	}

	inline any_a<> pop_back_()
	{
		if (_vector.empty())
		{
			return no();
		}
		return number_t<PRIMITIVE>::val(pop_back());
	}

	inline PRIMITIVE pop_back()
	{
		PRIMITIVE number = _vector.back();
		_vector.pop_back();
		return number;
	}

	inline lake_t& operator+=(any_a<> const& range)
	{
		if (check<lake_a<PRIMITIVE>>(range))
		{
			auto other = cast<lake_a<PRIMITIVE>>(range).extract();
			_vector.insert(_vector.cend(), other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::lake += passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				push_back(thing);
			}
		}
		return *this;
	}

	inline lake_t& operator-=(any_a<> const& range)
	{
		if (check<collection_a<>>(range))
		{
			_vector.resize(std::size_t(std::max<int64_t>(0, int64_t(_vector.size()) - cast<collection_a<>>(range).size())));
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::lake -= passed non-range");
			}
			for (auto const& thing : cast<range_a<>>(range))
			{
				if (_vector.empty())
				{
					break;
				}
				_vector.pop_back();
			}
		}
		return *this;
	}

	// data
	inline std_vector_number const& extract() const
	{
		return _vector;
	}

	inline void mutate(std_vector_number const& data)
	{
		_vector = data;
	}

	inline std_vector_number& reference()
	{
		return _vector;
	}

protected:
	std_vector_number _vector;

	template <typename F>
	inline lake_t(F&& init)
		: thing_t{}
		, _vector{ std::forward<F>(init) }
	{}
};

template <typename _ABSTRACTION_ = lake_a<int8_t>>
using lake_int_8_t = lake_t<int8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<uint8_t>>
using lake_uint_8_t = lake_t<uint8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<int16_t>>
using lake_int_16_t = lake_t<int16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<uint16_t>>
using lake_uint_16_t = lake_t<uint16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<int32_t>>
using lake_int_32_t = lake_t<int32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<uint32_t>>
using lake_uint_32_t = lake_t<uint32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<int64_t>>
using lake_int_64_t = lake_t<int64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<uint64_t>>
using lake_uint_64_t = lake_t<uint64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<float>>
using lake_float_32_t = lake_t<float, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_a<double>>
using lake_float_64_t = lake_t<double, _ABSTRACTION_>;

} // namespace strange

#endif
