#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_cat_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_cat_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			return create(token, terms, number_int_64_t<>::create(1));
		}
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-int-64 order");
		}
		if (++it == terms.cend_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-symbol name");
		}
		if (++it == terms.cend_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<expression_a<>>(dimensions))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-expression dimensions");
		}
		if (++it == terms.cend_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<expression_a<>>(dimensions));
		}
		any_a<> parameters = *it;
		if (!check<expression_a<>>(parameters))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-expression parameters");
		}
		if (++it == terms.cend_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<expression_a<>>(dimensions), cast<expression_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-expression result");
		}
		if (++it == terms.cend_())
		{
			return create(token, terms,
				cast<number_data_a<int64_t>>(order),
				cast<symbol_a<>>(name),
				cast<expression_a<>>(dimensions),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result));
		}
		any_a<> fixed = *it;
		if (++it == terms.cend_())
		{
			return create(token, terms,
				cast<number_data_a<int64_t>>(order),
				cast<symbol_a<>>(name),
				cast<expression_a<>>(dimensions),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result),
				fixed);
		}
		return create(token, terms,
			cast<number_data_a<int64_t>>(order),
			cast<symbol_a<>>(name),
			cast<expression_a<>>(dimensions),
			cast<expression_a<>>(parameters),
			cast<expression_a<>>(result),
			fixed,
			*it);
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""))
	{
		return expression_substitute_t<over>::create(over{ expression_cat_t<>(token, terms, 1, order, name, expression_t<>::create(token), expression_t<>::create(token), expression_t<>::create(token), no(), no()) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions)
	{
		return expression_substitute_t<over>::create(over{ expression_cat_t<>(token, terms, 2, order, name, dimensions, expression_t<>::create(token), expression_t<>::create(token), no(), no()) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& parameters)
	{
		return expression_substitute_t<over>::create(over{ expression_cat_t<>(token, terms, 3, order, name, dimensions, parameters, expression_t<>::create(token), no(), no()) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& fixed = no(), any_a<> const& optional = no())
	{
		return expression_substitute_t<over>::create(over{ expression_cat_t<>(token, terms, 4, order, name, dimensions, parameters, result, fixed, optional) });
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
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		if (_count <= 1)
		{
			return cat_t<>::create_(_order, _name);
		}
		auto dimensions = _dimensions.operate(thing, range);
		if (!check<flock_a<>>(dimensions))
		{
			throw dis(_token.report() + "strange::expression_cat::operate dimensions are not a flock");
		}
		if (_count == 2)
		{
			return cat_t<>::create_(_order, _name, cast<flock_a<>>(dimensions));
		}
		auto parameters = _parameters.operate(thing, range);
		if (!check<flock_a<>>(parameters))
		{
			throw dis(_token.report() + "strange::expression_cat::operate parameters are not a flock");
		}
		if (_count == 3)
		{
			return cat_t<>::create_(_order, _name, cast<flock_a<>>(dimensions), cast<flock_a<>>(parameters));
		}
		auto result = _result.operate(thing, range);
		if (!check<symbol_a<>>(result))
		{
			throw dis(_token.report() + "strange::expression_cat::operate result is not a symbol");
		}
		return cat_t<>::create_(_order, _name, cast<flock_a<>>(dimensions), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), _fixed, _optional);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// <name[d1,d2,d3](p1,p2,p3):result>&
		river.write_string(" <" + _name.to_string());
		if (_count >= 2)
		{
			_dimensions.generate(version, indent, river);
			if (_count >= 3)
			{
				auto parameters = river_t<>::create();
				_parameters.generate(version, indent, parameters);
				auto str = parameters.to_string();
				auto len = str.length();
				if (len >= 4 && str[1] == '{' && str[len - 2] == '}')
				{
					str[1] = '(';
					str[len - 2] = ')';
					river.write_string(str);
				}
				if (_count >= 4)
				{
					river.write_string(":");
					_result.generate(version, indent, river);
					if (_fixed)
					{
						river.write_string(">& ");
						return;
					}
				}
			}
		}
		river.write_string("> ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool def, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_cat::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::cat_t<>::create(\"" + _name.to_string() + "\"");
		if (_count >= 2)
		{
			river.write_string(",");
			_dimensions.generate_cpp(version, indent, river, def);
			if (_count >= 3)
			{
				river.write_string(",");
				_parameters.generate_cpp(version, indent, river, def);
				if (_count >= 4)
				{
					river.write_string(",");
					_result.generate_cpp(version, indent, river, def);
					if (_fixed)
					{
						river.write_string(", true");
					}
					else if (_optional)
					{
						river.write_string(", false");
					}
					if (_optional)
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
	number_data_a<int64_t> const _order;
	symbol_a<> const _name;
	expression_a<> const _dimensions;
	expression_a<> const _parameters;
	expression_a<> const _result;
	any_a<> const _fixed;
	any_a<> const _optional;

	inline expression_cat_t(token_a<> const& token, flock_a<> const& terms, int64_t count, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& fixed, any_a<> const& optional)
		: expression_t(token, dimensions.pure() && parameters.pure() && result.pure(), dimensions.literal() && parameters.literal() && result.literal()) // pure, literal
		, _terms{ terms }
		, _count{ count }
		, _order{ order }
		, _name{ name }
		, _dimensions{ dimensions }
		, _parameters{ parameters }
		, _result{ result }
		, _fixed{ fixed }
		, _optional{ optional }
	{}

private:
	static bool const ___share___;
	friend class ___expression_cat_t_share___;
};

template <typename ___ego___>
bool const expression_cat_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_cat_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
