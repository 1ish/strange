#ifndef COM_ONEISH_STRANGE_EXPRESSION_MEMBER_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_MEMBER_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_member_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_member_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_member::val passed empty range");
		}
		auto thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_member::val passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_member::val passed short range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_member::val passed non-expression member term");
		}
		return expression_substitute_t<over>::val(over{ expression_member_t<>(token, terms, cast<expression_a<>>(thing), cast<symbol_a<>>(member)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_member_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_member_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const thing_term = _thing.operate(thing, range);
		auto const member = thing_term.operations_().at_(_member);
		if (!check<operation_a<>>(member))
		{
			throw dis(_token.report() + "strange::expression_member::operate with non-existent or non-operaton member");
		}
		return member;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		_thing.generate(version, indent, river);
		river.write_string(":." + _member.to_string());
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		_thing.generate_cpp(version, indent, river);
		river.write_string(":." + _member.to_string());
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	symbol_a<> const _member;

	inline expression_member_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, symbol_a<> const& member)
		: expression_t(token, is_pure_literal(token, thing, member))
		, _terms{ terms }
		, _thing{ thing }
		, _member{ member }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, expression_a<> const& thing_expression, symbol_a<> const& member)
	{
		std::pair<bool, bool> pure_literal(true, true);
		if (!thing_expression.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		try
		{
			auto thing = thing_expression.evaluate_();
			if (!thing.operations_().has_(member))
			{
				throw dis(token.report() + "strange::expression_member::val passed non-existent member");
			}
			auto any_operation = thing.operations_().at_(member);
			if (!check<operation_a<>>(any_operation))
			{
				throw dis(token.report() + "strange::expression_member::val passed non-operation member");
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
		}
		catch (misunderstanding_a<>& misunderstanding)
		{
			throw dis("strange::expression_member::val pure literal evaluation error:") + token.report_() + misunderstanding;
		}

		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_member_t_share___;
};

template <typename ___ego___>
bool const expression_member_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_member_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
