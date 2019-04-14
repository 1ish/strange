#ifndef COM_ONEISH_STRANGE_RANGE_H
#define COM_ONEISH_STRANGE_RANGE_H

namespace strange
{

template <typename CAT = thing_>
class Range : public Something<CAT>
{
public: ___THING___
	// construction
	static inline thing_ val(thing_ range)
	{
		thing_ it = range.cbegin();
		assert(it != range.cend());
		thing_ begin = *it;
		++it;
		assert(it != range.cend());
		return val_(begin, *it);
	}

	static inline thing_ val_(thing_ begin, thing_ end)
	{
		return thing_{ Range(begin, end) };
	}

	static inline thing_ ref(thing_ range)
	{
		thing_ it = range.cbegin();
		assert(it != range.cend());
		thing_ begin = *it;
		++it;
		assert(it != range.cend());
		return ref_(begin, *it);
	}

	static inline thing_ ref_(thing_ begin, thing_ end)
	{
		return thing_(Range(begin, end), true);
	}

	// range
	inline thing_ cbegin() const
	{
		return _begin;
	}

	inline thing_ begin()
	{
		return _begin;
	}

	inline thing_ cend() const
	{
		return _end;
	}

	inline thing_ end()
	{
		return _end;
	}

protected:
	thing_ _begin;
	thing_ _end;

	inline Range(thing_ begin, thing_ end)
		: Something{}
		, _begin(begin)
		, _end(end)
	{}
};

} // namespace strange

#endif
