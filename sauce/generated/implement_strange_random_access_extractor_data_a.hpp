
namespace strange
{

class ___random_access_extractor_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___random_access_extractor_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element, typename _type>
inline random_access_extractor_data_d<_element, _type> ___random_access_extractor_data_dynamic___(any_a<> const& thing)
{
	return random_access_extractor_data_d<_element, _type>{ thing };
}

} // namespace
