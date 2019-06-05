#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_local_at_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(range_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis("strange::expression_local_at::val not passed any terms");
		}
		return expression_a<>{ expression_local_at_t<>{ *it } };
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
	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis("strange::expression_local_at::generate_cpp called with non-symbol key");
		}
		river.write_(lake_from_string(" " + cast<symbol_a<>>(_key).to_string() + " "));
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
