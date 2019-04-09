#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

namespace strange
{

template <typename THING_>
class Thing : public One
{
public:
	// erasure
	inline const THING_ me_() const
	{
		return THING_(_meek.lock(), true);
	}

	inline THING_ me_()
	{
		return THING_(_meek.lock(), true);
	}

	// identification
	inline thing_ identical(thing_ range) const
	{
		const auto it = range.cbegin();
		assert(it != range.cend()); //TODO throw
		return identical_(*it);
	}

	inline thing_ identical_(thing_ thing) const
	{
		return _boole_(identical__(thing));
	}

	// comparison
	inline thing_ nothing(thing_) const
	{
		return nothing_();
	}

	inline thing_ nothing_() const
	{
		return Nothing<>::ref();
	}

	inline thing_ anything(thing_) const
	{
		return anything_();
	}

	inline thing_ anything_() const
	{
		return Everything<>::ref();
	}

	inline thing_ something(thing_) const
	{
		return something_();
	}

	inline thing_ something_() const
	{
		return Nothing<>::ref();
	}

	inline thing_ everything(thing_) const
	{
		return everything_();
	}

	inline thing_ everything_() const
	{
		return Nothing<>::ref();
	}

	// range
	inline thing_ cbegin() const
	{
		return It<true>::val_(me_());
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

	// iterator
	inline thing_& operator*() const
	{
		return Nothing<>::val();
	}

	inline void operator++()
	{}

	inline void operator++(int)
	{}

protected:
	// construction
	inline Thing()
		: One{}
	{}

	// conversion
	static inline thing_ _boole_(bool b)
	{
		return b ? Everything<>::ref() : Nothing<>::ref();
	}
};

// adaptation
#define ___THING___ \
inline thing_ extract(thing_ range) const \
{ \
	return operator()(range); \
} \
inline thing_ mutate(thing_ range) \
{ \
	return operator()(range); \
} \
inline thing_ same(thing_ range) const \
{ \
	const auto it = range.cbegin(); \
	assert(it != range.cend()); \
	return same_(*it); \
} \
inline thing_ same_(thing_ thing) const \
{ \
	return _boole_(operator==(thing)); \
} \
inline thing_ different(thing_ range) const \
{ \
	const auto it = range.cbegin(); \
	assert(it != range.cend()); \
	return different_(*it); \
} \
inline thing_ different_(thing_ thing) const \
{ \
	return _boole_(operator!=(thing)); \
} \
inline thing_ hash(thing_) const \
{ \
	return hash_(); \
} \
inline thing_ hash_() const \
{ \
	return Everything<>::ref(); /* //TODO */ \
} \
inline thing_ beget(thing_) const \
{ \
	return beget_(); \
} \
inline thing_ beget_() const \
{ \
	return cbegin(); \
} \
inline thing_ beset(thing_) \
{ \
	return beset_(); \
} \
inline thing_ beset_() \
{ \
	return begin(); \
} \
inline thing_ enget(thing_) const \
{ \
	return enget_(); \
} \
inline thing_ enget_() const \
{ \
	return cend(); \
} \
inline thing_ enset(thing_) \
{ \
	return enset_(); \
} \
inline thing_ enset_() \
{ \
	return end(); \
} \
inline thing_ get(thing_) const \
{ \
	return get_(); \
} \
inline thing_ get_() const \
{ \
	return operator*(); \
} \
inline thing_ set(thing_ range) const \
{ \
	const auto it = range.cbegin(); \
	assert(it != range.cend()); \
	return set_(*it); \
} \
inline thing_ set_(thing_ thing) const \
{ \
	return operator*() = thing; \
} \
inline thing_* operator->() const \
{ \
	return &operator*(); \
} \
inline thing_ increment(thing_) \
{ \
	return increment_(); \
} \
inline thing_ increment_() \
{ \
	operator++(); \
	return me_(); \
} \

} // namespace strange

#endif
