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
	static inline cat_a cat_()
	{
		static cat_a CATEGORY = Cat<>::val_(sym__(std::string("strange") + CAT_::___abstraction_name___()));
		return CATEGORY;
	}

	static inline any_a eater_()
	{
		return Nothing<>::val_();
	}

	static inline any_a feeder(any_a range)
	{
		return Nothing<>::val_();
	}

	// visitor pattern
	static inline any_a visit(any_a range)
	{
		any_a it = range.cbegin();
		assert(it != range.cend()); //TODO
		any_a visitor = *it;
		return visitor->invoke(Range<>::val_(++it, range.cend())); //TODO me_() must already be in range
	}

	// function
	inline any_a invoke(any_a range) const
	{
		any_a it = range.cbegin();
		assert(it != range.cend()); //TODO
		any_a member = *it;
		return invoke_(member, Range<>::val_(++it, range.cend()));
	}

	inline any_a invoke_(any_a member, any_a range) const
	{
		//TODO
		// thing = me_();
		// operation = thing.operations_().at(member);
		// return operate_(thing, operation, range);
		return Nothing<>::val_();
	}

	static inline any_a operate(any_a range)
	{
		any_a it = range.cbegin();
		assert(it != range.cend()); //TODO
		any_a thing = *it;
		++it;
		assert(it != range.cend()); //TODO
		any_a operation = *it;
		return operate_(thing, operation, Range<>::val_(++it, range.cend()));
	}

	static inline any_a operate_(any_a thing, any_a operation, any_a range)
	{
		return operation.operator()(thing, range);
	}

	// identification
	inline any_a identical(any_a range) const
	{
		any_a it = range.cbegin();
		assert(it != range.cend()); //TODO
		return identical_(*it);
	}

	inline any_a identical_(any_a thing) const
	{
		return _boole_(identical__(thing));
	}

	// comparison
	static inline any_a nothing(any_a)
	{
		return nothing_();
	}

	static inline any_a nothing_()
	{
		return Nothing<>::val_();
	}

	static inline any_a anything(any_a)
	{
		return anything_();
	}

	static inline any_a anything_()
	{
		return Everything<>::val_();
	}

	static inline any_a something(any_a)
	{
		return something_();
	}

	static inline any_a something_()
	{
		return Nothing<>::val_();
	}

	static inline any_a everything(any_a)
	{
		return everything_();
	}

	static inline any_a everything_()
	{
		return Nothing<>::val_();
	}

	// range
	inline any_a cbegin() const
	{
		return It<true>::val_(me_());
	}

	inline any_a begin()
	{
		return It<>::val_(me_());
	}

	inline any_a cend() const
	{
		return Nothing<>::val_();
	}

	inline any_a end()
	{
		return Nothing<>::val_();
	}

	// iterator
	inline any_a& operator*() const
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
	static inline any_a _boole_(bool b)
	{
		return b ? Everything<>::val_() : Nothing<>::val_();
	}
};

// adaptation
#define ___THING___ \
inline symbol_a type(any_a _) const \
{ \
	return type_(); \
} \
inline cat_a cat(any_a _) const \
{ \
	return cat_(); \
} \
inline any_a eater(any_a _) const \
{ \
	return eater_(); \
} \
inline any_a same(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	assert(it != range.cend()); /* //TODO */ \
	return same_(*it); \
} \
inline any_a same_(any_a thing) const \
{ \
	return _boole_(operator==(thing)); \
} \
inline any_a different(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	assert(it != range.cend()); /* //TODO */ \
	return different_(*it); \
} \
inline any_a different_(any_a thing) const \
{ \
	return _boole_(operator!=(thing)); \
} \
inline any_a hash(any_a) const \
{ \
	return hash_(); \
} \
inline any_a hash_() const \
{ \
	return Everything<>::val_(); /* //TODO */ \
} \
inline any_a beget(any_a) const \
{ \
	return beget_(); \
} \
inline any_a beget_() const \
{ \
	return cbegin(); \
} \
inline any_a beset(any_a) \
{ \
	return beset_(); \
} \
inline any_a beset_() \
{ \
	return begin(); \
} \
inline any_a enget(any_a) const \
{ \
	return enget_(); \
} \
inline any_a enget_() const \
{ \
	return cend(); \
} \
inline any_a enset(any_a) \
{ \
	return enset_(); \
} \
inline any_a enset_() \
{ \
	return end(); \
} \
inline any_a get(any_a) const \
{ \
	return get_(); \
} \
inline any_a get_() const \
{ \
	return operator*(); \
} \
inline any_a set(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	assert(it != range.cend()); /* //TODO */ \
	return set_(*it); \
} \
inline any_a set_(any_a thing) const \
{ \
	return operator*() = thing; \
} \
inline any_a* operator->() const \
{ \
	return &operator*(); \
} \
inline any_a increment(any_a) \
{ \
	return increment_(); \
} \
inline any_a increment_() \
{ \
	operator++(); \
	return me_(); \
} \

} // namespace strange

#endif
