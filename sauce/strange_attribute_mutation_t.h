#ifndef COM_ONEISH_STRANGE_ATTRIBUTE_MUTATION_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTE_MUTATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class attribute_mutation_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<attribute_mutation_t<>>;

	// construction
	static inline operation_a<> val_(any_a<> const& thing)
	{
		return operation_a<>{ over{ attribute_mutation_t<>(thing) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::attribute_mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		return any_a<>(_thing, true);
	}

protected:
	any_a<> const _thing;

	inline attribute_mutation_t(any_a<> const& thing)
		: operation_t{}
		, _thing{ thing }
	{}
};

} // namespace strange

#endif
