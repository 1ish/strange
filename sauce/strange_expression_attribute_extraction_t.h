#ifndef COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_EXTRACTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_attribute_extraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_attribute_extraction_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed no terms");
		}

		any_a<> const name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed too few terms");
		}

		any_a<> const kind = *it;
		if (!check<kind_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed non-kind");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed too few terms");
		}

		any_a<> const value = *it;
		if (!check<expression_a<>>(value))
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed non-expression value");
		}

		auto const thing = cast<expression_a<>>(value).evaluate_();
		if (!thing.kinds_().has_(kind))
		{
			throw dis(token.report() + "strange::expression_attribute_extraction::create passed wrong kind of thing");
		}
		return expression_substitute_t<over>::create(over{ expression_attribute_extraction_t<>(token, terms, cast<symbol_a<>>(name), cast<kind_a<>>(kind), cast<expression_a<>>(value)) },
			attribute_extraction_t<>::create_(thing));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_attribute_extraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_attribute_extraction_t<>>::share(shoal);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// name :# expression
		river.write_string(" " + _name.to_string() + " :# ");
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
	kind_a<> const _result;
	expression_a<> const _expression;

	inline expression_attribute_extraction_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, kind_a<> const& result, expression_a<> const& expression)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _name{ name }
		, _result{ result }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_attribute_extraction_t_share___;
};

template <typename ___ego___>
bool const expression_attribute_extraction_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_attribute_extraction_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
