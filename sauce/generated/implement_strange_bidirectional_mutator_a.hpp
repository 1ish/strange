
namespace strange
{

template <typename _1_>
inline any_a<> bidirectional_mutator_a<_1_>::decrement__(range_a<> const& ___arguments___)
{
	return decrement_();
}

template <typename _1_>
bool const bidirectional_mutator_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<bidirectional_mutator_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline bidirectional_mutator_d<_1_> ___bidirectional_mutator_dynamic___(any_a<> const& thing)
{
	return bidirectional_mutator_d<_1_>{ thing };
}

} // namespace