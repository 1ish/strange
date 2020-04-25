
namespace strange
{

template <typename _type>
inline bool data_a<_type>::operator==(data_a < _type > const & data ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(data); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::operator==(data_a < _type > const & data ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(data); }

template <typename _type>
inline bool data_a<_type>::operator!=(data_a < _type > const & data ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(data); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::operator!=(data_a < _type > const & data ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(data); }

template <typename _type>
inline _type const & data_a<_type>::extract_data() const
{ assert(any_a<>::___handle___); return ___read___().extract_data(); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type const & data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::extract_data() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_data(); }

template <typename _type>
inline _type & data_a<_type>::mutate_data()
{ assert(any_a<>::___handle___); return ___write___().mutate_data(); }

template <typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type & data_a<_type>::___data_a_handle___<___TTT___, ___DHB___>::mutate_data()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_data(); }

template <typename _type>
inline cat_a<> data_a<_type>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::data", flock_vals(kind_create(2, "")));
	return CAT;
}

template <typename _type>
inline unordered_herd_a<> data_a<_type>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = any_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _type>
inline kind_a<> data_a<_type>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___(), flock_vals(kind_of<_type>()));
	return KIND;
}

template <typename _type>
inline unordered_herd_a<> data_a<_type>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = any_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _type>
inline unordered_shoal_a<> data_a<_type>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
		return operations;
	}();
	return OPERATIONS;
}

class ___data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _type>
inline data_d<_type> ___data_dynamic___(any_a<> const& thing)
{
	return data_d<_type>{ thing };
}

} // namespace
