#ifndef COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_MUTATION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_MUTATION_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_attribute_mutation_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_attribute_mutation_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed no terms");
		}

		auto const name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-symbol name");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed too few terms");
		}

		auto const kind = *it;
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-kind/expression");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed too few terms");
		}

		auto const expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_attribute_mutation::create passed non-expression value");
		}
		return expression_substitute_t<expression_attribute_mutation_t<>>::create(expression_attribute_mutation_t<>(token, terms, fast<symbol_a<>>(name), kind, fast<expression_a<>>(expression)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_attribute_mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_attribute_mutation::create"), native_function_create(&expression_attribute_mutation_t<>::create__));
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
			return attribute_mutation_create(_name, kind, value);
		}
		catch (misunderstanding_a<>& misunderstanding)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_attribute_mutation::operate value evaluation error") + misunderstanding;
		}
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_attribute_mutation_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, range_create());
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

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		// name := expression
		river.write_string(" " + _name.to_string() + " := ");
		_expression.generate(version, indent, river);
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_expression.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_attribute_mutation::generate_cpp called for wrong type of expression");
		}
		river.write_string(" [](");
		river.write_string(")\n{\n");
		_expression.generate_cpp(version, indent, river, declare, define);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _name;
	any_a<> const _kind;
	expression_a<> const _expression;

	friend class any_a<>;

	inline expression_attribute_mutation_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, any_a<> const& kind, expression_a<> const& expression)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
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
	return shoal;
}();

class ___expression_attribute_mutation_t_share___
{
	static inline bool ___share___()
	{
		return expression_attribute_mutation_t<>::___share___;
	}
};

} // namespace strange

#endif
