
namespace strange
{

template <typename _element>
inline any_a<> range_a<_element>::extract_begin__(list_a<> const& ___arguments___) const
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
inline any_a<> range_a<_element>::extract_end__(list_a<> const& ___arguments___) const
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
inline cat_a<> range_a<_element>::___cat___()
{
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::range");
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> range_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = list_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> range_a<_element>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> range_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = list_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> range_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = list_a<>::___operations___();
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
