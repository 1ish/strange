#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_shared_at_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_at::val not passed any terms");
		}
		return expression_a<>{ expression_shared_at_t<>{ token, *it } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_shared_at_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_shared_at_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract();
		auto lit = local.find(sym("$"));
		if (lit == local.cend())
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate passed non-unordered-shoal shared");
		}
#endif
		auto const& shared = static_cast<unordered_shoal_a<> const&>(lit->second);
		auto const& map = shared.extract();
		auto lock = shared.read_lock_();
		auto it = map.find(_key);
		if (it == map.cend())
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate key not found");
		}
		return it->second;
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_shared_at::generate with non-symbol key");
		}
		river.write_string(" $" + cast<symbol_a<>>(_key).to_string() + " ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_shared_at::generate_cpp with non-symbol key");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " ");
	}

protected:
	any_a<> const _key;

	inline expression_shared_at_t(token_a<> const& token, any_a<> const& key)
		: expression_t{ token }
		, _key{ key }
	{}
};

} // namespace strange

#endif
