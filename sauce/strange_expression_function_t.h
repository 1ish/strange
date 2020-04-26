#ifndef COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_function_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_function_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		auto end = terms.extract_end_();
		if (it == end)
		{
			throw dis(token.report() + "strange::expression_function::create not passed any terms");
		}
		auto const scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_function::create passed non-symbol scope");
		}
		auto names = flock_t<>::create_();
		auto kinds = flock_t<>::create_();
		auto expressions = flock_t<>::create_();
		auto defaults = flock_t<>::create_();
		any_a<> expression = expression_t<>::create(token);
		bool at_end = ++it == end;
		while (!at_end)
		{
			auto const& term = *it;
			at_end = ++it == end;
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_function::create passed non-expression term");
			}
			if (at_end) // expression
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
			auto const subterms = fast<expression_a<>>(term).terms_();
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
				defaults.push_back(fast<expression_a<>>(expression).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis(__FILE__, __LINE__, "strange::expression_function::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<expression_function_t<>>::create(
			function_t<>::create_(token, fast<symbol_a<>>(scope), names, kinds, defaults, fast<expression_a<>>(expression)),
			token, terms, fast<symbol_a<>>(scope), names, kinds, expressions, defaults, fast<expression_a<>>(expression));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_function");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_function::create"), native_function_create(&expression_function_t<>::create__));
		shoal.update(sym("function!"), native_function_create(&expression_function_t<>::create__));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_function_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
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
			auto name = fast<symbol_a<>>(*nit++);
			auto kind = fast<kind_a<>>(*kit++);
			auto expression = fast<expression_a<>>(*eit++);
			river.write_string(name.to_string() + ":");
			river.write_string(kind.to_string() + "=");
			expression.generate(version, indent, river);
		}
		river.write_string(")\n");
		_expression.generate(version, indent, river);
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_expression.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_function::generate_cpp called for wrong type of expression");
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
			auto name = fast<symbol_a<>>(*nit++);
			auto kind = fast<kind_a<>>(*kit++);
			auto expression = fast<expression_a<>>(*eit++);
			river.write_string("catch(" + kind.code() + " const& ");
			river.write_string(name.to_string() + " =");
			expression.generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(")\n{\n");
		_expression.generate_cpp(version, indent, river, declare, define);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _scope;
	flock_a<> const _names;
	flock_a<> const _kinds;
	flock_a<> const _expressions;
	flock_a<> const _defaults;
	expression_a<> const _expression;

	friend class any_a<>;

	inline expression_function_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& scope, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& expressions, flock_a<> const& defaults, expression_a<> const& expression)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _scope{ scope }
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
	auto& shoal = shared();
	expression_function_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_function_t_share___
{
	static inline bool ___share___()
	{
		return expression_function_t<>::___share___;
	}
};

} // namespace strange

#endif
