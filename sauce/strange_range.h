#ifndef COM_ONEISH_STRANGE_RANGE_H
#define COM_ONEISH_STRANGE_RANGE_H

namespace strange
{

template <typename THING_ = thing_>
class Range : public Something<THING_>
{
public:
	// range
	inline thing_ cbegin() const
	{
		return It<>::val_(me_());
	}

	inline thing_ begin()
	{
		return It<>::val_(me_());
	}

	inline thing_ cend() const
	{
		return Nothing<>::ref();
	}

	inline thing_ end()
	{
		return Nothing<>::ref();
	}

protected:
	inline Range()
		: Something{}
	{}
};

} // namespace strange

#endif
