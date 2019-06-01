#ifndef COM_ONEISH_STRANGE_TOKENIZER_T_H
#define COM_ONEISH_STRANGE_TOKENIZER_T_H

namespace strange
{

template <typename _ABSTRACTION_ = range_a<>>
class tokenizer_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_RANGE___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::tokenizer::val passed empty range");
		}
		any_a<> begin = *it;
		if (!check<forward_const_iterator_a<>>(begin))
		{
			throw dis("strange::tokenizer::val passed non-iterator begin");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::tokenizer::val passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_const_iterator_a<>>(end))
		{
			throw dis("strange::tokenizer::val passed non-iterator end");
		}
		return val_(cast<forward_const_iterator_a<>>(begin), cast<forward_const_iterator_a<>>(end));
	}

	static inline range_a<> val_(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
	{
		return range_a<>{ tokenizer_t(begin, end) };
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
		return _begin;
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return _end;
	}

protected:
	forward_const_iterator_a<> _begin;
	forward_const_iterator_a<> _end;

	inline tokenizer_t(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
		: thing_t{}
		, _begin(begin)
		, _end(end)
	{}
};

} // namespace strange

#endif
