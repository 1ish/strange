
namespace strange
{

template <typename _1>
inline any_a<> shoal_a<_1>::mutate_begin__(range_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _1>
inline any_a<> shoal_a<_1>::mutate_end__(range_a<> const& ___arguments___)
{
	return mutate_end_();
}

class ___shoal_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___shoal_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline shoal_d<_1> ___shoal_dynamic___(any_a<> const& thing)
{
	return shoal_d<_1>{ thing };
}

} // namespace
