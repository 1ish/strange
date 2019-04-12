#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

namespace strange
{

template <typename CAT>
class Something : public Thing<CAT>
{
public:
	// function
	inline thing_ operator()(const void* identity, thing_ range) const
	{
		return Everything<>::val_(); //TODO
	}

	inline thing_ operator()(void* identity, thing_ range) const
	{
		return Everything<>::val_(); //TODO
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
