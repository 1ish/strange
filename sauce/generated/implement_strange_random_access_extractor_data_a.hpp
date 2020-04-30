
namespace strange
{

template <typename _element, typename _type>
inline bool random_access_extractor_data_a<_element, _type>::operator==(random_access_extractor_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::operator==(random_access_extractor_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(it); }

template <typename _element, typename _type>
inline bool random_access_extractor_data_a<_element, _type>::operator!=(random_access_extractor_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::operator!=(random_access_extractor_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(it); }

template <typename _element, typename _type>
inline bool random_access_extractor_data_a<_element, _type>::operator<(random_access_extractor_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::operator<(random_access_extractor_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(it); }

template <typename _element, typename _type>
inline bool random_access_extractor_data_a<_element, _type>::operator>(random_access_extractor_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::operator>(random_access_extractor_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(it); }

template <typename _element, typename _type>
inline bool random_access_extractor_data_a<_element, _type>::operator<=(random_access_extractor_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::operator<=(random_access_extractor_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(it); }

template <typename _element, typename _type>
inline bool random_access_extractor_data_a<_element, _type>::operator>=(random_access_extractor_data_a < _element , _type > const & it ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(it); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline bool random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::operator>=(random_access_extractor_data_a < _element , _type > const & it ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(it); }

template <typename _element, typename _type>
inline _type const & random_access_extractor_data_a<_element, _type>::extract_it() const
{ assert(any_a<>::___handle___); return ___read___().extract_it(); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type const & random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::extract_it() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_it(); }

template <typename _element, typename _type>
inline _type & random_access_extractor_data_a<_element, _type>::mutate_it()
{ assert(any_a<>::___handle___); return ___write___().mutate_it(); }

template <typename _element, typename _type>
template <typename ___TTT___, typename ___DHB___>
inline _type & random_access_extractor_data_a<_element, _type>::___random_access_extractor_data_a_handle___<___TTT___, ___DHB___>::mutate_it()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_it(); }

template <typename _element, typename _type>
inline cat_a<> random_access_extractor_data_a<_element, _type>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::random_access_extractor_data", flock::create_vals(kind_create(2, ""), kind_create(2, "")));
	return CAT;
}

template <typename _element, typename _type>
inline unordered_herd_a<> random_access_extractor_data_a<_element, _type>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = random_access_extractor_a< _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element, typename _type>
inline kind_a<> random_access_extractor_data_a<_element, _type>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___(), flock::create_vals(kind_of<_element>(), kind_of<_type>()));
	return KIND;
}

template <typename _element, typename _type>
inline unordered_herd_a<> random_access_extractor_data_a<_element, _type>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = random_access_extractor_a< _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element, typename _type>
inline unordered_shoal_a<> random_access_extractor_data_a<_element, _type>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = random_access_extractor_a< _element >::___operations___();
		return operations;
	}();
	return OPERATIONS;
}

class ___random_access_extractor_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___random_access_extractor_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element, typename _type>
inline random_access_extractor_data_d<_element, _type> ___random_access_extractor_data_dynamic___(any_a<> const& thing)
{
	return random_access_extractor_data_d<_element, _type>{ thing };
}

} // namespace
