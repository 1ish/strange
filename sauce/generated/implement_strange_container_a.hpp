
namespace strange
{

template <typename _1>
inline any_a<> container_a<_1>::release__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("container_a::release_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	return release_(shared_shoal);
}

template <typename _1>
inline any_a<> container_a<_1>::release_(shoal_a<> const& shared_shoal) const
{ assert(any_a<>::___handle___); return ___read___().release_(shared_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::release_(shoal_a<> const& shared_shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.release_(shared_shoal); }

template <typename _1>
inline any_a<> container_a<_1>::release_unique__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("container_a::release_unique_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis("container_a::release_unique_ passed short range");
	}
	auto unique_shoal = cast_dup<shoal_a<number_data_uint64_a<>, strange::any_a<>>>(*___it___);
	return release_unique_(shared_shoal, unique_shoal);
}

template <typename _1>
inline any_a<> container_a<_1>::release_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
{ assert(any_a<>::___handle___); return ___read___().release_unique_(shared_shoal, unique_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::release_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.release_unique_(shared_shoal, unique_shoal); }

template <typename _1>
inline any_a < > container_a<_1>::release(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
{ assert(any_a<>::___handle___); return ___read___().release(shared_shoal, unique_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a < > container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::release(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.release(shared_shoal, unique_shoal); }

template <typename _1>
inline any_a<> container_a<_1>::keys_begin__(list_a<> const& ___arguments___) const
{
	return keys_begin_();
}

template <typename _1>
inline bidirectional_extractor_a< any_a<> > container_a<_1>::keys_begin_() const
{ assert(any_a<>::___handle___); return ___read___().keys_begin_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_a< any_a<> > container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::keys_begin_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_begin_(); }

template <typename _1>
inline any_a<> container_a<_1>::keys_end__(list_a<> const& ___arguments___) const
{
	return keys_end_();
}

template <typename _1>
inline bidirectional_extractor_a< any_a<> > container_a<_1>::keys_end_() const
{ assert(any_a<>::___handle___); return ___read___().keys_end_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_a< any_a<> > container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::keys_end_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_end_(); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ container_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = collection_a< any_a<> , container_a<> , container_a<> >::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("release_"), native_extraction_t<container_a>::create(&container_a::release__));
		operations.update(sym("release_unique_"), native_extraction_t<container_a>::create(&container_a::release_unique__));
		operations.update(sym("keys_begin_"), native_extraction_t<container_a>::create(&container_a::keys_begin__));
		operations.update(sym("keys_end_"), native_extraction_t<container_a>::create(&container_a::keys_end__));
		return operations;
	}();
	return OPERATIONS;
}

class ___container_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___container_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline container_d<_1> ___container_dynamic___(any_a<> const& thing)
{
	return container_d<_1>{ thing };
}

} // namespace
