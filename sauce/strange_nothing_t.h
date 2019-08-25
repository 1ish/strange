#ifndef COM_ONEISH_STRANGE_NOTHING_T_H
#define COM_ONEISH_STRANGE_NOTHING_T_H

namespace strange
{

template <typename ___ego___ = any_a<>>
class nothing_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<nothing_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		static any_a<> VAL = any_a<>{ over{ nothing_t<>{} } };
		return VAL;
	}

	// conversion
	inline operator bool() const
	{
		return something();
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<nothing_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<nothing_t<>>::share(shoal);
	}

	// comparison
	static inline any_a<> nothing__(range_a<> const&)
	{
		return nothing_();
	}

	static inline any_a<> nothing_()
	{
		return yes();
	}

	static inline bool nothing()
	{
		return true;
	}

	static inline any_a<> something__(range_a<> const&)
	{
		return something_();
	}

	static inline any_a<> something_()
	{
		return no();
	}

	static inline bool something()
	{
		return false;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return thing.nothing();
	}

	inline std::size_t hash() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(0);
		return HASH;
	}

	// conversion
	inline range_a<> ranged_() const
	{
		return range_t<>::val_(it_t<true, something_t<>>::val_(no()), it_t<true, something_t<>>::val_());
	}

protected:
	inline nothing_t()
		: thing_t{}
	{}

private:
	static bool const ___share___;
	friend class ___nothing_t_share___;
};

template <typename ___ego___>
bool const nothing_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	nothing_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
