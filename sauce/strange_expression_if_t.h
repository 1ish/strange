#ifndef COM_ONEISH_STRANGE_EXPRESSION_IF_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_IF_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_if_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_if_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_if::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_if::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_if::create passed too few terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_if::create passed non-expression condition");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_if::create not passed sufficient terms");
		}
		any_a<> yay = *it;
		if (!check<expression_a<>>(yay))
		{
			throw dis(token.report() + "strange::expression_if::create passed non-expression");
		}
		if (++it == terms.extract_end_())
		{
			return expression_a<>::create<expression_if_t<>>(token, terms, fast<expression_a<>>(condition), fast<expression_a<>>(yay), expression_t<>::create(token));
		}
		any_a<> nay = *it;
		if (!check<expression_a<>>(nay))
		{
			throw dis(token.report() + "strange::expression_if::create passed non-expression");
		}
		return expression_a<>::create<expression_if_t<>>(token, terms, fast<expression_a<>>(condition), fast<expression_a<>>(yay), fast<expression_a<>>(nay));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_if");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_if::create"), native_function_create(&expression_if_t<>::create__));
		shoal.update(sym("if!"), native_function_create(&expression_if_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		any_a<> local = any_a<>::val(thing); // new block scope
		if (_condition.operate(local, range))
		{
			return _yay.operate(local, range);
		}
		return _nay.operate(local, range);
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_if_t<___ego___>>(expression_t<___ego___>::me_());
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
		river.write_string(" if(");
		_condition.generate(version, indent, river);
		river.write_string(", ");
		_yay.generate(version, indent, river);
		river.write_string(", ");
		_nay.generate(version, indent, river);
		river.write_string(")\n");
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
			_condition.generate_cpp(version, indent, river, declare, define);
			_yay.generate_cpp(version, indent, river, declare, define);
			_nay.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_if::generate_cpp called for wrong type of expression");
		}
		river.write_string(" (");
		_condition.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ? (");
		_yay.generate_cpp(version, indent, river, declare, define);
		river.write_string(") : (");
		_nay.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _condition;
	expression_a<> const _yay;
	expression_a<> const _nay;

	friend class any_a<>;

	inline expression_if_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& condition, expression_a<> const& yay, expression_a<> const& nay)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _condition{ condition }
		, _yay{ yay }
		, _nay{ nay }
	{}

private:
	static bool const ___share___;
	friend class ___expression_if_t_share___;
};

template <typename ___ego___>
bool const expression_if_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_if_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_if_t_share___
{
	static inline bool ___share___()
	{
		return expression_if_t<>::___share___;
	}
};

} // namespace strange

#endif
