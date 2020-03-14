#ifndef COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_extraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_extraction_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_extraction::create not passed any terms");
		}
		auto const scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_extraction::create passed non-symbol scope");
		}
		auto names = flock_t<>::create_();
		auto kinds = flock_t<>::create_();
		auto expressions = flock_t<>::create_();
		auto defaults = flock_t<>::create_();
		any_a<> expression = expression_t<>::create(token);
		bool end = ++it == terms.extract_end_();
		while (!end)
		{
			auto const& term = *it;
			end = ++it == terms.extract_end_();
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_extraction::create passed non-expression term");
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
				throw dis(token.report() + "strange::expression_extraction::create passed invalid parameter term");
			}
			auto const subterms = fast<expression_a<>>(term).terms_();
			int64_t const count = subterms.size();
			auto const name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_extraction::create passed non-symbol parameter name");
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
					throw dis(token.report() + "strange::expression_extraction::create passed non-kind/expression parameter kind");
				}
				kinds.push_back(kind);
			}
			if (count == 3)
			{
				expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_extraction::create passed non-expression parameter default");
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
				throw dis("strange::expression_extraction::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_extraction_t<>(token, terms, fast<symbol_a<>>(scope), names, kinds, expressions, defaults, fast<expression_a<>>(expression)) },
			extraction_t<>::create_(token, fast<symbol_a<>>(scope), names, kinds, defaults, fast<expression_a<>>(expression)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_extraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_extraction::create", native_function_create(&expression_extraction_t<>::over::create__));
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

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_expression.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_extraction::generate_cpp called for wrong type of expression");
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

	void abstraction(int64_t version, std::string& result, std::string& parameters, std::string& arguments, std::string& constness) const
	{
		if (_expression.type_() != expression_kind_t<>::type_())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_extraction::abstraction called with wrong type of result expression");
		}
		auto river = river_t<>::create();
		_expression.generate_cpp(version, 0, river, false, false, true);
		result = river.to_string().substr(1);
		result = result.substr(0, result.length() - 1);
		parameters = "(";
		arguments = "(";
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
				parameters += ", ";
				arguments += ", ";
			}
			auto name = fast<symbol_a<>>(*nit++);
			auto any_kind = *kit++;
			auto expression = fast<expression_a<>>(*eit++);
			bool optional = false;
			if (check<expression_a<>>(any_kind))
			{
				auto const exp = fast<expression_a<>>(any_kind);
				river = river_t<>::create();
				exp.generate_cpp(version, 0, river, false, false, true);
				parameters += river.to_string().substr(1);
				optional = exp.terms_().at_index(8);
			}
			else if (!check<kind_a<>>(any_kind))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_extraction::abstraction non-kind parameter kind");
			}
			else
			{
				auto const kind = fast<kind_a<>>(any_kind);
				if (kind.name_().to_string().empty())
				{
					parameters += "any_a<> ";
				}
				else
				{
					parameters += kind.code() + " ";
				}
				if (kind.fixed())
				{
					parameters += "const& ";
				}
				else if (kind.reference())
				{
					parameters += "& ";
				}
				optional = kind.optional();
			}
			parameters += name.to_string();
			arguments += name.to_string();
			if (optional)
			{
				parameters += " =";
				river = river_t<>::create();
				expression.generate_cpp(version, 0, river, false, false);
				parameters += river.to_string();
			}
		}
		parameters += ")";
		arguments += ")";
		constness = " const";
	}

	void abstraction_arguments(std::string const& class_name, std::string const& member, int64_t version, river_a<>& river) const
	{
		if (_names.empty())
		{
			river.write_string(
				"\treturn " + member + "();\n");
			return;
		}
		river.write_string("\tforward_extractor_a<> ___it___ = ___arguments___.extract_begin_();\n");
		auto temp = river_t<>::create();
		std::string arguments = "(";
		auto kit = _kinds.extract_vector().cbegin();
		bool first = true;
		for (auto const& name : _names.extract_vector())
		{
			auto const name_string = fast<symbol_a<>>(name).to_string();
			auto const any_kind = *kit++;
			std::string type;
			bool fixed = false;
			bool reference = false;
			bool optional = false;
			if (check<expression_a<>>(any_kind))
			{
				auto const exp = fast<expression_a<>>(any_kind);
				exp.generate_cpp(version, 0, temp, false, false, true);
				type = temp.to_string();
				type = type.substr(0, type.find(' ', 1));
				fixed = exp.terms_().at_index(6);
				reference = exp.terms_().at_index(7);
				optional = exp.terms_().at_index(8);
			}
			else if (!check<kind_a<>>(any_kind))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_extraction::abstraction_arguments non-kind parameter kind");
			}
			else
			{
				auto const kind = fast<kind_a<>>(any_kind);
				if (kind.name_().to_string().empty())
				{
					type = "any_a<>";
				}
				else
				{
					type = kind.code();
				}
				fixed = kind.fixed();
				reference = kind.reference();
				optional = kind.optional();
			}
			river.write_string(
				"\tif (" + std::string(first ? "___it___" : "++___it___") + " == ___arguments___.extract_end_())\n"
				"\t{\n" +
				(optional
					? "\t\treturn " + member + arguments + ");\n"
					: std::string("\t\tthrow dis(\"" + class_name + "::" + member +
						" passed short range\");\n")) +
				"\t}\n"
				"\tauto " + name_string +
				(reference ? " = cast_dup<" : " = cast<") + type + ">(*___it___);\n");
			if (first)
			{
				first = false;
			}
			else
			{
				arguments += ", ";
			}
			arguments += name_string;
		}
		river.write_string(
			"\treturn " + member + arguments + ");\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _scope;
	flock_a<> const _names;
	flock_a<> const _kinds;
	flock_a<> const _expressions;
	flock_a<> const _defaults;
	expression_a<> const _expression;

	inline expression_extraction_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& scope, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& expressions, flock_a<> const& defaults, expression_a<> const& expression)
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
	friend class ___expression_extraction_t_share___;
};

template <typename ___ego___>
bool const expression_extraction_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_extraction_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_extraction_t_share___
{
	static inline bool ___share___()
	{
		return expression_extraction_t<>::___share___;
	}
};

} // namespace strange

#endif
