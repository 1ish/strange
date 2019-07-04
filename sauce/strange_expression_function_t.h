#ifndef COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_function_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_function_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_function::val not passed any terms");
		}
		any_a<> expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_function::val passed non-expression");
		}
		auto names = flock_t<>::val_();
		auto evaluated = flock_t<>::val_();
		forward_const_iterator_a<> pit = ++it;
		while (it != terms.cend_())
		{
			auto name = *it;
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-symbol name");
			}
			names.push_back(name);
			if (++it == terms.cend_())
			{
				throw dis(token.report() + "strange::expression_function::val passed short range");
			}
			auto cat_expression = *it;
			if (!check<expression_a<>>(cat_expression))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-expression cat");
			}
			auto cat = cast<expression_a<>>(cat_expression).evaluate_();
			if (!check<cat_a<>>(cat))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-cat");
			}
			evaluated.push_back(cat);
			if (++it == terms.cend_())
			{
				throw dis(token.report() + "strange::expression_function::val passed short range");
			}
			auto default_expression = *it;
			if (!check<expression_a<>>(default_expression))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-expression default");
			}
			evaluated.push_back(cast<expression_a<>>(default_expression).evaluate_());
			++it;
		}
		return expression_substitute_t<over>::val(over{ expression_function_t<>(token, terms, cast<expression_a<>>(expression), range_t<>::val_(pit, terms.cend_()), names, evaluated) });
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

	inline any_a<> eater_() const
	{
		return _names;
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		auto local_shoal = unordered_shoal_t<>::val_();
		auto& local = local_shoal.reference();
		local.emplace(sym("$"), _shared);
		local.emplace(sym("^"), thing);
		auto eit = _evaluated.extract().cbegin();
		forward_const_iterator_a<> ait = range.cbegin_();
		for (auto const& name : _names.extract())
		{
			auto cat = *eit++;
			any_a<> argument = (ait == range.cend_())
				? *eit
				: (*ait++);
			++eit;
			if (!argument.cats_().has_(cat))
			{
				throw dis(_token.report() + "strange::expression_function::operate cat does not include argument");
			}
			local.emplace(name, argument);
		}
		try
		{
			return _expression.operate_(local_shoal, range);
		}
		catch (return_i& ret)
		{
			return ret.result;
		}
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" function(");
		forward_const_iterator_a<> pit = _parameters.cbegin_();
		bool first = true;
		while (pit != _parameters.cend_())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			river.write_string(cast<symbol_a<>>(*pit).to_string() + " :");
			cast<expression_a<>>(*++pit).generate(indent, river);
			river.write_string("=");
			cast<expression_a<>>(*++pit).generate(indent, river);
			++pit;
		}
		river.write_string(")\n");
		_expression.generate(indent, river);
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" [](");
		forward_const_iterator_a<> pit = _parameters.cbegin_();
		bool first = true;
		while (pit != _parameters.cend_())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto name = cast<symbol_a<>>(*pit).to_string();
			cast<expression_a<>>(*++pit).generate_cpp(indent, river);
			river.write_string( name + " =");
			cast<expression_a<>>(*++pit).generate_cpp(indent, river);
			++pit;
		}
		river.write_string(")\n");
		river.write_string("{\n");
		_expression.generate_cpp(indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _expression;
	range_a<> const _parameters;
	flock_a<> const _names;
	flock_a<> const _evaluated;
	unordered_shoal_a<> const _shared;

	inline expression_function_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& expression, range_a<> const& parameters, flock_a<> const& names, flock_a<> const& evaluated)
		: expression_t(token, is_pure(expression, parameters), is_literal(expression, parameters))
		, _terms{ terms }
		, _expression{ expression }
		, _parameters{ parameters }
		, _names{ names }
		, _evaluated{ evaluated }
		, _shared{ unordered_shoal_t<true>::val_() }
	{}

	static inline bool is_pure(expression_a<> const& expression, range_a<> const& parameters)
	{
		if (!expression.pure())
		{
			return false;
		}
		forward_const_iterator_a<> pit = parameters.cbegin_();
		while (pit != parameters.cend_())
		{
			if (!cast<expression_a<>>(*++pit).pure())
			{
				return false;
			}
			if (!cast<expression_a<>>(*++pit).pure())
			{
				return false;
			}
			++pit;
		}
		return true;
	}

	static inline bool is_literal(expression_a<> const& expression, range_a<> const& parameters)
	{
		if (!expression.literal())
		{
			return false;
		}
		forward_const_iterator_a<> pit = parameters.cbegin_();
		while (pit != parameters.cend_())
		{
			if (!cast<expression_a<>>(*++pit).literal())
			{
				return false;
			}
			if (!cast<expression_a<>>(*++pit).literal())
			{
				return false;
			}
			++pit;
		}
		return true;
	}
};

} // namespace strange

#endif
