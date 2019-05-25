#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

// adaptation
#define ___STRANGE_RANGE___ ___STRANGE_THING___ \
inline any_a<> cbegin__(range_a<> const&) const \
{ \
return cbegin_(); \
} \
inline forward_const_iterator_a<> cbegin_() const \
{ \
return cbegin(); \
} \
inline any_a<> cend__(range_a<> const&) const \
{ \
return cend_(); \
} \
inline forward_const_iterator_a<> cend_() const \
{ \
return cend(); \
} \

template <typename _ABSTRACTION_ = range_a<>>
class range_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_RANGE___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::range::val passed empty range");
		}
		any_a<> begin = *it;
		if (!check<forward_const_iterator_a<>>(begin))
		{
			throw dis("strange::range::val passed non-iterator begin");
		}
		if (++it == range.cend())
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

	static inline range_a<> val_(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
	{
		return range_a<>{ range_t(begin, end) };
	}

	static inline range_a<> ref__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::range::ref passed empty range");
		}
		any_a<> begin = *it;
		if (!check<forward_const_iterator_a<>>(begin))
		{
			throw dis("strange::range::ref passed non-iterator begin");
		}
		if (++it == range.cend())
		{
			throw dis("strange::range::ref passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_const_iterator_a<>>(end))
		{
			throw dis("strange::range::ref passed non-iterator end");
		}
		return ref_(cast<forward_const_iterator_a<>>(begin), cast<forward_const_iterator_a<>>(end));
	}

	static inline range_a<> ref_(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
	{
		return range_a<>(range_t(begin, end), true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::range");
		return TYPE;
	}

	// range
	inline forward_const_iterator_a<> cbegin() const
	{
		return _begin;
	}

	inline forward_const_iterator_a<> begin() const
	{
		return _begin;
	}

	inline forward_const_iterator_a<> cend() const
	{
		return _end;
	}

	inline forward_const_iterator_a<> end() const
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
};

} // namespace strange

#endif
