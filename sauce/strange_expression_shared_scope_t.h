#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_shared_scope_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_shared_scope_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_extractor_a<> it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_scope::create not passed any terms");
		}
		any_a<> shared = *it;
		if (!check<shoal_a<>>(shared))
		{
			throw dis(token.report() + "strange::expression_shared_scope::create passed non-shoal shared");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_scope::create passed too few terms");
		}
		auto shared_shoal = cast<shoal_a<>>(shared);
		auto key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_shared_scope::create passed non-symbol key");
		}
		auto value = shared_shoal.at_(key);
		if (value)
		{
			return expression_substitute_t<over>::create(over{ expression_shared_scope_t<>(token, terms, shared_shoal, cast<symbol_a<>>(key)) }, value);
		}
		return expression_a<>::create<over>(expression_shared_scope_t<>(token, terms, shared_shoal, cast<symbol_a<>>(key)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_scope");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shared_scope::create", native_function_create(&expression_shared_scope_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		auto value = _shared.at_(_key);
		if (!value)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_scope::operate key not found");
		}
		return value;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" $$" + cast<symbol_a<>>(_key).to_string() + " ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_scope::generate_cpp called for wrong type of expression");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " ");
	}

protected:
	flock_a<> const _terms;
	shoal_a<> const _shared;
	symbol_a<> const _key;

	inline expression_shared_scope_t(token_a<> const& token, flock_a<> const& terms, shoal_a<> const& shared, symbol_a<> const& key)
		: expression_t<___ego___>{ token }
		, _terms{ terms }
		, _shared{ shared }
		, _key{ key }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_scope_t_share___;
};

template <typename ___ego___>
bool const expression_shared_scope_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_shared_scope_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_shared_scope_t_share___
{
	static inline bool ___share___()
	{
		return expression_shared_scope_t<>::___share___;
	}
};

} // namespace strange

#endif
