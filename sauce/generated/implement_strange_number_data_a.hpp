
namespace strange
{

class ___number_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___number_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline number_data_d<_1_> ___number_data_dynamic___(any_a<> const& thing)
{
	return number_data_d<_1_>{ thing };
}

} // namespace
