#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_local_at_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		if (!check<flock_a<>>(range))
		{
			throw dis("strange::expression_local_at::val passed non-flock range");
		}
		return val_(cast<flock_a<>>(range));
	}

	static inline expression_a<> val_(flock_a<> const& terms)
	{
		if (terms.size() != 1)
		{
			throw dis("strange::expression_local_at::val passed wrong number of terms");
		}
		return expression_a<>{ expression_local_at_t<>{ terms.at(0) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_local_at_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_local_at_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis("strange::expression_local_at::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract();
		auto it = local.find(_key);
		if (it == local.cend())
		{
			throw dis("strange::expression_local_at::operate key not found");
		}
		return it->second;
	}

	// expression
	inline void generate(int64_t indent, river_a<> const& river) const //TODO
	{
	}

protected:
	any_a<> const _key;

	inline expression_local_at_t(any_a<> const& key)
		: expression_t{}
		, _key{ key }
	{}
};

} // namespace strange

#endif
