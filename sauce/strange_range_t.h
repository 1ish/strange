#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a>
class range_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline any_a val(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return dis__("empty range passed to strange::range::val");
		}
		any_a begin = *it;
		++it;
		if (it == range.cend())
		{
			return dis__("short range passed to strange::range::val");
		}
		return val_(begin, *it);
	}

	static inline any_a val_(any_a begin, any_a end)
	{
		return any_a{ range_t(begin, end) };
	}

	static inline any_a ref(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return dis__("empty range passed to strange::range::ref");
		}
		any_a begin = *it;
		++it;
		if (it == range.cend())
		{
			return dis__("short range passed to strange::range::ref");
		}
		return ref_(begin, *it);
	}

	static inline any_a ref_(any_a begin, any_a end)
	{
		return any_a(range_t(begin, end), true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::range");
		return TYPE;
	}

	// range
	inline any_a cbegin() const
	{
		return _begin;
	}

	inline any_a begin()
	{
		return _begin;
	}

	inline any_a cend() const
	{
		return _end;
	}

	inline any_a end()
	{
		return _end;
	}

protected:
	any_a _begin;
	any_a _end;

	inline range_t(any_a begin, any_a end)
		: something_t{}
		, _begin(begin)
		, _end(end)
	{}
};

} // namespace strange

#endif
