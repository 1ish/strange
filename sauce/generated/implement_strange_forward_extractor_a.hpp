
namespace strange
{

template <typename _element>
inline any_a<> forward_extractor_a<_element>::get__(list_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _element>
inline _element forward_extractor_a<_element>::get_() const
{ assert(any_a<>::___handle___); return ___read___().get_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::get_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

template <typename _element>
inline _element const & forward_extractor_a<_element>::operator*() const
{ assert(any_a<>::___handle___); return ___read___().operator*(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element const & forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::operator*() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

template <typename _element>
inline _element const * forward_extractor_a<_element>::operator->() const
{ assert(any_a<>::___handle___); return ___read___().operator->(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element const * forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::operator->() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

template <typename _element>
inline any_a<> forward_extractor_a<_element>::increment__(list_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _element>
inline forward_extractor_a<_element> forward_extractor_a<_element>::increment_()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

template <typename _element>
inline forward_extractor_a<_element>& forward_extractor_a<_element>::operator++()
{
	assert(any_a<>::___handle___);
	___write___().increment_();
	return *this;
}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
template <typename _element>
inline forward_extractor_a<_element> forward_extractor_a<_element>::operator++(int)
{
	assert(any_a<>::___handle___);
	forward_extractor_a result = *this;
	___write___().increment_();
	return result;
}
#endif

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::increment_()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

template <typename _element>
inline any_a<> forward_extractor_a<_element>::to_extractor_any__(list_a<> const& ___arguments___) const
{
	return to_extractor_any_();
}

template <typename _element>
inline forward_extractor_a< any_a<> > forward_extractor_a<_element>::to_extractor_any_() const
{ assert(any_a<>::___handle___); return ___read___().to_extractor_any_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_a< any_a<> > forward_extractor_a<_element>::___forward_extractor_a_handle___<___TTT___, ___DHB___>::to_extractor_any_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_extractor_any_(); }

template <typename _element>
inline cat_a<> forward_extractor_a<_element>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::forward_extractor", flock_vals(kind_create(2, "")));
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> forward_extractor_a<_element>::___cats___()
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
inline kind_a<> forward_extractor_a<_element>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___(), flock_vals(kind_of<_element>()));
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> forward_extractor_a<_element>::___kinds___()
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
inline unordered_shoal_a<> forward_extractor_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
		operations.update(sym("get_"), native_extraction_t<forward_extractor_a>::create(&forward_extractor_a::get__));
		operations.update(sym("increment_"), native_mutation_t<forward_extractor_a>::create(&forward_extractor_a::increment__));
		operations.update(sym("to_extractor_any_"), native_extraction_t<forward_extractor_a>::create(&forward_extractor_a::to_extractor_any__));
		return operations;
	}();
	return OPERATIONS;
}

class ___forward_extractor_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___forward_extractor_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline forward_extractor_d<_element> ___forward_extractor_dynamic___(any_a<> const& thing)
{
	return forward_extractor_d<_element>{ thing };
}

} // namespace
