
namespace strange
{

template <typename _element>
inline bool inventory_a<_element>::has_index(int64_t index ) const
{ assert(any_a<>::___handle___); return ___read___().has_index(index); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::has_index(int64_t index ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has_index(index); }

template <typename _element>
inline _element inventory_a<_element>::at_index(int64_t index ) const
{ assert(any_a<>::___handle___); return ___read___().at_index(index); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::at_index(int64_t index ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.at_index(index); }

template <typename _element>
inline void inventory_a<_element>::update_index(int64_t index , any_a < > const & value )
{ assert(any_a<>::___handle___); ___write___().update_index(index, value); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::update_index(int64_t index , any_a < > const & value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_index(index, value); }

template <typename _element>
inline bool inventory_a<_element>::insert_index(int64_t index , any_a < > const & value )
{ assert(any_a<>::___handle___); return ___write___().insert_index(index, value); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::insert_index(int64_t index , any_a < > const & value )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_index(index, value); }

template <typename _element>
inline bool inventory_a<_element>::erase_index(int64_t index )
{ assert(any_a<>::___handle___); return ___write___().erase_index(index); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::erase_index(int64_t index )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_index(index); }

template <typename _element>
inline any_a<> inventory_a<_element>::mutate_begin__(range_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _element>
inline random_access_mutator_a< any_a<> > inventory_a<_element>::mutate_begin_()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_a< any_a<> > inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::mutate_begin_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin_(); }

template <typename _element>
inline any_a<> inventory_a<_element>::mutate_end__(range_a<> const& ___arguments___)
{
	return mutate_end_();
}

template <typename _element>
inline random_access_mutator_a< any_a<> > inventory_a<_element>::mutate_end_()
{ assert(any_a<>::___handle___); return ___write___().mutate_end_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_a< any_a<> > inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::mutate_end_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end_(); }

class ___inventory_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___inventory_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline inventory_d<_element> ___inventory_dynamic___(any_a<> const& thing)
{
	return inventory_d<_element>{ thing };
}

} // namespace
