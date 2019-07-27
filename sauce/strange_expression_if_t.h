#ifndef COM_ONEISH_STRANGE_EXPRESSION_IF_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_IF_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_if_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_if_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_if::val not passed any terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_if::val passed non-expression condition");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_if::val not passed sufficient terms");
		}
		any_a<> yay = *it;
		if (!check<expression_a<>>(yay))
		{
			throw dis(token.report() + "strange::expression_if::val passed non-expression");
		}
		if (++it == terms.cend_())
		{
			return expression_a<>{ over{ expression_if_t<>( token, terms, cast<expression_a<>>(condition), cast<expression_a<>>(yay), expression_t<>::val(token)) } };
		}
		any_a<> nay = *it;
		if (!check<expression_a<>>(nay))
		{
			throw dis(token.report() + "strange::expression_if::val passed non-expression");
		}
		return expression_a<>{ over{ expression_if_t<>( token, terms, cast<expression_a<>>(condition), cast<expression_a<>>(yay), cast<expression_a<>>(nay)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_if_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_if_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		if (_condition.operate_(thing, range))
		{
			return _yay.operate_(thing, range);
		}
		return _nay.operate_(thing, range);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" if_(");
		bool first = true;
		for (auto const& term : _terms)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_if::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" (");
		_condition.generate_cpp(version, indent, river);
		river.write_string(") ? (");
		_yay.generate_cpp(version, indent, river);
		river.write_string(") : (");
		_nay.generate_cpp(version, indent, river);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _condition;
	expression_a<> const _yay;
	expression_a<> const _nay;

	inline expression_if_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& condition, expression_a<> const& yay, expression_a<> const& nay)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _condition{ condition }
		, _yay{ yay }
		, _nay{ nay }
	{}

private:
	static bool const ___share___;
	friend class ___expression_if_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_if_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_if_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
