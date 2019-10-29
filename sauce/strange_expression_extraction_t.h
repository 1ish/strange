#ifndef COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_extraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_extraction_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto names = flock_t<>::create_();
		auto kinds = flock_t<>::create_();
		auto expressions = flock_t<>::create_();
		auto defaults = flock_t<>::create_();
		any_a<> name = sym("");
		any_a<> kind = kind_t<>::create_();
		any_a<> expression = expression_t<>::create(token);
		auto it = terms.cbegin_();
		bool end = it == terms.cend_();
		while (!end)
		{
			auto const& term = *it;
			end = ++it == terms.cend_();
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_extraction::create passed non-expression term");
			}
			if (end)
			{
				expression = term;
				break;
			}
			if (term.type_().is("strange::expression_local_at"))
			{
				auto subterms = cast<expression_a<>>(term).terms_();
				if (subterms.size() != 1)
				{
					throw dis(token.report() + "strange::expression_extraction::create passed wrong number of subterms");
				}
				name = subterms.at_index(0);
				if (!check<symbol_a<>>(name))
				{
					throw dis(token.report() + "strange::expression_extraction::create passed non-symbol name");
				}
				kind = kind_t<>::create_();
				expression = expression_t<>::create(token);
			}
			else if (term.type_().is("strange::expression_local_insert") ||
				term.type_().is("strange::expression_local_update"))
			{
				auto subterms = cast<expression_a<>>(term).terms_();
				if (subterms.size() != 3)
				{
					throw dis(token.report() + "strange::expression_extraction::create passed wrong number of subterms");
				}
				name = subterms.at_index(0);
				if (!check<symbol_a<>>(name))
				{
					throw dis(token.report() + "strange::expression_extraction::create passed non-symbol name");
				}
				kind = subterms.at_index(1);
				if (!check<kind_a<>>(kind))
				{
					throw dis(token.report() + "strange::expression_extraction::create passed non-kind");
				}
				expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_extraction::create passed non-expression");
				}
			}
			else
			{
				throw dis(token.report() + "strange::expression_extraction::create passed invalid parameter term");
			}
			names.push_back(name);
			kinds.push_back(kind);
			expressions.push_back(expression);
			try
			{
				defaults.push_back(cast<expression_a<>>(expression).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_extraction::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_extraction_t<>(token, terms, names, kinds, expressions, defaults, cast<expression_a<>>(expression)) },
			extraction_t<>::create_(token, names, kinds, defaults, cast<expression_a<>>(expression)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_extraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_extraction_t<>>::share(shoal);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		// name :<kind># (...)
		river.write_string(" extraction(");
		auto nit = _names.extract().cbegin();
		auto kit = _kinds.extract().cbegin();
		auto eit = _expressions.extract().cbegin();
		bool first = true;
		for (auto const& def : _defaults.extract())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto name = cast<symbol_a<>>(*nit++);
			auto kind = cast<kind_a<>>(*kit++);
			auto expression = cast<expression_a<>>(*eit++);
			river.write_string(name.to_string() + ":");
			river.write_string(kind.to_string() + "=");
			expression.generate(version, indent, river);
		}
		river.write_string(")\n");
		_expression.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" [](");
		auto nit = _names.extract().cbegin();
		auto kit = _kinds.extract().cbegin();
		auto eit = _expressions.extract().cbegin();
		bool first = true;
		for (auto const& def : _defaults.extract())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto name = cast<symbol_a<>>(*nit++);
			auto kind = cast<kind_a<>>(*kit++);
			auto expression = cast<expression_a<>>(*eit++);
			river.write_string("catch(" + kind.name_().to_string() + "_a<> const& ");
			river.write_string(name.to_string() + " =");
			expression.generate_cpp(version, indent, river);
		}
		river.write_string(")\n{\n");
		_expression.generate_cpp(version, indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	flock_a<> const _names;
	flock_a<> const _kinds;
	flock_a<> const _expressions;
	flock_a<> const _defaults;
	expression_a<> const _expression;

	inline expression_extraction_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& expressions, flock_a<> const& defaults, expression_a<> const& expression)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _names{ names }
		, _kinds{ kinds }
		, _expressions{ expressions }
		, _defaults{ defaults }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_extraction_t_share___;
};

template <typename ___ego___>
bool const expression_extraction_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_extraction_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
