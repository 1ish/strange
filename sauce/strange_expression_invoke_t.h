#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_invoke_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		return expression_a<>{ expression_invoke_t<>{ token, terms } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_invoke_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_invoke_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return invoke__(range_operator_t<>::val_(_terms, thing, range));
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" $$strange::thing::invoke[");
		bool first = true;
		for (auto const& term : _terms)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(", ");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_invoke::generate passed non-expression term");
			}
			cast<expression_a<>>(term).generate(indent, river);
		}
		river.write_string("] ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" thing_t<>::invoke__(");
		bool first = true;
		for (auto const& term : _terms)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(", ");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_invoke::generate_cpp passed non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(indent, river);
		}
		river.write_string(") ");
	}

protected:
	range_a<> const _terms;

	inline expression_invoke_t(token_a<> const& token, range_a<> const& terms)
		: expression_t{ token }
		, _terms{ terms }
	{}
};

} // namespace strange

#endif
