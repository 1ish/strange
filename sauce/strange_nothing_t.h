#ifndef COM_ONEISH_STRANGE_NOTHING_T_H
#define COM_ONEISH_STRANGE_NOTHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class nothing_t : public anything_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		static any_a<> VAL = any_a<>{ nothing_t<>{} };
		return VAL;
	}

	static inline any_a<> ref__(range_a<> const& _)
	{
		return ref_();
	}

	static inline any_a<> ref_()
	{
		static any_a<> REF = any_a<>(nothing_t<>{}, true);
		return REF;
	}

	// conversion
	inline operator bool() const
	{
		return everything();
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::nothing");
		return TYPE;
	}

	// comparison
	static inline any_a<> nothing__(range_a<> const&)
	{
		return nothing_();
	}

	static inline any_a<> nothing_()
	{
		return something_t<>::val_();
	}

	static inline bool nothing()
	{
		return true;
	}

	static inline any_a<> everything__(range_a<> const&)
	{
		return everything_();
	}

	static inline any_a<> everything_()
	{
		return nothing_t<>::val_();
	}

	static inline bool everything()
	{
		return false;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return thing.nothing();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !thing.nothing();
	}

	inline std::size_t hash() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(0);
		return HASH;
	}

	// conversion
	inline range_a<> ranged_() const
	{
		return range_t<>::val_(it_t<true, something_t<>>::val_(nothing_t<>::val_()), it_t<true, something_t<>>::val_(something_t<>::val_()));
	}

protected:
	inline nothing_t()
		: anything_t{}
	{}
};

} // namespace strange

#endif
