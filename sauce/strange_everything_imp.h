#ifndef COM_ONEISH_STRANGE_EVERYTHING_IMP_H
#define COM_ONEISH_STRANGE_EVERYTHING_IMP_H

#include "strange_everything.h"

namespace strange
{

inline thing_ Everything::same(thing_ range) const
{
	const auto other = range.cbegin();
	return (other != range.cend() && other.get().is_something_()) ? Everything::val() : Nothing::val();
}

inline thing_ Everything::different(thing_ range) const
{
	const auto other = range.cbegin();
	return (other == range.cend() || other.get().is_nothing_()) ? Everything::val() : Nothing::val();
}

inline thing_ Everything::is_nothing(thing_) const
{
	return Nothing::val();
}

} // namespace strange

#endif
