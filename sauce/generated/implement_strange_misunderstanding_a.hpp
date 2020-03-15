
namespace strange
{

template <typename lake_int8>
inline any_a<> misunderstanding_a<lake_int8>::to_lake__(range_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename lake_int8>
inline any_a<> misunderstanding_a<lake_int8>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("misunderstanding_a::add_ passed short range");
	}
	auto misunderstanding = cast<misunderstanding_a<>>(*___it___);
	return add_(misunderstanding);
}

template <typename lake_int8>
bool const misunderstanding_a<lake_int8>::___share___ = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

class ___misunderstanding_a_share___
{
	static inline bool ___share___()
	{
		return false; // misunderstanding_a<>::___share___;
	}
};

template <typename lake_int8>
inline misunderstanding_d<lake_int8> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<lake_int8>{ thing };
}

} // namespace
