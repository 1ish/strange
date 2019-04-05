#ifndef COM_ONEISH_STRANGE_EVERYTHING_IMP_H
#define COM_ONEISH_STRANGE_EVERYTHING_IMP_H

#include "strange_everything.h"

namespace strange
{

template <typename THING_>
inline thing_ Creature<THING_>::extract(thing_ range) const
{
	me_().hash_();//TODO
	return Everything<>::val();
}

template <typename THING_>
inline thing_ Creature<THING_>::operator()(thing_ range) const
{
	return Everything<>::val();
}

template <typename THING_>
inline thing_ Creature<THING_>::mutate(thing_ range)
{
	return Everything<>::val();
}

template <typename THING_>
inline thing_ Creature<THING_>::operator()(thing_ range)
{
	return Everything<>::val();
}

template <typename THING_>
inline thing_ Everything<THING_>::same(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return (*other) ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Everything<THING_>::same_(thing_ thing) const
{
	return thing ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Everything<THING_>::different(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return (!*other) ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Everything<THING_>::different_(thing_ thing) const
{
	return (!thing) ? Everything<>::val() : Nothing<>::val();
}

template <typename THING_>
inline thing_ Everything<THING_>::is_nothing(thing_) const
{
	return Nothing<>::val();
}

template <typename THING_>
inline thing_ Everything<THING_>::is_nothing_() const
{
	return Nothing<>::val();
}

} // namespace strange

#endif
