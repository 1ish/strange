
namespace strange
{

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("parcel_a::unwrap_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	return unwrap_(shared_shoal);
}

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_(shoal_a<> const& shared_shoal) const
{ assert(any_a<>::___handle___); return ___read___().unwrap_(shared_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap_(shoal_a<> const& shared_shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unwrap_(shared_shoal); }

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_unique__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("parcel_a::unwrap_unique_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis("parcel_a::unwrap_unique_ passed short range");
	}
	auto unique_shoal = cast_dup<shoal_a<number_data_uint64_a<>, strange::any_a<>>>(*___it___);
	return unwrap_unique_(shared_shoal, unique_shoal);
}

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
{ assert(any_a<>::___handle___); return ___read___().unwrap_unique_(shared_shoal, unique_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unwrap_unique_(shared_shoal, unique_shoal); }

template <typename _1>
inline any_a < > parcel_a<_1>::unwrap(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
{ assert(any_a<>::___handle___); return ___read___().unwrap(shared_shoal, unique_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a < > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unwrap(shared_shoal, unique_shoal); }

template <typename _1>
inline bool parcel_a<_1>::operator==(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator==(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator!=(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator!=(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(parcel); }

template <typename _1>
inline any_a<> parcel_a<_1>::keys_begin__(range_a<> const& ___arguments___) const
{
	return keys_begin_();
}

template <typename _1>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::keys_begin_() const
{ assert(any_a<>::___handle___); return ___read___().keys_begin_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::keys_begin_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_begin_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::keys_end__(range_a<> const& ___arguments___) const
{
	return keys_end_();
}

template <typename _1>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::keys_end_() const
{ assert(any_a<>::___handle___); return ___read___().keys_end_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::keys_end_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_end_(); }

template <typename _1>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::keys_begin() const
{ assert(any_a<>::___handle___); return ___read___().keys_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::keys_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_begin(); }

template <typename _1>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::keys_end() const
{ assert(any_a<>::___handle___); return ___read___().keys_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::keys_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_end(); }

template <typename _1>
inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _1>
inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _1>
inline dart :: packet const & parcel_a<_1>::extract_packet() const
{ assert(any_a<>::___handle___); return ___read___().extract_packet(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline dart :: packet const & parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::extract_packet() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_packet(); }

template <typename _1>
inline dart :: packet & parcel_a<_1>::mutate_packet()
{ assert(any_a<>::___handle___); return ___write___().mutate_packet(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline dart :: packet & parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::mutate_packet()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_packet(); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ parcel_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("unwrap_"), native_extraction_t<parcel_a>::create(&parcel_a::unwrap__));
		operations.update(sym("unwrap_unique_"), native_extraction_t<parcel_a>::create(&parcel_a::unwrap_unique__));
		operations.update(sym("keys_begin_"), native_extraction_t<parcel_a>::create(&parcel_a::keys_begin__));
		operations.update(sym("keys_end_"), native_extraction_t<parcel_a>::create(&parcel_a::keys_end__));
		return operations;
	}();
	return OPERATIONS;
}

class ___parcel_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___parcel_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline parcel_d<_1> ___parcel_dynamic___(any_a<> const& thing)
{
	return parcel_d<_1>{ thing };
}

} // namespace
