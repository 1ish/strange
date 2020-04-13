#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_MEMBER_RANGE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_MEMBER_RANGE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_intimate_member_range_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_intimate_member_range_t<___ego___>>(range);
	}

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
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_intimate_member_range::create passed short range");
		}
		auto range = *it;
		if (!check<expression_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_intimate_member_range::create passed non-expression range term");
		}
		return expression_substitute_t<expression_intimate_member_range_t<>>::create(expression_intimate_member_range_t<>(token, terms, fast<symbol_a<>>(member), fast<expression_a<>>(range)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_intimate_member_range");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update(sym("strange::expression_intimate_member_range::create"), native_function_create(&expression_intimate_member_range_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member_range::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<std::unordered_map<any_a<>, any_a<>>&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto it = local.find(sym("^"));
		if (it == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member_range::operate ^ not found");
		}
		auto const range_term = _range.operate(thing, range);
		if (!check<range_a<>>(range_term))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member_range::operate with non-range term");
		}
		return any_c<>::intimate(it->second, _member, fast<range_a<>>(range_term));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_intimate_member_range_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, range_create());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" me." + _member.to_string());
		_range.generate(version, indent, river);
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_range.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_member_range::generate_cpp called for wrong type of expression");
		}
		river.write_string(" me." + _member.to_string());
		_range.generate_cpp(version, indent, river, declare, define);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;
	expression_a<> const _range;

	friend class any_a<>;

	inline expression_intimate_member_range_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member, expression_a<> const& range)
		: expression_t<___ego___>(token, is_pure_literal(token, member, range))
		, _terms{ terms }
		, _member{ member }
		, _range{ range }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, symbol_a<> const& member, expression_a<> const& range_expression)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
		if (!range_expression.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_intimate_member_range_t_share___;
};

template <typename ___ego___>
bool const expression_intimate_member_range_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_intimate_member_range_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_intimate_member_range_t_share___
{
	static inline bool ___share___()
	{
		return expression_intimate_member_range_t<>::___share___;
	}
};

inline expression_a<> expression_intimate_member_range_create(token_a<> const& token, flock_a<> const& terms)
{
	return expression_intimate_member_range_t<>::create_(token, terms);
}

} // namespace strange

#endif
