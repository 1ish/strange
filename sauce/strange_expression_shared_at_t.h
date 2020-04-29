#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_shared_at_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_shared_at_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_at::create not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_shared_at::create passed non-symbol key");
		}
		return expression_a<>::create<expression_shared_at_t<>>(token, terms, fast<symbol_a<>>(key));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_at");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_shared_at::create"), native_function::create(&expression_shared_at_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const&) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_at::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<std_unordered_map<any_a<>, any_a<>>&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto lit = local.find(sym("$"));
		if (lit == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_at::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_at::operate passed non-unordered-shoal shared");
		}
#endif
		auto& shared = static_cast<unordered_shoal_a<>&>(lit->second);
		auto& map = const_cast<std_unordered_map<any_a<>, any_a<>>&>(shared.extract_map());
		auto lock = shared.read_lock_();
		auto it = map.find(_key);
		if (it == map.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_at::operate key not found");
		}
		return any_a<>::ref(it->second);
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_shared_at_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, list::create());
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

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" " + fast<symbol_a<>>(_key).to_string() + " ");
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
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_at::generate_cpp called for wrong type of expression");
		}
		river.write_string(" " + fast<symbol_a<>>(_key).to_string() + " "); //TODO remove $ prefix
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;

	friend class any_a<>;

	inline expression_shared_at_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key)
		: expression_t<___ego___>{ token }
		, _terms{ terms }
		, _key{ key }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_at_t_share___;
};

template <typename ___ego___>
bool const expression_shared_at_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_shared_at_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_shared_at_t_share___
{
	static inline bool ___share___()
	{
		return expression_shared_at_t<>::___share___;
	}
};

} // namespace strange

#endif
