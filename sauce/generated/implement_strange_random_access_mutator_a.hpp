
namespace strange
{

template <typename _element>
inline any_a<> random_access_mutator_a<_element>::self_add__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename _element>
inline random_access_mutator_a<_element> random_access_mutator_a<_element>::self_add_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_add_(number);
	return *this;
}

template <typename _element>
inline random_access_mutator_a<_element>& random_access_mutator_a<_element>::operator+=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_add_(number);
	return *this;
}

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void random_access_mutator_a<_element>::___random_access_mutator_a_handle___<___TTT___, ___DHB___>::self_add_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(number); }

template <typename _element>
inline any_a<> random_access_mutator_a<_element>::add__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename _element>
inline random_access_mutator_a< _element > random_access_mutator_a<_element>::add_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().add_(number); }

template <typename _element>
inline random_access_mutator_a< _element > random_access_mutator_a<_element>::operator+(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().add_(number); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_a< _element > random_access_mutator_a<_element>::___random_access_mutator_a_handle___<___TTT___, ___DHB___>::add_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(number); }

template <typename _element>
inline any_a<> random_access_mutator_a<_element>::self_subtract__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename _element>
inline random_access_mutator_a<_element> random_access_mutator_a<_element>::self_subtract_(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_subtract_(number);
	return *this;
}

template <typename _element>
inline random_access_mutator_a<_element>& random_access_mutator_a<_element>::operator-=(number_a<> const& number)
{
	assert(any_a<>::___handle___);
	___write___().self_subtract_(number);
	return *this;
}

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void random_access_mutator_a<_element>::___random_access_mutator_a_handle___<___TTT___, ___DHB___>::self_subtract_(number_a<> const& number)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(number); }

template <typename _element>
inline any_a<> random_access_mutator_a<_element>::subtract__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("random_access_mutator_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

template <typename _element>
inline random_access_mutator_a< _element > random_access_mutator_a<_element>::subtract_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().subtract_(number); }

template <typename _element>
inline random_access_mutator_a< _element > random_access_mutator_a<_element>::operator-(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().subtract_(number); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_a< _element > random_access_mutator_a<_element>::___random_access_mutator_a_handle___<___TTT___, ___DHB___>::subtract_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(number); }

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

template <typename _element>
inline random_access_mutator_d<_element> ___random_access_mutator_dynamic___(any_a<> const& thing)
{
	return random_access_mutator_d<_element>{ thing };
}

} // namespace
