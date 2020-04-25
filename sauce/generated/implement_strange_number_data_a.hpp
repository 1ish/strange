
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
inline cat_a<> number_data_a<_primitive>::___cat___()
{
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::number_data", flock_vals(kind_create<kind_a<>>(2, "")));
	return CAT;
}

template <typename _primitive>
inline unordered_herd_a<> number_data_a<_primitive>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = number_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _primitive>
inline kind_a<> number_data_a<_primitive>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___(), flock_vals(kind_of<_primitive>()));
	return KIND;
}

template <typename _primitive>
inline unordered_herd_a<> number_data_a<_primitive>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = number_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _primitive>
inline unordered_shoal_a<> number_data_a<_primitive>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = number_a<>::___operations___();
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
