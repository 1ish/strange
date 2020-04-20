
namespace strange
{

template <typename _element>
inline any_a<> herd_a<_element>::update_thing__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("herd_a::update_thing_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return update_thing_(thing);
}

template <typename _element>
inline _element herd_a<_element>::update_thing_(_element const& thing)
{ assert(any_a<>::___handle___); return ___write___().update_thing_(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::update_thing_(_element const& thing)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_thing_(thing); }

template <typename _element>
inline void herd_a<_element>::update_thing(_element const & thing )
{ assert(any_a<>::___handle___); ___write___().update_thing(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::update_thing(_element const & thing )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_thing(thing); }

template <typename _element>
inline any_a<> herd_a<_element>::insert_thing__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("herd_a::insert_thing_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return insert_thing_(thing);
}

template <typename _element>
inline any_a<> herd_a<_element>::insert_thing_(_element const& thing)
{ assert(any_a<>::___handle___); return ___write___().insert_thing_(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::insert_thing_(_element const& thing)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_thing_(thing); }

template <typename _element>
inline bool herd_a<_element>::insert_thing(_element const & thing )
{ assert(any_a<>::___handle___); return ___write___().insert_thing(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::insert_thing(_element const & thing )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_thing(thing); }

template <typename _element>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ herd_a<_element>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = collection_a< _element , _element , _element >::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("update_thing_"), native_mutation_t<herd_a>::create(&herd_a::update_thing__));
		operations.update(sym("insert_thing_"), native_mutation_t<herd_a>::create(&herd_a::insert_thing__));
		return operations;
	}();
	return OPERATIONS;
}

class ___herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline herd_d<_element> ___herd_dynamic___(any_a<> const& thing)
{
	return herd_d<_element>{ thing };
}

} // namespace
