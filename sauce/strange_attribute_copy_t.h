#ifndef COM_ONEISH_STRANGE_ATTRIBUTE_COPY_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTE_COPY_T_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class attribute_copy_t : public operation_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<attribute_copy_t<>>;

	// construction
	static inline operation_a<> val_(any_a<> const& thing)
	{
		return operation_a<>{ over{ attribute_copy_t<>(thing) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::attribute_copy");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	// function
	inline any_a<> operate_(any_a<>&, range_a<> const&) const
	{
		any_a<> copy = _thing;
		copy.mutable_thing();
		return copy;
	}

protected:
	any_a<> const _thing;

	inline attribute_copy_t(any_a<> const& thing)
		: operation_t{}
		, _thing{ thing }
	{}
};

} // namespace strange

#endif
