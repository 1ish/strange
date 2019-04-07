#ifndef COM_ONEISH_STRANGE_ANYTHING_H
#define COM_ONEISH_STRANGE_ANYTHING_H

namespace strange
{

template <typename THING_>
class Anything : public Thing<THING_>
{
public:
	// function
	inline thing_ extract(thing_ range) const
	{
		return operator()(range);
	}

	inline thing_ operator()(thing_ range) const
	{
		return Everything<>::ref(); //TODO
	}

	inline thing_ mutate(thing_ range)
	{
		return operator()(range);
	}

	inline thing_ operator()(thing_ range)
	{
		return Everything<>::ref(); //TODO
	}

protected:
	inline Anything()
		: Thing{}
	{}
};

} // namespace strange

#endif
