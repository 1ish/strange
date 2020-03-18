
namespace strange
{

template <typename _1>
inline any_a<> cat_a<_1>::symbolic__(range_a<> const& ___arguments___) const
{
	return symbolic_();
}

template <typename _1>
inline any_a<> cat_a<_1>::order__(range_a<> const& ___arguments___) const
{
	return order_();
}

template <typename _1>
inline any_a<> cat_a<_1>::name__(range_a<> const& ___arguments___) const
{
	return name_();
}

template <typename _1>
inline any_a<> cat_a<_1>::dimensions__(range_a<> const& ___arguments___) const
{
	return dimensions_();
}

template <typename _1>
inline any_a<> cat_a<_1>::parameters__(range_a<> const& ___arguments___) const
{
	return parameters_();
}

template <typename _1>
inline any_a<> cat_a<_1>::result__(range_a<> const& ___arguments___) const
{
	return result_();
}

template <typename _1>
inline any_a<> cat_a<_1>::code__(range_a<> const& ___arguments___) const
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

template <typename _1>
inline cat_d<_1> ___cat_dynamic___(any_a<> const& thing)
{
	return cat_d<_1>{ thing };
}

} // namespace
