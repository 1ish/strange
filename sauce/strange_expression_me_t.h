#ifndef COM_ONEISH_STRANGE_EXPRESSION_ME_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ME_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_me_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_me_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token)
	{
		return expression_a<>{ over{ expression_me_t<>{ token } } };
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const&)
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
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_me::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract_map();
		auto it = local.find(sym("^"));
		if (it == local.cend())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_me::operate ^ not found");
		}
		return it->second;
	}

	// expression
	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" ^ ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_me::generate_cpp called for wrong type of expression");
		}
		river.write_string(" me_() ");
	}

protected:
	inline expression_me_t(token_a<> const& token)
		: expression_t<___ego___>{ token }
	{}

private:
	static bool const ___share___;
	friend class ___expression_me_t_share___;
};

template <typename ___ego___>
bool const expression_me_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_me_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
