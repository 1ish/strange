#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

#include "strange_thing_.h"
#include "strange_everything.h"

namespace strange
{

class Nothing
{
public:
	static inline thing_& val(thing_ _ = thing_{})
	{
		static thing_ VAL = Nothing{};
		return VAL;
	}

	// function
	inline thing_ mutate(thing_)
	{
		return Nothing::val();
	}

	inline thing_ extract(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ operator()(thing_)
	{
		return Nothing::val();
	}

	inline thing_ operator()(thing_) const
	{
		return Nothing::val();
	}

	// comparison
	inline thing_ same(thing_ thing) const
	{
		return thing.is_nothing_() ? Everything::val() : Nothing::val();
	}

	inline thing_ different(thing_ thing) const
	{
		return thing.is_something_() ? Everything::val() : Nothing::val();
	}

	inline bool operator==(thing_ thing) const
	{
		return thing.is_nothing_();
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing.is_something_();
	}

	inline thing_ is_something(thing_) const
	{
		return Nothing::val();
	}

	inline bool is_something_() const
	{
		return false;
	}

	inline thing_ is_nothing(thing_) const
	{
		return Everything::val();
	}

	inline bool is_nothing_() const
	{
		return true;
	}

	// range
	inline thing_ begin(thing_)
	{
		return Nothing::val();
	}

	inline thing_ cbegin(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ end(thing_)
	{
		return Nothing::val();
	}

	inline thing_ cend(thing_) const
	{
		return Nothing::val();
	}

	// iterator
	inline thing_ set(thing_ thing)
	{
		return Nothing::val();
	}

	inline thing_ get(thing_) const
	{
		return Nothing::val();
	}

	inline thing_& operator*()
	{
		return Nothing::val();
	}

	inline const thing_& operator*() const
	{
		return Nothing::val();
	}

	inline thing_* operator->()
	{
		return &Nothing::val();
	}

	inline const thing_* operator->() const
	{
		return &Nothing::val();
	}

	inline thing_ increment(thing_)
	{
		return Nothing::val();
	}

	inline thing_& operator++()
	{
		return Nothing::val();
	}

private:
	inline Nothing() {};
};

} // namespace strange

#endif
