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
		const auto it = range.beget_();
		assert(it != range.enget_()); //TODO throw
		return identical_(it.get_());
	}

	inline thing_ identical_(thing_ thing) const
	{
		return _boole_(identical__(thing));
	}

	// comparison
	inline thing_ something(thing_) const
	{
		return something_();
	}

	inline thing_ something_() const
	{
		return Everything<>::ref();
	}

	inline thing_ nothing(thing_) const
	{
		return nothing_();
	}

	inline thing_ nothing_() const
	{
		return Nothing<>::ref();
	}

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
inline thing_ same(thing_ range) const \
{ \
	const auto it = range.beget_(); \
	assert(it != range.enget_()); \
	return same_(it.get_()); \
} \
inline thing_ same_(thing_ thing) const \
{ \
	return _boole_(operator==(thing)); \
} \
inline thing_ different(thing_ range) const \
{ \
	const auto it = range.beget_(); \
	assert(it != range.enget_()); \
	return different_(it.get_()); \
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
	return Everything<>::ref(); \
} \
inline thing_ extract(thing_ range) const \
{ \
	return operator()(range); \
} \
inline thing_ mutate(thing_ range) \
{ \
	return operator()(range); \
} \

} // namespace strange

#endif
