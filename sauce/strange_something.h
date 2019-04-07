#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

namespace strange
{

template <typename THING_, bool NOTHING = false>
class Something : public Anything<THING_>
{
public:
	// conversion
	inline operator bool() const
	{
		return true;
	}

	inline thing_ something(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ something_() const
	{
		return Everything<>::ref();
	}

	inline thing_ nothing(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ nothing_() const
	{
		return Nothing<>::ref();
	}

protected:
	inline Something()
		: Anything{}
	{}
};

template <typename THING_>
class Something<THING_, true> : public Anything<THING_>
{
public:
	// conversion
	inline operator bool() const
	{
		return false;
	}

	inline thing_ something(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ something_() const
	{
		return Nothing<>::ref();
	}

	inline thing_ nothing(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ nothing_() const
	{
		return Everything<>::ref();
	}

protected:
	inline Something()
		: Anything{}
	{}
};

} // namespace strange

#endif
