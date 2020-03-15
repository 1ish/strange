
namespace strange
{

class ___unordered_shoal_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___unordered_shoal_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline unordered_shoal_d<_1_> ___unordered_shoal_dynamic___(any_a<> const& thing)
{
	return unordered_shoal_d<_1_>{ thing };
}

} // namespace
