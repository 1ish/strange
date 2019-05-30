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
		return operate__(range);
	}

	static inline any_a<> visit_(flock_a<> const& flock)
	{
		return operate__(flock);
	}

	// function
	static inline any_a<> invoke__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::invoke passed empty range");
		}
		any_a<> thing(*it, true);
		if (++it == range.cend_())
		{
			throw dis("strange::thing::invoke passed short range");
		}
		any_a<> member = *it;
		return invoke(thing, member, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> invoke_(any_a<>& thing, range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::invoke passed short range");
		}
		any_a<> member = *it;
		return invoke(thing, member, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> invoke(any_a<>& thing, any_a<> const& member, range_a<> const& range)
	{
		if (!thing.operations_().has_(member))
		{
			throw dis("strange::thing::invoke passed non-existent member");
		}
		return operate(thing, thing.operations_().at_(member), range);
	}

	static inline any_a<> operate__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::operate passed empty range");
		}
		any_a<> thing(*it, true);
		if (++it == range.cend_())
		{
			throw dis("strange::thing::operate passed short range");
		}
		any_a<> operation = *it;
		return operate(thing, operation, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> operate_(any_a<>& thing, range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::operate passed short range");
		}
		any_a<> operation = *it;
		return operate(thing, operation, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> operate(any_a<>& thing, any_a<> const& operation, range_a<> const& range)
	{
		return operation.operate_(thing, range);
	}

	// identification
	inline any_a<> identity__(range_a<> const&) const
	{
		return identity_();
	}

	inline number_data_a<uint64_t> identity_() const
	{
		return number_uint_64_t<>::val(uint64_t(identity()));
	}

	inline any_a<> identical__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
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

	static inline any_a<> something__(range_a<> const&)
	{
		return something_();
	}

	static inline any_a<> something_()
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
inline any_a<> share__(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin_(); \
	if (it == range.cend_()) \
	{ \
		throw dis("[thing] share passed empty range"); \
	} \
	any_a<> thing = *it; \
	if (!check<shoal_a<>>(thing)) \
	{ \
		throw dis("[thing] share passed non-shoal"); \
	} \
	return share_(cast<shoal_a<>>(thing, true)); \
} \
inline shoal_a<> share_(shoal_a<>& shoal) const \
{ \
	share(shoal); \
	return shoal; \
} \
inline any_a<> shared__(range_a<> const&) const \
{ \
	return shared_(); \
} \
inline unordered_shoal_a<> shared_() const \
{ \
	unordered_shoal_a<> shoal = unordered_shoal_t<>::val_(); \
	share(shoal); \
	return shoal; \
} \
inline any_a<> eater__(range_a<> const&) const \
{ \
	return eater_(); \
} \
inline any_a<> same__(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin_(); \
	if (it == range.cend_()) \
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
	forward_const_iterator_a<> it = range.cbegin_(); \
	if (it == range.cend_()) \
	{ \
		throw dis("[thing] different passed empty range"); \
	} \
	return different_(*it); \
} \
inline any_a<> different_(any_a<> const& thing) const \
{ \
	return boole(operator!=(thing)); \
} \
inline bool operator!=(any_a<> const& thing) const \
{ \
	return !operator==(thing); \
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
