#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = range_a<>>
class range_t : public thing_t<_ABSTRACTION_>
{
public:
	// override
	using over = range_o<range_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return val_();
		}
		any_a<> begin = *it;
		if (!check<forward_const_iterator_a<>>(begin))
		{
			throw dis("strange::range::val passed non-iterator begin");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::range::val passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_const_iterator_a<>>(end))
		{
			throw dis("strange::range::val passed non-iterator end");
		}
		return val_(cast<forward_const_iterator_a<>>(begin), cast<forward_const_iterator_a<>>(end));
	}

	static inline range_a<> val_()
	{
		static range_a<> VAL = range_t<>::val_(it_t<true>::val_(), it_t<true>::val_());
		return VAL;
	}

	static inline range_a<> val_(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
	{
		return range_a<>{ over{ range_t<>(begin, end) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<range_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<range_t<>>::share(shoal);
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

	inline range_t(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
		: thing_t{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___range_t_share___;
};

template <typename _ABSTRACTION_>
bool const range_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	range_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
