
namespace strange
{

template <typename _element>
inline any_a<> forward_mutator_a<_element>::get__(range_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _element>
inline _element forward_mutator_a<_element>::get_() const
{ assert(any_a<>::___handle___); return ___read___().get_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::get_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

template <typename _element>
inline any_a<> forward_mutator_a<_element>::set__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("forward_mutator_a::set_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return set_(thing);
}

template <typename _element>
inline _element forward_mutator_a<_element>::set_(_element const& thing) const
{ assert(any_a<>::___handle___); return ___read___().set_(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::set_(_element const& thing) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_(thing); }

template <typename _element>
inline _element & forward_mutator_a<_element>::operator*() const
{ assert(any_a<>::___handle___); return ___read___().operator*(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element & forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::operator*() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

template <typename _element>
inline _element * forward_mutator_a<_element>::operator->() const
{ assert(any_a<>::___handle___); return ___read___().operator->(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element * forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::operator->() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

template <typename _element>
inline any_a<> forward_mutator_a<_element>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _element>
inline forward_mutator_a<_element> forward_mutator_a<_element>::increment_()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

template <typename _element>
inline forward_mutator_a<_element>& forward_mutator_a<_element>::operator++()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _element>
inline forward_mutator_a<_element> forward_mutator_a<_element>::operator++(int)
{
	assert(any_a<>::___handle___);
	forward_mutator_a result = *this;
	___write___().increment_();
	return result;
}
#endif

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::increment_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

template <typename _element>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ forward_mutator_a<_element>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("get_"), native_extraction_t<forward_mutator_a>::create(&forward_mutator_a::get__));
		operations.update(sym("set_"), native_extraction_t<forward_mutator_a>::create(&forward_mutator_a::set__));
		operations.update(sym("increment_"), native_mutation_t<forward_mutator_a>::create(&forward_mutator_a::increment__));
		return operations;
	}();
	return OPERATIONS;
}

class ___forward_mutator_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_mutator_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline forward_mutator_d<_element> ___forward_mutator_dynamic___(any_a<> const& thing)
{
	return forward_mutator_d<_element>{ thing };
}

} // namespace
