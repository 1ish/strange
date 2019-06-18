#ifndef COM_ONEISH_STRANGE_EXPRESSION_OVERRIDE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OVERRIDE_T_H

namespace strange
{

template <typename _OVERRIDDEN_>
class expression_override_t : public _OVERRIDDEN_
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val(_OVERRIDDEN_&& overridden)
	{
		if (overridden.literal())
		{
			any_a<> literal = overridden.evaluate_();
			if (expression_literal_t<>::validate(literal))
			{
				return expression_literal_t<>::val(overridden.token_(), literal);
			}
			return expression_a<>{ expression_override_t(std::move(overridden), literal) };
		}
		return expression_a<>{ std::move(overridden) };
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return _literal;
	}

protected:
	any_a<> const _literal;

	inline expression_override_t(_OVERRIDDEN_&& overridden, any_a<> const& literal)
		: _OVERRIDDEN_{ std::move(overridden) }
		, _literal{ literal }
	{}
};

} // namespace strange

#endif
