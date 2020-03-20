
namespace strange
{

template <typename _lake_int8>
inline any_a<> misunderstanding_a<_lake_int8>::to_lake__(range_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _lake_int8>
inline any_a<> misunderstanding_a<_lake_int8>::add__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("misunderstanding_a::add_ passed short range");
	}
	auto misunderstanding = cast<misunderstanding_a<>>(*___it___);
	return add_(misunderstanding);
}

class ___misunderstanding_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___misunderstanding_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _lake_int8>
inline misunderstanding_d<_lake_int8> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<_lake_int8>{ thing };
}

} // namespace
