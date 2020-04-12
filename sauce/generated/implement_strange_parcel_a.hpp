
namespace strange
{

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap__(range_a<> const& ___arguments___) const
{
	return unwrap_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_() const
{ assert(any_a<>::___handle___); return ___read___().unwrap_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unwrap_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::close__(range_a<> const& ___arguments___)
{
	return close_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::close_()
{ assert(any_a<>::___handle___); return ___write___().close_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::close_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.close_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::closed__(range_a<> const& ___arguments___) const
{
	return closed_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::closed_() const
{ assert(any_a<>::___handle___); return ___read___().closed_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::closed_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.closed_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::reopen__(range_a<> const& ___arguments___)
{
	return reopen_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::reopen_()
{ assert(any_a<>::___handle___); return ___write___().reopen_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::reopen_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.reopen_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::binary__(range_a<> const& ___arguments___) const
{
	return binary_();
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::binary_() const
{ assert(any_a<>::___handle___); return ___read___().binary_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::binary_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.binary_(); }

template <typename _1>
inline std :: string parcel_a<_1>::binary() const
{ assert(any_a<>::___handle___); return ___read___().binary(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::binary() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.binary(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_number__(range_a<> const& ___arguments___) const
{
	return to_number_();
}

template <typename _1>
inline number_a<> parcel_a<_1>::to_number_() const
{ assert(any_a<>::___handle___); return ___read___().to_number_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_number_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_number_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_number_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_number_or_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return to_number_or_(number);
}

template <typename _1>
inline number_a<> parcel_a<_1>::to_number_or_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().to_number_or_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_number_or_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_number_or_(number); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_int_64__(range_a<> const& ___arguments___) const
{
	return to_int_64_();
}

template <typename _1>
inline number_data_int64_a<> parcel_a<_1>::to_int_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_int_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_int_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_float_64__(range_a<> const& ___arguments___) const
{
	return to_float_64_();
}

template <typename _1>
inline number_data_double_a<> parcel_a<_1>::to_float_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_float_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_double_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_float_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_symbol__(range_a<> const& ___arguments___) const
{
	return to_symbol_();
}

template <typename _1>
inline symbol_a<> parcel_a<_1>::to_symbol_() const
{ assert(any_a<>::___handle___); return ___read___().to_symbol_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_symbol_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_symbol_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_flock__(range_a<> const& ___arguments___) const
{
	return to_flock_();
}

template <typename _1>
inline flock_a<> parcel_a<_1>::to_flock_() const
{ assert(any_a<>::___handle___); return ___read___().to_flock_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_flock_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_flock_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_lake__(range_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::to_lake_() const
{ assert(any_a<>::___handle___); return ___read___().to_lake_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_lake_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_ordered_herd__(range_a<> const& ___arguments___) const
{
	return to_ordered_herd_();
}

template <typename _1>
inline ordered_herd_a<> parcel_a<_1>::to_ordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().to_ordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_herd_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_ordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_ordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_ordered_shoal__(range_a<> const& ___arguments___) const
{
	return to_ordered_shoal_();
}

template <typename _1>
inline ordered_shoal_a<> parcel_a<_1>::to_ordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().to_ordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_shoal_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_ordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_ordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_squad__(range_a<> const& ___arguments___) const
{
	return to_squad_();
}

template <typename _1>
inline squad_a<> parcel_a<_1>::to_squad_() const
{ assert(any_a<>::___handle___); return ___read___().to_squad_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline squad_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_squad_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_squad_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_unordered_herd__(range_a<> const& ___arguments___) const
{
	return to_unordered_herd_();
}

template <typename _1>
inline unordered_herd_a<> parcel_a<_1>::to_unordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().to_unordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_herd_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_unordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_unordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_unordered_shoal__(range_a<> const& ___arguments___) const
{
	return to_unordered_shoal_();
}

template <typename _1>
inline unordered_shoal_a<> parcel_a<_1>::to_unordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().to_unordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_shoal_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_unordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_unordered_shoal_(); }

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
inline bool parcel_a<_1>::operator<(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator<(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator>(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator>(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator<=(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator<=(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(parcel); }

template <typename _1>
inline bool parcel_a<_1>::operator>=(parcel_a < > const & parcel ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(parcel); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::operator>=(parcel_a < > const & parcel ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(parcel); }

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
inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::mutate_begin()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::mutate_begin()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

template <typename _1>
inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::mutate_end()
{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::mutate_end()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

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
