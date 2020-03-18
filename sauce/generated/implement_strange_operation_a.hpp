
namespace strange
{

template <typename _1>
inline any_a<> operation_a<_1>::pure__(range_a<> const& ___arguments___) const
{
	return pure_();
}

template <typename _1>
inline any_a<> operation_a<_1>::names__(range_a<> const& ___arguments___) const
{
	return names_();
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
