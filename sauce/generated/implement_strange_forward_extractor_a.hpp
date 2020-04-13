
namespace strange
{

template <typename _element>
inline any_a<> forward_extractor_a<_element>::get__(range_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _element>
inline _element forward_extractor_a<_element>::get_() const
{ assert(any_a<>::___handle___); return ___read___().get_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::get_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

template <typename _element>
inline _element const & forward_extractor_a<_element>::operator*() const
{ assert(any_a<>::___handle___); return ___read___().operator*(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element const & forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::operator*() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

template <typename _element>
inline _element const * forward_extractor_a<_element>::operator->() const
{ assert(any_a<>::___handle___); return ___read___().operator->(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element const * forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::operator->() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

template <typename _element>
inline any_a<> forward_extractor_a<_element>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _element>
inline forward_extractor_a<_element> forward_extractor_a<_element>::increment_()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

template <typename _element>
inline forward_extractor_a<_element>& forward_extractor_a<_element>::operator++()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _element>
inline forward_extractor_a<_element> forward_extractor_a<_element>::operator++(int)
{
	assert(any_a<>::___handle___);
	forward_extractor_a result = *this;
	___write___().increment_();
	return result;
}
#endif

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::increment_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

template <typename _element>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ forward_extractor_a<_element>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("get_"), native_extraction_t<forward_extractor_a>::create(&forward_extractor_a::get__));
		operations.update(sym("increment_"), native_mutation_t<forward_extractor_a>::create(&forward_extractor_a::increment__));
		return operations;
	}();
	return OPERATIONS;
}

class ___forward_extractor_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_extractor_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline forward_extractor_d<_element> ___forward_extractor_dynamic___(any_a<> const& thing)
{
	return forward_extractor_d<_element>{ thing };
}

} // namespace
