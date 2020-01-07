#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_intimate_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_intimate_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate::create passed empty range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate::create passed non-symbol member term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate::create passed short range");
		}
		auto arguments = *it;
		if (!check<flock_a<>>(arguments))
		{
			throw dis(token.report() + "strange::expression_intimate::create passed non-flock arguments");
		}
		return expression_substitute_t<over>::create(over{ expression_intimate_t<>(token, terms, cast<symbol_a<>>(member), cast<flock_a<>>(arguments)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_intimate_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_intimate_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_intimate::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<unordered_shoal_t<>::std_unordered_map_any_any&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto it = local.find(sym("^"));
		if (it == local.end())
		{
			throw dis(_token.report() + "strange::expression_intimate::operate ^ not found");
		}
		return any_c<>::intimate(it->second, _member, range_operator_t<>::create_(_arguments, thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" intimate ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const //TODO
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_intimate::generate_cpp called for wrong type of expression");
		}
		river.write_string(" intimate ");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;
	flock_a<> const _arguments;

	inline expression_intimate_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member, flock_a<> const& arguments)
		: expression_t(token, is_pure_literal(token, member, arguments))
		, _terms{ terms }
		, _member{ member }
		, _arguments{ arguments }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, symbol_a<> const& member, flock_a<> const& arguments)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_intimate_t_share___;
};

template <typename ___ego___>
bool const expression_intimate_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_intimate_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
