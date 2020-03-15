
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

template <typename element>
bool const range_of_a<element>::___share___ = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

class ___range_of_a_share___
{
	static inline bool ___share___()
	{
		return false; // range_of_a<>::___share___;
	}
};

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing)
{
	return range_of_d<element>{ thing };
}

} // namespace
