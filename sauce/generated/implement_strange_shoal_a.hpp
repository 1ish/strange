
namespace strange
{

template <typename _1_>
inline any_a<> shoal_a<_1_>::mutate_begin__(range_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _1_>
inline any_a<> shoal_a<_1_>::mutate_end__(range_a<> const& ___arguments___)
{
	return mutate_end_();
}

template <typename _1_>
bool const shoal_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<shoal_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline shoal_d<_1_> ___shoal_dynamic___(any_a<> const& thing)
{
	return shoal_d<_1_>{ thing };
}

} // namespace
