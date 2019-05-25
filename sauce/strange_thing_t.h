#ifndef COM_ONEISH_STRANGE_THING_T_H
#define COM_ONEISH_STRANGE_THING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class thing_t : public one_t
{
public:
	// erasure
	inline _ABSTRACTION_ const me_() const
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	inline _ABSTRACTION_ me_()
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	// reflection
	static inline any_a<> cat__(range_a<> const&)
	{
		return cat_();
	}
	
	static inline cat_a<> cat_()
	{
		return reflection<_ABSTRACTION_>::cat();
	}

	static inline any_a<> cats__(range_a<> const&)
	{
		return cats_();
	}

	static inline unordered_herd_a<> cats_()
	{
		return reflection<_ABSTRACTION_>::cats();
	}

	static inline any_a<> operations__(range_a<> const&)
	{
		return operations_();
	}
	
	static inline unordered_shoal_a<> operations_()
	{
		return reflection<_ABSTRACTION_>::operations();
	}

	static inline any_a<> eater_()
	{
		return no();
	}

	static inline any_a<> feeder__(range_a<> const& range)
	{
		return no();
	}

	// visitor pattern
	static inline any_a<> visit__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::thing::visit passed empty range");
		}
		any_a<> visitor = *it;
		return visitor.invoke__(range_t<>::val_(++it, range.cend()));
	}

	// function
	inline any_a<> invoke__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::thing::invoke passed empty range");
		}
		any_a<> member = *it;
		return invoke_(member, range_t<>::val_(++it, range.cend()));
	}

	inline any_a<> invoke_(any_a<> const& member, range_a<> const& range) const
	{
		//TODO
		// thing = me_();
		// operation = thing.operations_().at(member);
		// return operate_(thing, operation, range);
		return no();
	}

	static inline any_a<> operate__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::thing::operate passed empty range");
		}
		any_a<> thing = *it;
		if (++it == range.cend())
		{
			throw dis("strange::thing::visit passed short range");
		}
		any_a<> operation = *it;
		return operate_(thing, operation, range_t<>::val_(++it, range.cend()));
	}

	static inline any_a<> operate_(any_a<> const& thing, any_a<> const& operation, range_a<> const& range)
	{
		return operation.operator()(thing, range);
	}

	inline any_a<> operator()(any_a<> const& thing, range_a<> const& range) const
	{
		//TODO
		// operation = thing.operations_().at(range.1st);
		// return operate_(thing, operation, range.2nd...);
		return no();
	}

	// identification
	inline any_a<> identical__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::thing::identical passed empty range");
		}
		return identical_(*it);
	}

	inline any_a<> identical_(any_a<> const& thing) const
	{
		return boole(identical(thing));
	}

	// comparison
	static inline any_a<> nothing__(range_a<> const&)
	{
		return nothing_();
	}

	static inline any_a<> nothing_()
	{
		return no();
	}

	static inline any_a<> everything__(range_a<> const&)
	{
		return everything_();
	}

	static inline any_a<> everything_()
	{
		return yes();
	}

	static inline any_a<> operation__(range_a<> const&)
	{
		return operation_();
	}

	static inline any_a<> operation_()
	{
		return no();
	}

	// conversion
	inline range_a<> ranged_() const
	{
		return range_t<>::val_(it_t<true>::val_(me_()), it_t<true>::val_(no()));
	}

	// operators
	inline void operator++()
	{}

	inline void operator++(int)
	{}

	inline void operator--()
	{}

	inline void operator--(int)
	{}

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
	// construction
	inline thing_t()
		: one_t{}
	{}
};

// adaptation
#define ___STRANGE_THING___ \
inline any_a<> type__(range_a<> const&) const \
{ \
	return type_(); \
} \
inline any_a<> eater__(range_a<> const&) const \
{ \
	return eater_(); \
} \
inline any_a<> same__(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis("[thing] same passed empty range"); \
	} \
	return same_(*it); \
} \
inline any_a<> same_(any_a<> const& thing) const \
{ \
	return boole(operator==(thing)); \
} \
inline any_a<> different__(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis("[thing] different passed empty range"); \
	} \
	return different_(*it); \
} \
inline any_a<> different_(any_a<> const& thing) const \
{ \
	return boole(operator!=(thing)); \
} \
inline any_a<> hash__(range_a<> const&) const \
{ \
	return hash_(); \
} \
inline number_data_a<uint64_t> hash_() const \
{ \
	return number_uint_64_t<>::val(uint64_t(hash())); \
} \
inline any_a<> ranged__(range_a<> const& _) const \
{ \
	return ranged_(); \
} \

} // namespace strange

#endif
