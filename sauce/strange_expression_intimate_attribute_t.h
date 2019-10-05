#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_intimate_attribute_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_intimate_attribute_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed empty range");
		}
		auto thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed short range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-symbol member term");
		}
		if (++it == terms.cend_())
		{
			return expression_substitute_t<over>::create(over{ expression_intimate_attribute_t<>(token, terms, cast<expression_a<>>(thing), cast<symbol_a<>>(member)) });
		}
		auto value = *it;
		if (!check<expression_a<>>(value))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-expression value term");
		}
		return expression_substitute_t<over>::create(over{ expression_intimate_attribute_t<>(token, terms, cast<expression_a<>>(thing), cast<symbol_a<>>(member), cast<expression_a<>>(value)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_intimate_attribute_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_intimate_attribute_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto thing_term = _thing.operate(thing, range);
		if (_assign)
		{
			return any_c<>::intimate(thing_term, _member, flock_t<>::create_(_value.operate(thing, range)));
		}
		return any_c<>::intimate(thing_term, _member, flock_t<>::create_());
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		_thing.generate(version, indent, river);
		river.write_string("." + _member.to_string());
		_value.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		_thing.generate_cpp(version, indent, river);
		river.write_string("." + _member.to_string());
		_value.generate_cpp(version, indent, river);
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	symbol_a<> const _member;
	expression_a<> const _value;
	bool const _assign;

	inline expression_intimate_attribute_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, symbol_a<> const& member)
		: expression_t(token, is_pure_literal(token, terms, thing, member, expression_t<>::create(token)))
		, _terms{ terms }
		, _thing{ thing }
		, _member{ member }
		, _value{ expression_t<>::create(token) }
		, _assign{ false }
	{}

	inline expression_intimate_attribute_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, symbol_a<> const& member, expression_a<> const& value)
		: expression_t(token, is_pure_literal(token, terms, thing, member, value))
		, _terms{ terms }
		, _thing{ thing }
		, _member{ member }
		, _value{ value }
		, _assign{ true }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, flock_a<> const& terms, expression_a<> const& expression_thing, symbol_a<> const& member, expression_a<> const& expression_value)
	{
		std::pair<bool, bool> pure_literal(true, true);
		if (!expression_thing.literal() || !expression_value.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		try
		{
			auto thing = expression_thing.evaluate_();
			if (!thing.operations_().has_(member))
			{
				throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-existent member");
			}
			auto any_operation = thing.operations_().at_(member);
			if (!check<operation_a<>>(any_operation))
			{
				throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-operation member");
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
			throw dis("strange::expression_intimate_attribute::create pure literal evaluation error:") + token.report_() + misunderstanding;
		}

		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_intimate_attribute_t_share___;
};

template <typename ___ego___>
bool const expression_intimate_attribute_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_intimate_attribute_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
