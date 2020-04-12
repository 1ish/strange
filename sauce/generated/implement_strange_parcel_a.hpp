
namespace strange
{

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap__(range_a<> const& ___arguments___) const
{
	return unwrap_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_() const
{ assert(any_a<>::___handle___); return ___read___().unwrap_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unwrap_(); }

template <typename _1>
inline bool parcel_a<_1>::operator==(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator==(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator!=(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator!=(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator<(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator<(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator>(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator>(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator<=(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator<=(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator>=(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator>=(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(parcel); }

template <typename _1>
inline bidirectional_extractor_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _1>
inline bidirectional_extractor_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _1>
inline bidirectional_mutator_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::mutate_begin()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_mutator_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::mutate_begin()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

template <typename _1>
inline bidirectional_mutator_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::mutate_end()
{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_mutator_data_a < flock_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::mutate_end()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

template <typename _1>
inline dart :: packet const & parcel_a<_1>::extract_packet() const
{ assert(any_a<>::___handle___); return ___read___().extract_packet(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline dart :: packet const & parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::extract_packet() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_packet(); }

template <typename _1>
inline dart :: packet & parcel_a<_1>::mutate_packet()
{ assert(any_a<>::___handle___); return ___write___().mutate_packet(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline dart :: packet & parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::mutate_packet()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_packet(); }

class ___parcel_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___parcel_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline parcel_d<_1> ___parcel_dynamic___(any_a<> const& thing)
{
	return parcel_d<_1>{ thing };
}

} // namespace
