#ifndef COM_ONEISH_STRANGE_NOTHING_IMP_H
#define COM_ONEISH_STRANGE_NOTHING_IMP_H

#include "strange_nothing.h"

namespace strange
{

template <typename THING_>
inline thing_ Nothing<THING_>::same(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return (!*other) ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Nothing<THING_>::same_(thing_ thing) const
{
	return (!thing) ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Nothing<THING_>::different(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return (*other) ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Nothing<THING_>::different_(thing_ thing) const
{
	return thing ? Everything<>::val() : Nothing<>::val();
}

} // namespace strange

#endif
