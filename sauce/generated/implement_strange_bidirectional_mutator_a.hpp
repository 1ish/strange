
namespace strange
{

template <typename _element>
inline any_a<> bidirectional_mutator_a<_element>::decrement__(list_a<> const& ___arguments___)
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
inline cat_a<> bidirectional_mutator_a<_element>::___cat___()
{
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::bidirectional_mutator", flock_vals(kind_create<kind_a<>>(2, "")));
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> bidirectional_mutator_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = forward_mutator_a< _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> bidirectional_mutator_a<_element>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___(), flock_vals(kind_of<_element>()));
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> bidirectional_mutator_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = forward_mutator_a< _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> bidirectional_mutator_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = forward_mutator_a< _element >::___operations___();
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
