
namespace strange
{

template <typename _1_>
inline any_a<> random_access_extractor_a<_1_>::self_add__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_extractor_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename _1_>
inline any_a<> random_access_extractor_a<_1_>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_extractor_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename _1_>
inline any_a<> random_access_extractor_a<_1_>::self_subtract__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_extractor_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename _1_>
inline any_a<> random_access_extractor_a<_1_>::subtract__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_extractor_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

class ___random_access_extractor_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___random_access_extractor_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline random_access_extractor_d<_1_> ___random_access_extractor_dynamic___(any_a<> const& thing)
{
	return random_access_extractor_d<_1_>{ thing };
}

} // namespace
