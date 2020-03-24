
namespace strange
{

template <typename _element>
inline any_a<> range_a<_element>::extract_begin__(range_a<> const& ___arguments___) const
{
	return extract_begin_();
}

template <typename _element>
inline forward_extractor_a< _element > range_a<_element>::extract_begin_() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_a< _element > range_a<_element>::___range_a_handle___<___TTT___, ___DHB___>::extract_begin_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin_(); }

template <typename _element>
inline any_a<> range_a<_element>::extract_end__(range_a<> const& ___arguments___) const
{
	return extract_end_();
}

template <typename _element>
inline forward_extractor_a< _element > range_a<_element>::extract_end_() const
{ assert(any_a<>::___handle___); return ___read___().extract_end_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_a< _element > range_a<_element>::___range_a_handle___<___TTT___, ___DHB___>::extract_end_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end_(); }

class ___range_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___range_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline range_d<_element> ___range_dynamic___(any_a<> const& thing)
{
	return range_d<_element>{ thing };
}

} // namespace
