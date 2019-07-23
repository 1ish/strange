#ifndef COM_ONEISH_STRANGE_SOMETHING_T_H
#define COM_ONEISH_STRANGE_SOMETHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class something_t : public thing_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<something_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		static any_a<> VAL = any_a<>{ over{ something_t<>{} } };
		return VAL;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<something_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<something_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return thing.something();
	}

	inline std::size_t hash() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(1);
		return HASH;
	}

protected:
	inline something_t()
		: thing_t{}
	{}

private:
	static bool const ___share___;
	friend class ___something_t_share___;
};

template <typename _ABSTRACTION_>
bool const something_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	something_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
