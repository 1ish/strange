#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

namespace strange
{

template <typename THING_>
class Something : public Thing<THING_>
{
public:
	// function
	inline thing_ operator()(thing_ range) const
	{
		return Everything<>::ref(); //TODO
	}

	inline thing_ operator()(thing_ range)
	{
		return Everything<>::ref(); //TODO
	}

protected:
	inline Something()
		: Thing{}
	{}
};

} // namespace strange

#endif
