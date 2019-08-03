#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_cat_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_cat_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			return val(token, terms);
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			return val(token, terms, cast<symbol_a<>>(name));
		}
		any_a<> args = *it;
		if (!check<expression_a<>>(args))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-expression args");
		}
		if (++it == terms.cend_())
		{
			return val(token, terms, cast<symbol_a<>>(name), cast<expression_a<>>(args));
		}
		any_a<> params = *it;
		if (!check<expression_a<>>(params))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-expression params");
		}
		if (++it == terms.cend_())
		{
			return val(token, terms, cast<symbol_a<>>(name), cast<expression_a<>>(args), cast<expression_a<>>(params));
		}
		any_a<> result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis(token.report() + "strange::expression_cat::val passed non-expression result");
		}
		if (++it == terms.cend_())
		{
			return val(token, terms, cast<symbol_a<>>(name),
				cast<expression_a<>>(args),
				cast<expression_a<>>(params),
				cast<expression_a<>>(result));
		}
		return val(token, terms, cast<symbol_a<>>(name),
			cast<expression_a<>>(args),
			cast<expression_a<>>(params),
			cast<expression_a<>>(result),
			*it);
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name = sym(""))
	{
		return expression_substitute_t<over>::val(over{ expression_cat_t<>(token, terms, 1, name, expression_t<>::val(token), expression_t<>::val(token), expression_t<>::val(token), no(), no()) });
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, expression_a<> const& args)
	{
		return expression_substitute_t<over>::val(over{ expression_cat_t<>(token, terms, 2, name, args, expression_t<>::val(token), expression_t<>::val(token), no(), no()) });
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, expression_a<> const& args, expression_a<> const& params)
	{
		return expression_substitute_t<over>::val(over{ expression_cat_t<>(token, terms, 3, name, args, params, expression_t<>::val(token), no(), no()) });
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, expression_a<> const& args, expression_a<> const& params, expression_a<> const& result, any_a<> const& def = no(), any_a<> const& ref = no())
	{
		return expression_substitute_t<over>::val(over{ expression_cat_t<>(token, terms, 4, name, args, params, result, def, ref) });
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
		if (_count <= 1)
		{
			return cat_t<>::val_(_name);
		}
		auto args = _args.operate_(thing, range);
		if (!check<flock_a<>>(args))
		{
			throw dis(_token.report() + "strange::expression_cat::operate args are not a flock");
		}
		if (_count == 2)
		{
			return cat_t<>::val_(_name, cast<flock_a<>>(args));
		}
		auto params = _params.operate_(thing, range);
		if (!check<flock_a<>>(params))
		{
			throw dis(_token.report() + "strange::expression_cat::operate params are not a flock");
		}
		if (_count == 3)
		{
			return cat_t<>::val_(_name, cast<flock_a<>>(args), cast<flock_a<>>(params));
		}
		auto result = _result.operate_(thing, range);
		if (!check<symbol_a<>>(result))
		{
			throw dis(_token.report() + "strange::expression_cat::operate result is not a symbol");
		}
		return cat_t<>::val_(_name, cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), _def, _ref);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" <" + _name.to_string());
		if (_count >= 2)
		{
			_args.generate(version, indent, river);
			if (_count >= 3)
			{
				auto params = river_t<>::val();
				_params.generate(version, indent, params);
				auto str = params.to_string();
				auto len = str.length();
				if (len >= 4 && str[1] == '[' && str[len - 2] == ']')
				{
					str[1] = '(';
					str[len - 2] = ')';
					river.write_string(str);
				}
				if (_count >= 4)
				{
					river.write_string(":");
					_result.generate(version, indent, river);
					if (_ref)
					{
						river.write_string(">& ");
						return;
					}
				}
			}
		}
		river.write_string("> ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" strange::cat_t<>::val(\"" + _name.to_string() + "\"");
		if (_count >= 2)
		{
			river.write_string(",");
			_args.generate_cpp(version, indent, river);
			if (_count >= 3)
			{
				river.write_string(",");
				_params.generate_cpp(version, indent, river);
				if (_count >= 4)
				{
					river.write_string(",");
					_result.generate_cpp(version, indent, river);
					if (_def)
					{
						river.write_string(", true");
					}
					else if (_ref)
					{
						river.write_string(", false");
					}
					if (_ref)
					{
						river.write_string(", true");
					}
				}
			}
		}
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	int64_t const _count;
	symbol_a<> const _name;
	expression_a<> const _args;
	expression_a<> const _params;
	expression_a<> const _result;
	any_a<> const _def;
	any_a<> const _ref;

	inline expression_cat_t(token_a<> const& token, flock_a<> const& terms, int64_t count, symbol_a<> const& name, expression_a<> const& args, expression_a<> const& params, expression_a<> const& result, any_a<> const& def, any_a<> const& ref)
		: expression_t(token, args.pure() && params.pure() && result.pure(), args.literal() && params.literal() && result.literal()) // pure, literal
		, _terms{ terms }
		, _count{ count }
		, _name{ name }
		, _args{ args }
		, _params{ params }
		, _result{ result }
		, _def{ def }
		, _ref{ ref }
	{}

private:
	static bool const ___share___;
	friend class ___expression_cat_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_cat_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_cat_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
