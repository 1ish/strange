
namespace strange
{

template <typename _element>
inline any_a<> forward_mutator_a<_element>::get__(list_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _element>
inline _element forward_mutator_a<_element>::get_() const
{ assert(any_a<>::___handle___); return ___read___().get_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::get_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

template <typename _element>
inline any_a<> forward_mutator_a<_element>::set__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "forward_mutator_a::set_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return set_(thing);
}

template <typename _element>
inline _element forward_mutator_a<_element>::set_(_element const& thing) const
{ assert(any_a<>::___handle___); return ___read___().set_(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::set_(_element const& thing) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_(thing); }

template <typename _element>
inline _element & forward_mutator_a<_element>::operator*() const
{ assert(any_a<>::___handle___); return ___read___().operator*(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element & forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::operator*() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

template <typename _element>
inline _element * forward_mutator_a<_element>::operator->() const
{ assert(any_a<>::___handle___); return ___read___().operator->(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element * forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::operator->() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

template <typename _element>
inline any_a<> forward_mutator_a<_element>::increment__(list_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _element>
inline forward_mutator_a<_element> forward_mutator_a<_element>::increment_()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

template <typename _element>
inline forward_mutator_a<_element>& forward_mutator_a<_element>::operator++()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _element>
inline forward_mutator_a<_element> forward_mutator_a<_element>::operator++(int)
{
	assert(any_a<>::___handle___);
	forward_mutator_a result = *this;
	___write___().increment_();
	return result;
}
#endif

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void forward_mutator_a<_element>::___forward_mutator_a_handle___<___TTT___, ___DHB___>::increment_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

template <typename _element>
inline cat_a<> forward_mutator_a<_element>::___cat___()
{
	static cat_a<> CAT = cat::create(1, "strange::forward_mutator", flock::create_vals(kind::create(2, "")));
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> forward_mutator_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = any_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> forward_mutator_a<_element>::___kind___()
{
	static kind_a<> KIND = kind::from_cat(___cat___(), flock::create_vals(kind_of<_element>()));
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> forward_mutator_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = any_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> forward_mutator_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
		operations.update(sym("get_"), native_extraction::create(&forward_mutator_a::get__));
		operations.update(sym("set_"), native_extraction::create(&forward_mutator_a::set__));
		operations.update(sym("increment_"), native_mutation::create(&forward_mutator_a::increment__));
		return operations;
	}();
	return OPERATIONS;
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

template <typename _element>
inline forward_mutator_d<_element> ___forward_mutator_dynamic___(any_a<> const& thing)
{
	return forward_mutator_d<_element>{ thing };
}

} // namespace
