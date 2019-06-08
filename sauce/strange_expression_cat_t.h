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
			return val(token, sym(""), no(), no(), no(), no());
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			return val(token, cast<symbol_a<>>(name), no(), no(), no(), no());
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
				no(), no(), no());
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
				no(), no());
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

	static inline expression_a<> val(token_a<> const& token, symbol_a<> const& name, any_a<> const& arguments, any_a<> const& parameters, any_a<> const& result, any_a<> const& reference)
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
		if (!check<expression_a<>>(_arguments))
		{
			return cat_t<>::val_(_name);
		}
		auto arguments = cast<expression_a<>>(_arguments).operate_(thing, range);
		if (!check<flock_a<>>(arguments))
		{
			throw dis(_token.report() + "strange::expression_cat::operate arguments are not a flock");
		}
		if (!check<expression_a<>>(_parameters))
		{
			return cat_t<>::val_(_name, cast<flock_a<>>(arguments));
		}
		auto parameters = cast<expression_a<>>(_parameters).operate_(thing, range);
		if (!check<flock_a<>>(parameters))
		{
			throw dis(_token.report() + "strange::expression_cat::operate parameters are not a flock");
		}
		if (!check<expression_a<>>(_result))
		{
			return cat_t<>::val_(_name, cast<flock_a<>>(arguments), cast<flock_a<>>(parameters));
		}
		auto result = cast<expression_a<>>(_result).operate_(thing, range);
		if (!check<symbol_a<>>(result))
		{
			throw dis(_token.report() + "strange::expression_cat::operate result is not a symbol");
		}
		return cat_t<>::val_(_name, cast<flock_a<>>(arguments), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), _reference);
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_(lake_from_string(" <" + _name.to_string()));
		if (check<expression_a<>>(_arguments))
		{
			cast<expression_a<>>(_arguments).generate(indent, river);
			if (check<expression_a<>>(_parameters))
			{
				auto params = river_t<>::val();
				cast<expression_a<>>(_parameters).generate(indent, params);
				auto str = params.to_string();
				auto len = str.length();
				if (len >= 4 && str[1] == '[' && str[len - 2] == ']')
				{
					str[1] = '(';
					str[len - 2] = ')';
					river.write_(lake_from_string(str));
				}
				if (check<expression_a<>>(_result))
				{
					cast<expression_a<>>(_result).generate(indent, river);
					if (_reference)
					{
						river.write_(lake_from_string(">& "));
						return;
					}
				}
			}
		}
		river.write_(lake_from_string("> "));
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_(lake_from_string(" strange::cat_t<>::val(\"" + _name.to_string() + "\""));
		if (check<expression_a<>>(_arguments))
		{
			river.write_(lake_from_string(","));
			cast<expression_a<>>(_arguments).generate_cpp(indent, river);
			if (check<expression_a<>>(_parameters))
			{
				river.write_(lake_from_string(","));
				cast<expression_a<>>(_parameters).generate_cpp(indent, river);
				if (check<expression_a<>>(_result))
				{
					river.write_(lake_from_string(","));
					cast<expression_a<>>(_result).generate_cpp(indent, river);
					if (_reference)
					{
						river.write_(lake_from_string(", true"));
					}
				}
			}
		}
		river.write_(lake_from_string(") "));
	}

protected:
	symbol_a<> const _name;
	any_a<> const _arguments;
	any_a<> const _parameters;
	any_a<> const _result;
	any_a<> const _reference;

	inline expression_cat_t(token_a<> const& token, symbol_a<> const& name, any_a<> const& arguments, any_a<> const& parameters, any_a<> const& result, any_a<> const& reference)
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
