#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_intimate_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_intimate_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_intimate::create passed empty range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate::create passed non-symbol member term");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_intimate::create passed short range");
		}
		auto arguments = *it;
		if (!check<flock_a<>>(arguments))
		{
			throw dis(token.report() + "strange::expression_intimate::create passed non-flock arguments");
		}
		return expression_substitute_t<expression_intimate_t<>>::create(expression_intimate_t<>(token, terms, fast<symbol_a<>>(member), fast<flock_a<>>(arguments)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_intimate");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update(sym("strange::expression_intimate::create"), native_function_create(&expression_intimate_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<std_unordered_map<any_a<>, any_a<>>&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto it = local.find(sym("^"));
		if (it == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate::operate ^ not found");
		}
		return any_c<>::intimate(it->second, _member, range_operator_t<>::create_(_arguments, thing, list));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_intimate_t<___ego___>>(expression_t<___ego___>::me_());
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
		river.write_string(" intimate ");
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
			for (auto const& argument : _arguments.extract_vector())
			{
				if (!check<expression_a<>>(argument))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate::generate_cpp with non-expression argument");
				}
				fast<expression_a<>>(argument).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate::generate_cpp called for wrong type of expression");
		}
		river.write_string(" intimate ");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;
	flock_a<> const _arguments;

	friend class any_a<>;

	inline expression_intimate_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member, flock_a<> const& arguments)
		: expression_t<___ego___>(token, is_pure_literal(token, member, arguments))
		, _terms{ terms }
		, _member{ member }
		, _arguments{ arguments }
	{}

	static inline std_pair<bool, bool> is_pure_literal(token_a<> const& token, symbol_a<> const& member, flock_a<> const& arguments)
	{
		std_pair<bool, bool> pure_literal(false, false); //TODO pure literal
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
	return shoal;
}();

class ___expression_intimate_t_share___
{
	static inline bool ___share___()
	{
		return expression_intimate_t<>::___share___;
	}
};

inline expression_a<> expression_intimate_create(token_a<> const& token, flock_a<> const& terms)
{
	return expression_intimate_t<>::create_(token, terms);
}

} // namespace strange

#endif
