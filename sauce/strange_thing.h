#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

#include "strange_thing_.h"
#include "strange_one.h"

namespace strange
{

template <typename THING_>
class Thing : public One
{
public:
	const THING_ me_() const
	{
		return THING_(_meek.lock(), true);
	}

	THING_ me_()
	{
		return THING_(_meek.lock(), true);
	}

protected:
	inline Thing(const thing_& me)
		: One(me)
	{}

	static inline thing_ _boole_(bool b)
	{
		return b ? Everything<>::ref() : Nothing<>::ref();
	}
};

} // namespace strange

#endif
