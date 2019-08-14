#ifndef COM_ONEISH_STRANGE_CREATION_T_H
#define COM_ONEISH_STRANGE_CREATION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = unordered_shoal_a<>>
class creation_t : public unordered_shoal_t<false, _ABSTRACTION_>
{
public:
	// override
	using over = collection_o<creation_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	template <typename... Args>
	static inline unordered_shoal_a<> val_(Args&&... args)
	{
		auto const parents = flock_t<>::val_(std::forward<Args>(args)...);
		auto child = over{ creation_t<>{} };
		//TODO
		return unordered_shoal_a<>{ child };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<creation_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<creation_t<>>::share(shoal);
	}

protected:
	inline creation_t()
		: unordered_shoal_t{ std_unordered_map_any_any{} }
	{}

private:
	static bool const ___share___;
	friend class ___creation_t_share___;
};

template <typename _ABSTRACTION_>
bool const creation_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	creation_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
