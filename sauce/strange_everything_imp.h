#ifndef COM_ONEISH_STRANGE_EVERYTHING_IMP_H
#define COM_ONEISH_STRANGE_EVERYTHING_IMP_H

#include "strange_everything.h"

namespace strange
{

inline Thing Everything::same(Thing thing) const
{
	return thing.is_something_() ? Everything::val() : Nothing::val();
}

inline Thing Everything::different(Thing thing) const
{
	return thing.is_nothing_() ? Everything::val() : Nothing::val();
}

inline Thing Everything::is_nothing(Thing _) const
{
	return Nothing::val();
}

} // namespace strange

#endif
