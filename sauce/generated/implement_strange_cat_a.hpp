
namespace strange
{

template <typename _1>
inline any_a<> cat_a<_1>::symbolic__(range_a<> const& ___arguments___) const
{
	return symbolic_();
}

template <typename _1>
inline any_a<> cat_a<_1>::symbolic_() const
{ assert(any_a<>::___handle___); return ___read___().symbolic_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::symbolic_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.symbolic_(); }

template <typename _1>
inline bool cat_a<_1>::symbolic() const
{ assert(any_a<>::___handle___); return ___read___().symbolic(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::symbolic() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.symbolic(); }

template <typename _1>
inline any_a<> cat_a<_1>::order__(range_a<> const& ___arguments___) const
{
	return order_();
}

template <typename _1>
inline number_data_int64_a<> cat_a<_1>::order_() const
{ assert(any_a<>::___handle___); return ___read___().order_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::order_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.order_(); }

template <typename _1>
inline int64_t cat_a<_1>::order() const
{ assert(any_a<>::___handle___); return ___read___().order(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int64_t cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::order() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.order(); }

template <typename _1>
inline any_a<> cat_a<_1>::name__(range_a<> const& ___arguments___) const
{
	return name_();
}

template <typename _1>
inline symbol_a<> cat_a<_1>::name_() const
{ assert(any_a<>::___handle___); return ___read___().name_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::name_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.name_(); }

template <typename _1>
inline std :: string cat_a<_1>::name() const
{ assert(any_a<>::___handle___); return ___read___().name(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::name() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.name(); }

template <typename _1>
inline any_a<> cat_a<_1>::dimensions__(range_a<> const& ___arguments___) const
{
	return dimensions_();
}

template <typename _1>
inline flock_a<> cat_a<_1>::dimensions_() const
{ assert(any_a<>::___handle___); return ___read___().dimensions_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::dimensions_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.dimensions_(); }

template <typename _1>
inline any_a<> cat_a<_1>::parameters__(range_a<> const& ___arguments___) const
{
	return parameters_();
}

template <typename _1>
inline flock_a<> cat_a<_1>::parameters_() const
{ assert(any_a<>::___handle___); return ___read___().parameters_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::parameters_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.parameters_(); }

template <typename _1>
inline any_a<> cat_a<_1>::result__(range_a<> const& ___arguments___) const
{
	return result_();
}

template <typename _1>
inline cat_a<> cat_a<_1>::result_() const
{ assert(any_a<>::___handle___); return ___read___().result_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline cat_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::result_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.result_(); }

template <typename _1>
inline any_a<> cat_a<_1>::code__(range_a<> const& ___arguments___) const
{
	return code_();
}

template <typename _1>
inline lake_int8_a<> cat_a<_1>::code_() const
{ assert(any_a<>::___handle___); return ___read___().code_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::code_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.code_(); }

template <typename _1>
inline std :: string cat_a<_1>::code() const
{ assert(any_a<>::___handle___); return ___read___().code(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string cat_a<_1>::___cat_a_handle___<___TTT___, ___DHB___>::code() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.code(); }

class ___cat_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___cat_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline cat_d<_1> ___cat_dynamic___(any_a<> const& thing)
{
	return cat_d<_1>{ thing };
}

} // namespace
