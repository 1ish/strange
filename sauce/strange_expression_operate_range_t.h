#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_RANGE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_RANGE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_operate_range_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_operate_range_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate_range::create passed empty range");
		}
		auto thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_operate_range::create passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate_range::create passed short range");
		}
		auto range = *it;
		if (!check<expression_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_operate_range::create passed non-expression range term");
		}
		return expression_substitute_t<over>::create(over{ expression_operate_range_t<>(token, terms, cast<expression_a<>>(thing), cast<expression_a<>>(range)) });
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
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto thing_term = _thing.operate(thing, range);
		auto const range_term = _range.operate(thing, range);
		if (!check<range_a<>>(range_term))
		{
			throw dis(_token.report() + "strange::expression_operate_range::operate with non-range term");
		}
		return thing_term.operate(thing_term, cast<range_a<>>(range_term));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		_thing.generate(version, indent, river);
		river.write_string(".perform");
		_range.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_operate_range::generate_cpp called for wrong type of expression");
		}
		_thing.generate(version, indent, river);
		river.write_string("(");
		_range.generate(version, indent, river);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	expression_a<> const _range;

	inline expression_operate_range_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, expression_a<> const& range)
		: expression_t(token, is_pure_literal(token, thing, range))
		, _terms{ terms }
		, _thing{ thing }
		, _range{ range }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, expression_a<> const& thing_expression, expression_a<> const& range_expression)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
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
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_operate_range_t_share___;
};

template <typename ___ego___>
bool const expression_operate_range_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_operate_range_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
