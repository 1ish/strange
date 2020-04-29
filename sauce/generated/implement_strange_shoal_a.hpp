
namespace strange
{

template <typename _key, typename _value>
inline any_a<> shoal_a<_key, _value>::mutate_begin__(list_a<> const& ___arguments___)
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
inline any_a<> shoal_a<_key, _value>::mutate_end__(list_a<> const& ___arguments___)
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
inline cat_a<> shoal_a<_key, _value>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::shoal");
	return CAT;
}

template <typename _key, typename _value>
inline unordered_herd_a<> shoal_a<_key, _value>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = collection_a< _key , _value , flock_a<> >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _key, typename _value>
inline kind_a<> shoal_a<_key, _value>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _key, typename _value>
inline unordered_herd_a<> shoal_a<_key, _value>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = collection_a< _key , _value , flock_a<> >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _key, typename _value>
inline unordered_shoal_a<> shoal_a<_key, _value>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = collection_a< _key , _value , flock_a<> >::___operations___();
		operations.update(sym("mutate_begin_"), native_mutation::create(&shoal_a::mutate_begin__));
		operations.update(sym("mutate_end_"), native_mutation::create(&shoal_a::mutate_end__));
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
