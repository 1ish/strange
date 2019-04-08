#ifndef COM_ONEISH_STRANGE_ONE_H
#define COM_ONEISH_STRANGE_ONE_H

namespace strange
{

class One
{
public:
	// erasure
	inline void ___weak___(thing_::___WEAK___ weak) const
	{
		_meek = weak;
	}

	// conversion
	inline operator bool() const
	{
		return true;
	}

	// identification
	inline const void* identity__() const
	{
		return this;
	}

	inline bool identical__(thing_ thing) const
	{
		return thing.identity__() == identity__();
	}

	// comparison
	inline bool operator==(thing_ thing) const
	{
		return identical__(thing);
	}

	inline bool operator!=(thing_ thing) const
	{
		return !identical__(thing);
	}

	inline size_t hash__() const
	{
		return std::hash<const void*>{}(identity__());
	}

protected:
	mutable thing_::___WEAK___ _meek;

	// construction
	inline One() {};
};

} // namespace strange

#endif
