
namespace strange
{

template <typename element>
bool const range_of_a<element>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<range_of_a<element>>::share(shared_shoal);
	return shared_shoal;
}();

} // namespace
