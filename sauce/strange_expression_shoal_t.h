#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHOAL_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHOAL_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_shoal_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_shoal_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::create(over{ expression_shoal_t<>(token, terms) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_shoal_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_shoal_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		return unordered_shoal_t<>::create__(range_operator_t<>::create_(_terms, thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" {");
		bool first = true;
		for (auto const& term : _terms.extract())
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
				throw dis(_token.report() + "strange::expression_shoal::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string("} ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_shoal::generate_cpp called for wrong type of expression");
		}
		river.write_string(" unordered_shoal_t<>::create_(");
		bool first = true;
		for (auto const& term : _terms.extract())
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
				throw dis(_token.report() + "strange::expression_shoal::generate_cpp with non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(version, indent, river);
		}
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;

	inline expression_shoal_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shoal_t_share___;
};

template <typename ___ego___>
bool const expression_shoal_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_shoal_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
