#ifndef COM_ONEISH_STRANGE_RANGE_H
#define COM_ONEISH_STRANGE_RANGE_H

namespace strange
{

template <typename THING_ = thing_, bool NOTHING = false>
class Range : public Something<THING_>
{
public:
	// range
	inline thing_ cbegin() const
	{
		return It<>::val_(me_());
	}

	inline thing_ begin()
	{
		return It<>::val_(me_());
	}

	inline thing_ cend() const
	{
		return Nothing<>::ref();
	}

	inline thing_ end()
	{
		return Nothing<>::ref();
	}

protected:
	inline Range()
		: Something{}
	{}
};

template <typename THING_>
class Range<THING_, true> : public Something<THING_>
{
public:
	// range
	inline thing_ cbegin() const
	{
		return It<thing_, Everything<>>::val_(Nothing<>::ref());
	}

	inline thing_ begin()
	{
		return It<thing_, Everything<>>::val_(Nothing<>::ref());
	}

	inline thing_ cend() const
	{
		return Everything<>::ref();
	}

	inline thing_ end()
	{
		return Everything<>::ref();
	}

protected:
	inline Range()
		: Something{}
	{}
};

} // namespace strange

#endif
