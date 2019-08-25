#ifndef COM_ONEISH_STRANGE_ATTRIBUTION_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class attribution_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<attribution_t<>>;

	// construction
	static inline operation_a<> val_(any_a<> const& thing)
	{
		return operation_a<>{ over{ attribution_t<>(thing) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::attribution");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	// function
	inline any_a<> operate_(any_a<>&, range_a<> const&) const
	{
		return _thing;
	}

protected:
	any_a<> const _thing;

	inline attribution_t(any_a<> const& thing)
		: operation_t{}
		, _thing{ thing }
	{}
};

} // namespace strange

#endif
