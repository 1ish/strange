
namespace strange
{

template <typename _element>
inline bool unordered_herd_a<_element>::operator==(unordered_herd_a < _element > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(herd); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::operator==(unordered_herd_a < _element > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(herd); }

template <typename _element>
inline bool unordered_herd_a<_element>::operator!=(unordered_herd_a < _element > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(herd); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::operator!=(unordered_herd_a < _element > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(herd); }

template <typename _element>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _element>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _element>
inline std_unordered_set < _element > const & unordered_herd_a<_element>::extract_set() const
{ assert(any_a<>::___handle___); return ___read___().extract_set(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline std_unordered_set < _element > const & unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::extract_set() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_set(); }

template <typename _element>
inline std_unordered_set < _element > & unordered_herd_a<_element>::mutate_set()
{ assert(any_a<>::___handle___); return ___write___().mutate_set(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline std_unordered_set < _element > & unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::mutate_set()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_set(); }

template <typename _element>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ unordered_herd_a<_element>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = herd_a< _element >::template ___operations___<___unordered_shoal_a___>();
		return operations;
	}();
	return OPERATIONS;
}

class ___unordered_herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___unordered_herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline unordered_herd_d<_element> ___unordered_herd_dynamic___(any_a<> const& thing)
{
	return unordered_herd_d<_element>{ thing };
}

} // namespace
