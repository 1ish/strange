
namespace strange
{

template <typename _1_>
bool const inventory_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<inventory_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline inventory_d<_1_> ___inventory_dynamic___(any_a<> const& thing)
{
	return inventory_d<_1_>{ thing };
}

} // namespace
