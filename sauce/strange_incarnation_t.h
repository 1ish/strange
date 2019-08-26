#ifndef COM_ONEISH_STRANGE_INCARNATION_T_H
#define COM_ONEISH_STRANGE_INCARNATION_T_H

namespace strange
{

template <typename ___ego___ = unordered_shoal_a<>>
class incarnation_t : public unordered_shoal_t<false, ___ego___>
{
public:
	// override
	using over = collection_o<incarnation_t<>>;

	// construction
	static inline unordered_shoal_a<> val_(unordered_shoal_a<> const& inspiration, flock_a<> const& mention, flock_a<> const& aspects)
	{
		return unordered_shoal_a<>{ over{ incarnation_t<>(inspiration, mention, aspects) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<incarnation_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<incarnation_t<>>::share(shoal);
	}

	// incarnation
	inline void merge(unordered_shoal_a<> const& parent)
	{
		for (auto const& member : parent.extract())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::incarnation::val merge passed non-symbol key");
			}
			auto key = cast<symbol_a<>>(member.first);
			if (_map.find(key) != _map.cend())
			{
				// no overrides
				throw dis("strange::incarnation::val merge invalid override");
			}
			_map.emplace(key, member.second);
		}
	}

protected:
	inline incarnation_t(unordered_shoal_a<> const& inspiration, flock_a<> const& mention, flock_a<> const& aspects)
		: unordered_shoal_t{ std_unordered_map_any_any{} }
	{
		//TODO
	}

private:
	static bool const ___share___;
	friend class ___incarnation_t_share___;
};

template <typename ___ego___>
bool const incarnation_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	incarnation_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
