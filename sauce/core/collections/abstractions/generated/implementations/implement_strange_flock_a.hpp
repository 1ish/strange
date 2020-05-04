
namespace strange
{

template <typename _element>
inline bool flock_a<_element>::operator==(flock_a < _element > const & flock ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(flock); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::operator==(flock_a < _element > const & flock ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(flock); }

template <typename _element>
inline bool flock_a<_element>::operator!=(flock_a < _element > const & flock ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(flock); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::operator!=(flock_a < _element > const & flock ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(flock); }

template <typename _element>
inline bool flock_a<_element>::operator<(flock_a < _element > const & flock ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(flock); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::operator<(flock_a < _element > const & flock ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(flock); }

template <typename _element>
inline bool flock_a<_element>::operator>(flock_a < _element > const & flock ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(flock); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::operator>(flock_a < _element > const & flock ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(flock); }

template <typename _element>
inline bool flock_a<_element>::operator<=(flock_a < _element > const & flock ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(flock); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::operator<=(flock_a < _element > const & flock ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(flock); }

template <typename _element>
inline bool flock_a<_element>::operator>=(flock_a < _element > const & flock ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(flock); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::operator>=(flock_a < _element > const & flock ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(flock); }

template <typename _element>
inline random_access_extractor_data_a < _element , typename std_vector < _element > :: const_iterator > flock_a<_element>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_extractor_data_a < _element , typename std_vector < _element > :: const_iterator > flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _element>
inline random_access_extractor_data_a < _element , typename std_vector < _element > :: const_iterator > flock_a<_element>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_extractor_data_a < _element , typename std_vector < _element > :: const_iterator > flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _element>
inline random_access_mutator_data_a < _element , typename std_vector < _element > :: iterator > flock_a<_element>::mutate_begin()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_data_a < _element , typename std_vector < _element > :: iterator > flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::mutate_begin()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

template <typename _element>
inline random_access_mutator_data_a < _element , typename std_vector < _element > :: iterator > flock_a<_element>::mutate_end()
{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_data_a < _element , typename std_vector < _element > :: iterator > flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::mutate_end()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

template <typename _element>
inline std_vector < _element > const & flock_a<_element>::extract_vector() const
{ assert(any_a<>::___handle___); return ___read___().extract_vector(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline std_vector < _element > const & flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::extract_vector() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_vector(); }

template <typename _element>
inline std_vector < _element > & flock_a<_element>::mutate_vector()
{ assert(any_a<>::___handle___); return ___write___().mutate_vector(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline std_vector < _element > & flock_a<_element>::___flock_a_handle___<___TTT___, ___DHB___>::mutate_vector()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_vector(); }

template <typename _element>
inline cat_a<> flock_a<_element>::___cat___()
{
	static cat_a<> CAT = cat::create(1, "strange::flock");
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> flock_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = inventory_a< _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> flock_a<_element>::___kind___()
{
	static kind_a<> KIND = kind::from_cat(___cat___());
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> flock_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = inventory_a< _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> flock_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = inventory_a< _element >::___operations___();
		return operations;
	}();
	return OPERATIONS;
}

class ___flock_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___flock_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline flock_d<_element> ___flock_dynamic___(any_a<> const& thing)
{
	return flock_d<_element>{ thing };
}

} // namespace
