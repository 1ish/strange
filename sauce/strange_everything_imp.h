#ifndef COM_ONEISH_STRANGE_EVERYTHING_IMP_H
#define COM_ONEISH_STRANGE_EVERYTHING_IMP_H

#include "strange_everything.h"

namespace strange
{

inline thing_ Everything::same(thing_ thing) const
{
	return thing.is_something_() ? Everything::val() : Nothing::val();
}

inline thing_ Everything::different(thing_ thing) const
{
	return thing.is_nothing_() ? Everything::val() : Nothing::val();
}

inline thing_ Everything::is_nothing(thing_ _) const
{
	return Nothing::val();
}

} // namespace strange

#endif
