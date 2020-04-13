
namespace strange
{

template <typename _element>
inline any_a<> herd_a<_element>::update_thing__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
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
inline void herd_a<_element>::update_string(std :: string const & s )
{ assert(any_a<>::___handle___); ___write___().update_string(s); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::update_string(std :: string const & s )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_string(s); }

template <typename _element>
inline any_a<> herd_a<_element>::insert_thing__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
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
inline bool herd_a<_element>::insert_string(std :: string const & s )
{ assert(any_a<>::___handle___); return ___write___().insert_string(s); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::insert_string(std :: string const & s )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_string(s); }

template <typename _element>
inline bool herd_a<_element>::erase_string(std :: string const & s )
{ assert(any_a<>::___handle___); return ___write___().erase_string(s); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::erase_string(std :: string const & s )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_string(s); }

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
