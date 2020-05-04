
namespace strange
{

template <typename _element>
inline any_a<> random_access_mutator_a<_element>::self_add__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "random_access_mutator_a::self_add_ passed short range");
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
inline any_a<> random_access_mutator_a<_element>::add__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "random_access_mutator_a::add_ passed short range");
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
inline any_a<> random_access_mutator_a<_element>::self_subtract__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "random_access_mutator_a::self_subtract_ passed short range");
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
inline any_a<> random_access_mutator_a<_element>::subtract__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "random_access_mutator_a::subtract_ passed short range");
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

template <typename _element>
inline cat_a<> random_access_mutator_a<_element>::___cat___()
{
	static cat_a<> CAT = cat::create(1, "strange::random_access_mutator", flock::create_vals(kind::create(2, "")));
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> random_access_mutator_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = bidirectional_mutator_a< _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> random_access_mutator_a<_element>::___kind___()
{
	static kind_a<> KIND = kind::from_cat(___cat___(), flock::create_vals(kind_of<_element>()));
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> random_access_mutator_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = bidirectional_mutator_a< _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> random_access_mutator_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = bidirectional_mutator_a< _element >::___operations___();
		operations.update(sym("self_add_"), native_mutation::create(&random_access_mutator_a::self_add__));
		operations.update(sym("add_"), native_extraction::create(&random_access_mutator_a::add__));
		operations.update(sym("self_subtract_"), native_mutation::create(&random_access_mutator_a::self_subtract__));
		operations.update(sym("subtract_"), native_extraction::create(&random_access_mutator_a::subtract__));
		return operations;
	}();
	return OPERATIONS;
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

template <typename _element>
inline random_access_mutator_d<_element> ___random_access_mutator_dynamic___(any_a<> const& thing)
{
	return random_access_mutator_d<_element>{ thing };
}

} // namespace
