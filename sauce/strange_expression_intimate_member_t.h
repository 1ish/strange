#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_MEMBER_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_MEMBER_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_intimate_member_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_intimate_member_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_intimate_member_range::create passed empty range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate_member_range::create passed non-symbol member term");
		}
		return expression_substitute_t<over>::create(over{ expression_intimate_member_t<>(token, terms, fast<symbol_a<>>(member)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_intimate_member");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update_string("strange::expression_intimate_member::create", native_function_create(&expression_intimate_member_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<unordered_shoal_t<>::std_unordered_map_any_any&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto it = local.find(sym("^"));
		if (it == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member::operate ^ not found");
		}
		return any_c<>::intimate_member(it->second, _member);
	}

	// expression
	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<true>());
		return operate(local, range_create());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string("." + _member.to_string());
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member::generate_cpp called for wrong type of expression");
		}
		river.write_string("." + _member.to_string());
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;

	inline expression_intimate_member_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member)
		: expression_t<___ego___>(token, is_pure_literal(token, member))
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
	auto& shoal = shared();
	expression_intimate_member_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_intimate_member_t_share___
{
	static inline bool ___share___()
	{
		return expression_intimate_member_t<>::___share___;
	}
};

inline expression_a<> expression_intimate_member_create(token_a<> const& token, flock_a<> const& terms)
{
	return expression_intimate_member_t<>::create_(token, terms);
}

} // namespace strange

#endif
