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

	// exposure
	inline one_t const& extract_thing() const
	{
		return *this;
	}

	inline one_t& mutate_thing()
	{
		return *this;
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

	inline bool operator==(any_a<> const& thing) const
	{
		return identical(thing);
	}

	inline std::size_t hash() const
	{
		return std::hash<void const*>{}(identity());
	}

	static inline bool is(std::string const& s)
	{
		return false;
	}

	// operators
	inline void operator+=(any_a<> const& other)
	{}

	inline void operator-=(any_a<> const& other)
	{}

	inline void operator*=(any_a<> const& other)
	{}

	inline void operator/=(any_a<> const& other)
	{}

	inline void operator%=(any_a<> const& other)
	{}

protected:
	any_a<>::___WEAK___ mutable _meek;

	// construction
	inline one_t() {};
};

} // namespace strange

#endif
