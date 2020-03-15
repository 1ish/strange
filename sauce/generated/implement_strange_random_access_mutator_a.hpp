
namespace strange
{

template <typename _1_>
inline any_a<> random_access_mutator_a<_1_>::self_add__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename _1_>
inline any_a<> random_access_mutator_a<_1_>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename _1_>
inline any_a<> random_access_mutator_a<_1_>::self_subtract__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename _1_>
inline any_a<> random_access_mutator_a<_1_>::subtract__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

template <typename _1_>
bool const random_access_mutator_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

class ___random_access_mutator_a_share___
{
	static inline bool ___share___()
	{
		return false; // random_access_mutator_a<>::___share___;
	}
};

template <typename _1_>
inline random_access_mutator_d<_1_> ___random_access_mutator_dynamic___(any_a<> const& thing)
{
	return random_access_mutator_d<_1_>{ thing };
}

} // namespace
