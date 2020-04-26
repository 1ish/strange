#ifndef COM_ONEISH_STRANGE_EXPRESSION_RETURN_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_RETURN_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_return_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_return_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_return::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_return::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			return create(token, terms);
		}
		any_a<> result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis("strange::expression_return::create passed non-expression result");
		}
		return create(token, terms, fast<expression_a<>>(result));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_a<>::create<expression_return_t<>>(token, terms, expression_t<>::create(token));
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, expression_a<> const& result)
	{
		return expression_a<>::create<expression_return_t<>>(token, terms, result);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_return");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_return::create"), native_function_create(&expression_return_t<>::create__));
		shoal.update(sym("return!"), native_function_create(&expression_return_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		throw typename expression_t<___ego___>::return_e{ _result.operate(thing, list) };
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_return_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, list_create());
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
		river.write_string(" return(");
		_result.generate(version, indent, river);
		river.write_string(") ");
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
			_result.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_return::generate_cpp called for wrong type of expression");
		}
		river.write_string(" return(");
		_result.generate_cpp(version, indent, river, declare, define);
		river.write_string("); ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _result;

	friend class any_a<>;

	inline expression_return_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& result)
		: expression_t<___ego___>(token, result.pure(), result.literal()) // pure, literal
		, _terms{ terms }
		, _result{ result }
	{}

private:
	static bool const ___share___;
	friend class ___expression_return_t_share___;
};

template <typename ___ego___>
bool const expression_return_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_return_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_return_t_share___
{
	static inline bool ___share___()
	{
		return expression_return_t<>::___share___;
	}
};

} // namespace strange

#endif
