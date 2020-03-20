
namespace strange
{

template <typename _1>
inline any_a<> random_access_mutator_a<_1>::self_add__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename _1>
inline any_a<> random_access_mutator_a<_1>::add__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename _1>
inline any_a<> random_access_mutator_a<_1>::self_subtract__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename _1>
inline any_a<> random_access_mutator_a<_1>::subtract__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

class ___random_access_mutator_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___random_access_mutator_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline random_access_mutator_d<_1> ___random_access_mutator_dynamic___(any_a<> const& thing)
{
	return random_access_mutator_d<_1>{ thing };
}

} // namespace
