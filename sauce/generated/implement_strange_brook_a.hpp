
namespace strange
{

class ___brook_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___brook_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _primitive>
inline brook_d<_primitive> ___brook_dynamic___(any_a<> const& thing)
{
	return brook_d<_primitive>{ thing };
}

} // namespace
