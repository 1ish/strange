
namespace strange
{

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::increment__(list_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::increment_()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator++()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator++(int)
{
	assert(any_a<>::___handle___);
	number_a result = *this;
	___write___().increment_();
	return result;
}
#endif

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::increment_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::decrement__(list_a<> const& ___arguments___)
{
	return decrement_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::decrement_()
{
	assert(any_a<>::___handle___);
	___write___().decrement_();
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator--()
{
	assert(any_a<>::___handle___);
	___write___().decrement_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator--(int)
{
	assert(any_a<>::___handle___);
	number_a result = *this;
	___write___().decrement_();
	return result;
}
#endif

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::decrement_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_assign__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::self_assign_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_assign_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_assign_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_assign_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::self_assign_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_assign_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_add__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_add_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_add_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator+=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_add_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::self_add_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::add__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::add_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().add_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator+(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().add_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::add_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_subtract__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_subtract_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_subtract_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator-=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_subtract_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::self_subtract_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::subtract__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::subtract_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().subtract_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator-(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().subtract_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::subtract_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_multiply__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::self_multiply_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_multiply_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_multiply_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_multiply_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator*=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_multiply_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::self_multiply_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_multiply_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::multiply__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::multiply_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return multiply_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::multiply_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().multiply_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator*(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().multiply_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::multiply_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.multiply_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_divide__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::self_divide_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_divide_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_divide_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_divide_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator/=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_divide_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::self_divide_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_divide_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::divide__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::divide_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return divide_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::divide_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().divide_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator/(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().divide_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::divide_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.divide_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_modulo__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::self_modulo_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_modulo_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::self_modulo_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_modulo_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<_number_data_int64, _number_data_uint64, _number_data_double>& number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator%=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_modulo_(number);
	return *this;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::self_modulo_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_modulo_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::modulo__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::modulo_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return modulo_(number);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::modulo_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().modulo_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::operator%(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().modulo_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::modulo_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.modulo_(number); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_int_64__(list_a<> const& ___arguments___) const
{
	return to_int_64_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline _number_data_int64 number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_int_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_int_64_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline _number_data_int64 number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::to_int_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline int64_t number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_int_64() const
{ assert(any_a<>::___handle___); return ___read___().to_int_64(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline int64_t number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::to_int_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_int_64__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::from_int_64_ passed short range");
	}
	auto int_64 = cast< _number_data_int64 >(*___it___);
	return from_int_64_(int_64);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_int_64_(_number_data_int64 const& int_64)
{ assert(any_a<>::___handle___); return ___write___().from_int_64_(int_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::from_int_64_(_number_data_int64 const& int_64)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64_(int_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_int_64(int64_t int_64 )
{ assert(any_a<>::___handle___); ___write___().from_int_64(int_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::from_int_64(int64_t int_64 )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64(int_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_uint_64__(list_a<> const& ___arguments___) const
{
	return to_uint_64_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline _number_data_uint64 number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_uint_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_uint_64_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline _number_data_uint64 number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::to_uint_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_uint_64_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline uint64_t number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_uint_64() const
{ assert(any_a<>::___handle___); return ___read___().to_uint_64(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline uint64_t number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::to_uint_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_uint_64(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_uint_64__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::from_uint_64_ passed short range");
	}
	auto uint_64 = cast< _number_data_uint64 >(*___it___);
	return from_uint_64_(uint_64);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_uint_64_(_number_data_uint64 const& uint_64)
{ assert(any_a<>::___handle___); return ___write___().from_uint_64_(uint_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::from_uint_64_(_number_data_uint64 const& uint_64)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_uint_64_(uint_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_uint_64(uint64_t uint_64 )
{ assert(any_a<>::___handle___); ___write___().from_uint_64(uint_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::from_uint_64(uint64_t uint_64 )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_uint_64(uint_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_float_64__(list_a<> const& ___arguments___) const
{
	return to_float_64_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline _number_data_double number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_float_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_float_64_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline _number_data_double number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::to_float_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline double number_a<_number_data_int64, _number_data_uint64, _number_data_double>::to_float_64() const
{ assert(any_a<>::___handle___); return ___read___().to_float_64(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline double number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::to_float_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_float_64__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("number_a::from_float_64_ passed short range");
	}
	auto float_64 = cast< _number_data_double >(*___it___);
	return from_float_64_(float_64);
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_float_64_(_number_data_double const& float_64)
{ assert(any_a<>::___handle___); return ___write___().from_float_64_(float_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::from_float_64_(_number_data_double const& float_64)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64_(float_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::from_float_64(double float_64 )
{ assert(any_a<>::___handle___); ___write___().from_float_64(float_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline void number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::from_float_64(double float_64 )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64(float_64); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::byte_size__(list_a<> const& ___arguments___) const
{
	return byte_size_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline _number_data_int64 number_a<_number_data_int64, _number_data_uint64, _number_data_double>::byte_size_() const
{ assert(any_a<>::___handle___); return ___read___().byte_size_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline _number_data_int64 number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::byte_size_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.byte_size_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline int64_t number_a<_number_data_int64, _number_data_uint64, _number_data_double>::byte_size() const
{ assert(any_a<>::___handle___); return ___read___().byte_size(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline int64_t number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::byte_size() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.byte_size(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_int__(list_a<> const& ___arguments___) const
{
	return is_int_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_int_() const
{ assert(any_a<>::___handle___); return ___read___().is_int_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_int_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_int() const
{ assert(any_a<>::___handle___); return ___read___().is_int(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_int() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_signed__(list_a<> const& ___arguments___) const
{
	return is_signed_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_signed_() const
{ assert(any_a<>::___handle___); return ___read___().is_signed_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_signed_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_signed_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_signed() const
{ assert(any_a<>::___handle___); return ___read___().is_signed(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_signed() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_signed(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_nan__(list_a<> const& ___arguments___) const
{
	return is_nan_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_nan_() const
{ assert(any_a<>::___handle___); return ___read___().is_nan_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_nan_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_nan_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_nan() const
{ assert(any_a<>::___handle___); return ___read___().is_nan(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_nan() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_nan(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_inf__(list_a<> const& ___arguments___) const
{
	return is_inf_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_inf_() const
{ assert(any_a<>::___handle___); return ___read___().is_inf_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_inf_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inf_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_inf() const
{ assert(any_a<>::___handle___); return ___read___().is_inf(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_inf() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inf(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_finite__(list_a<> const& ___arguments___) const
{
	return is_finite_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_finite_() const
{ assert(any_a<>::___handle___); return ___read___().is_finite_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_finite_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_finite_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_finite() const
{ assert(any_a<>::___handle___); return ___read___().is_finite(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_finite() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_finite(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_normal__(list_a<> const& ___arguments___) const
{
	return is_normal_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_normal_() const
{ assert(any_a<>::___handle___); return ___read___().is_normal_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_normal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_normal_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::is_normal() const
{ assert(any_a<>::___handle___); return ___read___().is_normal(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::is_normal() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_normal(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::little_endian__(list_a<> const& ___arguments___) const
{
	return little_endian_();
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::little_endian_() const
{ assert(any_a<>::___handle___); return ___read___().little_endian_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::little_endian_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.little_endian_(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::little_endian() const
{ assert(any_a<>::___handle___); return ___read___().little_endian(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
template <typename ___TTT___, typename ___DHB___>
inline bool number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___number_a_handle___<___TTT___, ___DHB___>::little_endian() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.little_endian(); }

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline cat_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::number");
	return CAT;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline unordered_herd_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = any_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline kind_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline unordered_herd_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = any_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline unordered_shoal_a<> number_a<_number_data_int64, _number_data_uint64, _number_data_double>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
		operations.update(sym("increment_"), native_mutation_t<number_a>::create(&number_a::increment__));
		operations.update(sym("decrement_"), native_mutation_t<number_a>::create(&number_a::decrement__));
		operations.update(sym("self_assign_"), native_mutation_t<number_a>::create(&number_a::self_assign__));
		operations.update(sym("self_add_"), native_mutation_t<number_a>::create(&number_a::self_add__));
		operations.update(sym("add_"), native_extraction_t<number_a>::create(&number_a::add__));
		operations.update(sym("self_subtract_"), native_mutation_t<number_a>::create(&number_a::self_subtract__));
		operations.update(sym("subtract_"), native_extraction_t<number_a>::create(&number_a::subtract__));
		operations.update(sym("self_multiply_"), native_mutation_t<number_a>::create(&number_a::self_multiply__));
		operations.update(sym("multiply_"), native_extraction_t<number_a>::create(&number_a::multiply__));
		operations.update(sym("self_divide_"), native_mutation_t<number_a>::create(&number_a::self_divide__));
		operations.update(sym("divide_"), native_extraction_t<number_a>::create(&number_a::divide__));
		operations.update(sym("self_modulo_"), native_mutation_t<number_a>::create(&number_a::self_modulo__));
		operations.update(sym("modulo_"), native_extraction_t<number_a>::create(&number_a::modulo__));
		operations.update(sym("to_int_64_"), native_extraction_t<number_a>::create(&number_a::to_int_64__));
		operations.update(sym("from_int_64_"), native_mutation_t<number_a>::create(&number_a::from_int_64__));
		operations.update(sym("to_uint_64_"), native_extraction_t<number_a>::create(&number_a::to_uint_64__));
		operations.update(sym("from_uint_64_"), native_mutation_t<number_a>::create(&number_a::from_uint_64__));
		operations.update(sym("to_float_64_"), native_extraction_t<number_a>::create(&number_a::to_float_64__));
		operations.update(sym("from_float_64_"), native_mutation_t<number_a>::create(&number_a::from_float_64__));
		operations.update(sym("byte_size_"), native_extraction_t<number_a>::create(&number_a::byte_size__));
		operations.update(sym("is_int_"), native_extraction_t<number_a>::create(&number_a::is_int__));
		operations.update(sym("is_signed_"), native_extraction_t<number_a>::create(&number_a::is_signed__));
		operations.update(sym("is_nan_"), native_extraction_t<number_a>::create(&number_a::is_nan__));
		operations.update(sym("is_inf_"), native_extraction_t<number_a>::create(&number_a::is_inf__));
		operations.update(sym("is_finite_"), native_extraction_t<number_a>::create(&number_a::is_finite__));
		operations.update(sym("is_normal_"), native_extraction_t<number_a>::create(&number_a::is_normal__));
		operations.update(sym("little_endian_"), native_extraction_t<number_a>::create(&number_a::little_endian__));
		return operations;
	}();
	return OPERATIONS;
}

class ___number_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___number_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
inline number_d<_number_data_int64, _number_data_uint64, _number_data_double> ___number_dynamic___(any_a<> const& thing)
{
	return number_d<_number_data_int64, _number_data_uint64, _number_data_double>{ thing };
}

} // namespace
