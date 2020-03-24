
namespace strange
{

template <typename _1>
inline bool ordered_herd_a<_1>::operator==(ordered_herd_a < > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::operator==(ordered_herd_a < > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(herd); }

template <typename _1>
inline bool ordered_herd_a<_1>::operator!=(ordered_herd_a < > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::operator!=(ordered_herd_a < > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(herd); }

template <typename _1>
inline bool ordered_herd_a<_1>::operator<(ordered_herd_a < > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::operator<(ordered_herd_a < > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(herd); }

template <typename _1>
inline bool ordered_herd_a<_1>::operator>(ordered_herd_a < > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::operator>(ordered_herd_a < > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(herd); }

template <typename _1>
inline bool ordered_herd_a<_1>::operator<=(ordered_herd_a < > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::operator<=(ordered_herd_a < > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(herd); }

template <typename _1>
inline bool ordered_herd_a<_1>::operator>=(ordered_herd_a < > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::operator>=(ordered_herd_a < > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(herd); }

template <typename _1>
inline bidirectional_extractor_data_a < any_a < > , typename std :: set < any_a < > > :: const_iterator > ordered_herd_a<_1>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , typename std :: set < any_a < > > :: const_iterator > ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _1>
inline bidirectional_extractor_data_a < any_a < > , typename std :: set < any_a < > > :: const_iterator > ordered_herd_a<_1>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , typename std :: set < any_a < > > :: const_iterator > ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _1>
inline std :: set < any_a < > > const & ordered_herd_a<_1>::extract_set() const
{ assert(any_a<>::___handle___); return ___read___().extract_set(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: set < any_a < > > const & ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::extract_set() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_set(); }

template <typename _1>
inline std :: set < any_a < > > & ordered_herd_a<_1>::mutate_set()
{ assert(any_a<>::___handle___); return ___write___().mutate_set(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: set < any_a < > > & ordered_herd_a<_1>::___ordered_herd_a_handle___<___TTT___, ___DHB___>::mutate_set()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_set(); }

class ___ordered_herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___ordered_herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline ordered_herd_d<_1> ___ordered_herd_dynamic___(any_a<> const& thing)
{
	return ordered_herd_d<_1>{ thing };
}

} // namespace
