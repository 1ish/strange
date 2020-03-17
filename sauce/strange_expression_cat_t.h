#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAT_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_cat_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_cat_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_extractor_a<> it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			return create(token, terms, number_int_64_t<>::create(1));
		}
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-int-64 order");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, fast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-symbol name");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<expression_a<>>(dimensions))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-expression dimensions");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<expression_a<>>(dimensions));
		}
		any_a<> parameters = *it;
		if (!check<expression_a<>>(parameters))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-expression parameters");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<expression_a<>>(dimensions), fast<expression_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis(token.report() + "strange::expression_cat::create passed non-expression result");
		}
		return create(token, terms,
			fast<number_data_a<int64_t>>(order),
			fast<symbol_a<>>(name),
			fast<expression_a<>>(dimensions),
			fast<expression_a<>>(parameters),
			fast<expression_a<>>(result));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""))
	{
		return expression_substitute_t<expression_cat_t<>>::create(expression_cat_t<>(token, terms, 1, order, name, expression_t<>::create(token), expression_t<>::create(token), expression_t<>::create(token)));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions)
	{
		return expression_substitute_t<expression_cat_t<>>::create(expression_cat_t<>(token, terms, 2, order, name, dimensions, expression_t<>::create(token), expression_t<>::create(token)));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& parameters)
	{
		return expression_substitute_t<expression_cat_t<>>::create(expression_cat_t<>(token, terms, 3, order, name, dimensions, parameters, expression_t<>::create(token)));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& parameters, expression_a<> const& result)
	{
		return expression_substitute_t<expression_cat_t<>>::create(expression_cat_t<>(token, terms, 4, order, name, dimensions, parameters, result));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_cat");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_cat::create", native_function_create(&expression_cat_t<>::create__));
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
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_cat::operate dimensions are not a flock");
		}
		if (_count == 2)
		{
			return cat_t<>::create_(_order, _name, fast<flock_a<>>(dimensions));
		}
		auto parameters = _parameters.operate(thing, range);
		if (!check<flock_a<>>(parameters))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_cat::operate parameters are not a flock");
		}
		if (_count == 3)
		{
			return cat_t<>::create_(_order, _name, fast<flock_a<>>(dimensions), fast<flock_a<>>(parameters));
		}
		auto result = _result.operate(thing, range);
		if (!check<symbol_a<>>(result))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_cat::operate result is not a symbol");
		}
		return cat_t<>::create_(_order, _name, fast<flock_a<>>(dimensions), fast<flock_a<>>(parameters), fast<symbol_a<>>(result));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_cat_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<true>());
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
				}
			}
		}
		river.write_string("> ");
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
			_dimensions.generate_cpp(version, indent, river, declare, define);
			_parameters.generate_cpp(version, indent, river, declare, define);
			_result.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_cat::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::cat_t<>::create(\"" + _name.to_string() + "\"");
		if (_count >= 2)
		{
			river.write_string(",");
			_dimensions.generate_cpp(version, indent, river, declare, define);
			if (_count >= 3)
			{
				river.write_string(",");
				_parameters.generate_cpp(version, indent, river, declare, define);
				if (_count >= 4)
				{
					river.write_string(",");
					_result.generate_cpp(version, indent, river, declare, define);
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

	friend class any_a<>;

	inline expression_cat_t(token_a<> const& token, flock_a<> const& terms, int64_t count, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& parameters, expression_a<> const& result)
		: expression_t<___ego___>(token, dimensions.pure() && parameters.pure() && result.pure(), dimensions.literal() && parameters.literal() && result.literal()) // pure, literal
		, _terms{ terms }
		, _count{ count }
		, _order{ order }
		, _name{ name }
		, _dimensions{ dimensions }
		, _parameters{ parameters }
		, _result{ result }
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
	return shoal;
}();

class ___expression_cat_t_share___
{
	static inline bool ___share___()
	{
		return expression_cat_t<>::___share___;
	}
};

} // namespace strange

#endif
