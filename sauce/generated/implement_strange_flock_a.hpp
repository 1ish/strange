
namespace strange
{

class ___flock_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___flock_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline flock_d<_1_> ___flock_dynamic___(any_a<> const& thing)
{
	return flock_d<_1_>{ thing };
}

} // namespace
