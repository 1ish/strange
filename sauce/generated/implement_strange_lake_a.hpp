
namespace strange
{

class ___lake_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___lake_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _primitive>
inline lake_d<_primitive> ___lake_dynamic___(any_a<> const& thing)
{
	return lake_d<_primitive>{ thing };
}

} // namespace
