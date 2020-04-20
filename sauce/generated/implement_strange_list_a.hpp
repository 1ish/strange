
namespace strange
{

template <typename _1>
inline any_a<> list_a<_1>::begin__(range_a<> const& ___arguments___) const
{
	return begin_();
}

template <typename _1>
inline forward_extractor_a< any_a<> > list_a<_1>::begin_() const
{ assert(any_a<>::___handle___); return ___read___().begin_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_a< any_a<> > list_a<_1>::___list_a_handle___<___TTT___, ___DHB___>::begin_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.begin_(); }

template <typename _1>
inline any_a<> list_a<_1>::end__(range_a<> const& ___arguments___) const
{
	return end_();
}

template <typename _1>
inline forward_extractor_a< any_a<> > list_a<_1>::end_() const
{ assert(any_a<>::___handle___); return ___read___().end_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_a< any_a<> > list_a<_1>::___list_a_handle___<___TTT___, ___DHB___>::end_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.end_(); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ list_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("begin_"), native_extraction_t<list_a>::create(&list_a::begin__));
		operations.update(sym("end_"), native_extraction_t<list_a>::create(&list_a::end__));
		return operations;
	}();
	return OPERATIONS;
}

class ___list_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___list_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline list_d<_1> ___list_dynamic___(any_a<> const& thing)
{
	return list_d<_1>{ thing };
}

} // namespace
