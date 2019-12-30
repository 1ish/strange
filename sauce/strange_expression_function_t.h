#ifndef COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_function_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_function_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto names = flock_t<>::create_();
		auto kinds = flock_t<>::create_();
		auto expressions = flock_t<>::create_();
		auto defaults = flock_t<>::create_();
		any_a<> expression = expression_t<>::create(token);
		auto it = terms.cbegin_();
		bool end = it == terms.cend_();
		while (!end)
		{
			auto const& term = *it;
			end = ++it == terms.cend_();
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_function::create passed non-expression term");
			}
			if (end) // expression
			{
				expression = term;
				break;
			}
			// parameters
			if (!term.type_().is("strange::expression_local_at") &&
				!term.type_().is("strange::expression_local_insert"))
			{
				throw dis(token.report() + "strange::expression_function::create passed invalid parameter term");
			}
			auto const subterms = cast<expression_a<>>(term).terms_();
			int64_t const count = subterms.size();
			auto const name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_function::create passed non-symbol parameter name");
			}
			names.push_back(name);
			if (count == 1)
			{
				kinds.push_back(kind_t<>::create_());
			}
			else
			{
				auto const kind = subterms.at_index(1);
				if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
				{
					throw dis(token.report() + "strange::expression_function::create passed non-kind/expression parameter kind");
				}
				kinds.push_back(kind);
			}
			if (count == 3)
			{
				expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_function::create passed non-expression parameter default");
				}
			}
			else
			{
				expression = expression_t<>::create(token);
			}
			expressions.push_back(expression);
			try
			{
				defaults.push_back(cast<expression_a<>>(expression).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_function::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_function_t<>(token, terms, names, kinds, expressions, defaults, cast<expression_a<>>(expression)) },
			function_t<>::create_(token, names, kinds, defaults, cast<expression_a<>>(expression)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_function_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_function_t<>>::share(shoal);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" function(");
		auto nit = _names.extract_vector().cbegin();
		auto kit = _kinds.extract_vector().cbegin();
		auto eit = _expressions.extract_vector().cbegin();
		bool first = true;
		for (auto const& def : _defaults.extract_vector())
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

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_function::generate_cpp called for wrong type of expression");
		}
		river.write_string(" [](");
		auto nit = _names.extract_vector().cbegin();
		auto kit = _kinds.extract_vector().cbegin();
		auto eit = _expressions.extract_vector().cbegin();
		bool first = true;
		for (auto const& def : _defaults.extract_vector())
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

	inline expression_function_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& expressions, flock_a<> const& defaults, expression_a<> const& expression)
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
	friend class ___expression_function_t_share___;
};

template <typename ___ego___>
bool const expression_function_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_function_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
