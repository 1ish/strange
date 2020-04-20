
namespace strange
{

template <typename _1>
inline any_a<> kind_a<_1>::aspects__(list_a<> const& ___arguments___) const
{
	return aspects_();
}

template <typename _1>
inline flock_a<> kind_a<_1>::aspects_() const
{ assert(any_a<>::___handle___); return ___read___().aspects_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a<> kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::aspects_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects_(); }

template <typename _1>
inline any_a<> kind_a<_1>::fixed__(list_a<> const& ___arguments___) const
{
	return fixed_();
}

template <typename _1>
inline any_a<> kind_a<_1>::fixed_() const
{ assert(any_a<>::___handle___); return ___read___().fixed_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::fixed_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed_(); }

template <typename _1>
inline bool kind_a<_1>::fixed() const
{ assert(any_a<>::___handle___); return ___read___().fixed(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::fixed() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed(); }

template <typename _1>
inline any_a<> kind_a<_1>::reference__(list_a<> const& ___arguments___) const
{
	return reference_();
}

template <typename _1>
inline any_a<> kind_a<_1>::reference_() const
{ assert(any_a<>::___handle___); return ___read___().reference_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::reference_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.reference_(); }

template <typename _1>
inline bool kind_a<_1>::reference() const
{ assert(any_a<>::___handle___); return ___read___().reference(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::reference() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.reference(); }

template <typename _1>
inline any_a<> kind_a<_1>::optional__(list_a<> const& ___arguments___) const
{
	return optional_();
}

template <typename _1>
inline any_a<> kind_a<_1>::optional_() const
{ assert(any_a<>::___handle___); return ___read___().optional_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::optional_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.optional_(); }

template <typename _1>
inline bool kind_a<_1>::optional() const
{ assert(any_a<>::___handle___); return ___read___().optional(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool kind_a<_1>::___kind_a_handle___<___TTT___, ___DHB___>::optional() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.optional(); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ kind_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = cat_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("aspects_"), native_extraction_t<kind_a>::create(&kind_a::aspects__));
		operations.update(sym("fixed_"), native_extraction_t<kind_a>::create(&kind_a::fixed__));
		operations.update(sym("reference_"), native_extraction_t<kind_a>::create(&kind_a::reference__));
		operations.update(sym("optional_"), native_extraction_t<kind_a>::create(&kind_a::optional__));
		return operations;
	}();
	return OPERATIONS;
}

class ___kind_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___kind_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline kind_d<_1> ___kind_dynamic___(any_a<> const& thing)
{
	return kind_d<_1>{ thing };
}

} // namespace
