#ifndef COM_ONEISH_STRANGE_SOMETHING_H
#define COM_ONEISH_STRANGE_SOMETHING_H

namespace strange
{

template <typename CAT_>
class Something : public Thing<CAT_>
{
public:
	// function
	inline any_a operator()(any_a thing, any_a range) const
	{
		//TODO
		// operation = thing.operations_().at(range.1st);
		// return operate_(thing, operation, range.2nd...);
		return Nothing<>::val_();
	}

	// comparison
	static inline any_a something(any_a)
	{
		return something_();
	}

	static inline any_a something_()
	{
		return Everything<>::val_();
	}

	static inline bool something__()
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
