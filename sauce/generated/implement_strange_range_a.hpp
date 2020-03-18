
namespace strange
{

template <typename _1>
inline any_a<> range_a<_1>::extract_begin__(range_a<> const& ___arguments___) const
{
	return extract_begin_();
}

template <typename _1>
inline any_a<> range_a<_1>::extract_end__(range_a<> const& ___arguments___) const
{
	return extract_end_();
}

class ___range_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___range_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline range_d<_1> ___range_dynamic___(any_a<> const& thing)
{
	return range_d<_1>{ thing };
}

} // namespace
