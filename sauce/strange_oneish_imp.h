#ifndef COM_ONEISH_STRANGE_ONEISH_IMP_H
#define COM_ONEISH_STRANGE_ONEISH_IMP_H

#include "strange_oneish.h"

namespace strange
{

inline Thing Oneish::same(Thing thing) const
{
	return thing.is_something_() ? oneish_() : Nothing::nothing_();
}

inline Thing Oneish::different(Thing thing) const
{
	return thing.is_nothing_() ? oneish_() : Nothing::nothing_();
}

inline Thing Oneish::is_nothing(Thing thing) const
{
	return Nothing::nothing_();
}

} // namespace strange

#endif
