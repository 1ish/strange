#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_operate_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_operate_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::val(over{ expression_operate_t<>(token, terms) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_operate_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_operate_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return operate__(range_operator_t<>::val_(_terms, thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		int64_t count = 0;
		for (auto const& term : _terms)
		{
			if (count == 1)
			{
				river.write_string(".perform[");
			}
			else if (count > 1)
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_operate::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(indent, river);
			++count;
		}
		river.write_string("] ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		int64_t count = 0;
		for (auto const& term : _terms)
		{
			if (count == 1)
			{
				river.write_string("(flock_t<>::val_(");
			}
			else if (count > 1)
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_operate::generate_cpp with non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(indent, river);
			++count;
		}
		river.write_string(")) ");
	}

protected:
	flock_a<> const _terms;

	inline expression_operate_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t(token, is_pure_literal(token, terms))
		, _terms{ terms }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, flock_a<> const& terms)
	{
		std::pair<bool, bool> pure_literal(true, true);
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate::val passed no terms");
		}
		auto any_thing = *it;
		if (!check<expression_a<>>(any_thing))
		{
			throw dis(token.report() + "strange::expression_operate::val passed non-expression thing");
		}
		auto expression_thing = cast<expression_a<>>(any_thing);
		if (!expression_thing.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate::val passed too few terms");
		}
		auto any_operation = *it;
		if (!check<expression_a<>>(any_operation))
		{
			throw dis(token.report() + "strange::expression_operate::val passed non-expression operation");
		}
		auto expression_operation = cast<expression_a<>>(any_operation);
		if (!expression_operation.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		auto thing = expression_thing.evaluate_();
		any_operation = expression_operation.evaluate_();
		if (!check<operation_a<>>(any_operation))
		{
			throw dis(token.report() + "strange::expression_operate::val passed non-operation");
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
		while (++it != terms.cend_())
		{
			auto term = *it;
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_operate::val passed non-expression argument");
			}
			auto expression = cast<expression_a<>>(term);
			if (!expression.pure())
			{
				pure_literal.first = false;
				if (!pure_literal.second)
				{
					return pure_literal;
				}
			}
			if (!expression.literal())
			{
				pure_literal.second = false;
				if (!pure_literal.first)
				{
					return pure_literal;
				}
			}
		}
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_operate_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_operate_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_operate_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
