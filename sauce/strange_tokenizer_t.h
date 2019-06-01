#ifndef COM_ONEISH_STRANGE_TOKENIZER_T_H
#define COM_ONEISH_STRANGE_TOKENIZER_T_H

namespace strange
{

template <typename _ABSTRACTION_ = range_a<>>
class tokenizer_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = forward_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline forward_const_iterator_data_a<ITERATOR> val(river_a<> const& river, F&& it)
		{
			return forward_const_iterator_data_a<ITERATOR>{ const_iterator_t(river, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::tokenizer::const_iterator");
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
		range_a<> _river;
		mutable token_a<> _token;

		template <typename F>
		inline const_iterator_t(river_a<> const& river, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _river(river, true)
			, _token{ token_t<>::val_() }
		{}
	};

public: ___STRANGE_RANGE___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::tokenizer::val passed empty range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::tokenizer::val passed non-river");
		}
		return val_(cast<river_a<>>(river));
	}

	static inline range_a<> val_(river_a<> const& river)
	{
		return range_a<>{ tokenizer_t(river) };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<tokenizer_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<tokenizer_t<>>::share(shoal);
	}

	// range
	inline forward_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::val(_river, _river.cbegin_());
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::val(_river, _river.cend_());
	}

protected:
	river_a<> _river;

	inline tokenizer_t(river_a<> const& river)
		: thing_t{}
		, _river(river)
	{}
};

} // namespace strange

#endif
