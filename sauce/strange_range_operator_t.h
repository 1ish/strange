#ifndef COM_ONEISH_STRANGE_RANGE_OPERATOR_T_H
#define COM_ONEISH_STRANGE_RANGE_OPERATOR_T_H

namespace strange
{

template <typename _ABSTRACTION_ = range_a<>>
class range_operator_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = forward_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline forward_const_iterator_data_a<ITERATOR> val(range_a<> const& range, F&& it, any_a<>& thing_ref, range_a<> const& range_ref)
		{
			return forward_const_iterator_data_a<ITERATOR>{ const_iterator_t(range, std::forward<F>(it), thing_ref, range_ref) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::range_operator::const_iterator");
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
			return _result;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			return _result;
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
			_result = next();
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

		// next thing
		inline any_a<> next()
		{
			if (_it == _range.cend_())
			{
				return no();
			}
			return _it.get_().operate_(_thing_ref, _range_ref);
		}

	protected:
		ITERATOR _it;
		range_a<> _range;
		any_a<>& _thing_ref;
		range_a<> const& _range_ref;
		mutable any_a<> _result;

		template <typename F>
		inline const_iterator_t(range_a<> const& range, F&& it, any_a<>& thing_ref, range_a<> const& range_ref)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _range(range, true)
			, _thing_ref{ thing_ref }
			, _range_ref{ range_ref }
			, _result{ next() }
		{}
	};

public: ___STRANGE_RANGE___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::range_operator::val passed empty range");
		}
		any_a<> the_range = *it;
		if (!check<range_a<>>(the_range))
		{
			throw dis("strange::range_operator::val passed non-range");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::range_operator::val passed short range");
		}
		any_a<> thing_ref(*it, true);
		if (++it == range.cend_())
		{
			throw dis("strange::range_operator::val passed short range");
		}
		any_a<> range_ref(*it, true);
		if (!check<range_a<>>(range_ref))
		{
			throw dis("strange::range_operator::val passed non-range range ref");
		}
		return val_(cast<range_a<>>(the_range), thing_ref, cast<range_a<>>(range_ref, true));
	}

	static inline range_a<> val_(range_a<> const& range, any_a<>& thing_ref, range_a<> const& range_ref)
	{
		return range_a<>{ range_operator_t(range, thing_ref, range_ref) };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<range_operator_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<range_operator_t<>>::share(shoal);
	}

	// range
	inline forward_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::val(_range, _range.cbegin_(), _thing_ref, _range_ref);
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::val(_range, _range.cend_(), _thing_ref, _range_ref);
	}

protected:
	range_a<> const _range;
	any_a<>& _thing_ref;
	range_a<> const& _range_ref;

	inline range_operator_t(range_a<> const& range, any_a<>& thing_ref, range_a<> const& range_ref)
		: thing_t{}
		, _range(range)
		, _thing_ref(thing_ref)
		, _range_ref(range_ref)
	{}
};

} // namespace strange

#endif
