#ifndef COM_ONEISH_STRANGE_ONE_T_H
#define COM_ONEISH_STRANGE_ONE_T_H

namespace strange
{

class one_t
{
public:
	// erasure
	inline void ___weak___(any_a::___WEAK___ weak) const
	{
		_meek = std::move(weak);
	}

	// conversion
	inline operator bool() const
	{
		return anything__();
	}

	// identification
	inline const void* identity__() const
	{
		return this;
	}

	inline bool identical__(any_a thing) const
	{
		return thing.identity__() == identity__();
	}

	// comparison
	static inline bool nothing__()
	{
		return false;
	}

	static inline bool anything__()
	{
		return true;
	}

	static inline bool something__()
	{
		return false;
	}

	static inline bool everything__()
	{
		return false;
	}

	inline bool operator==(any_a thing) const
	{
		return identical__(std::move(thing));
	}

	inline bool operator!=(any_a thing) const
	{
		return !identical__(std::move(thing));
	}

	inline std::size_t hash__() const
	{
		return std::hash<const void*>{}(identity__());
	}

	static inline bool is__(const std::string& s)
	{
		return false;
	}

protected:
	mutable any_a::___WEAK___ _meek;

	// construction
	inline one_t() {};
};

} // namespace strange

#endif
