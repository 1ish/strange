#ifndef COM_ONEISH_STRANGE_ATTRIBUTE_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class attribute_t : public operation_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<attribute_t<>>;

	// construction
	static inline operation_a<> val_(any_a<> const& thing)
	{
		return operation_a<>{ over{ attribute_t<>(thing) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::attribute");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

	// function
	inline any_a<> operate_(any_a<>& _, range_a<> const& range) const
	{
		return _thing;
	}

protected:
	any_a<> const _thing;

	inline attribute_t(any_a<> const& thing)
		: operation_t{}
		, _thing{ thing }
	{}
};

} // namespace strange

#endif
