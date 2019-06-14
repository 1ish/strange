#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_shared_scope_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_scope::val not passed any terms");
		}
		any_a<> shared = *it;
		if (!check<unordered_shoal_a<>>(shared))
		{
			throw dis(token.report() + "strange::expression_shared_scope::val passed non-unordered-shoal shared");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_scope::val passed too few terms");
		}
		return expression_a<>{ expression_shared_scope_t<>(token, cast<unordered_shoal_a<>>(shared), *it) };
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
		auto const& shared = _shared.extract();
		auto sit = shared.find(_key);
		if (sit == shared.cend())
		{
			throw dis(_token.report() + "strange::expression_shared_scope::operate key not found");
		}
		return sit->second;
	}

	// expression
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
	unordered_shoal_a<> const _shared;
	any_a<> const _key;

	inline expression_shared_scope_t(token_a<> const& token, unordered_shoal_a<> const& shared, any_a<> const& key)
		: expression_t{ token }
		, _shared{ shared }
		, _key{ key }
	{}
};

} // namespace strange

#endif
