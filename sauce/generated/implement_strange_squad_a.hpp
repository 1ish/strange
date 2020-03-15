
namespace strange
{

class ___squad_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___squad_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline squad_d<_1_> ___squad_dynamic___(any_a<> const& thing)
{
	return squad_d<_1_>{ thing };
}

} // namespace
