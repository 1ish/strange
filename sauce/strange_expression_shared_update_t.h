#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_shared_update_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_update::val not passed any terms");
		}
		any_a<> cat = *it;
		if (!check<cat_a<>>(cat))
		{
			throw dis(token.report() + "strange::expression_shared_update::val passed non-cat");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_update::val not passed sufficient terms");
		}
		any_a<> key = *it;
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_update::val not passed sufficient terms");
		}
		any_a<> val = *it;
		if (!check<expression_a<>>(val))
		{
			throw dis(token.report() + "strange::expression_shared_update::val passed non-expression");
		}
		return expression_a<>{ expression_shared_update_t<>{ token, cast<cat_a<>>(cat), key, cast<expression_a<>>(val) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_shared_update_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_shared_update_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).reference();
		auto lit = local.find(sym("$"));
		if (lit == local.end())
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate passed non-unordered-shoal shared");
		}
#endif
		auto& shared = static_cast<unordered_shoal_a<>&>(lit->second).reference();
		auto sit = shared.find(_key);
		if (sit == shared.end())
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate key not found");
		}
		auto val = _val.operate_(thing, range);
		if (!val.cats_().has_(_cat))
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate cat does not include value");
		}
		return sit->second = val;
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_shared_update::generate called with non-symbol key");
		}
		river.write_(lake_from_string(" $" + cast<symbol_a<>>(_key).to_string() + " :="));
		_val.generate(indent, river);
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_shared_update::generate_cpp called with non-symbol key");
		}
		river.write_(lake_from_string(" " + cast<symbol_a<>>(_key).to_string() + " ="));
		_val.generate_cpp(indent, river);
	}

protected:
	cat_a<> const _cat;
	any_a<> const _key;
	expression_a<> const _val;

	inline expression_shared_update_t(token_a<> const& token, cat_a<> const& cat, any_a<> const& key, expression_a<> const& val)
		: expression_t{ token }
		, _cat{ cat }
		, _key{ key }
		, _val{ val }
	{}
};

} // namespace strange

#endif
