#ifndef COM_ONEISH_STRANGE_EVERYTHING_T_H
#define COM_ONEISH_STRANGE_EVERYTHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class everything_t : public something_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val(range_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		static any_a<> VAL = any_a<>{ everything_t<>{} };
		return VAL;
	}

	static inline any_a<> ref(range_a<> const& _)
	{
		return ref_();
	}

	static inline any_a<> ref_()
	{
		static any_a<> REF = any_a<>(everything_t<>{}, true);
		return REF;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::everything");
		return TYPE;
	}

	// comparison
	static inline any_a<> everything__(range_a<> const&)
	{
		return everything_();
	}

	static inline any_a<> everything_()
	{
		return everything_t<>::val_();
	}

	static inline bool everything()
	{
		return true;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return thing.everything();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !thing.everything();
	}

	inline std::size_t hash() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(1);
		return HASH;
	}

protected:
	inline everything_t()
		: something_t{}
	{}
};

} // namespace strange

#endif
