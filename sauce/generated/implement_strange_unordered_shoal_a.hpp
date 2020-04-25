
namespace strange
{

template <typename _key, typename _value>
inline bool unordered_shoal_a<_key, _value>::operator==(unordered_shoal_a < _key , _value > const & shoal ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(shoal); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::operator==(unordered_shoal_a < _key , _value > const & shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(shoal); }

template <typename _key, typename _value>
inline bool unordered_shoal_a<_key, _value>::operator!=(unordered_shoal_a < _key , _value > const & shoal ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(shoal); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::operator!=(unordered_shoal_a < _key , _value > const & shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(shoal); }

template <typename _key, typename _value>
inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > unordered_shoal_a<_key, _value>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _key, typename _value>
inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > unordered_shoal_a<_key, _value>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _key, typename _value>
inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > unordered_shoal_a<_key, _value>::mutate_begin()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::mutate_begin()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

template <typename _key, typename _value>
inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > unordered_shoal_a<_key, _value>::mutate_end()
{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::mutate_end()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

template <typename _key, typename _value>
inline std_unordered_map < _key , _value > const & unordered_shoal_a<_key, _value>::extract_map() const
{ assert(any_a<>::___handle___); return ___read___().extract_map(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline std_unordered_map < _key , _value > const & unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::extract_map() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_map(); }

template <typename _key, typename _value>
inline std_unordered_map < _key , _value > & unordered_shoal_a<_key, _value>::mutate_map()
{ assert(any_a<>::___handle___); return ___write___().mutate_map(); }

template <typename _key, typename _value>
template <typename ___TTT___, typename ___DHB___>
inline std_unordered_map < _key , _value > & unordered_shoal_a<_key, _value>::___unordered_shoal_a_handle___<___TTT___, ___DHB___>::mutate_map()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_map(); }

template <typename _key, typename _value>
inline cat_a<> unordered_shoal_a<_key, _value>::___cat___()
{
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::unordered_shoal");
	return CAT;
}

template <typename _key, typename _value>
inline unordered_herd_a<> unordered_shoal_a<_key, _value>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = shoal_a< _key , _value >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _key, typename _value>
inline kind_a<> unordered_shoal_a<_key, _value>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _key, typename _value>
inline unordered_herd_a<> unordered_shoal_a<_key, _value>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = shoal_a< _key , _value >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _key, typename _value>
inline unordered_shoal_a<> unordered_shoal_a<_key, _value>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = shoal_a< _key , _value >::___operations___();
		return operations;
	}();
	return OPERATIONS;
}

class ___unordered_shoal_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___unordered_shoal_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _key, typename _value>
inline unordered_shoal_d<_key, _value> ___unordered_shoal_dynamic___(any_a<> const& thing)
{
	return unordered_shoal_d<_key, _value>{ thing };
}

} // namespace
