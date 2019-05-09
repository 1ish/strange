#ifndef COM_ONEISH_STRANGE_LAKE_T_H
#define COM_ONEISH_STRANGE_LAKE_T_H

namespace strange
{

template <typename PRIMITIVE, typename _ABSTRACTION_ = lake_data_a<PRIMITIVE>>
class lake_t : public something_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_iterator_data_a<ITERATOR>>
	class iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___THING___
		// construction
		template <typename F>
		static inline random_access_iterator_data_a<ITERATOR> val__(lake_a<> const& lake, F&& it)
		{
			return random_access_iterator_data_a<ITERATOR>{ iterator_t(lake, std::forward<F>(it)) };
		}

		template <typename F>
		static inline random_access_iterator_data_a<ITERATOR> ref__(lake_a<> const& lake, F&& it)
		{
			return random_access_iterator_data_a<ITERATOR>(iterator_t(lake, std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym__("strange::lake::iterator");
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
			return number_t<PRIMITIVE>::val__(*_it);
		}

		inline any_a<> set(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::iterator set passed empty range");
			}
			return set_(*it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check_<number_a<>>(thing))
			{
				throw dis__("strange::lake::iterator set passed non-number");
			}
			*_it = number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing));
			return thing;
		}

		inline any_a<>* operator->() const
		{
			return &operator*();
		}

		inline any_a<>& operator*() const
		{
			_number = number_reference_t<PRIMITIVE>::val__(*_it);
			return _number;
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
				throw dis__("strange::lake::iterator += passed non-number");
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
				throw dis__("strange::lake::iterator -= passed non-number");
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
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::iterator::less_than passed incompatible thing");
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
				throw dis__("strange::lake::iterator < passed incompatible thing");
			}
			return _it < cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> greater_than(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::iterator::greater_than passed incompatible thing");
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
				throw dis__("strange::lake::iterator > passed incompatible thing");
			}
			return _it > cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> less_or_equal(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::iterator::less_or_equal passed incompatible thing");
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
				throw dis__("strange::lake::iterator <= passed incompatible thing");
			}
			return _it <= cast_<random_access_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> greater_or_equal(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::iterator::greater_or_equal passed incompatible thing");
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
				throw dis__("strange::lake::iterator >= passed incompatible thing");
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

	protected:
		ITERATOR _it;
		lake_a<> _lake;
		mutable number_data_a<PRIMITIVE> _number;

		template <typename F>
		inline iterator_t(lake_a<> const& lake, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _lake(lake, true)
			, _number{ number_t<PRIMITIVE>::val_() }
		{}
	};

	template <typename ITERATOR, typename _ABSTRACTION_ = random_access_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___THING___
		// construction
		template <typename F>
		static inline random_access_const_iterator_data_a<ITERATOR> val__(lake_a<> const& lake, F&& it)
		{
			return random_access_const_iterator_data_a<ITERATOR>{ const_iterator_t(lake, std::forward<F>(it)) };
		}

		template <typename F>
		static inline random_access_const_iterator_data_a<ITERATOR> ref__(lake_a<> const& lake, F&& it)
		{
			return random_access_const_iterator_data_a<ITERATOR>(const_iterator_t(lake, std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym__("strange::lake::const_iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast_<random_access_const_iterator_data_a<ITERATOR>>(thing).extract__();
		}

		inline bool operator!=(any_a<> const& thing) const
		{
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast_<random_access_const_iterator_data_a<ITERATOR>>(thing).extract__();
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

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			_number = number_t<PRIMITIVE>::val__(*_it);
			return _number;
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

		inline const_iterator_t& operator+=(any_a<> const& thing)
		{
			if (!check_<number_a<>>(thing))
			{
				throw dis__("strange::lake::const_iterator += passed non-number");
			}
			_it += cast_<number_a<>>(thing).to_int_64__();
			return *this;
		}

		inline random_access_const_iterator_a<> add(any_a<> const& range) const
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

		inline const_iterator_t& operator-=(any_a<> const& thing)
		{
			if (!check_<number_a<>>(thing))
			{
				throw dis__("strange::lake::const_iterator -= passed non-number");
			}
			_it -= cast_<number_a<>>(thing).to_int_64__();
			return *this;
		}

		inline random_access_const_iterator_a<> subtract(any_a<> const& range) const
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
			result.reference__() -= number.to_int_64__();
			return result;
		}

		inline any_a<> less_than(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::const_iterator::less_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::const_iterator::less_than passed incompatible thing");
			}
			return _boole_(_it < cast_<random_access_const_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> less_than_(random_access_const_iterator_a<> const& it) const
		{
			return _boole_(operator<(it));
		}

		inline bool operator<(random_access_const_iterator_a<> const& it) const
		{
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::lake::const_iterator < passed incompatible thing");
			}
			return _it < cast_<random_access_const_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> greater_than(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::const_iterator::greater_than passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::const_iterator::greater_than passed incompatible thing");
			}
			return _boole_(_it > cast_<random_access_const_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> greater_than_(random_access_const_iterator_a<> const& it) const
		{
			return _boole_(operator>(it));
		}

		inline bool operator>(random_access_const_iterator_a<> const& it) const
		{
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::lake::const_iterator > passed incompatible thing");
			}
			return _it > cast_<random_access_const_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> less_or_equal(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::const_iterator::less_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::const_iterator::less_or_equal passed incompatible thing");
			}
			return _boole_(_it <= cast_<random_access_const_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const
		{
			return _boole_(operator<=(it));
		}

		inline bool operator<=(random_access_const_iterator_a<> const& it) const
		{
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::lake::const_iterator <= passed incompatible thing");
			}
			return _it <= cast_<random_access_const_iterator_data_a<ITERATOR>>(it).extract__();
		}

		inline any_a<> greater_or_equal(any_a<> const& range) const
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				throw dis__("strange::lake::const_iterator::greater_or_equal passed empty range");
			}
			any_a<> thing = *it;
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(thing))
			{
				throw dis__("strange::lake::const_iterator::greater_or_equal passed incompatible thing");
			}
			return _boole_(_it >= cast_<random_access_const_iterator_data_a<ITERATOR>>(thing).extract__());
		}

		inline any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const
		{
			return _boole_(operator>=(it));
		}

		inline bool operator>=(random_access_const_iterator_a<> const& it) const
		{
			if (!check_<random_access_const_iterator_data_a<ITERATOR>>(it))
			{
				throw dis__("strange::lake::const_iterator >= passed incompatible thing");
			}
			return _it >= cast_<random_access_const_iterator_data_a<ITERATOR>>(it).extract__();
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
		lake_a<> _lake;
		mutable number_data_a<PRIMITIVE> _number;

		template <typename F>
		inline const_iterator_t(lake_a<> const& lake, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _lake(lake, true)
			, _number{ number_t<PRIMITIVE>::val_() }
		{}
	};

public: ___COLLECTION___
	using std_vector_number = std::vector<PRIMITIVE>;

	// construction
	static inline lake_data_a<PRIMITIVE> val(any_a<> const& range)
	{
		return cast_<lake_data_a<PRIMITIVE>>(val_() += range);
	}

	static inline lake_data_a<PRIMITIVE> val_()
	{
		return val__(std_vector_number{});
	}

	template <typename F>
	static inline lake_data_a<PRIMITIVE> val__(F&& init)
	{
		return lake_data_a<PRIMITIVE>{ lake_t{ std::forward<F>(init) } };
	}

	static inline lake_data_a<PRIMITIVE> ref(any_a<> const& range)
	{
		return cast_<lake_data_a<PRIMITIVE>>(ref_() += range, true);
	}

	static inline lake_data_a<PRIMITIVE> ref_()
	{
		return ref__(std_vector_number{});
	}

	template <typename F>
	static inline lake_data_a<PRIMITIVE> ref__(F&& init)
	{
		return lake_data_a<PRIMITIVE>(lake_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::lake");
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
		if (!check_<lake_data_a<PRIMITIVE>>(thing))
		{
			return false;
		}
		return _vector == cast_<lake_data_a<PRIMITIVE>>(thing).extract__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<lake_data_a<PRIMITIVE>>(thing))
		{
			return true;
		}
		return _vector != cast_<lake_data_a<PRIMITIVE>>(thing).extract__();
	}

	inline std::size_t hash__() const
	{
		std::size_t seed = std::hash<std::size_t>{}(_vector.size());
		for (auto item : _vector)
		{
			seed ^= std::hash<PRIMITIVE>{}(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline random_access_const_iterator_a<> cbegin() const
	{
		return const_iterator_t<std_vector_number::const_iterator>::val__(me_(), _vector.cbegin());
	}

	inline random_access_const_iterator_a<> begin() const
	{
		return const_iterator_t<std_vector_number::const_iterator>::val__(me_(), _vector.cbegin());
	}

	inline any_a<> beset(any_a<> const&)
	{
		return beset_();
	}

	inline random_access_iterator_a<> beset_()
	{
		return begin();
	}

	inline random_access_iterator_a<> begin()
	{
		return iterator_t<std_vector_number::iterator>::val__(me_(), _vector.begin());
	}

	inline random_access_const_iterator_a<> cend() const
	{
		return const_iterator_t<std_vector_number::const_iterator>::val__(me_(), _vector.cend());
	}

	inline random_access_const_iterator_a<> end() const
	{
		return const_iterator_t<std_vector_number::const_iterator>::val__(me_(), _vector.cend());
	}

	inline any_a<> enset(any_a<> const&)
	{
		return enset_();
	}

	inline random_access_iterator_a<> enset_()
	{
		return end();
	}

	inline random_access_iterator_a<> end()
	{
		return iterator_t<std_vector_number::iterator>::val__(me_(), _vector.end());
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
		return at__(-1);
	}

	inline any_a<> at__(int64_t index) const
	{
		return number_t<PRIMITIVE>::val__(at___(index));
	}

	inline PRIMITIVE at___(int64_t index) const
	{
		if (index >= 0 && index < size__())
		{
			return _vector[std::size_t(index)];
		}
		return PRIMITIVE{};
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
		if (!check_<number_a<>>(value))
		{
			throw dis__("strange::lake::update passed non-number value");
		}
		return update__(index, number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(value)));
	}

	inline void update__(int64_t index, PRIMITIVE number)
	{
		if (index >= 0)
		{
			int64_t const size = size__();
			if (index == size)
			{
				push_back__(number);
			}
			else
			{
				if (index > size)
				{
					_vector.resize(std::size_t(index) + 1, nothing_t<>::val_());
				}
				_vector[std::size_t(index)] = number;
			}
		}
	}

	inline bool insert__(any_a<> const& key, any_a<> const& value)
	{
		return check_<number_a<>>(key) && insert__(cast_<number_a<>>(key).to_int_64__(), value);
	}

	inline bool insert__(int64_t index, any_a<> const& value)
	{
		if (!check_<number_a<>>(value))
		{
			throw dis__("strange::lake::insert passed non-number value");
		}
		return insert__(index, number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(value)));
	}

	inline bool insert__(int64_t index, PRIMITIVE number)
	{
		if (index >= 0)
		{
			int64_t const size = size__();
			if (index == size)
			{
				push_back__(number);
			}
			else
			{
				if (index > size)
				{
					_vector.resize(std::size_t(index) + 1, nothing_t<>::val_());
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

	inline void push_front__(PRIMITIVE number)
	{
		push_back__(number);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline PRIMITIVE pop_front__()
	{
		return pop_back__();
	}

	inline void push_back__(any_a<> const& thing)
	{
		if (!check_<number_a<>>(thing))
		{
			throw dis__("strange::lake::push_back passed non-number");
		}
		push_back__(number_u<PRIMITIVE>::from_number__(cast_<number_a<>>(thing)));
	}

	inline void push_back__(PRIMITIVE number)
	{
		_vector.push_back(number);
	}

	inline any_a<> pop_back_()
	{
		if (_vector.empty())
		{
			return nothing_t<>::val_();
		}
		return number_t<PRIMITIVE>::val__(pop_back__());
	}

	inline PRIMITIVE pop_back__()
	{
		PRIMITIVE number = _vector.back();
		_vector.pop_back();
		return number;
	}

	inline lake_t& operator+=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline lake_t& operator-=(any_a<> const& range)
	{
		for (auto const& thing : range)
		{
			erase(thing);
		}
		return *this;
	}

	// data
	inline std_vector_number const& extract__() const
	{
		return _vector;
	}

	inline void mutate__(std_vector_number const& data)
	{
		_vector = data;
	}

	inline std_vector_number& reference__()
	{
		return _vector;
	}

protected:
	std_vector_number _vector;

	template <typename F>
	inline lake_t(F&& init)
		: something_t{}
		, _vector{ std::forward<F>(init) }
	{}
};

template <typename _ABSTRACTION_ = lake_data_a<int8_t>>
using lake_int_8_t = lake_t<int8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<uint8_t>>
using lake_uint_8_t = lake_t<uint8_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<int16_t>>
using lake_int_16_t = lake_t<int16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<uint16_t>>
using lake_uint_16_t = lake_t<uint16_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<int32_t>>
using lake_int_32_t = lake_t<int32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<uint32_t>>
using lake_uint_32_t = lake_t<uint32_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<int64_t>>
using lake_int_64_t = lake_t<int64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<uint64_t>>
using lake_uint_64_t = lake_t<uint64_t, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<float>>
using lake_float_32_t = lake_t<float, _ABSTRACTION_>;

template <typename _ABSTRACTION_ = lake_data_a<double>>
using lake_float_64_t = lake_t<double, _ABSTRACTION_>;

} // namespace strange

#endif
