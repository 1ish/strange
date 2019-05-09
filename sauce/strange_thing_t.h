#ifndef COM_ONEISH_STRANGE_THING_T_H
#define COM_ONEISH_STRANGE_THING_T_H

namespace strange
{

template <typename _ABSTRACTION_>
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
	static inline cat_a<> cat_()
	{
		static cat_a<> CATEGORY = cat_t<>::val_(sym__(std::string("strange::") + _ABSTRACTION_::___abstraction_name___()));
		return CATEGORY;
	}

	static inline any_a<> eater_()
	{
		return nothing_t<>::val_();
	}

	static inline any_a<> feeder(any_a<> const& range)
	{
		return nothing_t<>::val_();
	}

	// visitor pattern
	static inline any_a<> visit(any_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::thing::visit passed empty range");
		}
		any_a<> visitor = *it;
		return visitor.invoke(range_t<>::val_(++it, range.cend()));
	}

	// function
	inline any_a<> invoke(any_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::thing::invoke passed empty range");
		}
		any_a<> member = *it;
		return invoke_(member, range_t<>::val_(++it, range.cend()));
	}

	inline any_a<> invoke_(any_a<> const& member, any_a<> const& range) const
	{
		//TODO
		// thing = me_();
		// operation = thing.operations_().at(member);
		// return operate_(thing, operation, range);
		return nothing_t<>::val_();
	}

	static inline any_a<> operate(any_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::thing::operate passed empty range");
		}
		any_a<> thing = *it;
		if (++it == range.cend())
		{
			throw dis__("strange::thing::visit passed short range");
		}
		any_a<> operation = *it;
		return operate_(thing, operation, range_t<>::val_(++it, range.cend()));
	}

	static inline any_a<> operate_(any_a<> const& thing, any_a<> const& operation, any_a<> const& range)
	{
		return operation.operator()(thing, range);
	}

	// identification
	inline any_a<> identical(any_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::thing::identical passed empty range");
		}
		return identical_(*it);
	}

	inline any_a<> identical_(any_a<> const& thing) const
	{
		return _boole_(identical__(thing));
	}

	// comparison
	static inline any_a<> nothing(any_a<> const&)
	{
		return nothing_();
	}

	static inline any_a<> nothing_()
	{
		return nothing_t<>::val_();
	}

	static inline any_a<> anything(any_a<> const&)
	{
		return anything_();
	}

	static inline any_a<> anything_()
	{
		return everything_t<>::val_();
	}

	static inline any_a<> something(any_a<> const&)
	{
		return something_();
	}

	static inline any_a<> something_()
	{
		return nothing_t<>::val_();
	}

	static inline any_a<> everything(any_a<> const&)
	{
		return everything_();
	}

	static inline any_a<> everything_()
	{
		return nothing_t<>::val_();
	}

	// range
	inline forward_const_iterator_a<> cbegin() const
	{
		return it_t<true>::val_(me_());
	}

	inline forward_const_iterator_a<> begin() const
	{
		return it_t<true>::val_(me_());
	}

	inline forward_const_iterator_a<> cend() const
	{
		return it_t<true>::val_(nothing_t<>::val_());
	}

	inline forward_const_iterator_a<> end() const
	{
		return it_t<true>::val_(nothing_t<>::val_());
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

	// conversion
	static inline any_a<> _boole_(bool b)
	{
		return b ? everything_t<>::val_() : nothing_t<>::val_();
	}
};

// adaptation
#define ___STRANGE_THING___ \
inline symbol_a<> type(any_a<> const&) const \
{ \
	return type_(); \
} \
inline cat_a<> cat(any_a<> const&) const \
{ \
	return cat_(); \
} \
inline any_a<> eater(any_a<> const&) const \
{ \
	return eater_(); \
} \
inline any_a<> same(any_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis__("[thing] same passed empty range"); \
	} \
	return same_(*it); \
} \
inline any_a<> same_(any_a<> const& thing) const \
{ \
	return _boole_(operator==(thing)); \
} \
inline any_a<> different(any_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis__("[thing] different passed empty range"); \
	} \
	return different_(*it); \
} \
inline any_a<> different_(any_a<> const& thing) const \
{ \
	return _boole_(operator!=(thing)); \
} \
inline any_a<> hash(any_a<> const&) const \
{ \
	return hash_(); \
} \
inline number_data_a<uint64_t> hash_() const \
{ \
	return number_uint_64_t<>::val__(uint64_t(hash__())); \
} \
inline any_a<> beget(any_a<> const&) const \
{ \
	return beget_(); \
} \
inline forward_const_iterator_a<> beget_() const \
{ \
	return cbegin(); \
} \
inline any_a<> enget(any_a<> const&) const \
{ \
	return enget_(); \
} \
inline forward_const_iterator_a<> enget_() const \
{ \
	return cend(); \
} \

} // namespace strange

#endif
