#ifndef COM_ONEISH_STRANGE_EXPRESSION_ME_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ME_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_me_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_me_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token)
	{
		return expression_a<>::create<expression_me_t<>>(token);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const&)
	{
		return expression_a<>::create<expression_me_t<>>(token);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_me");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_me::create"), native_function_create(&expression_me_t<>::create__));
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
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_me_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, range_create());
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" ^ ");
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
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
	friend class any_a<>;

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

class ___expression_me_t_share___
{
	static inline bool ___share___()
	{
		return expression_me_t<>::___share___;
	}
};

} // namespace strange

#endif
