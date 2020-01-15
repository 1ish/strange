#ifndef COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_MUTATION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_MUTATION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_attribute_mutation_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_attribute_mutation_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed no terms");
		}

		auto const name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed too few terms");
		}

		auto const kind = *it;
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-kind/expression");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed too few terms");
		}

		auto const expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-expression value");
		}
		return expression_substitute_t<over>::create(over{ expression_attribute_mutation_t<>(token, terms, cast<symbol_a<>>(name), kind, cast<expression_a<>>(expression)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_attribute_mutation_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_attribute_mutation_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		try
		{
			auto const kind = check<expression_a<>>(_kind) ? _kind.operate(thing, range) : _kind;
			auto const value = _expression.operate(thing, range);
			if (!value.kinds_().has(kind))
			{
				throw dis("wrong kind of thing");
			}
			return attribute_mutation_t<>::create_(_name, kind, value);
		}
		catch (misunderstanding_a<>& misunderstanding)
		{
			throw dis(_token.report() + "strange::expression_attribute_mutation::operate value evaluation error") + misunderstanding;
		}
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		// name := expression
		river.write_string(" " + _name.to_string() + " := ");
		_expression.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool def, bool type = false) const //TODO
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_attribute_mutation::generate_cpp called for wrong type of expression");
		}
		river.write_string(" [](");
		river.write_string(")\n{\n");
		_expression.generate_cpp(version, indent, river, def);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _name;
	any_a<> const _kind;
	expression_a<> const _expression;

	inline expression_attribute_mutation_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, any_a<> const& kind, expression_a<> const& expression)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _name{ name }
		, _kind{ kind }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_attribute_mutation_t_share___;
};

template <typename ___ego___>
bool const expression_attribute_mutation_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_attribute_mutation_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
