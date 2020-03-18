
namespace strange
{

template <typename _1>
inline any_a<> forward_extractor_a<_1>::get__(range_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _1>
inline any_a<> forward_extractor_a<_1>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

class ___forward_extractor_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_extractor_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline forward_extractor_d<_1> ___forward_extractor_dynamic___(any_a<> const& thing)
{
	return forward_extractor_d<_1>{ thing };
}

} // namespace
