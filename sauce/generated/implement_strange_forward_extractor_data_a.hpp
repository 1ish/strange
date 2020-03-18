
namespace strange
{

class ___forward_extractor_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_extractor_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _type>
inline forward_extractor_data_d<_type> ___forward_extractor_data_dynamic___(any_a<> const& thing)
{
	return forward_extractor_data_d<_type>{ thing };
}

} // namespace
