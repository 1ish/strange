#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_UPDATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_UPDATE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_local_update_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(flock_a<> const& terms)
	{
		if (terms.size() != 3)
		{
			throw dis("strange::expression_local_update::val passed wrong number of terms");
		}
		any_a<> cat = terms.at(0);
		if (!check<cat_a<>>(cat))
		{
			throw dis("strange::expression_local_update::val passed non-cat");
		}
		any_a<> val = terms.at(2);
		if (!check<expression_a<>>(val))
		{
			throw dis("strange::expression_local_update::val passed non-expression");
		}
		return expression_a<>{ expression_local_update_t<>{ cast<cat_a<>>(cat), terms.at(1), cast<expression_a<>>(val) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_local_update_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_local_update_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis("strange::expression_local_update::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).reference();
		auto it = local.find(_key);
		if (it == local.cend())
		{
			throw dis("strange::expression_local_update::operate key not found");
		}
		auto val = _val.operate_(thing, range);
		if (!val.cats_().has_(_cat))
		{
			throw dis("strange::expression_local_update::operate cat does not include value");
		}
		return it->second = val;
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis("strange::expression_local_update::generate called with non-symbol key");
		}
		river.write_(lake_from_string(" " + cast<symbol_a<>>(_key).to_string() + " ="));
		_val.generate(indent, river);
	}

protected:
	cat_a<> const _cat;
	any_a<> const _key;
	expression_a<> const _val;

	inline expression_local_update_t(cat_a<> const& cat, any_a<> const& key, expression_a<> const& val)
		: expression_t{}
		, _cat{ cat }
		, _key{ key }
		, _val{ val }
	{}
};

} // namespace strange

#endif
