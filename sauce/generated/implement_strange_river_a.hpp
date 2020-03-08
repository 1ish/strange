
namespace strange
{

template <typename _1_>
bool const river_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<river_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline river_d<_1_> ___river_dynamic___(any_a<> const& thing)
{
	return river_d<_1_>{ thing };
}

} // namespace
