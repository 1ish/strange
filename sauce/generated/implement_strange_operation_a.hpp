
namespace strange
{

template <typename _1_>
inline any_a<> operation_a<_1_>::pure__(range_a<> const& ___arguments___) const
{
	return pure_();
}

template <typename _1_>
inline any_a<> operation_a<_1_>::names__(range_a<> const& ___arguments___) const
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

template <typename _1_>
inline operation_d<_1_> ___operation_dynamic___(any_a<> const& thing)
{
	return operation_d<_1_>{ thing };
}

} // namespace
