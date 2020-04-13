
namespace strange
{

template <typename _key, typename _value>
inline bool shoal_a<_key, _value>::erase_string(std :: string const & s )
{ assert(any_a<>::___handle___); return ___write___().erase_string(s); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline bool shoal_a<_key, _value>::___shoal_a_handle___<___TTT___, ___DHB___>::erase_string(std :: string const & s )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_string(s); }

template <typename _key, typename _value>
inline any_a<> shoal_a<_key, _value>::mutate_begin__(range_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _key, typename _value>
inline forward_mutator_a< flock_a<> > shoal_a<_key, _value>::mutate_begin_()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin_(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_a< flock_a<> > shoal_a<_key, _value>::___shoal_a_handle___<___TTT___, ___DHB___>::mutate_begin_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin_(); }

template <typename _key, typename _value>
inline any_a<> shoal_a<_key, _value>::mutate_end__(range_a<> const& ___arguments___)
{
	return mutate_end_();
}

template <typename _key, typename _value>
inline forward_mutator_a< flock_a<> > shoal_a<_key, _value>::mutate_end_()
{ assert(any_a<>::___handle___); return ___write___().mutate_end_(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_a< flock_a<> > shoal_a<_key, _value>::___shoal_a_handle___<___TTT___, ___DHB___>::mutate_end_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end_(); }

template <typename _key, typename _value>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ shoal_a<_key, _value>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = collection_a< _key , _value , flock_a<> >::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("mutate_begin_"), native_mutation_t<shoal_a>::create(&shoal_a::mutate_begin__));
		operations.update(sym("mutate_end_"), native_mutation_t<shoal_a>::create(&shoal_a::mutate_end__));
		return operations;
	}();
	return OPERATIONS;
}

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

template <typename _key, typename _value>
inline shoal_d<_key, _value> ___shoal_dynamic___(any_a<> const& thing)
{
	return shoal_d<_key, _value>{ thing };
}

} // namespace
