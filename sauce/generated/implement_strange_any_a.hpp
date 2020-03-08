
namespace strange
{

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
bool const any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>>::share(shared_shoal);
	return shared_shoal;
}();

} // namespace
