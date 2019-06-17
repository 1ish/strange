#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_RANGE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_RANGE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_operate_range_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed empty range");
		}
		auto thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed short range");
		}
		auto range = *it;
		if (!check<expression_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed non-expression range term");
		}
		return expression_override_t<expression_operate_range_t<>>::val(expression_operate_range_t<>(token, cast<expression_a<>>(thing), cast<expression_a<>>(range)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_operate_range_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_operate_range_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		auto thing_term = _thing.operate_(thing, range);
		auto range_term = _range.operate_(thing, range);
		if (!check<range_a<>>(range_term))
		{
			throw dis(_token.report() + "strange::expression_operate_range::operate with non-range term");
		}
		return operate_(thing_term, cast<range_a<>>(range_term));
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		_thing.generate(indent, river);
		river.write_string(".perform");
		_range.generate(indent, river);
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		_thing.generate(indent, river);
		river.write_string("(");
		_range.generate(indent, river);
		river.write_string(") ");
	}

protected:
	expression_a<> const _thing;
	expression_a<> const _range;

	inline expression_operate_range_t(token_a<> const& token, expression_a<> const& thing, expression_a<> const& range)
		: expression_t(token, is_pure_literal(token, thing, range))
		, _thing{ thing }
		, _range{ range }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, expression_a<> const& thing_expression, expression_a<> const& range_expression)
	{
		std::pair<bool, bool> pure_literal(true, true);
		if (!thing_expression.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		if (!range_expression.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		auto thing = thing_expression.evaluate_();
		auto any_range = range_expression.evaluate_();
		if (!check<range_a<>>(any_range))
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed non-range");
		}
		auto range = cast<range_a<>>(any_range);
		auto it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed empty range");
		}
		auto any_operation = *it;
		if (!check<operation_a<>>(any_operation))
		{
			throw dis(token.report() + "strange::expression_operate_range::val passed non-operation");
		}
		auto operation = cast<operation_a<>>(any_operation);
		if (!operation.pure())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		if (!operation.literal())
		{
			pure_literal.second = false;
		}
		return pure_literal;
	}
};

} // namespace strange

#endif
