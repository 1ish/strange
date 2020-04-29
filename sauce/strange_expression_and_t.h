#ifndef COM_ONEISH_STRANGE_EXPRESSION_AND_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_AND_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_and_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_and_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_and::create not passed any terms");
		}
		any_a<> left = *it;
		if (!check<expression_a<>>(left))
		{
			throw dis(token.report() + "strange::expression_and::create passed non-expression left-hand term");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_and::create not passed sufficient terms");
		}
		any_a<> right = *it;
		if (!check<expression_a<>>(right))
		{
			throw dis(token.report() + "strange::expression_and::create passed non-expression right-hand term");
		}
		return expression_a<>::create<expression_and_t>(token, terms, fast<expression_a<>>(left), fast<expression_a<>>(right));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_and");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_and::create"), native_function::create(&expression_and_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		return boole(_left.operate(thing, list) && _right.operate(thing, list));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_and_t<___ego___>>(expression_t<___ego___>::me_());
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
		// (left && right)
		river.write_string(" (");
		_left.generate(version, indent, river);
		river.write_string(" && ");
		_right.generate(version, indent, river);
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
			_left.generate_cpp(version, indent, river, declare, define);
			_right.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_and::generate_cpp called for wrong type of expression");
		}
		river.write_string(" (");
		_left.generate_cpp(version, indent, river, declare, define);
		river.write_string(" && ");
		_right.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _left;
	expression_a<> const _right;

	friend class any_a<>;

	inline expression_and_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& left, expression_a<> const& right)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _left{ left }
		, _right{ right }
	{}

private:
	static bool const ___share___;
	friend class ___expression_and_t_share___;
};

template <typename ___ego___>
bool const expression_and_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_and_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_and_t_share___
{
	static inline bool ___share___()
	{
		return expression_and_t<>::___share___;
	}
};

} // namespace strange

#endif
