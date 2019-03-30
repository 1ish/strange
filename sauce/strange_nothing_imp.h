#ifndef COM_ONEISH_STRANGE_NOTHING_IMP_H
#define COM_ONEISH_STRANGE_NOTHING_IMP_H

#include "strange_nothing.h"

namespace strange
{

inline thing_ Nothing::same(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return other.get().is_nothing_() ? Everything::val() : Nothing::val();
}

inline thing_ Nothing::different(thing_ range) const
{
	const auto other = range.cbegin();
	assert(other != range.cend()); //TODO throw
	return other.get().is_something_() ? Everything::val() : Nothing::val();
}

} // namespace strange

#endif
