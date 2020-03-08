
namespace strange
{

template <typename _1_>
inline any_a<> forward_const_iterator_a<_1_>::get__(range_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _1_>
inline any_a<> forward_const_iterator_a<_1_>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _1_>
bool const forward_const_iterator_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<forward_const_iterator_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline forward_const_iterator_d<_1_> ___forward_const_iterator_dynamic___(any_a<> const& thing)
{
	return forward_const_iterator_d<_1_>{ thing };
}

} // namespace
