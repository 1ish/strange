#ifndef COM_ONEISH_STRANGE_ABSTRACTION_T_H
#define COM_ONEISH_STRANGE_ABSTRACTION_T_H

namespace strange
{

template <typename ___ego___ = unordered_shoal_a<>>
class abstraction_t : public unordered_shoal_t<false, ___ego___>
{
public:
	// override
	using over = collection_o<abstraction_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::abstraction::create passed empty range");
		}
		auto const token = *it;
		if (!check<token_a<>>(token))
		{
			throw dis("strange::abstraction::create passed non-token");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const dimension_names = *it;
		if (!check<flock_a<>>(dimension_names))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock dimension names");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const dimension_kinds = *it;
		if (!check<flock_a<>>(dimension_kinds))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock dimension kinds");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const dimension_defaults = *it;
		if (!check<flock_a<>>(dimension_defaults))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock dimension defaults");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const parent_shoals = *it;
		if (!check<flock_a<>>(parent_shoals))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock parent shoals");
		}
		return create_(cast<token_a<>>(token), cast<flock_a<>>(dimension_names), cast<flock_a<>>(dimension_kinds), cast<flock_a<>>(dimension_defaults), cast<flock_a<>>(parent_shoals));
	}

	static inline unordered_shoal_a<> create_(token_a<> const& token, flock_a<> const& dimension_names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_defaults, flock_a<> const& parent_shoals)
	{
		return unordered_shoal_a<>{ over{ abstraction_t<>(token, dimension_names, dimension_kinds, dimension_defaults, parent_shoals) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<abstraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<abstraction_t<>>::share(shoal);
	}

	// abstraction
	inline void merge(unordered_shoal_a<> const& parent)
	{
		//TODO dimensions
		for (auto const& member : parent.extract())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::abstraction::create merge passed non-symbol key");
			}
			auto key = cast<symbol_a<>>(member.first);
			if (_map.find(key) != _map.cend())
			{
				// no overrides
				throw dis("strange::abstraction::create merge invalid override");
			}
			_map.emplace(key, member.second);
		}
	}

protected:
	token_a<> const _token;
	flock_a<> const _dimension_names;
	flock_a<> const _dimension_kinds;
	flock_a<> const _dimension_defaults;
	flock_a<> const _parent_shoals;

	inline abstraction_t(token_a<> const& token, flock_a<> const& dimension_names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_defaults, flock_a<> const& parent_shoals)
		: unordered_shoal_t{ std_unordered_map_any_any{} }
		, _token{ token }
		, _dimension_names{ dimension_names }
		, _dimension_kinds{ dimension_kinds }
		, _dimension_defaults{ dimension_defaults }
		, _parent_shoals{ parent_shoals }
	{
		for (auto const& parent : parent_shoals)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::abstraction::create passed non-unordered-shoal parent");
			}
			merge(cast<unordered_shoal_a<>>(parent));
		}
	}

private:
	static bool const ___share___;
	friend class ___abstraction_t_share___;
};

template <typename ___ego___>
bool const abstraction_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	abstraction_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
