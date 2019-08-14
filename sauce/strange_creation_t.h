#ifndef COM_ONEISH_STRANGE_CREATION_T_H
#define COM_ONEISH_STRANGE_CREATION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class creation_t : public thing_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<creation_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		static any_a<> VAL = any_a<>{ over{ creation_t<>{} } };
		return VAL;
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
		: thing_t{}
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
