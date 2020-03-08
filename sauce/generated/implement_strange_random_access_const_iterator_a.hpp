
namespace strange
{

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::self_add__(range_a<> const& ___arguments___)
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::add__(range_a<> const& ___arguments___) const
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::self_subtract__(range_a<> const& ___arguments___)
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::subtract__(range_a<> const& ___arguments___) const
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::less_than__(range_a<> const& ___arguments___) const
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::less_than_ passed short range");
	}
	auto it = cast<random_access_const_iterator_a<>>(*___it___);
	return less_than_(it);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::greater_than__(range_a<> const& ___arguments___) const
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::greater_than_ passed short range");
	}
	auto it = cast<random_access_const_iterator_a<>>(*___it___);
	return greater_than_(it);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::less_or_equal__(range_a<> const& ___arguments___) const
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::less_or_equal_ passed short range");
	}
	auto it = cast<random_access_const_iterator_a<>>(*___it___);
	return less_or_equal_(it);
}

template <typename _1_>
inline any_a<> random_access_const_iterator_a<_1_>::greater_or_equal__(range_a<> const& ___arguments___) const
{
	forward_const_iterator_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("random_access_const_iterator_a::greater_or_equal_ passed short range");
	}
	auto it = cast<random_access_const_iterator_a<>>(*___it___);
	return greater_or_equal_(it);
}

template <typename _1_>
bool const random_access_const_iterator_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<random_access_const_iterator_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline random_access_const_iterator_d<_1_> ___random_access_const_iterator_dynamic___(any_a<> const& thing)
{
	return random_access_const_iterator_d<_1_>{ thing };
}

} // namespace
