#ifndef COM_ONEISH_STRANGE_EXPRESSION_CHECK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CHECK_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_check_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_check_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_check::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_check::create passed non-symbol scope");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_check::create passed too few terms");
		}
		any_a<> thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_check::create passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			return expression_a<>{ over{ expression_check_t<>(token, terms, cast<expression_a<>>(thing), expression_kind_t<>::create_(token, flock_t<>::create_())) } };
		}
		any_a<> abstraction = *it;
		if (!check<expression_a<>>(abstraction))
		{
			throw dis(token.report() + "strange::expression_check::create passed non-expression abstraction term");
		}
		return expression_a<>{ over{ expression_check_t<>(token, terms, cast<expression_a<>>(thing), cast<expression_a<>>(abstraction)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_check");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_check::create", native_function_create(&expression_check_t<>::over::create__));
		shoal.update_string("check!", native_function_create(&expression_check_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const evaluated = _thing.operate(thing, range);
		return evaluated.kinds_().has_(_abstraction.operate(thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" check(");
		_thing.generate(version, indent, river);
		river.write_string(", ");
		_abstraction.generate(version, indent, river);
		river.write_string(") ");
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
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_check::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::check<");
		_abstraction.generate_cpp(version, indent, river, declare, define, true); // type
		river.write_string(">(");
		_thing.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	expression_a<> const _abstraction;

	inline expression_check_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, expression_a<> const& abstraction)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _thing{ thing }
		, _abstraction{ abstraction }
	{}

private:
	static bool const ___share___;
	friend class ___expression_check_t_share___;
};

template <typename ___ego___>
bool const expression_check_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_check_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_check_t_share___
{
	static inline bool ___share___()
	{
		return expression_check_t<>::___share___;
	}
};

} // namespace strange

#endif
