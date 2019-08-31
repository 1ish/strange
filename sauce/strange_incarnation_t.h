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
	static inline unordered_shoal_a<> val_(unordered_shoal_a<> const& inspiration, flock_a<> const& mention, flock_a<> const& aspects, flock_a<> const& defaults)
	{
		return unordered_shoal_a<>{ over{ incarnation_t<>(inspiration, mention, aspects, defaults) } };
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
	inline void incarnate(flock_a<> const& mention, flock_a<> const& aspects, flock_a<> const& defaults)
	{
		auto aspect = aspects.cbegin_();
		auto value = defaults.cbegin_();
		for (auto const& name : mention)
		{
			if (!check<symbol_a<>>(name))
			{
				throw dis("strange::incarnation::val passed non-symbol dimension name");
			}
			if (aspect == aspects.cend_())
			{
				if (value == defaults.cend_())
				{
					_map.emplace(name, introspection_t<>::val_(no()));
				}
				else
				{
					_map.emplace(name, introspection_t<>::val_(*value++));
				}
			}
			else
			{
				_map.emplace(name, introspection_t<>::val_(*aspect++));
				if (value != defaults.cend_())
				{
					++value;
				}
			}
		}
	}

protected:
	inline incarnation_t(unordered_shoal_a<> const& inspiration, flock_a<> const& mention, flock_a<> const& aspects, flock_a<> const& defaults)
		: unordered_shoal_t{ inspiration.extract() }
	{
		incarnate(mention, aspects, defaults);
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
