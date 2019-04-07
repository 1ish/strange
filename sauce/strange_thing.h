#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

namespace strange
{

template <typename THING_>
class Thing : public One
{
public:
	inline const THING_ me_() const
	{
		return THING_(_meek.lock(), true);
	}

	inline THING_ me_()
	{
		return THING_(_meek.lock(), true);
	}

protected:
	inline Thing()
		: One{}
	{}

	static inline thing_ _boole_(bool b)
	{
		return b ? Everything<>::ref() : Nothing<>::ref();
	}
};

} // namespace strange

#endif
