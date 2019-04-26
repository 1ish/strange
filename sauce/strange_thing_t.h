#ifndef COM_ONEISH_STRANGE_THING_T_H
#define COM_ONEISH_STRANGE_THING_T_H

namespace strange
{

template <typename _ABSTRACTION_>
class thing_t : public one_t
{
public:
	// erasure
	inline const _ABSTRACTION_ me_() const
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	inline _ABSTRACTION_ me_()
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	// reflection
	static inline cat_a cat_()
	{
		static cat_a CATEGORY = cat_t<>::val_(sym__(std::string("strange::") + _ABSTRACTION_::___abstraction_name___()));
		return CATEGORY;
	}

	static inline any_a eater_()
	{
		return nothing_t<>::val_();
	}

	static inline any_a feeder(any_a range)
	{
		return nothing_t<>::val_();
	}

	// visitor pattern
	static inline any_a visit(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return dis__("strange::thing::visit passed empty range");
		}
		any_a visitor = *it;
		return visitor->invoke(range_t<>::val_(++it, range.cend())); //TODO me_() must already be in range
	}

	// function
	inline any_a invoke(any_a range) const
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return dis__("strange::thing::invoke passed empty range");
		}
		any_a member = *it;
		return invoke_(std::move(member), range_t<>::val_(++it, range.cend()));
	}

	inline any_a invoke_(any_a member, any_a range) const
	{
		//TODO
		// thing = me_();
		// operation = thing.operations_().at(std::move(member));
		// return operate_(std::move(thing), std::move(operation), std::move(range));
		return nothing_t<>::val_();
	}

	static inline any_a operate(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return dis__("strange::thing::operate passed empty range");
		}
		any_a thing = *it;
		if (++it == range.cend())
		{
			return dis__("strange::thing::visit passed short range");
		}
		any_a operation = *it;
		return operate_(std::move(thing), std::move(operation), range_t<>::val_(++it, range.cend()));
	}

	static inline any_a operate_(any_a thing, any_a operation, any_a range)
	{
		return operation.operator()(std::move(thing), std::move(range));
	}

	// identification
	inline any_a identical(any_a range) const
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return dis__("strange::thing::identical passed empty range");
		}
		return identical_(*it);
	}

	inline any_a identical_(any_a thing) const
	{
		return _boole_(identical__(std::move(thing)));
	}

	// comparison
	static inline any_a nothing(any_a)
	{
		return nothing_();
	}

	static inline any_a nothing_()
	{
		return nothing_t<>::val_();
	}

	static inline any_a anything(any_a)
	{
		return anything_();
	}

	static inline any_a anything_()
	{
		return everything_t<>::val_();
	}

	static inline any_a something(any_a)
	{
		return something_();
	}

	static inline any_a something_()
	{
		return nothing_t<>::val_();
	}

	static inline any_a everything(any_a)
	{
		return everything_();
	}

	static inline any_a everything_()
	{
		return nothing_t<>::val_();
	}

	// range
	inline any_a cbegin() const
	{
		return it_t<true>::val_(me_());
	}

	inline any_a begin()
	{
		return it_t<>::val_(me_());
	}

	inline any_a cend() const
	{
		return nothing_t<>::val_();
	}

	inline any_a end()
	{
		return nothing_t<>::val_();
	}

	// iterator
	inline any_a& operator*() const
	{
		return nothing_t<>::val__();
	}

	inline void operator++()
	{}

	inline void operator++(int)
	{}

	inline void operator--()
	{}

	inline void operator--(int)
	{}

	inline void operator+=(any_a other)
	{}

	inline void operator-=(any_a other)
	{}

	inline void operator*=(any_a other)
	{}

	inline void operator/=(any_a other)
	{}

	inline void operator%=(any_a other)
	{}

protected:
	// construction
	inline thing_t()
		: one_t{}
	{}

	// conversion
	static inline any_a _boole_(bool b)
	{
		return b ? everything_t<>::val_() : nothing_t<>::val_();
	}
};

// adaptation
#define ___THING___ \
inline symbol_a type(any_a) const \
{ \
	return type_(); \
} \
inline cat_a cat(any_a) const \
{ \
	return cat_(); \
} \
inline any_a eater(any_a) const \
{ \
	return eater_(); \
} \
inline any_a same(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		return dis__("same passed empty range"); \
	} \
	return same_(*it); \
} \
inline any_a same_(any_a thing) const \
{ \
	return _boole_(operator==(std::move(thing))); \
} \
inline any_a different(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		return dis__("different passed empty range"); \
	} \
	return different_(*it); \
} \
inline any_a different_(any_a thing) const \
{ \
	return _boole_(operator!=(std::move(thing))); \
} \
inline any_a hash(any_a) const \
{ \
	return hash_(); \
} \
inline any_a hash_() const \
{ \
	return everything_t<>::val_(); /* //TODO */ \
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
	if (it == range.cend()) \
	{ \
		return dis__("set passed empty range"); \
	} \
	return set_(*it); \
} \
inline any_a set_(any_a thing) const \
{ \
	return operator*() = std::move(thing); \
} \
inline any_a* operator->() const \
{ \
	return &operator*(); \
} \
inline _ABSTRACTION_ increment(any_a) \
{ \
	return increment_(); \
} \
inline _ABSTRACTION_ increment_() \
{ \
	operator++(); \
	return me_(); \
} \

} // namespace strange

#endif
