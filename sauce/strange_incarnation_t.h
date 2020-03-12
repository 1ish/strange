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
	static inline unordered_shoal_a<> create_(unordered_shoal_a<> const& inspiration, flock_a<> const& mention, flock_a<> const& aspects, flock_a<> const& defaults)
	{
		return unordered_shoal_a<>::create<over>(incarnation_t<>(inspiration, mention, aspects, defaults));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::incarnation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::incarnation::create", native_function_create(&incarnation_t<>::create__));
	}

	// incarnation
	inline void incarnate(flock_a<> const& mention, flock_a<> const& aspects, flock_a<> const& defaults)
	{
		auto aspect = aspects.extract_begin_();
		auto value = defaults.extract_begin_();
		for (auto const& name : mention)
		{
			if (!check<symbol_a<>>(name))
			{
				throw dis("strange::incarnation::create passed non-symbol dimension name");
			}
			if (aspect == aspects.extract_end_())
			{
				if (value == defaults.extract_end_())
				{
					unordered_shoal_t<false, ___ego___>::_map.emplace(name, attribute_extraction_create(no()));
				}
				else
				{
					unordered_shoal_t<false, ___ego___>::_map.emplace(name, attribute_extraction_create(*value));
					++value;
				}
			}
			else
			{
				unordered_shoal_t<false, ___ego___>::_map.emplace(name, attribute_extraction_create(*aspect));
				++aspect;
				if (value != defaults.extract_end_())
				{
					++value;
				}
			}
		}
	}

protected:
	inline incarnation_t(unordered_shoal_a<> const& inspiration, flock_a<> const& mention, flock_a<> const& aspects, flock_a<> const& defaults)
		: unordered_shoal_t<false, ___ego___>{ inspiration.extract_map() }
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
	auto& shoal = shared();
	incarnation_t<___ego___>::share(shoal);
	return shoal;
}();

class ___incarnation_t_share___
{
	static inline bool ___share___()
	{
		return incarnation_t<>::___share___;
	}
};

} // namespace strange

#endif
