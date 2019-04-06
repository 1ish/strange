#ifndef COM_ONEISH_STRANGE_ONE_H
#define COM_ONEISH_STRANGE_ONE_H

namespace strange
{

class One
{
protected:
	const decltype(thing_().weak_()) _meek; //TODO this doesn't work

	inline One(const thing_& me)
		: _meek(me.weak_())
	{}
};

} // namespace strange

#endif
