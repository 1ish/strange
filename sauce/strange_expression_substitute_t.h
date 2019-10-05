#ifndef COM_ONEISH_STRANGE_EXPRESSION_SUBSTITUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SUBSTITUTE_T_H

namespace strange
{

template <typename _SUBSTITUTED_>
class expression_substitute_t : public _SUBSTITUTED_
{
public:
	// construction
	static inline expression_a<> create(_SUBSTITUTED_&& substituted)
	{
		if (substituted.literal())
		{
			try
			{
				any_a<> literal = substituted.evaluate_();
				if (expression_literal_t<>::validate(literal))
				{
					flock_a<> terms = flock_t<>::create_();
					terms.push_back(literal);
					return expression_literal_t<>::create(substituted.token_(), terms, literal);
				}
				return expression_a<>{ expression_substitute_t(std::move(substituted), literal) };
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_substitute::create literal evaluation error:") + substituted.token_().report_() + misunderstanding;
			}
		}
		return expression_a<>{ std::move(substituted) };
	}

	static inline expression_a<> create(_SUBSTITUTED_&& substituted, any_a<> const& literal)
	{
		return expression_a<>{ expression_substitute_t(std::move(substituted), literal) };
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
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
