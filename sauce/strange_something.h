#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

#include "strange_thing_.h"
#include "strange_anything.h"

namespace strange
{

template <typename THING_, bool SOMETHING = true>
class Something : public Anything<THING_>
{
public:
	// conversion
	inline operator bool() const
	{
		return SOMETHING;
	}

	inline thing_ is_something(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ is_something_() const
	{
		return Everything<>::ref();
	}

	inline thing_ is_nothing(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ is_nothing_() const
	{
		return Nothing<>::ref();
	}

protected:
	inline Something(const thing_& me)
		: Anything{ me }
	{};
};

template <typename THING_>
class Something<THING_, false> : public Anything<THING_>
{
public:
	// conversion
	inline operator bool() const
	{
		return false;
	}

	inline thing_ is_something(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ is_something_() const
	{
		return Nothing<>::ref();
	}

	inline thing_ is_nothing(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ is_nothing_() const
	{
		return Everything<>::ref();
	}

protected:
	inline Something(const thing_& me)
		: Anything{ me }
	{};
};

} // namespace strange

#endif
