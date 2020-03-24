
namespace strange
{

template <typename _1>
inline bool herd_a<_1>::has_string(std :: string const & s ) const
{ assert(any_a<>::___handle___); return ___read___().has_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::has_string(std :: string const & s ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has_string(s); }

template <typename _1>
inline any_a < > herd_a<_1>::at_string(std :: string const & s ) const
{ assert(any_a<>::___handle___); return ___read___().at_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a < > herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::at_string(std :: string const & s ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.at_string(s); }

template <typename _1>
inline void herd_a<_1>::update_thing(any_a < > const & thing )
{ assert(any_a<>::___handle___); ___write___().update_thing(thing); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::update_thing(any_a < > const & thing )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_thing(thing); }

template <typename _1>
inline void herd_a<_1>::update_string(std :: string const & s )
{ assert(any_a<>::___handle___); ___write___().update_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::update_string(std :: string const & s )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_string(s); }

template <typename _1>
inline bool herd_a<_1>::insert_thing(any_a < > const & thing )
{ assert(any_a<>::___handle___); return ___write___().insert_thing(thing); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::insert_thing(any_a < > const & thing )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_thing(thing); }

template <typename _1>
inline bool herd_a<_1>::insert_string(std :: string const & s )
{ assert(any_a<>::___handle___); return ___write___().insert_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::insert_string(std :: string const & s )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_string(s); }

template <typename _1>
inline bool herd_a<_1>::erase_string(std :: string const & s )
{ assert(any_a<>::___handle___); return ___write___().erase_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_1>::___herd_a_handle___<___TTT___, ___DHB___>::erase_string(std :: string const & s )
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

template <typename _1>
inline herd_d<_1> ___herd_dynamic___(any_a<> const& thing)
{
	return herd_d<_1>{ thing };
}

} // namespace
