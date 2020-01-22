#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAST_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAST_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_cast_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_cast_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_cast::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_cast::create passed non-symbol scope");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_cast::create passed too few terms");
		}
		any_a<> thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_cast::create passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			return expression_a<>{ over{ expression_cast_t<>(token, terms, cast<expression_a<>>(thing), expression_kind_t<>::create_(token, flock_t<>::create_())) } };
		}
		any_a<> abstraction = *it;
		if (!check<expression_a<>>(abstraction))
		{
			throw dis(token.report() + "strange::expression_cast::create passed non-expression abstraction term");
		}
		return expression_a<>{ over{ expression_cast_t<>(token, terms, cast<expression_a<>>(thing), cast<expression_a<>>(abstraction)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_cast_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_cast_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const evaluated = _thing.operate(thing, range);
		auto const abstraction = _abstraction.operate(thing, range);
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!evaluated.kinds_().has_(abstraction))
		{
			throw dis(_token.report() + "strange::expression_cast::operate check failed");
		}
#endif
		return evaluated;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" cast(");
		_thing.generate(version, indent, river);
		river.write_string(", ");
		_abstraction.generate(version, indent, river);
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool def, bool type = false) const
	{
		if (def)
		{
			_abstraction.generate_cpp(version, indent, river, def);
			_thing.generate_cpp(version, indent, river, def);
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_cast::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::cast<");
		_abstraction.generate_cpp(version, indent, river, def, true); // type
		river.write_string(">(");
		_thing.generate_cpp(version, indent, river, def);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	expression_a<> const _abstraction;

	inline expression_cast_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, expression_a<> const& abstraction)
		: expression_t(token, pure_literal_terms(token, terms))
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
	return shoal.something();
}();

} // namespace strange

#endif
