#ifndef COM_ONEISH_STRANGE_EXPRESSION_LITERAL_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LITERAL_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_literal_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_literal::val not passed any terms");
		}
		return expression_a<>{ expression_literal_t<>{ token, *it } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_literal_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_literal_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return _literal;
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		auto const& tag = _token.tag();
		if (tag == "symbol")
		{
			river.write_(lake_from_string(" '" + _token.symbol() + "' "));
		}
		else if (tag == "lake")
		{
			river.write_(lake_from_string(" \"" + _token.symbol() + "\" "));
		}
		else
		{
			river.write_(lake_from_string(" " + _token.symbol() + " "));
		}
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		auto const& tag = _token.tag();
		if (tag == "symbol")
		{
			river.write_(lake_from_string(" strange::sym(\"" + _token.symbol() + "\") "));
		}
		else if (tag == "lake")
		{
			river.write_(lake_from_string(" strange::lake_from_string(\"" + _token.symbol() + "\") "));
		}
		else
		{
			river.write_(lake_from_string(" " + _token.symbol() + " "));
		}
	}

protected:
	any_a<> const _literal;

	inline expression_literal_t(token_a<> const& token, any_a<> const& literal)
		: expression_t{ token }
		, _literal{ literal }
	{}
};

} // namespace strange

#endif
