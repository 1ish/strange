#ifndef COM_ONEISH_STRANGE_EXPRESSION_KIND_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_KIND_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_kind_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_kind_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_extractor_a<> it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			return create(token, terms);
		}
		auto const order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-int-64 order");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order));
		}
		auto const name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-symbol name");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name));
		}
		auto const dimensions = *it;
		if (!check<expression_a<>>(dimensions))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-expression dimensions");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<expression_a<>>(dimensions));
		}
		auto const aspects = *it;
		if (!check<expression_a<>>(aspects))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-expression aspects");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<expression_a<>>(dimensions), cast<expression_a<>>(aspects));
		}
		auto const parameters = *it;
		if (!check<expression_a<>>(parameters))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-expression parameters");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms, cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<expression_a<>>(dimensions), cast<expression_a<>>(aspects), cast<expression_a<>>(parameters));
		}
		auto const result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-expression result");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms,
				cast<number_data_a<int64_t>>(order),
				cast<symbol_a<>>(name),
				cast<expression_a<>>(dimensions),
				cast<expression_a<>>(aspects),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result));
		}
		auto const fixed = *it;
		if (++it == terms.extract_end_())
		{
			return create(token, terms,
				cast<number_data_a<int64_t>>(order),
				cast<symbol_a<>>(name),
				cast<expression_a<>>(dimensions),
				cast<expression_a<>>(aspects),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result),
				fixed);
		}
		auto const reference = *it;
		if (++it == terms.extract_end_())
		{
			return create(token, terms,
				cast<number_data_a<int64_t>>(order),
				cast<symbol_a<>>(name),
				cast<expression_a<>>(dimensions),
				cast<expression_a<>>(aspects),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result),
				fixed,
				reference);
		}
		auto const optional = *it;
		if (++it == terms.extract_end_())
		{
			return create(token, terms,
				cast<number_data_a<int64_t>>(order),
				cast<symbol_a<>>(name),
				cast<expression_a<>>(dimensions),
				cast<expression_a<>>(aspects),
				cast<expression_a<>>(parameters),
				cast<expression_a<>>(result),
				fixed,
				reference,
				optional);
		}
		auto const expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_kind::create passed non-expression");
		}
		return create(token, terms,
			cast<number_data_a<int64_t>>(order),
			cast<symbol_a<>>(name),
			cast<expression_a<>>(dimensions),
			cast<expression_a<>>(aspects),
			cast<expression_a<>>(parameters),
			cast<expression_a<>>(result),
			fixed,
			reference,
			optional,
			cast<expression_a<>>(expression));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order = number_int_64_t<>::create(1), symbol_a<> const& name = sym(""))
	{
		return expression_substitute_t<over>::create(over{ expression_kind_t<>(token, terms, order, name, expression_t<>::create(token), expression_t<>::create(token), expression_t<>::create(token), expression_t<>::create(token), no(), no(), no(), expression_t<>::create(token)) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions)
	{
		return expression_substitute_t<over>::create(over{ expression_kind_t<>(token, terms, order, name, dimensions, expression_t<>::create(token), expression_t<>::create(token), expression_t<>::create(token), no(), no(), no(), expression_t<>::create(token)) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& aspects)
	{
		return expression_substitute_t<over>::create(over{ expression_kind_t<>(token, terms, order, name, dimensions, aspects, expression_t<>::create(token), expression_t<>::create(token), no(), no(), no(), expression_t<>::create(token)) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& aspects, expression_a<> const& parameters)
	{
		return expression_substitute_t<over>::create(over{ expression_kind_t<>(token, terms, order, name, dimensions, aspects, parameters, expression_t<>::create(token), no(), no(), no(), expression_t<>::create(token)) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& aspects, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& fixed = no(), any_a<> const& reference = no(), any_a<> const& optional = no())
	{
		return expression_substitute_t<over>::create(over{ expression_kind_t<>(token, terms, order, name, dimensions, aspects, parameters, result, fixed, reference, optional, expression_t<>::create(token)) });
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& aspects, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional, expression_a<> const& expression)
	{
		return expression_substitute_t<over>::create(over{ expression_kind_t<>(token, terms, order, name, dimensions, aspects, parameters, result, fixed, reference, optional, expression) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_kind");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_kind::create", native_function_create(&expression_kind_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		if (_count <= 2)
		{
			return kind_t<>::create_(_order, _name);
		}
		if (_count == 10)
		{
			auto const any_kind = _expression.operate(thing, range);
			if (!check<kind_a<>>(any_kind))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_kind::operate expression did not return a kind");
			}
			auto const kind = cast<kind_a<>>(any_kind);
			return kind_t<>::create_(number_int_64_t<>::create(kind.order() + _order.extract_primitive()), kind.name_(), kind.dimensions_(), kind.aspects_(), kind.parameters_(), kind.result_(), _fixed, _reference, _optional);
		}
		auto const dimensions = _dimensions.operate(thing, range);
		if (!check<flock_a<>>(dimensions))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_kind::operate dimensions are not a flock");
		}
		if (_count == 3)
		{
			return kind_t<>::create_(_order, _name, cast<flock_a<>>(dimensions));
		}
		auto const aspects = _aspects.operate(thing, range);
		if (!check<flock_a<>>(aspects))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_kind::operate aspects are not a flock");
		}
		if (_count == 4)
		{
			return kind_t<>::create_(_order, _name, cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects));
		}
		auto const parameters = _parameters.operate(thing, range);
		if (!check<flock_a<>>(parameters))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_kind::operate parameters are not a flock");
		}
		if (_count == 5)
		{
			return kind_t<>::create_(_order, _name, cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters));
		}
		auto const result = _result.operate(thing, range);
		if (!check<symbol_a<>>(result))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_kind::operate result is not a symbol");
		}
		return kind_t<>::create_(_order, _name, cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), _fixed, _reference, _optional);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO _count == 9 : _expression
	{
		river.write_string(" <" + _name.to_string());
		if (_count >= 3)
		{
			_dimensions.generate(version, indent, river);
			if (_count >= 4)
			{
				_aspects.generate(version, indent, river);
				if (_count >= 5)
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
					if (_count >= 6)
					{
						river.write_string(":");
						_result.generate(version, indent, river);
						if (_fixed)
						{
							river.write_string(">& "); //TODO reference
							return;
						}
					}
				}
			}
		}
		river.write_string("> ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_dimensions.generate_cpp(version, indent, river, declare, define);
			_aspects.generate_cpp(version, indent, river, declare, define);
			_parameters.generate_cpp(version, indent, river, declare, define);
			_result.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			if (_expression.type_() == expression_local_at_t<>::type_())
			{
				_expression.generate_cpp(version, 0, river, false, false);
			}
			else
			{
				std::string const name = _name.to_string();
				river.write_string(" " + (name.empty() ? std::string("any") : name) + "_a<> "); //TODO
			}
			if (_fixed)
			{
				river.write_string("const& ");
			}
			else if (_reference)
			{
				river.write_string("& ");
			}
			return;
		}
		if (_count == 10)
		{
			//TODO _count == 10 : _expression
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_kind::generate_cpp expression kind expression not implemented yet");
		}
		river.write_string(" strange::kind_t<>::create(\"" + std::to_string(_order) + ", " + _name.to_string() + "\"");
		if (_count >= 3)
		{
			river.write_string(",");
			_dimensions.generate_cpp(version, indent, river, declare, define);
			if (_count >= 4)
			{
				river.write_string(",");
				_aspects.generate_cpp(version, indent, river, declare, define);
				if (_count >= 5)
				{
					river.write_string(",");
					_parameters.generate_cpp(version, indent, river, declare, define);
					if (_count >= 6)
					{
						river.write_string(",");
						_result.generate_cpp(version, indent, river, declare, define);
						if (_count >= 7)
						{
							river.write_string(_fixed ? ", true" : ", false");
							if (_count >= 8)
							{
								river.write_string(_reference ? ", true" : ", false");
								if (_count >= 9)
								{
									river.write_string(_optional ? ", true" : ", false");
								}
							}
						}
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
	expression_a<> const _aspects;
	expression_a<> const _parameters;
	expression_a<> const _result;
	any_a<> const _fixed;
	any_a<> const _reference;
	any_a<> const _optional;
	expression_a<> const _expression;

	inline expression_kind_t(token_a<> const& token, flock_a<> const& terms, number_data_a<int64_t> const& order, symbol_a<> const& name, expression_a<> const& dimensions, expression_a<> const& aspects, expression_a<> const& parameters, expression_a<> const& result, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional, expression_a<> const& expression)
		: expression_t<___ego___>(token, dimensions.pure() && aspects.pure() && parameters.pure() && result.pure() && expression.pure(), dimensions.literal() && aspects.literal() && parameters.literal() && result.literal() && expression.literal()) // pure, literal
		, _terms{ terms }
		, _count{ _terms.size() }
		, _order{ order }
		, _name{ name }
		, _dimensions{ dimensions }
		, _aspects{ aspects }
		, _parameters{ parameters }
		, _result{ result }
		, _fixed{ fixed }
		, _reference{ reference }
		, _optional{ optional }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_kind_t_share___;
};

template <typename ___ego___>
bool const expression_kind_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_kind_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_kind_t_share___
{
	static inline bool ___share___()
	{
		return expression_kind_t<>::___share___;
	}
};

} // namespace strange

#endif
