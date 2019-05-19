#ifndef COM_ONEISH_STRANGE_ONE_T_H
#define COM_ONEISH_STRANGE_ONE_T_H

namespace strange
{

class one_t
{
public:
	// erasure
	inline void ___weak___(any_a<>::___WEAK___ const& weak) const
	{
		_meek = weak;
	}

	// conversion
	inline operator bool() const
	{
		return something();
	}

	// identification
	inline void const* identity() const
	{
		return this;
	}

	inline bool identical(any_a<> const& thing) const
	{
		return thing.identity() == identity();
	}

	// comparison
	static inline bool nothing()
	{
		return false;
	}

	static inline bool something()
	{
		return true;
	}

	static inline bool anything()
	{
		return false;
	}

	static inline bool everything()
	{
		return false;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return identical(thing);
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !identical(thing);
	}

	inline std::size_t hash() const
	{
		return std::hash<void const*>{}(identity());
	}

	static inline bool is(std::string const& s)
	{
		return false;
	}

protected:
	mutable any_a<>::___WEAK___ _meek;

	// construction
	inline one_t() {};
};

} // namespace strange

#endif
