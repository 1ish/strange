#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class range_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline any_a<> val(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::range::val passed empty range");
		}
		any_a<> begin = *it;
		if (!check_<forward_iterator_a<>>(begin))
		{
			throw dis__("strange::range::val passed non-iterator begin");
		}
		if (++it == range.cend())
		{
			throw dis__("strange::range::val passed short range");
		}
		any_a<> end = *it;
		if (!check_<forward_iterator_a<>>(end))
		{
			throw dis__("strange::range::val passed non-iterator end");
		}
		return val_(cast_<forward_iterator_a<>>(begin), cast_<forward_iterator_a<>>(end));
	}

	static inline any_a<> val_(forward_iterator_a<> const& begin, forward_iterator_a<> const& end)
	{
		return any_a<>{ range_t(begin, end) };
	}

	static inline any_a<> ref(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::range::ref passed empty range");
		}
		any_a<> begin = *it;
		if (!check_<forward_iterator_a<>>(begin))
		{
			throw dis__("strange::range::ref passed non-iterator begin");
		}
		if (++it == range.cend())
		{
			throw dis__("strange::range::ref passed short range");
		}
		any_a<> end = *it;
		if (!check_<forward_iterator_a<>>(end))
		{
			throw dis__("strange::range::ref passed non-iterator end");
		}
		return ref_(cast_<forward_iterator_a<>>(begin), cast_<forward_iterator_a<>>(end));
	}

	static inline any_a<> ref_(forward_iterator_a<> const& begin, forward_iterator_a<> const& end)
	{
		return any_a<>(range_t(begin, end), true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::range");
		return TYPE;
	}

	// range
	inline forward_iterator_a<> cbegin() const
	{
		return _begin;
	}

	inline forward_iterator_a<> begin() const
	{
		return _begin;
	}

	inline forward_iterator_a<> begin()
	{
		return _begin;
	}

	inline forward_iterator_a<> cend() const
	{
		return _end;
	}

	inline forward_iterator_a<> end() const
	{
		return _end;
	}

	inline forward_iterator_a<> end()
	{
		return _end;
	}

protected:
	forward_iterator_a<> _begin;
	forward_iterator_a<> _end;

	inline range_t(forward_iterator_a<> const& begin, forward_iterator_a<> const& end)
		: something_t{}
		, _begin(begin)
		, _end(end)
	{}
};

} // namespace strange

#endif
