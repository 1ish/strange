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

		any_a<> const name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed too few terms");
		}

		any_a<> const cat = *it;
		if (!check<cat_a<>>(cat))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-cat");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed too few terms");
		}

		any_a<> const value = *it;
		if (!check<expression_a<>>(value))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-expression catch");
		}

		auto const thing = cast<expression_a<>>(value).evaluate_();
		if (!thing.cats_().has_(cat))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed wrong kind of thing");
		}
		return expression_substitute_t<over>::create(over{ expression_attribute_mutation_t<>(token, terms, cast<symbol_a<>>(name), cast<cat_a<>>(cat), cast<expression_a<>>(value)) },
			attribute_mutation_t<>::create_(cast<symbol_a<>>(name), thing));
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

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" attribute_mutation(");
		river.write_string(")\n");
		_expression.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" [](");
		river.write_string(")\n{\n");
		_expression.generate_cpp(version, indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _name;
	cat_a<> const _result;
	expression_a<> const _expression;

	inline expression_attribute_mutation_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _name{ name }
		, _result{ result }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_attribute_mutation_t_share___;
};

template <typename ___ego___>
bool const expression_attribute_mutation_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_attribute_mutation_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
