
namespace strange
{

template <typename _element>
inline any_a<> bidirectional_mutator_a<_element>::decrement__(range_a<> const& ___arguments___)
{
	return decrement_();
}

template <typename _element>
inline bidirectional_mutator_a<_element> bidirectional_mutator_a<_element>::decrement_()
{
	assert(any_a<>::___handle___);
	___write___().decrement_();
	return *this;
}

template <typename _element>
inline bidirectional_mutator_a<_element>& bidirectional_mutator_a<_element>::operator--()
{
	assert(any_a<>::___handle___);
	___write___().decrement_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _element>
inline bidirectional_mutator_a<_element> bidirectional_mutator_a<_element>::operator--(int)
{
	assert(any_a<>::___handle___);
	bidirectional_mutator_a result = *this;
	___write___().decrement_();
	return result;
}
#endif

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void bidirectional_mutator_a<_element>::___bidirectional_mutator_a_handle___<___TTT___, ___DHB___>::decrement_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement_(); }

template <typename _element>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ bidirectional_mutator_a<_element>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = forward_mutator_a< _element >::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("decrement_"), native_mutation_t<bidirectional_mutator_a>::create(&bidirectional_mutator_a::decrement__));
		return operations;
	}();
	return OPERATIONS;
}

class ___bidirectional_mutator_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___bidirectional_mutator_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline bidirectional_mutator_d<_element> ___bidirectional_mutator_dynamic___(any_a<> const& thing)
{
	return bidirectional_mutator_d<_element>{ thing };
}

} // namespace
