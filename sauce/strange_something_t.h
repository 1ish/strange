#ifndef COM_ONEISH_STRANGE_SOMETHING_T_H
#define COM_ONEISH_STRANGE_SOMETHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class something_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		static any_a<> VAL = any_a<>{ something_t<>{} };
		return VAL;
	}

	static inline any_a<> ref__(range_a<> const& _)
	{
		return ref_();
	}

	static inline any_a<> ref_()
	{
		static any_a<> REF = any_a<>(something_t<>{}, true);
		return REF;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::something");
		return TYPE;
	}

	// comparison
	static inline any_a<> something__(range_a<> const&)
	{
		return something_();
	}

	static inline any_a<> something_()
	{
		return something_t<>::val_();
	}

	static inline bool something()
	{
		return true;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return thing.something();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !thing.something();
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
};

} // namespace strange

#endif
