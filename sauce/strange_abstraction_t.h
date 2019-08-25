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
	static inline any_a<> val__(range_a<> const& range)
	{
		return unordered_shoal_a<>{ over{ abstraction_t<>{ range } } };
	}

	template <typename... Args>
	static inline unordered_shoal_a<> val_(Args&&... args)
	{
		return unordered_shoal_a<>{ over{ abstraction_t<>{ flock_t<>::val_(std::forward<Args>(args)...) } } };
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
		for (auto const& member : parent.extract())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::abstraction::val merge passed non-symbol key");
			}
			auto key = cast<symbol_a<>>(member.first);
			if (_map.find(key) != _map.cend())
			{
				// no overrides
				throw dis("strange::abstraction::val merge invalid override");
			}
			_map.emplace(key, member.second);
		}
	}

protected:
	inline abstraction_t(range_a<> const& parents)
		: unordered_shoal_t{ std_unordered_map_any_any{} }
	{
		for (auto const& parent : parents)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::abstraction::val passed non-unordered-shoal parent");
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
