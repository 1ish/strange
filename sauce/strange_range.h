#ifndef COM_ONEISH_STRANGE_RANGE_H
#define COM_ONEISH_STRANGE_RANGE_H

namespace strange
{

template <typename THING_ = thing_, bool NOTHING = false>
class Range : public Something<THING_>
{
public:
	// range
	inline thing_ beget(thing_) const
	{
		return beget_();
	}

	inline thing_ beget_() const
	{
		return cbegin();
	}

	inline thing_ cbegin() const
	{
		return It<>::val_(me_());
	}

	inline thing_ beset(thing_)
	{
		return beset_();
	}

	inline thing_ beset_()
	{
		return begin();
	}

	inline thing_ begin()
	{
		return It<>::val_(me_());
	}

	inline thing_ enget(thing_) const
	{
		return enget_();
	}

	inline thing_ enget_() const
	{
		return cend();
	}

	inline thing_ cend() const
	{
		return Nothing<>::ref();
	}

	inline thing_ enset(thing_)
	{
		return enset_();
	}

	inline thing_ enset_()
	{
		return end();
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
	inline thing_ beget(thing_) const
	{
		return beget_();
	}

	inline thing_ beget_() const
	{
		return cbegin();
	}

	inline thing_ cbegin() const
	{
		return It<thing_, Everything<>>::val_(Nothing<>::ref());
	}

	inline thing_ beset(thing_)
	{
		return beset_();
	}

	inline thing_ beset_()
	{
		return begin();
	}

	inline thing_ begin()
	{
		return It<thing_, Everything<>>::val_(Nothing<>::ref());
	}

	inline thing_ enget(thing_) const
	{
		return enget_();
	}

	inline thing_ enget_() const
	{
		return cend();
	}

	inline thing_ cend() const
	{
		return Everything<>::ref();
	}

	inline thing_ enset(thing_)
	{
		return enset_();
	}

	inline thing_ enset_()
	{
		return end();
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
