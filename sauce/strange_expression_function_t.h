#ifndef COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_function_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
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
		forward_const_iterator_a<> pit = ++it;
		while (it != terms.cend_())
		{
			if (!check<symbol_a<>>(*it))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-symbol name");
			}
			if (++it == terms.cend_())
			{
				throw dis(token.report() + "strange::expression_function::val passed short range");
			}
			if (!check<expression_a<>>(*it))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-expression cat");
			}
			if (++it == terms.cend_())
			{
				throw dis(token.report() + "strange::expression_function::val passed short range");
			}
			if (!check<expression_a<>>(*it))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-expression default");
			}
			++it;
		}
		return expression_a<>{ expression_function_t<>(token, cast<expression_a<>>(expression), range_t<>::val_(pit, terms.cend_())) };
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

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_function::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).reference();
		forward_const_iterator_a<> pit = _parameters.cbegin_();
		forward_const_iterator_a<> ait = range.cbegin_();
		while (pit != _parameters.cend_())
		{
			auto name = cast<symbol_a<>>(*pit);
			auto cat = cast<expression_a<>>(*++pit).operate_(thing, range);
			if (!check<cat_a<>>(cat))
			{
				throw dis(_token.report() + "strange::expression_function::operate passed non-cat");
			}
			++pit;
			any_a<> argument = (ait == range.cend_())
				? cast<expression_a<>>(*pit).operate_(thing, range)
				: (*ait++);
			++pit;
			if (!argument.cats_().has_(cat))
			{
				throw dis(_token.report() + "strange::expression_function::operate cat does not include argument");
			}
			local.emplace(name, argument);
		}
		return _expression.operate_(thing, range);
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const //TODO
	{
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const //TODO
	{
	}

protected:
	expression_a<> const _expression;
	range_a<> const _parameters;

	inline expression_function_t(token_a<> const& token, expression_a<> const& expression, range_a<> const& parameters)
		: expression_t{ token }
		, _expression{ expression }
		, _parameters{ parameters }
	{}
};

} // namespace strange

#endif
