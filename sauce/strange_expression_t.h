#ifndef COM_ONEISH_STRANGE_EXPRESSION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_t : public operation_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline expression_a<> val_()
	{
		return expression_a<>{ expression_t<>{ flock_t<>::val_() } };
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
	inline any_a<> operate_(any_a<>& local, range_a<> const& _) const
	{
		if (!check<unordered_shoal_a<>>(local))
		{
			throw dis("strange::expression::operate passed non-unordered-shoal local");
		}
		return evaluate_(static_cast<unordered_shoal_a<>&>(local));
	}

	// expression
	inline any_a<> evaluate__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::expression::evaluate passed empty range");
		}
		any_a<> local = *it;
		if (!check<unordered_shoal_a<>>(local))
		{
			throw dis("strange::expression::evaluate passed non-unordered-shoal local");
		}
		return evaluate_(cast<unordered_shoal_a<>>(local, true));
	}

	inline any_a<> evaluate_(unordered_shoal_a<>& local) const
	{
		return no();
	}

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
	flock_a<> const _terms;

	inline expression_t(flock_a<> const& terms)
		: operation_t{}
		, _terms{ terms }
	{}
};

} // namespace strange

#endif
