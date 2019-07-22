#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_shared_scope_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_shared_scope_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_scope::val not passed any terms");
		}
		any_a<> shared = *it;
		if (!check<shoal_a<>>(shared))
		{
			throw dis(token.report() + "strange::expression_shared_scope::val passed non-shoal shared");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_scope::val passed too few terms");
		}
		auto shared_shoal = cast<shoal_a<>>(shared);
		auto key = *it;
		auto value = shared_shoal.at_(key);
		if (value)
		{
			return expression_substitute_t<over>::val(over{ expression_shared_scope_t<>(token, terms, shared_shoal, key) }, value);
		}
		return expression_a<>{ over{ expression_shared_scope_t<>(token, terms, shared_shoal, key) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_shared_scope_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_shared_scope_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		auto value = _shared.at_(_key);
		if (!value)
		{
			throw dis(_token.report() + "strange::expression_shared_scope::operate key not found");
		}
		return value;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_shared_scope::generate with non-symbol key");
		}
		river.write_string(" $$" + cast<symbol_a<>>(_key).to_string() + " ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_shared_scope::generate_cpp with non-symbol key");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " ");
	}

protected:
	flock_a<> const _terms;
	shoal_a<> const _shared;
	any_a<> const _key;

	inline expression_shared_scope_t(token_a<> const& token, flock_a<> const& terms, shoal_a<> const& shared, any_a<> const& key)
		: expression_t{ token }
		, _terms{ terms }
		, _shared{ shared }
		, _key{ key }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_scope_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_shared_scope_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_shared_scope_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
