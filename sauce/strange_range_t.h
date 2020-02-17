#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

// template <typename ___ego___ = range_a<>>
template <typename ___ego___>
class range_t : public thing_t<___ego___>
{
public:
	// override
	using over = range_o<range_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return create_();
		}
		any_a<> begin = *it;
		if (!check<forward_const_iterator_a<>>(begin))
		{
			throw dis("strange::range::create passed non-iterator begin");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::range::create passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_const_iterator_a<>>(end))
		{
			throw dis("strange::range::create passed non-iterator end");
		}
		return create_(cast<forward_const_iterator_a<>>(begin), cast<forward_const_iterator_a<>>(end));
	}

	static inline range_a<> create_()
	{
		static range_a<> VAL = range_t<>::create_(it_t<>::create_(), it_t<>::create_());
		return VAL;
	}

	static inline range_a<> create_(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
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
		: thing_t<___ego___>{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___range_t_share___;
};

template <typename ___ego___>
bool const range_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	range_t<___ego___>::share(shoal);
	return shoal;
}();

inline range_a<> range_create()
{
	return range_t<>::create_();
}

inline range_a<> range_create(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
{
	return range_t<>::create_(begin, end);
}

} // namespace strange

#endif
