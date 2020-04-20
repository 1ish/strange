
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

template <typename _element>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ range_a<_element>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = list_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("extract_begin_"), native_extraction_t<range_a>::create(&range_a::extract_begin__));
		operations.update(sym("extract_end_"), native_extraction_t<range_a>::create(&range_a::extract_end__));
		return operations;
	}();
	return OPERATIONS;
}

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
