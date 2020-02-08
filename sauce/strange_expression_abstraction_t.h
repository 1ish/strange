#ifndef COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_abstraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_abstraction_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_abstraction::create not passed any terms");
		}
		auto const scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol scope");
		}
		auto dimension_names = flock_t<>::create_();
		auto dimension_kinds = flock_t<>::create_();
		auto dimension_expressions = flock_t<>::create_();
		auto dimension_defaults = flock_t<>::create_();
		auto parent_expressions = flock_t<>::create_();
		bool end = ++it == terms.cend_();
		while (!end)
		{
			auto const& term = *it;
			end = ++it == terms.cend_();
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed non-expression term");
			}
			if (end) // parents
			{
				if (!term.type_().is("strange::expression_block"))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-block last term");
				}
				auto const subterms = cast<expression_a<>>(term).terms_();
				if (subterms.empty())
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed no subterms");
				}
				for (auto const& subterm : subterms)
				{
					if (!check<expression_a<>>(subterm))
					{
						throw dis(token.report() + "strange::expression_abstraction::create passed non-expression subterm");
					}
					parent_expressions.push_back(subterm);
				}
				break;
			}
			// dimensions
			if (!term.type_().is("strange::expression_local_at") &&
				!term.type_().is("strange::expression_local_insert"))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed invalid dimension term");
			}
			auto const subterms = cast<expression_a<>>(term).terms_();
			int64_t const count = subterms.size();
			auto const name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol dimension name");
			}
			if (cast<symbol_a<>>(name).first_character() != '#')
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed dimension name without # preceding it");
			}
			dimension_names.push_back(name);
			if (count == 1)
			{
				dimension_kinds.push_back(kind_t<>::create_());
			}
			else
			{
				auto const kind = subterms.at_index(1);
				if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-kind/expression dimension kind");
				}
				dimension_kinds.push_back(kind);
			}
			any_a<> expression;
			if (count == 3)
			{
				expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-expression dimension default");
				}
			}
			else
			{
				expression = expression_t<>::create(token);
			}
			dimension_expressions.push_back(expression);
			try
			{
				dimension_defaults.push_back(cast<expression_a<>>(expression).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_abstraction::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_abstraction_t<>(token, terms, cast<symbol_a<>>(scope), dimension_names, dimension_kinds, dimension_expressions, dimension_defaults, parent_expressions) },
			abstraction_t<>::create_(token, cast<symbol_a<>>(scope), dimension_names, dimension_kinds, dimension_defaults, parent_expressions));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_abstraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_abstraction_t<>>::share(shoal);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" abstraction(");
		auto nit = _dimension_names.extract_vector().cbegin();
		auto kit = _dimension_kinds.extract_vector().cbegin();
		auto eit = _dimension_expressions.extract_vector().cbegin();
		bool first = true;
		for (auto const& def : _dimension_defaults.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto const name = cast<symbol_a<>>(*nit++);
			auto const kind = *kit++;
			auto const expression = cast<expression_a<>>(*eit++);
			river.write_string(name.to_string() + ":");
			if (check<kind_a<>>(kind))
			{
				river.write_string(cast<kind_a<>>(kind).to_string() + "=");
			}
			else
			{
				cast<expression_a<>>(kind).generate(version, indent, river);
			}
			expression.generate(version, indent, river);
		}
		river.write_string(")\n");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_declare_or_define_(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_abstraction::generate_cpp called for wrong type of expression");
		}
		river.write_string(" [](");
		auto nit = _dimension_names.extract_vector().cbegin();
		auto kit = _dimension_kinds.extract_vector().cbegin();
		auto eit = _dimension_expressions.extract_vector().cbegin();
		bool first = true;
		for (auto const& def : _dimension_defaults.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto const name = cast<symbol_a<>>(*nit++);
			auto const kind = *kit++;
			auto const expression = cast<expression_a<>>(*eit++);
			if (check<kind_a<>>(kind))
			{
				river.write_string("catch(" + cast<kind_a<>>(kind).name_().to_string() + "_a<> const& ");
				river.write_string(cast<kind_a<>>(kind).to_string() + " =");
			}
			else
			{
				cast<expression_a<>>(kind).generate_cpp(version, indent, river, declare, define);
			}
			expression.generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(")\n{\n");
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _scope;
	flock_a<> const _dimension_names;
	flock_a<> const _dimension_kinds;
	flock_a<> const _dimension_expressions;
	flock_a<> const _dimension_defaults;
	flock_a<> const _parent_expressions;

	inline expression_abstraction_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& scope, flock_a<> const& dimension_names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_expressions, flock_a<> const& dimension_defaults, flock_a<> const& parent_expressions)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _scope{ scope }
		, _dimension_names{ dimension_names }
		, _dimension_kinds{ dimension_kinds }
		, _dimension_expressions{ dimension_expressions }
		, _dimension_defaults{ dimension_defaults }
		, _parent_expressions{ parent_expressions }
	{}

	inline void _declare_or_define_(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		flock_a<> split_scope = _split_scope_();
		river.write_string("\n");
		auto const name = _namespace_open_(split_scope, river);
		_declare_or_define_template_(version, indent, river, declare, define);
		_declare_or_define_class_(name, version, indent, river, declare, define);
		_namespace_close_(split_scope, river);
	}

	inline flock_a<> _split_scope_() const
	{
		auto split_scope = flock_t<>::create_();
		std::string const& scope = _scope.to_string();
		std::size_t begin = 0;
		std::size_t pos = scope.find("::", begin);
		int64_t nest = 1;
		while (pos != std::string::npos)
		{
			split_scope.push_back(sym(scope.substr(begin, pos)));
			++nest;
			begin = pos + 2;
			pos = scope.find("::", begin);
		}
		split_scope.push_back(sym(scope.substr(begin)));
		return split_scope;
	}

	static inline symbol_a<> _namespace_open_(flock_a<> const& split_scope, river_a<>& river)
	{
		symbol_a<> name;
		for (auto const& scope_name : split_scope)
		{
			if (check<any_a<>>(name))
			{
				river.write_string(
					"namespace " + name.to_string() + "\n"
					"{\n");
			}
			name = cast<symbol_a<>>(scope_name);
		}
		return name;
	}

	static inline void _namespace_close_(flock_a<> const& split_scope, river_a<>& river)
	{
		int64_t nest = split_scope.size();
		while (--nest)
		{
			river.write_string("} // namespace\n");
		}
	}

	inline void _declare_or_define_template_(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		river.write_string("template <");
		if (declare)
		{
			if (_dimension_names.empty())
			{
				river.write_string("typename _1_ = void");
			}
			else
			{
				bool first = true;
				auto kit = _dimension_kinds.extract_vector().cbegin();
				auto eit = _dimension_expressions.extract_vector().cbegin();
				for (auto const& name : _dimension_names.extract_vector())
				{
					if (first)
					{
						first = false;
					}
					else
					{
						river.write_string(", ");
					}
					river.write_string("typename " + cast<symbol_a<>>(name).to_string().substr(1));

					auto any_kind = *kit++;
					if (check<expression_a<>>(any_kind))
					{
						try
						{
							any_kind = cast<expression_a<>>(any_kind).evaluate_();
						}
						catch (misunderstanding_a<>& misunderstanding)
						{
							throw dis(_token.report() + "strange::expression_abstraction::generate_cpp kind expression evaluation error") + misunderstanding;
						}
					}
					if (!check<kind_a<>>(any_kind))
					{
						throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-kind dimension kind");
					}
					auto const kind = cast<kind_a<>>(any_kind);

					auto const expression = *eit++;
					if (kind.optional())
					{
						river.write_string(" = ");
						cast<expression_a<>>(expression).generate_cpp(version, indent, river, false, false, true); // declare, define, type
					}
				}
			}
		}
		else if (define)
		{
			if (_dimension_names.empty())
			{
				river.write_string("typename _1_");
			}
			else
			{
				bool first = true;
				for (auto const& name : _dimension_names.extract_vector())
				{
					if (first)
					{
						first = false;
					}
					else
					{
						river.write_string(", ");
					}
					river.write_string("typename " + cast<symbol_a<>>(name).to_string().substr(1));
				}
			}
		}
		river.write_string(">\n");
	}

	inline void _declare_or_define_class_(symbol_a<> const& name, int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		std::string const& name_string = name.to_string();
		std::string const class_name =
			((name.first_character() == '<' && name.last_character() == '>')
				? name_string.substr(1, name_string.length() - 2)
				: name_string)
			+ "_a";
		if (declare)
		{
			river.write_string("class " + class_name + ";\n");
		}
		else if (define)
		{
			_define_class_(class_name, version, indent, river, declare, define);
		}
	}

	inline void _define_class_(std::string const& class_name, int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		river.write_string(
			"class " + class_name + "\n"
			"{\n"
			"public:\n");
		_define_class_boilerplate_(true, // root
			class_name, version, indent, river);
		auto const class_expression_terms = _class_expression_terms_();
		_define_class_nonvirtual_members_(true, // root
			class_name, class_expression_terms, version, indent, river);
		_define_class_handle_(true, // root
			class_name, class_expression_terms, version, indent, river);
		//TODO
		river.write_string("}; // class " + class_name +"\n");
	}

	inline flock_a<> _class_expression_terms_() const
	{
		if (_parent_expressions.empty())
		{
			return flock_t<>::create_();
		}
		auto const expression = _parent_expressions.at_index(_parent_expressions.size() - 1);
		if (!check<expression_a<>>(expression))
		{
			throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-expression class definition");
		}
		return cast<expression_a<>>(expression).terms_();
	}

	static inline void _define_class_boilerplate_(bool root, std::string const& class_name, int64_t version, int64_t indent, river_a<>& river)
	{
		if (root)
		{
			river.write_string(
				"\t// constructor tags\n"
				"\tstruct ___reference_tag___ {};\n"
				"\tstruct ___duplicate_tag___ {};\n"
				"\n"
				"\t// shared pointer typedefs\n"
				"\tstruct ___root_handle_base___;\n"
				"\tusing ___WEAK___ = std::weak_ptr<___root_handle_base___>;\n"
				"\tusing ___SHARED___ = std::shared_ptr<___root_handle_base___>;\n"
				"\n"
				"\t// hash function wrapper class\n"
				"\tclass hash_f\n"
				"\t{\n"
				"\tpublic:\n"
				"\t\tinline std::size_t operator()(" + class_name + " const& thing) const\n"
				"\t\t{\n"
				"\t\t\treturn thing.hash();\n"
				"\t\t}\n"
				"\t};\n"
				"\n"
				"\t// operator overloads\n"
				"\tinline any_a operator[](range_a const& range)\n"
				"\t{\n"
				"\t\treturn invoke(*this, range);\n"
				"\t}\n"
				"\n"
				"\tinline any_a operator()(range_a const& range)\n"
				"\t{\n"
				"\t\treturn operate(*this, range);\n"
				"\t}\n"
				"\n"
				"\tinline operator bool() const\n"
				"\t{\n"
				"\t\tassert(handle_);\n"
				"\t\treturn read().operator bool();\n"
				"\t}\n"
				"\n"
				"\t// trigger copy on write\n"
				"\tvoid mutate()\n"
				"\t{\n"
				"\t\tassert(handle_);\n"
				"\t\twrite();\n"
				"\t}\n"
				"\n");
		}
		river.write_string(
			"\t// arithmetic operator overloads\n"
			"\tinline " + class_name + "& operator++()\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator++();\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + " operator++(int)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\tany_a result = *this;\n"
			"\t\twrite().operator++();\n"
			"\t\treturn result;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + "& operator--()\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator--();\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + " operator--(int)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\tany_a result = *this;\n"
			"\t\twrite().operator--();\n"
			"\t\treturn result;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + "& operator+=(any_a const& other)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator+=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + "& operator-=(any_a const& other)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator-=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + "& operator*=(any_a const& other)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator*=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + "& operator/=(any_a const& other)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator/=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n"
			"\tinline " + class_name + "& operator%=(any_a const& other)\n"
			"\t{\n"
			"\t\tassert(handle_);\n"
			"\t\twrite().operator%=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n"
			"\n");
	}

	using _define_member_p = void (expression_abstraction_t::*)(bool root, int64_t version, std::string const& name, expression_a<> const& expression, bool extraction, river_a<> & river) const;
	using _define_native_member_p = void (expression_abstraction_t::*)(std::string const& name, std::string const& value, river_a<>& river) const;

	inline void _define_class_members_(bool root, std::string const& class_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river,
		_define_member_p define_member_p,
		_define_native_member_p define_native_member_p) const
	{
		for (auto const& expression : class_expression_terms.extract_vector())
		{
			if (!check<expression_a<>>(expression) || expression.type_() != expression_flock_t<>::type_())
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-flock expression pair in class definition");
			}
			auto const pair = cast<expression_a<>>(expression).terms_();
			if (pair.size() != 2)
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-pair in class definition");
			}
			auto any_name = pair.at_index(0);
			if (!check<expression_a<>>(any_name) || any_name.type_() != expression_literal_t<>::type_())
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-literal expression name in class definition");
			}
			auto const name_flock = cast<expression_a<>>(any_name).terms_();
			if (name_flock.size() != 1)
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-single name in class definition");
			}
			any_name = name_flock.at_index(0);
			if (!check<symbol_a<>>(any_name))
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-symbol name in class definition");
			}
			auto const name = cast<symbol_a<>>(any_name);

			auto any_value = pair.at_index(1);
			if (!check<expression_a<>>(any_value))
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp non-expression value in class definition");
			}
			auto const value_expression = cast<expression_a<>>(any_value);
			if (name.last_character() == '_')
			{
				bool const extraction = value_expression.type_() == expression_extraction_t<>::type_();
				if (extraction || value_expression.type_() == expression_mutation_t<>::type_())
				{
					(this->*define_member_p)(root, version, name.to_string(), value_expression, extraction, river);
				}
				else
				{
					throw dis(_token.report() + "strange::expression_abstraction::generate_cpp invalid expression value in class definition");
				}
			}
			else if (value_expression.type_() == expression_literal_t<>::type_() && value_expression.terms_().size() == 1)
			{
				auto const value = value_expression.terms_().at_index(0);
				if (check<lake_a<int8_t>>(value))
				{
					(this->*define_native_member_p)(name.to_string(), lake_to_string(cast<lake_a<int8_t>>(value)), river);
				}
			}
			else
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp invalid expression pair in class definition");
			}
		}
	}

	inline void _define_class_nonvirtual_members_(bool root, std::string const& class_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		_define_class_members_(root, class_name, class_expression_terms, version, indent, river,
			&expression_abstraction_t::_define_class_nonvirtual_member_,
			&expression_abstraction_t::_define_class_nonvirtual_native_member_);
	}

	inline void _define_class_nonvirtual_member_(bool root, int64_t version, std::string const& name, expression_a<> const& expression, bool extraction, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_member_definition_(version, expression, extraction, result, parameters, arguments, constness);

		river.write_string(
			"\tinline any_a<> " + name + "_(range_a" +
				(root ? "" : "<>") + " const& range)" + constness + "\n"
			"\t{ assert(handle_); return ");
		if (constness.empty())
		{
			river.write_string("write().");
		}
		else
		{
			river.write_string("read().");
		}
		river.write_string(name + "_(range); }\n\n");

		river.write_string(
			"\tinline " + result + name + parameters + constness + "\n"
			"\t{ assert(handle_); return ");
		if (constness.empty())
		{
			river.write_string("write().");
		}
		else
		{
			river.write_string("read().");
		}
		river.write_string(name + arguments + "; }\n\n");
	}

	inline void _define_class_nonvirtual_native_member_(std::string const& name, std::string const& value, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_native_member_definition_(value, result, parameters, arguments, constness);
		river.write_string(
			"\tinline " + result + name + parameters + constness + "\n"
			"\t{ assert(handle_); ");
		if (result != "void ")
		{
			river.write_string("return ");
		}
		if (constness.empty())
		{
			river.write_string("write().");
		}
		else
		{
			river.write_string("read().");
		}
		river.write_string(name + arguments + "; }\n"
			"\n");
	}

	inline void _define_class_handle_(bool root, std::string const& class_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(
			"protected:\n"
			"\tstruct ___root_handle_base___\n"
			"\t{\n"
			"\t\t___root_handle_base___() = default;\n"
			"\t\t___root_handle_base___(___root_handle_base___ const&) = default;\n"
			"\t\t___root_handle_base___(___root_handle_base___&&) = default;\n"
			"\t\t___root_handle_base___& operator=(___root_handle_base___ const&) = default;\n"
			"\t\t___root_handle_base___& operator=(___root_handle_base___&&) = default;\n"
			"\t\tvirtual ~___root_handle_base___() = default;\n"
			"\t\tvirtual ___SHARED___ ___clone___() const = 0;\n"
			"\t\tvirtual void ___weak___(___WEAK___ const& weak) const = 0;\n"
			"\t\tvirtual inline operator bool() const = 0;\n"
			"\t\tvirtual inline void operator++() = 0;\n"
			"\t\tvirtual inline void operator--() = 0;\n"
			"\t\tvirtual inline void operator+=(any_a const& other) = 0;\n"
			"\t\tvirtual inline void operator-=(any_a const& other) = 0;\n"
			"\t\tvirtual inline void operator*=(any_a const& other) = 0;\n"
			"\t\tvirtual inline void operator/=(any_a const& other) = 0;\n"
			"\t\tvirtual inline void operator%=(any_a const& other) = 0;\n");
		_define_class_members_(root, class_name, class_expression_terms, version, indent, river,
			&expression_abstraction_t::_define_class_pure_virtual_member_,
			&expression_abstraction_t::_define_class_pure_virtual_native_member_);
		river.write_string(
			"\t};\n\n");
	}

	inline void _define_class_pure_virtual_member_(bool root, int64_t version, std::string const& name, expression_a<> const& expression, bool extraction, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_member_definition_(version, expression, extraction, result, parameters, arguments, constness);

		river.write_string(
			"\t\tvirtual inline any_a<> " + name + "_(range_a" +
			(root ? "" : "<>") + " const& range)" + constness + " = 0;\n");
		river.write_string(
			"\t\tvirtual inline " + result + name + parameters + constness + " = 0;\n");
	}

	inline void _define_class_pure_virtual_native_member_(std::string const& name, std::string const& value, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_native_member_definition_(value, result, parameters, arguments, constness);
		river.write_string(
			"\t\tvirtual inline " + result + name + parameters + constness + " = 0;\n");
	}

	inline void _parse_member_definition_(int64_t version, expression_a<> const& expression, bool extraction, std::string& result, std::string& parameters, std::string& arguments, std::string& constness) const
	{
		if (extraction)
		{
			auto const& exp = static_cast<expression_extraction_t<> const&>(expression.extract_thing());
			exp.abstraction(version, result, parameters, arguments, constness);
		}
		else
		{
			auto const& exp = static_cast<expression_mutation_t<> const&>(expression.extract_thing());
			exp.abstraction(version, result, parameters, arguments, constness);
		}
	}

	inline void _parse_native_member_definition_(std::string const& value, std::string& result, std::string& parameters, std::string& arguments, std::string& constness) const
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create(value));
		int64_t toke = 1;
		std::string argument;
		for (auto const& any_token : tokenizer)
		{
			if (!check<token_a<>>(any_token))
			{
				throw dis(_token.report() + "strange::expression_abstraction::generate_cpp invalid token in class definition");
			}
			auto const token = cast<token_a<>>(any_token);
			switch (toke)
			{
			case 1:
				if (token.tag() == "punctuation" && token.symbol() == "(")
				{
					parameters = "(";
					arguments = "(";
					toke = 2;
				}
				else
				{
					result += token.symbol() + " ";
				}
				break;
			case 2:
				if (token.tag() == "punctuation" && token.symbol() == ")")
				{
					parameters += ")";
					arguments += argument + ")";
					toke = 3;
				}
				else if (token.tag() == "punctuation" && token.symbol() == ",")
				{
					parameters += ", ";
					arguments += argument + ", ";
				}
				else
				{
					parameters += token.symbol() + " ";
					if (token.tag() == "name")
					{
						argument = token.symbol();
					}
				}
				break;
			case 3:
				if (token.tag() == "name" && token.symbol() == "const")
				{
					constness = " const";
				}
				break;
			}
		}
	}

private:
	static bool const ___share___;
	friend class ___expression_abstraction_t_share___;
};

template <typename ___ego___>
bool const expression_abstraction_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_abstraction_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
