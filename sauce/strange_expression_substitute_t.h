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
				any_a<> thing = substituted.evaluate_();
				if (expression_literal_t<>::validate(thing))
				{
					flock_a<> terms = flock_t<>::create_();
					terms.push_back(thing);
					return expression_literal_t<>::create(substituted.token_(), terms, thing);
				}
				return expression_a<>{ expression_substitute_t(std::move(substituted), thing) };
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_substitute::create thing evaluation error:") + substituted.token_().report_() + misunderstanding;
			}
		}
		return expression_a<>{ std::move(substituted) };
	}

	static inline expression_a<> create(_SUBSTITUTED_&& substituted, any_a<> const& thing)
	{
		return expression_a<>{ expression_substitute_t(std::move(substituted), thing) };
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		return _thing;
	}

	// expression
	inline void recreated(expression_a<> const& expression) const
	{
		auto const thing = expression.evaluate_();
		if (check<operation_a<>>(_thing) && check<operation_a<>>(thing))
		{
			fast_ref<operation_a<>>(_thing).assign(fast<operation_a<>>(thing));
		}
		_thing = thing;
	}

protected:
	any_a<> mutable _thing;

	inline expression_substitute_t(_SUBSTITUTED_&& substituted, any_a<> const& thing)
		: _SUBSTITUTED_{ std::move(substituted) }
		, _thing{ thing }
	{}
};

} // namespace strange

#endif
