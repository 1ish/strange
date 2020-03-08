
namespace strange
{

template <typename _1_>
bool const inventory_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<inventory_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

} // namespace
