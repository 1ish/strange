
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

template <typename _1>
inline flock_d<_1> ___flock_dynamic___(any_a<> const& thing)
{
	return flock_d<_1>{ thing };
}

} // namespace
