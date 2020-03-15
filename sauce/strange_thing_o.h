#ifndef COM_ONEISH_STRANGE_THING_O_H
#define COM_ONEISH_STRANGE_THING_O_H

namespace strange
{
	
template <typename _OVERRIDDEN_>
class thing_o : public _OVERRIDDEN_
{
public:
	inline thing_o(_OVERRIDDEN_&& overridden)
		: _OVERRIDDEN_{ std::move(overridden) }
	{}
};

} // namespace strange

#endif
