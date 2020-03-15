
namespace strange
{

class ___data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline data_d<_1_> ___data_dynamic___(any_a<> const& thing)
{
	return data_d<_1_>{ thing };
}

} // namespace
