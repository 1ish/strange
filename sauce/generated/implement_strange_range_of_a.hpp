
namespace strange
{

template <typename element>
inline any_a<> range_of_a<element>::extract_begin__(range_a<> const& ___arguments___) const
{
	return extract_begin_();
}

template <typename element>
inline any_a<> range_of_a<element>::extract_end__(range_a<> const& ___arguments___) const
{
	return extract_end_();
}

class ___range_of_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___range_of_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing)
{
	return range_of_d<element>{ thing };
}

} // namespace
