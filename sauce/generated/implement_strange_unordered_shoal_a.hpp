
namespace strange
{

template <typename _1>
inline bool unordered_shoal_a<_1>::operator==(unordered_shoal_a < > const & shoal ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::operator==(unordered_shoal_a < > const & shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(shoal); }

template <typename _1>
inline bool unordered_shoal_a<_1>::operator!=(unordered_shoal_a < > const & shoal ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::operator!=(unordered_shoal_a < > const & shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(shoal); }

template <typename _1>
inline forward_extractor_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: const_iterator > unordered_shoal_a<_1>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: const_iterator > unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _1>
inline forward_extractor_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: const_iterator > unordered_shoal_a<_1>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: const_iterator > unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _1>
inline forward_mutator_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: iterator > unordered_shoal_a<_1>::mutate_begin()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: iterator > unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::mutate_begin()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

template <typename _1>
inline forward_mutator_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: iterator > unordered_shoal_a<_1>::mutate_end()
{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_data_a < any_a < > , typename std :: unordered_map < any_a < > , any_a < > > :: iterator > unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::mutate_end()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

template <typename _1>
inline std :: unordered_map < any_a < > , any_a < > > const & unordered_shoal_a<_1>::extract_map() const
{ assert(any_a<>::___handle___); return ___read___().extract_map(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: unordered_map < any_a < > , any_a < > > const & unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::extract_map() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_map(); }

template <typename _1>
inline std :: unordered_map < any_a < > , any_a < > > & unordered_shoal_a<_1>::mutate_map()
{ assert(any_a<>::___handle___); return ___write___().mutate_map(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: unordered_map < any_a < > , any_a < > > & unordered_shoal_a<_1>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::mutate_map()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_map(); }

class ___unordered_shoal_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___unordered_shoal_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline unordered_shoal_d<_1> ___unordered_shoal_dynamic___(any_a<> const& thing)
{
	return unordered_shoal_d<_1>{ thing };
}

} // namespace
