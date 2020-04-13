#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_invoke_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_invoke_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_invoke::create passed empty range");
		}
		auto expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_invoke::create passed non-expression");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_invoke::create passed short range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_invoke::create passed non-symbol member");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_invoke::create passed short range");
		}
		auto range = *it;
		if (!check<range_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_invoke::create passed non-range");
		}
		return expression_substitute_t<expression_invoke_t<>>::create(expression_invoke_t<>(token, terms, fast<expression_a<>>(expression), fast<symbol_a<>>(member), fast<range_a<>>(range)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_invoke");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_invoke::create"), native_function_create(&expression_invoke_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto expression_thing = _expression.operate(thing, range);
		return thing_t<>::invoke_member(expression_thing, _member, range_operator_t<>::create_(_range, thing, range));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_invoke_t<___ego___>>(expression_t<___ego___>::me_());
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

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// (thing.name[x,y,z]) - or could have done (thing.call['name',x,y,z]) instead
		river.write_string(" (");
		_expression.generate(version, indent, river);
		river.write_string("." + _member.to_string() + "[");
		bool first = true;
		for (auto const& expression : _range)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(expression))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_invoke::generate with non-expression range term");
			}
			fast<expression_a<>>(expression).generate(version, indent, river);
		}
		river.write_string("]) ");
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
			_expression.generate_cpp(version, indent, river, declare, define);
			for (auto const& expression : _range)
			{
				if (!check<expression_a<>>(expression))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_invoke::generate_cpp with non-expression argument");
				}
				fast<expression_a<>>(expression).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_invoke::generate_cpp called for wrong type of expression");
		}
		river.write_string(" (");
		_expression.generate_cpp(version, indent, river, declare, define);
		river.write_string("[flock_t<>::create_(" + _member.to_string() + ",");
		bool first = true;
		for (auto const& expression : _range)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(expression))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_invoke::generate with non-expression range term");
			}
			fast<expression_a<>>(expression).generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(")]) ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _expression;
	symbol_a<> const _member;
	range_a<> const _range;

	friend class any_a<>;

	inline expression_invoke_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& expression, symbol_a<> const& member, range_a<> const& range)
		: expression_t<___ego___>(token, is_pure_literal(token, expression, member, range))
		, _terms{ terms }
		, _expression{ expression }
		, _member{ member }
		, _range{ range }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, expression_a<> const& expression, symbol_a<> const& member, range_a<> const& range)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_invoke_t_share___;
};

template <typename ___ego___>
bool const expression_invoke_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_invoke_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_invoke_t_share___
{
	static inline bool ___share___()
	{
		return expression_invoke_t<>::___share___;
	}
};

} // namespace strange

#endif
