#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_cat_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			return val(token, sym(""),
				expression_literal_t<>::val(token, flock_t<>::val_()),
				expression_literal_t<>::val(token, flock_t<>::val_()),
				expression_literal_t<>::val(token, cat_t<>::any_sym()),
				no());
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			return val(token, cast<symbol_a<>>(name),
				expression_literal_t<>::val(token, flock_t<>::val_()),
				expression_literal_t<>::val(token, flock_t<>::val_()),
				expression_literal_t<>::val(token, cat_t<>::any_sym()),
				no());
		}
		any_a<> arguments = *it;
		if (!check<expression_a<>>(arguments))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-expression arguments");
		}
		if (++it == terms.cend_())
		{
			return val(token, cast<symbol_a<>>(name),
				cast<expression_a<>>(arguments),
				expression_literal_t<>::val(token, flock_t<>::val_()),
				expression_literal_t<>::val(token, cat_t<>::any_sym()),
				no());
		}
		any_a<> parameters = *it;
		if (!check<expression_a<>>(parameters))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-expression parameters");
		}
		if (++it == terms.cend_())
		{
			return val(token, cast<symbol_a<>>(name),
				cast<expression_a<>>(arguments),
				cast<expression_a<>>(parameters),
				expression_literal_t<>::val(token, cat_t<>::any_sym()),
				no());
		}
		any_a<> result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-expression result");
		}
		if (++it == terms.cend_())
		{
			return val(token, cast<symbol_a<>>(name),
				cast<expression_a<>>(arguments),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result),
				no());
		}
		return val(token, cast<symbol_a<>>(name),
			cast<expression_a<>>(arguments),
			cast<expression_a<>>(parameters),
			cast<expression_a<>>(result),
			*it);
	}

	static inline expression_a<> val(token_a<> const& token, symbol_a<> const& name, expression_a<> const& arguments, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& reference)
	{
		return expression_a<>{ expression_cat_t<>(token, name, arguments, parameters, result, reference) };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_cat_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_cat_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		auto arguments = _arguments.operate_(thing, range);
		if (!check<flock_a<>>(arguments))
		{
			throw dis(_token.report() + "strange::expression_cat::operate arguments are not a flock");
		}
		auto parameters = _parameters.operate_(thing, range);
		if (!check<flock_a<>>(parameters))
		{
			throw dis(_token.report() + "strange::expression_cat::operate parameters are not a flock");
		}
		auto result = _result.operate_(thing, range);
		if (!check<symbol_a<>>(result))
		{
			throw dis(_token.report() + "strange::expression_cat::operate result is not a symbol");
		}
		return cat_t<>::val_(_name, cast<flock_a<>>(arguments), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), _reference);
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const //TODO
	{
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const //TODO
	{
	}

protected:
	symbol_a<> const _name;
	expression_a<> const _arguments;
	expression_a<> const _parameters;
	expression_a<> const _result;
	any_a<> const _reference;

	inline expression_cat_t(token_a<> const& token, symbol_a<> const& name, expression_a<> const& arguments, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& reference)
		: expression_t{ token }
		, _name{ name }
		, _arguments{ arguments }
		, _parameters{ parameters }
		, _result{ result }
		, _reference{ reference }
	{}
};

} // namespace strange

#endif
