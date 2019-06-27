#ifndef COM_ONEISH_STRANGE_EXPRESSION_ME_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ME_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_me_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_me_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		return expression_a<>{ over{ expression_me_t<>{ token } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_me_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_me_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_me::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract();
		auto it = local.find(sym("^"));
		if (it == local.cend())
		{
			throw dis(_token.report() + "strange::expression_me::operate ^ not found");
		}
		return it->second;
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" ^ ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" me_() ");
	}

protected:
	inline expression_me_t(token_a<> const& token)
		: expression_t{ token }
	{}
};

} // namespace strange

#endif
