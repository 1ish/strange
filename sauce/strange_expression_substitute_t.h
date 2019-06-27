#ifndef COM_ONEISH_STRANGE_EXPRESSION_SUBSTITUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SUBSTITUTE_T_H

namespace strange
{

template <typename _SUBSTITUTED_>
class expression_substitute_t : public _SUBSTITUTED_
{
public:
	// construction
	static inline expression_a<> val(_SUBSTITUTED_&& substituted)
	{
		if (substituted.literal())
		{
			any_a<> literal = substituted.evaluate_();
			if (expression_literal_t<>::validate(literal))
			{
				return expression_literal_t<>::val(substituted.token_(), literal);
			}
			return expression_a<>{ expression_substitute_t(std::move(substituted), literal) };
		}
		return expression_a<>{ std::move(substituted) };
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return _literal;
	}

protected:
	any_a<> const _literal;

	inline expression_substitute_t(_SUBSTITUTED_&& substituted, any_a<> const& literal)
		: _SUBSTITUTED_{ std::move(substituted) }
		, _literal{ literal }
	{}
};

} // namespace strange

#endif
