
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
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
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

template <typename _1_>
bool const forward_mutator_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<forward_mutator_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline forward_mutator_d<_1_> ___forward_mutator_dynamic___(any_a<> const& thing)
{
	return forward_mutator_d<_1_>{ thing };
}

} // namespace
