
namespace strange
{

template <typename _1_>
inline any_a<> range_a<_1_>::extract_begin__(range_a<> const& ___arguments___) const
{
	return extract_begin_();
}

template <typename _1_>
inline any_a<> range_a<_1_>::extract_end__(range_a<> const& ___arguments___) const
{
	return extract_end_();
}

template <typename _1_>
bool const range_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<range_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline range_d<_1_> ___range_dynamic___(any_a<> const& thing)
{
	return range_d<_1_>{ thing };
}

} // namespace
