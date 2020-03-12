
namespace strange
{

template <typename _1_>
inline any_a<> misunderstanding_a<_1_>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("misunderstanding_a::add_ passed short range");
	}
	auto misunderstanding = cast<misunderstanding_a<>>(*___it___);
	return add_(misunderstanding);
}

template <typename _1_>
bool const misunderstanding_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<misunderstanding_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline misunderstanding_d<_1_> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<_1_>{ thing };
}

} // namespace
