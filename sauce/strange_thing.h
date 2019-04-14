#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

namespace strange
{

template <typename CAT_>
class Thing : public One
{
public:
	// erasure
	inline const CAT_ me_() const
	{
		return CAT_(_meek.lock(), true);
	}

	inline CAT_ me_()
	{
		return CAT_(_meek.lock(), true);
	}

	// reflection
	static inline cat_ category_()
	{
		static cat_ CATEGORY = Cat<>::val_(sym__(std::string("strange") + CAT_::___struct_name___()));
		return CATEGORY;
	}

	static inline thing_ eater_()
	{
		return Nothing<>::val_();
	}

	static inline thing_ feeder(thing_ range)
	{
		return Nothing<>::val_();
	}

	// visitor pattern
	static inline thing_ visit(thing_ range)
	{
		thing_ it = range.cbegin();
		assert(it != range.cend()); //TODO
		thing_ visitor = *it;
		return visitor->invoke(Range<>::val_(++it, range.cend())); //TODO me_() must already be in range
	}

	// function
	inline thing_ invoke(thing_ range) const
	{
		thing_ it = range.cbegin();
		assert(it != range.cend()); //TODO
		thing_ member = *it;
		return invoke_(member, Range<>::val_(++it, range.cend()));
	}

	inline thing_ invoke_(thing_ member, thing_ range) const
	{
		//TODO
		// thing = me_();
		// operation = thing.operations_().at(member);
		// return operate_(thing, operation, range);
		return Nothing<>::val_();
	}

	static inline thing_ operate(thing_ range)
	{
		thing_ it = range.cbegin();
		assert(it != range.cend()); //TODO
		thing_ thing = *it;
		++it;
		assert(it != range.cend()); //TODO
		thing_ operation = *it;
		return operate_(thing, operation, Range<>::val_(++it, range.cend()));
	}

	static inline thing_ operate_(thing_ thing, thing_ operation, thing_ range)
	{
		return operation.operator()(thing, range);
	}

	// identification
	inline thing_ identical(thing_ range) const
	{
		thing_ it = range.cbegin();
		assert(it != range.cend()); //TODO
		return identical_(*it);
	}

	inline thing_ identical_(thing_ thing) const
	{
		return _boole_(identical__(thing));
	}

	// comparison
	static inline thing_ nothing(thing_)
	{
		return nothing_();
	}

	static inline thing_ nothing_()
	{
		return Nothing<>::val_();
	}

	static inline thing_ anything(thing_)
	{
		return anything_();
	}

	static inline thing_ anything_()
	{
		return Everything<>::val_();
	}

	static inline thing_ something(thing_)
	{
		return something_();
	}

	static inline thing_ something_()
	{
		return Nothing<>::val_();
	}

	static inline thing_ everything(thing_)
	{
		return everything_();
	}

	static inline thing_ everything_()
	{
		return Nothing<>::val_();
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
		return Nothing<>::val_();
	}

	inline thing_ end()
	{
		return Nothing<>::val_();
	}

	// iterator
	inline thing_& operator*() const
	{
		return Nothing<>::val__();
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
		return b ? Everything<>::val_() : Nothing<>::val_();
	}
};

// adaptation
#define ___THING___ \
inline symbol_ type(thing_ _) const \
{ \
	return type_(); \
} \
inline cat_ category(thing_ _) const \
{ \
	return category_(); \
} \
inline thing_ eater(thing_ _) const \
{ \
	return eater_(); \
} \
inline thing_ same(thing_ range) const \
{ \
	thing_ it = range.cbegin(); \
	assert(it != range.cend()); /* //TODO */ \
	return same_(*it); \
} \
inline thing_ same_(thing_ thing) const \
{ \
	return _boole_(operator==(thing)); \
} \
inline thing_ different(thing_ range) const \
{ \
	thing_ it = range.cbegin(); \
	assert(it != range.cend()); /* //TODO */ \
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
	return Everything<>::val_(); /* //TODO */ \
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
	thing_ it = range.cbegin(); \
	assert(it != range.cend()); /* //TODO */ \
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
