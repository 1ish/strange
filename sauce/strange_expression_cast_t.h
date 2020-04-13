#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAST_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAST_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_cast_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_cast_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_cast::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_cast::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_cast::create passed too few terms");
		}
		any_a<> thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_cast::create passed non-expression thing term");
		}
		if (++it == terms.extract_end_())
		{
			return expression_a<>::create<expression_cast_t<>>(token, terms, fast<expression_a<>>(thing), expression_kind_t<>::create_(token, flock_t<>::create_()));
		}
		any_a<> abstraction = *it;
		if (!check<expression_a<>>(abstraction))
		{
			throw dis(token.report() + "strange::expression_cast::create passed non-expression abstraction term");
		}
		return expression_a<>::create<expression_cast_t<>>(token, terms, fast<expression_a<>>(thing), fast<expression_a<>>(abstraction));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_cast");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_cast::create"), native_function_create(&expression_cast_t<>::create__));
		shoal.update(sym("cast!"), native_function_create(&expression_cast_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const evaluated = _thing.operate(thing, range);
		auto const abstraction = _abstraction.operate(thing, range);
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!evaluated.kinds_().has_(abstraction))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_cast::operate check failed");
		}
#endif
		return evaluated;
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_cast_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<any_a<>, any_a<>, true>());
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
		river.write_string(" cast(");
		_thing.generate(version, indent, river);
		river.write_string(", ");
		_abstraction.generate(version, indent, river);
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
			_abstraction.generate_cpp(version, indent, river, declare, define);
			_thing.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_cast::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::cast<");
		_abstraction.generate_cpp(version, indent, river, declare, define, true); // type
		river.write_string(">(");
		_thing.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	expression_a<> const _abstraction;

	friend class any_a<>;

	inline expression_cast_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, expression_a<> const& abstraction)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _thing{ thing }
		, _abstraction{ abstraction }
	{}

private:
	static bool const ___share___;
	friend class ___expression_cast_t_share___;
};

template <typename ___ego___>
bool const expression_cast_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_cast_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_cast_t_share___
{
	static inline bool ___share___()
	{
		return expression_cast_t<>::___share___;
	}
};

} // namespace strange

#endif
