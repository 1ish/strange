
namespace strange
{

template <typename _1>
inline bool shoal_a<_1>::has_string(std :: string const & s ) const
{ assert(any_a<>::___handle___); return ___read___().has_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::has_string(std :: string const & s ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has_string(s); }

template <typename _1>
inline any_a < > shoal_a<_1>::at_string(std :: string const & s ) const
{ assert(any_a<>::___handle___); return ___read___().at_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a < > shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::at_string(std :: string const & s ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.at_string(s); }

template <typename _1>
inline void shoal_a<_1>::update_string(std :: string const & s , any_a < > const & value )
{ assert(any_a<>::___handle___); ___write___().update_string(s, value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::update_string(std :: string const & s , any_a < > const & value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_string(s, value); }

template <typename _1>
inline bool shoal_a<_1>::insert_string(std :: string const & s , any_a < > const & value )
{ assert(any_a<>::___handle___); return ___write___().insert_string(s, value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::insert_string(std :: string const & s , any_a < > const & value )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_string(s, value); }

template <typename _1>
inline bool shoal_a<_1>::erase_string(std :: string const & s )
{ assert(any_a<>::___handle___); return ___write___().erase_string(s); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::erase_string(std :: string const & s )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_string(s); }

template <typename _1>
inline any_a<> shoal_a<_1>::mutate_begin__(range_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _1>
inline forward_mutator_a< any_a<> > shoal_a<_1>::mutate_begin_()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_a< any_a<> > shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::mutate_begin_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin_(); }

template <typename _1>
inline any_a<> shoal_a<_1>::mutate_end__(range_a<> const& ___arguments___)
{
	return mutate_end_();
}

template <typename _1>
inline forward_mutator_a< any_a<> > shoal_a<_1>::mutate_end_()
{ assert(any_a<>::___handle___); return ___write___().mutate_end_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_a< any_a<> > shoal_a<_1>::___shoal_a_handle___<___TTT___, ___DHB___>::mutate_end_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end_(); }

class ___shoal_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___shoal_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline shoal_d<_1> ___shoal_dynamic___(any_a<> const& thing)
{
	return shoal_d<_1>{ thing };
}

} // namespace
