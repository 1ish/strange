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
		if (terms.size() != 1)
		{
			throw dis("strange::expression_local_update::val passed wrong number of terms");
		}
		return expression_a<>{ expression_local_update_t<>{ terms.at(0) } };
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
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract();
		auto it = local.find(_key);
		if (it == local.cend())
		{
			throw dis("strange::expression_local_update::operate key not found");
		}
		return it->second;
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis("strange::expression_local_update::generate called with non-symbol key");
		}
		river.write_(lake_from_string(" " + cast<symbol_a<>>(_key).to_string() + " "));
	}

protected:
	any_a<> const _key;

	inline expression_local_update_t(any_a<> const& key)
		: expression_t{}
		, _key{ key }
	{}
};

} // namespace strange

#endif
