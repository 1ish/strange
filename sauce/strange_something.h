#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

namespace strange
{

template <typename CAT>
class Something : public Thing<CAT>
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

	// comparison
	inline thing_ something(thing_) const
	{
		return something_();
	}

	inline thing_ something_() const
	{
		return Everything<>::ref();
	}

	inline bool something__() const
	{
		return true;
	}

protected:
	inline Something()
		: Thing{}
	{}
};

} // namespace strange

#endif
