#ifndef COM_ONEISH_STRANGE_RANGE_H
#define COM_ONEISH_STRANGE_RANGE_H

namespace strange
{

template <typename CAT_ = any_a>
class Range : public Something<CAT_>
{
public: ___THING___
	// construction
	static inline any_a val(any_a range)
	{
		any_a it = range.cbegin();
		assert(it != range.cend());
		any_a begin = *it;
		++it;
		assert(it != range.cend());
		return val_(begin, *it);
	}

	static inline any_a val_(any_a begin, any_a end)
	{
		return any_a{ Range(begin, end) };
	}

	static inline any_a ref(any_a range)
	{
		any_a it = range.cbegin();
		assert(it != range.cend());
		any_a begin = *it;
		++it;
		assert(it != range.cend());
		return ref_(begin, *it);
	}

	static inline any_a ref_(any_a begin, any_a end)
	{
		return any_a(Range(begin, end), true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::Range");
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

	inline Range(any_a begin, any_a end)
		: Something{}
		, _begin(begin)
		, _end(end)
	{}
};

} // namespace strange

#endif
