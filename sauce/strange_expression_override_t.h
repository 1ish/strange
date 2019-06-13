#ifndef COM_ONEISH_STRANGE_EXPRESSION_OVERRIDE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OVERRIDE_T_H

namespace strange
{

template <typename _OVERRIDDEN_>
class expression_override_t : public _OVERRIDDEN_
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val(_OVERRIDDEN_ const& overridden)
	{
		if (overridden.literal())
		{
			any_a<> literal = overridden.operate_(no(), no().ranged_()); //TODO expression_a/t evaluate
			if (check<symbol_a<>>(literal)) //TODO expression_literal_t<>::validate(literal)
			{
				return expression_literal_t<>::val(overridden.token_(), literal);
			}
			return expression_a<>{ expression_override_t(overridden, literal) };
		}
		return expression_a<>{ overridden };
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return _literal;
	}

protected:
	any_a<> const _literal;

	inline expression_override_t(_OVERRIDDEN_ const& overridden, any_a<> const& literal)
		: _OVERRIDDEN_{ overridden }
		, _literal{ literal }
	{}
};

} // namespace strange

#endif
