
namespace strange
{

template <typename _1>
inline any_a<> operation_a<_1>::pure__(list_a<> const& ___arguments___) const
{
	return pure_();
}

template <typename _1>
inline any_a<> operation_a<_1>::pure_() const
{ assert(any_a<>::___handle___); return ___read___().pure_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> operation_a<_1>::___operation_a_handle___<___TTT___, ___DHB___>::pure_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.pure_(); }

template <typename _1>
inline bool operation_a<_1>::pure() const
{ assert(any_a<>::___handle___); return ___read___().pure(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool operation_a<_1>::___operation_a_handle___<___TTT___, ___DHB___>::pure() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.pure(); }

template <typename _1>
inline void operation_a<_1>::aspects(unordered_shoal_a < > const & shoal )
{ assert(any_a<>::___handle___); ___write___().aspects(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void operation_a<_1>::___operation_a_handle___<___TTT___, ___DHB___>::aspects(unordered_shoal_a < > const & shoal )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects(shoal); }

template <typename _1>
inline void operation_a<_1>::assign(operation_a < > const & operation )
{ assert(any_a<>::___handle___); ___write___().assign(operation); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void operation_a<_1>::___operation_a_handle___<___TTT___, ___DHB___>::assign(operation_a < > const & operation )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.assign(operation); }

template <typename _1>
inline any_a<> operation_a<_1>::names__(list_a<> const& ___arguments___) const
{
	return names_();
}

template <typename _1>
inline flock_a<> operation_a<_1>::names_() const
{ assert(any_a<>::___handle___); return ___read___().names_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a<> operation_a<_1>::___operation_a_handle___<___TTT___, ___DHB___>::names_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.names_(); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ operation_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("pure_"), native_extraction_t<operation_a>::create(&operation_a::pure__));
		operations.update(sym("names_"), native_extraction_t<operation_a>::create(&operation_a::names__));
		return operations;
	}();
	return OPERATIONS;
}

class ___operation_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___operation_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline operation_d<_1> ___operation_dynamic___(any_a<> const& thing)
{
	return operation_d<_1>{ thing };
}

} // namespace
