
namespace strange
{

template <typename _type>
inline bool data_a<_type>::operator==(data_a < _type > const & data ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(data); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::operator==(data_a < _type > const & data ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(data); }

template <typename _type>
inline bool data_a<_type>::operator!=(data_a < _type > const & data ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(data); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::operator!=(data_a < _type > const & data ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(data); }

template <typename _type>
inline _type const & data_a<_type>::extract_data() const
{ assert(any_a<>::___handle___); return ___read___().extract_data(); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type const & data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::extract_data() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_data(); }

template <typename _type>
inline _type & data_a<_type>::mutate_data()
{ assert(any_a<>::___handle___); return ___write___().mutate_data(); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type & data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::mutate_data()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_data(); }

class ___data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _type>
inline data_d<_type> ___data_dynamic___(any_a<> const& thing)
{
	return data_d<_type>{ thing };
}

} // namespace
