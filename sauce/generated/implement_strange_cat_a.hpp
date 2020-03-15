
namespace strange
{

template <typename _1_>
inline any_a<> cat_a<_1_>::symbolic__(range_a<> const& ___arguments___) const
{
	return symbolic_();
}

template <typename _1_>
inline any_a<> cat_a<_1_>::order__(range_a<> const& ___arguments___) const
{
	return order_();
}

template <typename _1_>
inline any_a<> cat_a<_1_>::name__(range_a<> const& ___arguments___) const
{
	return name_();
}

template <typename _1_>
inline any_a<> cat_a<_1_>::dimensions__(range_a<> const& ___arguments___) const
{
	return dimensions_();
}

template <typename _1_>
inline any_a<> cat_a<_1_>::parameters__(range_a<> const& ___arguments___) const
{
	return parameters_();
}

template <typename _1_>
inline any_a<> cat_a<_1_>::result__(range_a<> const& ___arguments___) const
{
	return result_();
}

template <typename _1_>
inline any_a<> cat_a<_1_>::code__(range_a<> const& ___arguments___) const
{
	return code_();
}

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

template <typename _1_>
inline cat_d<_1_> ___cat_dynamic___(any_a<> const& thing)
{
	return cat_d<_1_>{ thing };
}

} // namespace
