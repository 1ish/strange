#ifndef COM_ONEISH_STRANGE_ONE_H
#define COM_ONEISH_STRANGE_ONE_H

#include "strange_thing_.h"

namespace strange
{

class One
{
protected:
	const decltype(thing_().weak_()) _meek;

	inline One(const thing_& me)
		: _meek(me.weak_())
	{}
};

} // namespace strange

#endif
