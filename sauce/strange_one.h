#ifndef COM_ONEISH_STRANGE_ONE_H
#define COM_ONEISH_STRANGE_ONE_H

namespace strange
{

class One
{
public:
	inline void ___weak___(thing_::___WEAK___ weak) const
	{
		_meek = weak;
	}

	inline const void* identity__() const
	{
		return this;
	}

	inline bool identical__(thing_ thing) const
	{
		return thing.identity__() == identity__();
	}

protected:
	inline One() {};

	mutable thing_::___WEAK___ _meek;
};

} // namespace strange

#endif
