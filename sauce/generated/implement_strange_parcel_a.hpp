
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
inline any_a<> parcel_a<_1>::unwrap_unique__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::unwrap_unique_ passed short range");
	}
	auto shoal = cast_dup<unordered_shoal_a<>>(*___it___);
	return unwrap_unique_(shoal);
}

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_unique_(unordered_shoal_a<> & shoal) const
{ assert(any_a<>::___handle___); return ___read___().unwrap_unique_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap_unique_(unordered_shoal_a<> & shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unwrap_unique_(shoal); }

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
inline any_a<> parcel_a<_1>::json__(range_a<> const& ___arguments___) const
{
	return json_();
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::json_() const
{ assert(any_a<>::___handle___); return ___read___().json_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::json_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.json_(); }

template <typename _1>
inline std :: string parcel_a<_1>::json() const
{ assert(any_a<>::___handle___); return ___read___().json(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::json() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.json(); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_null__(range_a<> const& ___arguments___) const
{
	return is_null_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_null_() const
{ assert(any_a<>::___handle___); return ___read___().is_null_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_null_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_null_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_boolean__(range_a<> const& ___arguments___) const
{
	return is_boolean_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_boolean_() const
{ assert(any_a<>::___handle___); return ___read___().is_boolean_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_boolean_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_boolean_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::boolean__(range_a<> const& ___arguments___) const
{
	return boolean_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::boolean_() const
{ assert(any_a<>::___handle___); return ___read___().boolean_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::boolean_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.boolean_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::boolean_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::boolean_or_ passed short range");
	}
	auto boolean = cast<any_a<>>(*___it___);
	return boolean_or_(boolean);
}

template <typename _1>
inline any_a<> parcel_a<_1>::boolean_or_(any_a<> const& boolean) const
{ assert(any_a<>::___handle___); return ___read___().boolean_or_(boolean); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::boolean_or_(any_a<> const& boolean) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.boolean_or_(boolean); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_number__(range_a<> const& ___arguments___) const
{
	return is_number_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_number_() const
{ assert(any_a<>::___handle___); return ___read___().is_number_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_number_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_number_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::number__(range_a<> const& ___arguments___) const
{
	return number_();
}

template <typename _1>
inline number_a<> parcel_a<_1>::number_() const
{ assert(any_a<>::___handle___); return ___read___().number_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::number_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.number_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::number_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::number_or_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return number_or_(number);
}

template <typename _1>
inline number_a<> parcel_a<_1>::number_or_(number_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().number_or_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::number_or_(number_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.number_or_(number); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_int_64__(range_a<> const& ___arguments___) const
{
	return is_int_64_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_int_64_() const
{ assert(any_a<>::___handle___); return ___read___().is_int_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_int_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int_64_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::int_64__(range_a<> const& ___arguments___) const
{
	return int_64_();
}

template <typename _1>
inline number_data_int64_a<> parcel_a<_1>::int_64_() const
{ assert(any_a<>::___handle___); return ___read___().int_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::int_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.int_64_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::int_64_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::int_64_or_ passed short range");
	}
	auto number = cast<number_data_int64_a<>>(*___it___);
	return int_64_or_(number);
}

template <typename _1>
inline number_data_int64_a<> parcel_a<_1>::int_64_or_(number_data_int64_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().int_64_or_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::int_64_or_(number_data_int64_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.int_64_or_(number); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_float_64__(range_a<> const& ___arguments___) const
{
	return is_float_64_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_float_64_() const
{ assert(any_a<>::___handle___); return ___read___().is_float_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_float_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_float_64_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::float_64__(range_a<> const& ___arguments___) const
{
	return float_64_();
}

template <typename _1>
inline number_data_double_a<> parcel_a<_1>::float_64_() const
{ assert(any_a<>::___handle___); return ___read___().float_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_double_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::float_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.float_64_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::float_64_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::float_64_or_ passed short range");
	}
	auto number = cast<number_data_double_a<>>(*___it___);
	return float_64_or_(number);
}

template <typename _1>
inline number_data_double_a<> parcel_a<_1>::float_64_or_(number_data_double_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().float_64_or_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_double_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::float_64_or_(number_data_double_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.float_64_or_(number); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_symbol__(range_a<> const& ___arguments___) const
{
	return is_symbol_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_symbol_() const
{ assert(any_a<>::___handle___); return ___read___().is_symbol_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_symbol_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_symbol_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::symbol__(range_a<> const& ___arguments___) const
{
	return symbol_();
}

template <typename _1>
inline symbol_a<> parcel_a<_1>::symbol_() const
{ assert(any_a<>::___handle___); return ___read___().symbol_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::symbol_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.symbol_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::symbol_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::symbol_or_ passed short range");
	}
	auto symbol = cast<symbol_a<>>(*___it___);
	return symbol_or_(symbol);
}

template <typename _1>
inline symbol_a<> parcel_a<_1>::symbol_or_(symbol_a<> const& symbol) const
{ assert(any_a<>::___handle___); return ___read___().symbol_or_(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::symbol_or_(symbol_a<> const& symbol) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.symbol_or_(symbol); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_flock__(range_a<> const& ___arguments___) const
{
	return is_flock_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_flock_() const
{ assert(any_a<>::___handle___); return ___read___().is_flock_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_flock_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_flock_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::flock__(range_a<> const& ___arguments___) const
{
	return flock_();
}

template <typename _1>
inline flock_a< parcel_a<> > parcel_a<_1>::flock_() const
{ assert(any_a<>::___handle___); return ___read___().flock_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::flock_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.flock_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::flock_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::flock_or_ passed short range");
	}
	auto flock = cast<flock_a<>>(*___it___);
	return flock_or_(flock);
}

template <typename _1>
inline flock_a< parcel_a<> > parcel_a<_1>::flock_or_(flock_a<> const& flock) const
{ assert(any_a<>::___handle___); return ___read___().flock_or_(flock); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::flock_or_(flock_a<> const& flock) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.flock_or_(flock); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_lake__(range_a<> const& ___arguments___) const
{
	return is_lake_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_lake_() const
{ assert(any_a<>::___handle___); return ___read___().is_lake_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_lake_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_lake_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::lake__(range_a<> const& ___arguments___) const
{
	return lake_();
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::lake_() const
{ assert(any_a<>::___handle___); return ___read___().lake_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::lake_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.lake_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::lake_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::lake_or_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return lake_or_(lake);
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::lake_or_(lake_int8_a<> const& lake) const
{ assert(any_a<>::___handle___); return ___read___().lake_or_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::lake_or_(lake_int8_a<> const& lake) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.lake_or_(lake); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_ordered_herd__(range_a<> const& ___arguments___) const
{
	return is_ordered_herd_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_ordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().is_ordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_ordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_ordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::ordered_herd__(range_a<> const& ___arguments___) const
{
	return ordered_herd_();
}

template <typename _1>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::ordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().ordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::ordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.ordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::ordered_herd_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::ordered_herd_or_ passed short range");
	}
	auto herd = cast<ordered_herd_a<>>(*___it___);
	return ordered_herd_or_(herd);
}

template <typename _1>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::ordered_herd_or_(ordered_herd_a<> const& herd) const
{ assert(any_a<>::___handle___); return ___read___().ordered_herd_or_(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::ordered_herd_or_(ordered_herd_a<> const& herd) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.ordered_herd_or_(herd); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_ordered_shoal__(range_a<> const& ___arguments___) const
{
	return is_ordered_shoal_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_ordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().is_ordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_ordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_ordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::ordered_shoal__(range_a<> const& ___arguments___) const
{
	return ordered_shoal_();
}

template <typename _1>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::ordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().ordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::ordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.ordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::ordered_shoal_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::ordered_shoal_or_ passed short range");
	}
	auto shoal = cast<ordered_shoal_a<>>(*___it___);
	return ordered_shoal_or_(shoal);
}

template <typename _1>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::ordered_shoal_or_(ordered_shoal_a<> const& shoal) const
{ assert(any_a<>::___handle___); return ___read___().ordered_shoal_or_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::ordered_shoal_or_(ordered_shoal_a<> const& shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.ordered_shoal_or_(shoal); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_squad__(range_a<> const& ___arguments___) const
{
	return is_squad_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_squad_() const
{ assert(any_a<>::___handle___); return ___read___().is_squad_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_squad_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_squad_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::squad__(range_a<> const& ___arguments___) const
{
	return squad_();
}

template <typename _1>
inline squad_a< parcel_a<> > parcel_a<_1>::squad_() const
{ assert(any_a<>::___handle___); return ___read___().squad_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline squad_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::squad_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.squad_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::squad_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::squad_or_ passed short range");
	}
	auto squad = cast<squad_a<>>(*___it___);
	return squad_or_(squad);
}

template <typename _1>
inline squad_a< parcel_a<> > parcel_a<_1>::squad_or_(squad_a<> const& squad) const
{ assert(any_a<>::___handle___); return ___read___().squad_or_(squad); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline squad_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::squad_or_(squad_a<> const& squad) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.squad_or_(squad); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_unordered_herd__(range_a<> const& ___arguments___) const
{
	return is_unordered_herd_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_unordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().is_unordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_unordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_unordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::unordered_herd__(range_a<> const& ___arguments___) const
{
	return unordered_herd_();
}

template <typename _1>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::unordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().unordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::unordered_herd_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::unordered_herd_or_ passed short range");
	}
	auto herd = cast<unordered_herd_a<>>(*___it___);
	return unordered_herd_or_(herd);
}

template <typename _1>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::unordered_herd_or_(unordered_herd_a<> const& herd) const
{ assert(any_a<>::___handle___); return ___read___().unordered_herd_or_(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unordered_herd_or_(unordered_herd_a<> const& herd) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unordered_herd_or_(herd); }

template <typename _1>
inline any_a<> parcel_a<_1>::is_unordered_shoal__(range_a<> const& ___arguments___) const
{
	return is_unordered_shoal_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::is_unordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().is_unordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::is_unordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_unordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::unordered_shoal__(range_a<> const& ___arguments___) const
{
	return unordered_shoal_();
}

template <typename _1>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::unordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().unordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::unordered_shoal_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::unordered_shoal_or_ passed short range");
	}
	auto shoal = cast<unordered_shoal_a<>>(*___it___);
	return unordered_shoal_or_(shoal);
}

template <typename _1>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::unordered_shoal_or_(unordered_shoal_a<> const& shoal) const
{ assert(any_a<>::___handle___); return ___read___().unordered_shoal_or_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unordered_shoal_or_(unordered_shoal_a<> const& shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unordered_shoal_or_(shoal); }

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
inline any_a<> parcel_a<_1>::key_begin__(range_a<> const& ___arguments___) const
{
	return key_begin_();
}

template <typename _1>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::key_begin_() const
{ assert(any_a<>::___handle___); return ___read___().key_begin_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::key_begin_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.key_begin_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::key_end__(range_a<> const& ___arguments___) const
{
	return key_end_();
}

template <typename _1>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::key_end_() const
{ assert(any_a<>::___handle___); return ___read___().key_end_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_a< any_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::key_end_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.key_end_(); }

template <typename _1>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::key_begin() const
{ assert(any_a<>::___handle___); return ___read___().key_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::key_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.key_begin(); }

template <typename _1>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::key_end() const
{ assert(any_a<>::___handle___); return ___read___().key_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::key_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.key_end(); }

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
