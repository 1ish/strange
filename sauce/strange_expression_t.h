#ifndef COM_ONEISH_STRANGE_EXPRESSION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_T_H

namespace strange
{

// adaptation
#define ___STRANGE_EXPRESSION___ ___STRANGE_THING___ \
static inline any_a<> val__(range_a<> const& range) \
{ \
	if (!check<flock_a<>>(range)) \
	{ \
		throw dis("[expression]::val passed non-flock range"); \
	} \
	return val_(cast<flock_a<>>(range)); \
} \

template <typename _ABSTRACTION_ = expression_a<>>
class expression_t : public operation_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(flock_a<> const& terms)
	{
		return expression_a<>{ expression_t<>{} };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return no();
	}

	// expression
	inline any_a<> generate__(range_a<> const& range) const
	{
		return no();
	}

	inline any_a<> generate_(number_data_a<int64_t> const& indent, river_a<> const& river) const
	{
		return no();
	}

	inline void generate(int64_t indent, river_a<> const& river) const
	{
	}

protected:
	inline expression_t()
		: operation_t{}
	{}
};

} // namespace strange

#endif
