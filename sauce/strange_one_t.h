#ifndef COM_ONEISH_STRANGE_ONE_T_H
#define COM_ONEISH_STRANGE_ONE_T_H

namespace strange
{

class one_t
{
public:
	// erasure
	inline void ___weak___(any_a::___WEAK___ const& weak) const
	{
		_meek = weak;
	}

	// conversion
	inline operator bool() const
	{
		return anything__();
	}

	// identification
	inline void const* identity__() const
	{
		return this;
	}

	inline bool identical__(any_a const& thing) const
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

	inline bool operator==(any_a const& thing) const
	{
		return identical__(thing);
	}

	inline bool operator!=(any_a const& thing) const
	{
		return !identical__(thing);
	}

	inline std::size_t hash__() const
	{
		return std::hash<void const*>{}(identity__());
	}

	static inline bool is__(std::string const& s)
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
