
namespace strange
{

template <typename _primitive>
inline bool number_data_a<_primitive>::operator==(number_data_a < _primitive > const & number ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(number); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline bool number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::operator==(number_data_a < _primitive > const & number ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(number); }

template <typename _primitive>
inline bool number_data_a<_primitive>::operator!=(number_data_a < _primitive > const & number ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(number); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline bool number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::operator!=(number_data_a < _primitive > const & number ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(number); }

template <typename _primitive>
inline bool number_data_a<_primitive>::operator<(number_data_a < _primitive > const & number ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(number); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline bool number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::operator<(number_data_a < _primitive > const & number ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(number); }

template <typename _primitive>
inline bool number_data_a<_primitive>::operator>(number_data_a < _primitive > const & number ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(number); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline bool number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::operator>(number_data_a < _primitive > const & number ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(number); }

template <typename _primitive>
inline bool number_data_a<_primitive>::operator<=(number_data_a < _primitive > const & number ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(number); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline bool number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::operator<=(number_data_a < _primitive > const & number ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(number); }

template <typename _primitive>
inline bool number_data_a<_primitive>::operator>=(number_data_a < _primitive > const & number ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(number); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline bool number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::operator>=(number_data_a < _primitive > const & number ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(number); }

template <typename _primitive>
inline _primitive const & number_data_a<_primitive>::extract_primitive() const
{ assert(any_a<>::___handle___); return ___read___().extract_primitive(); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline _primitive const & number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::extract_primitive() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_primitive(); }

template <typename _primitive>
inline _primitive & number_data_a<_primitive>::mutate_primitive()
{ assert(any_a<>::___handle___); return ___write___().mutate_primitive(); }

template <typename _primitive>
template <typename ___TTT___, typename ___DHB___>
inline _primitive & number_data_a<_primitive>::___number_data_a_handle___<___TTT___, ___DHB___>::mutate_primitive()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_primitive(); }

template <typename _primitive>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ number_data_a<_primitive>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = number_a<>::template ___operations___<___unordered_shoal_a___>();
		return operations;
	}();
	return OPERATIONS;
}

class ___number_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___number_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _primitive>
inline number_data_d<_primitive> ___number_data_dynamic___(any_a<> const& thing)
{
	return number_data_d<_primitive>{ thing };
}

} // namespace
