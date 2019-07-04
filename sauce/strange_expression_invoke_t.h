#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_invoke_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_invoke_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::val(over{ expression_invoke_t<>(token, terms) });
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
				river.write_string(".call[");
			}
			else if (count > 1)
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_invoke::generate with non-expression term");
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
				river.write_string("[flock_t<>::val_(");
			}
			else if (count > 1)
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_invoke::generate_cpp with non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(indent, river);
			++count;
		}
		river.write_string(")] ");
	}

protected:
	flock_a<> const _terms;

	inline expression_invoke_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t(token, is_pure_literal(token, terms))
		, _terms{ terms }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, flock_a<> const& terms)
	{
		std::pair<bool, bool> pure_literal(true, true);
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_invoke::val passed no terms");
		}
		auto any_thing = *it;
		if (!check<expression_a<>>(any_thing))
		{
			throw dis(token.report() + "strange::expression_invoke::val passed non-expression thing");
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
			throw dis(token.report() + "strange::expression_invoke::val passed too few terms");
		}
		auto any_member = *it;
		if (!check<expression_a<>>(any_member))
		{
			throw dis(token.report() + "strange::expression_invoke::val passed non-expression member");
		}
		auto expression_member = cast<expression_a<>>(any_member);
		if (!expression_member.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		auto thing = expression_thing.evaluate_();
		auto member = expression_member.evaluate_();
		if (!thing.operations_().has_(member))
		{
			throw dis(token.report() + "strange::expression_invoke::val passed non-existent member");
		}
		auto any_operation = thing.operations_().at_(member);
		if (!check<operation_a<>>(any_operation))
		{
			throw dis(token.report() + "strange::expression_invoke::val passed non-operation member");
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
				throw dis(token.report() + "strange::expression_invoke::val passed non-expression argument");
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
};

} // namespace strange

#endif
