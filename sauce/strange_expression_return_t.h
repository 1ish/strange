#ifndef COM_ONEISH_STRANGE_EXPRESSION_RETURN_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_RETURN_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_return_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_return_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			return val(token, terms);
		}
		any_a<> result = *it;
		if (!check<expression_a<>>(result))
		{
			throw dis("strange::expression_return::val passed non-expression result");
		}
		return val(token, terms, cast<expression_a<>>(result));
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_a<>{ over{ expression_return_t<>(token, terms, expression_t<>::val(token)) } };
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms, expression_a<> const& result)
	{
		return expression_a<>{ over{ expression_return_t<>(token, terms, result) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_return_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_return_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		throw return_i{ _result.operate_(thing, range) };
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" return[");
		_result.generate(indent, river);
		river.write_string("] ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" return(");
		_result.generate_cpp(indent, river);
		river.write_string("); ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _result;

	inline expression_return_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& result)
		: expression_t(token, result.pure(), result.literal()) // pure, literal
		, _terms{ terms }
		, _result{ result }
	{}

private:
	static bool const ___share___;
	friend class ___expression_return_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_return_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_return_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
