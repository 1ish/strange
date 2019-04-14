#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

namespace strange
{

template <typename CAT_>
class Something : public Thing<CAT_>
{
public:
	// function
	inline thing_ operator()(thing_ thing, thing_ range) const
	{
		//TODO
		// operation = thing.operations_().at(range.1st);
		// return operate_(thing, operation, range.2nd...);
		return Nothing<>::val_();
	}

	// comparison
	inline thing_ something(thing_) const
	{
		return something_();
	}

	inline thing_ something_() const
	{
		return Everything<>::val_();
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
