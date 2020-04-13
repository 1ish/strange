
namespace strange
{

template <typename _element, typename _type>
inline bool forward_mutator_data_a<_element, _type>::operator==(forward_mutator_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool forward_mutator_data_a<_element, _type>::___forward_mutator_data_a_handle___<___TTT___, ___DHB___>::operator==(forward_mutator_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(it); }

template <typename _element, typename _type>
inline bool forward_mutator_data_a<_element, _type>::operator!=(forward_mutator_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool forward_mutator_data_a<_element, _type>::___forward_mutator_data_a_handle___<___TTT___, ___DHB___>::operator!=(forward_mutator_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(it); }

template <typename _element, typename _type>
inline _type const & forward_mutator_data_a<_element, _type>::extract_it() const
{ assert(any_a<>::___handle___); return ___read___().extract_it(); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type const & forward_mutator_data_a<_element, _type>::___forward_mutator_data_a_handle___<___TTT___, ___DHB___>::extract_it() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_it(); }

template <typename _element, typename _type>
inline _type & forward_mutator_data_a<_element, _type>::mutate_it()
{ assert(any_a<>::___handle___); return ___write___().mutate_it(); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type & forward_mutator_data_a<_element, _type>::___forward_mutator_data_a_handle___<___TTT___, ___DHB___>::mutate_it()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_it(); }

template <typename _element, typename _type>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ forward_mutator_data_a<_element, _type>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = forward_mutator_a< _element >::template ___operations___<___unordered_shoal_a___>();
		return operations;
	}();
	return OPERATIONS;
}

class ___forward_mutator_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_mutator_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element, typename _type>
inline forward_mutator_data_d<_element, _type> ___forward_mutator_data_dynamic___(any_a<> const& thing)
{
	return forward_mutator_data_d<_element, _type>{ thing };
}

} // namespace
