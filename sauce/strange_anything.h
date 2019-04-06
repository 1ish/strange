#ifndef COM_ONEISH_STRANGE_ANYTHING_H
#define COM_ONEISH_STRANGE_ANYTHING_H

#include "strange_thing_.h"
#include "strange_thing.h"

namespace strange
{

template <typename THING_>
class Anything : public Thing<THING_>
{
public:
	// function
	inline thing_ extract(thing_ range) const
	{
		return Everything<>::ref();
	}

	inline thing_ operator()(thing_ range) const
	{
		return Everything<>::ref();
	}

	inline thing_ mutate(thing_ range)
	{
		return Everything<>::ref();
	}

	inline thing_ operator()(thing_ range)
	{
		return Everything<>::ref();
	}

protected:
	inline Anything(const thing_& me)
		: Thing{ me }
	{};
};

} // namespace strange

#endif
