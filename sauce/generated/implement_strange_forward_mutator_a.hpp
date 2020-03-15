
namespace strange
{

template <typename _1_>
inline any_a<> forward_mutator_a<_1_>::get__(range_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _1_>
inline any_a<> forward_mutator_a<_1_>::set__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("forward_mutator_a::set_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return set_(thing);
}

template <typename _1_>
inline any_a<> forward_mutator_a<_1_>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

class ___forward_mutator_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_mutator_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline forward_mutator_d<_1_> ___forward_mutator_dynamic___(any_a<> const& thing)
{
	return forward_mutator_d<_1_>{ thing };
}

} // namespace
