
namespace strange
{

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
bool const number_a<number_data_int64, number_data_uint64, number_data_double>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<number_a<number_data_int64, number_data_uint64, number_data_double>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline number_d<number_data_int64, number_data_uint64, number_data_double> ___number_dynamic___(any_a<> const& thing)
{
	return number_d<number_data_int64, number_data_uint64, number_data_double>{ thing };
}

} // namespace
