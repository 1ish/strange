#ifndef COM_ONEISH_STRANGE_EVERYTHING_IMP_H
#define COM_ONEISH_STRANGE_EVERYTHING_IMP_H

#include "strange_everything.h"

namespace strange
{

inline thing_ Creature::extract(thing_ range) const
{
	me_().hash_();//TODO
	return Everything::val();
}

inline thing_ Creature::operator()(thing_ range) const
{
	return Everything::val();
}

inline thing_ Creature::mutate(thing_ range)
{
	return Everything::val();
}

inline thing_ Creature::operator()(thing_ range)
{
	return Everything::val();
}

inline thing_ Everything::same(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return (*other) ? Everything::val() : Nothing::val();
}

inline thing_ Everything::same_(thing_ thing) const
{
	return thing ? Everything::val() : Nothing::val();
}

inline thing_ Everything::different(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return (!*other) ? Everything::val() : Nothing::val();
}

inline thing_ Everything::different_(thing_ thing) const
{
	return (!thing) ? Everything::val() : Nothing::val();
}

inline thing_ Everything::is_nothing(thing_) const
{
	return Nothing::val();
}

inline thing_ Everything::is_nothing_() const
{
	return Nothing::val();
}

} // namespace strange

#endif
