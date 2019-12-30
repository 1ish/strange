#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_MEMBER_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_MEMBER_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_intimate_member_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_intimate_member_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate_member_range::create passed empty range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate_member_range::create passed non-symbol member term");
		}
		return expression_substitute_t<over>::create(over{ expression_intimate_member_t<>(token, terms, cast<symbol_a<>>(member)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_intimate_member_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_intimate_member_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_intimate_member::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract_map();
		auto it = local.find(sym("^"));
		if (it == local.cend())
		{
			throw dis(_token.report() + "strange::expression_intimate_member::operate ^ not found");
		}
		return any_c<>::intimate_member(any_a<>(it->second, true), _member);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string("." + _member.to_string());
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const //TODO
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_intimate_member::generate_cpp called for wrong type of expression");
		}
		river.write_string("." + _member.to_string());
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;

	inline expression_intimate_member_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member)
		: expression_t(token, is_pure_literal(token, member))
		, _terms{ terms }
		, _member{ member }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, symbol_a<> const& member)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_intimate_member_t_share___;
};

template <typename ___ego___>
bool const expression_intimate_member_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_intimate_member_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
