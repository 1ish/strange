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
		return expression_override_t<expression_invoke_t<>>::val(expression_invoke_t<>(token, terms));
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
				throw dis(_token.report() + "strange::expression_invoke::generate with non-expression term");
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
				throw dis(_token.report() + "strange::expression_invoke::generate_cpp with non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(indent, river);
		}
		river.write_string(") ");
	}

protected:
	range_a<> const _terms;

	inline expression_invoke_t(token_a<> const& token, range_a<> const& terms)
		: expression_t(token, is_pure(token, terms), is_literal(token, terms))
		, _terms{ terms }
	{}

	static inline bool is_pure(token_a<> const& token, range_a<> const& terms)
	{
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
		if (!expression_thing.literal() || !expression_member.literal())
		{
			return false;
		}
		auto thing = expression_thing.evaluate_();
		auto member = expression_member.evaluate_();
		if (!thing.operations_().has_(member))
		{
			throw dis("strange::expression_invoke::val passed non-existent member");
		}
		auto operation = thing.operations_().at_(member);
		if (!check<operation_a<>>(operation))
		{
			throw dis("strange::expression_invoke::val passed non-operation member");
		}
		if (!cast<operation_a<>>(operation).pure())
		{
			return false;
		}
		while (++it != terms.cend_())
		{
			auto term = *it;
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_invoke::val passed non-expression argument");
			}
			if (!cast<expression_a<>>(term).pure())
			{
				return false;
			}
		}
		return true;
	}

	static inline bool is_literal(token_a<> const& token, range_a<> const& terms)
	{
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
		if (!expression_thing.literal() || !expression_member.literal())
		{
			return false;
		}
		auto thing = expression_thing.evaluate_();
		auto member = expression_member.evaluate_();
		if (!thing.operations_().has_(member))
		{
			throw dis("strange::expression_invoke::val passed non-existent member");
		}
		auto operation = thing.operations_().at_(member);
		if (!check<operation_a<>>(operation))
		{
			throw dis("strange::expression_invoke::val passed non-operation member");
		}
		if (!cast<operation_a<>>(operation).literal())
		{
			return false;
		}
		while (++it != terms.cend_())
		{
			auto term = *it;
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_invoke::val passed non-expression argument");
			}
			if (!cast<expression_a<>>(term).literal())
			{
				return false;
			}
		}
		return true;
	}
};

} // namespace strange

#endif
