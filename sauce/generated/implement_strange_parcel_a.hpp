
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
	auto shoal = cast_dup<unordered_shoal_a<number_data_uint64_a<>, strange::any_a<>>>(*___it___);
	return unwrap_unique_(shoal);
}

template <typename _1>
inline any_a<> parcel_a<_1>::unwrap_unique_(unordered_shoal_a<number_data_uint64_a<>, strange::any_a<>> & shoal) const
{ assert(any_a<>::___handle___); return ___read___().unwrap_unique_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::unwrap_unique_(unordered_shoal_a<number_data_uint64_a<>, strange::any_a<>> & shoal) const
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
inline any_a<> parcel_a<_1>::to_json__(range_a<> const& ___arguments___) const
{
	return to_json_();
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::to_json_() const
{ assert(any_a<>::___handle___); return ___read___().to_json_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_json_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_json_(); }

template <typename _1>
inline std :: string parcel_a<_1>::to_json() const
{ assert(any_a<>::___handle___); return ___read___().to_json(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_json() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_json(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_binary__(range_a<> const& ___arguments___) const
{
	return to_binary_();
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::to_binary_() const
{ assert(any_a<>::___handle___); return ___read___().to_binary_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_binary_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_binary_(); }

template <typename _1>
inline std :: string parcel_a<_1>::to_binary() const
{ assert(any_a<>::___handle___); return ___read___().to_binary(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_binary() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_binary(); }

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
inline any_a<> parcel_a<_1>::to_boolean__(range_a<> const& ___arguments___) const
{
	return to_boolean_();
}

template <typename _1>
inline any_a<> parcel_a<_1>::to_boolean_() const
{ assert(any_a<>::___handle___); return ___read___().to_boolean_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_boolean_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_boolean_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_boolean_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_boolean_or_ passed short range");
	}
	auto boolean = cast<any_a<>>(*___it___);
	return to_boolean_or_(boolean);
}

template <typename _1>
inline any_a<> parcel_a<_1>::to_boolean_or_(any_a<> const& boolean) const
{ assert(any_a<>::___handle___); return ___read___().to_boolean_or_(boolean); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_boolean_or_(any_a<> const& boolean) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_boolean_or_(boolean); }

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
inline any_a<> parcel_a<_1>::to_int_64_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_int_64_or_ passed short range");
	}
	auto number = cast<number_data_int64_a<>>(*___it___);
	return to_int_64_or_(number);
}

template <typename _1>
inline number_data_int64_a<> parcel_a<_1>::to_int_64_or_(number_data_int64_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().to_int_64_or_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_int_64_or_(number_data_int64_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64_or_(number); }

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
inline any_a<> parcel_a<_1>::to_float_64_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_float_64_or_ passed short range");
	}
	auto number = cast<number_data_double_a<>>(*___it___);
	return to_float_64_or_(number);
}

template <typename _1>
inline number_data_double_a<> parcel_a<_1>::to_float_64_or_(number_data_double_a<> const& number) const
{ assert(any_a<>::___handle___); return ___read___().to_float_64_or_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_double_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_float_64_or_(number_data_double_a<> const& number) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64_or_(number); }

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
inline any_a<> parcel_a<_1>::to_symbol_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_symbol_or_ passed short range");
	}
	auto symbol = cast<symbol_a<>>(*___it___);
	return to_symbol_or_(symbol);
}

template <typename _1>
inline symbol_a<> parcel_a<_1>::to_symbol_or_(symbol_a<> const& symbol) const
{ assert(any_a<>::___handle___); return ___read___().to_symbol_or_(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_symbol_or_(symbol_a<> const& symbol) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_symbol_or_(symbol); }

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
inline any_a<> parcel_a<_1>::to_flock__(range_a<> const& ___arguments___) const
{
	return to_flock_();
}

template <typename _1>
inline flock_a< parcel_a<> > parcel_a<_1>::to_flock_() const
{ assert(any_a<>::___handle___); return ___read___().to_flock_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_flock_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_flock_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_flock_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_flock_or_ passed short range");
	}
	auto flock = cast<flock_a<parcel_a<>>>(*___it___);
	return to_flock_or_(flock);
}

template <typename _1>
inline flock_a< parcel_a<> > parcel_a<_1>::to_flock_or_(flock_a<parcel_a<>> const& flock) const
{ assert(any_a<>::___handle___); return ___read___().to_flock_or_(flock); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_flock_or_(flock_a<parcel_a<>> const& flock) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_flock_or_(flock); }

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
inline any_a<> parcel_a<_1>::to_lake_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_lake_or_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return to_lake_or_(lake);
}

template <typename _1>
inline lake_int8_a<> parcel_a<_1>::to_lake_or_(lake_int8_a<> const& lake) const
{ assert(any_a<>::___handle___); return ___read___().to_lake_or_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_lake_or_(lake_int8_a<> const& lake) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_or_(lake); }

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
inline any_a<> parcel_a<_1>::to_ordered_herd__(range_a<> const& ___arguments___) const
{
	return to_ordered_herd_();
}

template <typename _1>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::to_ordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().to_ordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_ordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_ordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_ordered_herd_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_ordered_herd_or_ passed short range");
	}
	auto herd = cast<ordered_herd_a<parcel_a<>>>(*___it___);
	return to_ordered_herd_or_(herd);
}

template <typename _1>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::to_ordered_herd_or_(ordered_herd_a<parcel_a<>> const& herd) const
{ assert(any_a<>::___handle___); return ___read___().to_ordered_herd_or_(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_ordered_herd_or_(ordered_herd_a<parcel_a<>> const& herd) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_ordered_herd_or_(herd); }

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
inline any_a<> parcel_a<_1>::to_ordered_shoal__(range_a<> const& ___arguments___) const
{
	return to_ordered_shoal_();
}

template <typename _1>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::to_ordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().to_ordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_ordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_ordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_ordered_shoal_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_ordered_shoal_or_ passed short range");
	}
	auto shoal = cast<ordered_shoal_a<strange::any_a<>, parcel_a<>>>(*___it___);
	return to_ordered_shoal_or_(shoal);
}

template <typename _1>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::to_ordered_shoal_or_(ordered_shoal_a<strange::any_a<>, parcel_a<>> const& shoal) const
{ assert(any_a<>::___handle___); return ___read___().to_ordered_shoal_or_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline ordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_ordered_shoal_or_(ordered_shoal_a<strange::any_a<>, parcel_a<>> const& shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_ordered_shoal_or_(shoal); }

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
inline any_a<> parcel_a<_1>::to_squad__(range_a<> const& ___arguments___) const
{
	return to_squad_();
}

template <typename _1>
inline squad_a< parcel_a<> > parcel_a<_1>::to_squad_() const
{ assert(any_a<>::___handle___); return ___read___().to_squad_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline squad_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_squad_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_squad_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_squad_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_squad_or_ passed short range");
	}
	auto squad = cast<squad_a<parcel_a<>>>(*___it___);
	return to_squad_or_(squad);
}

template <typename _1>
inline squad_a< parcel_a<> > parcel_a<_1>::to_squad_or_(squad_a<parcel_a<>> const& squad) const
{ assert(any_a<>::___handle___); return ___read___().to_squad_or_(squad); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline squad_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_squad_or_(squad_a<parcel_a<>> const& squad) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_squad_or_(squad); }

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
inline any_a<> parcel_a<_1>::to_unordered_herd__(range_a<> const& ___arguments___) const
{
	return to_unordered_herd_();
}

template <typename _1>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::to_unordered_herd_() const
{ assert(any_a<>::___handle___); return ___read___().to_unordered_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_unordered_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_unordered_herd_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_unordered_herd_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_unordered_herd_or_ passed short range");
	}
	auto herd = cast<unordered_herd_a<parcel_a<>>>(*___it___);
	return to_unordered_herd_or_(herd);
}

template <typename _1>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::to_unordered_herd_or_(unordered_herd_a<parcel_a<>> const& herd) const
{ assert(any_a<>::___handle___); return ___read___().to_unordered_herd_or_(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_herd_a< parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_unordered_herd_or_(unordered_herd_a<parcel_a<>> const& herd) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_unordered_herd_or_(herd); }

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
inline any_a<> parcel_a<_1>::to_unordered_shoal__(range_a<> const& ___arguments___) const
{
	return to_unordered_shoal_();
}

template <typename _1>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::to_unordered_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().to_unordered_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_unordered_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_unordered_shoal_(); }

template <typename _1>
inline any_a<> parcel_a<_1>::to_unordered_shoal_or__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parcel_a::to_unordered_shoal_or_ passed short range");
	}
	auto shoal = cast<unordered_shoal_a<strange::any_a<>, parcel_a<>>>(*___it___);
	return to_unordered_shoal_or_(shoal);
}

template <typename _1>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::to_unordered_shoal_or_(unordered_shoal_a<strange::any_a<>, parcel_a<>> const& shoal) const
{ assert(any_a<>::___handle___); return ___read___().to_unordered_shoal_or_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline unordered_shoal_a< any_a<> , parcel_a<> > parcel_a<_1>::___parcel_a_handle___<___TTT___, ___DHB___>::to_unordered_shoal_or_(unordered_shoal_a<strange::any_a<>, parcel_a<>> const& shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_unordered_shoal_or_(shoal); }

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

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ parcel_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("unwrap_"), native_extraction_t<parcel_a>::create(&parcel_a::unwrap__));
		operations.update(sym("unwrap_unique_"), native_extraction_t<parcel_a>::create(&parcel_a::unwrap_unique__));
		operations.update(sym("close_"), native_mutation_t<parcel_a>::create(&parcel_a::close__));
		operations.update(sym("closed_"), native_extraction_t<parcel_a>::create(&parcel_a::closed__));
		operations.update(sym("reopen_"), native_mutation_t<parcel_a>::create(&parcel_a::reopen__));
		operations.update(sym("to_json_"), native_extraction_t<parcel_a>::create(&parcel_a::to_json__));
		operations.update(sym("to_binary_"), native_extraction_t<parcel_a>::create(&parcel_a::to_binary__));
		operations.update(sym("is_null_"), native_extraction_t<parcel_a>::create(&parcel_a::is_null__));
		operations.update(sym("is_boolean_"), native_extraction_t<parcel_a>::create(&parcel_a::is_boolean__));
		operations.update(sym("to_boolean_"), native_extraction_t<parcel_a>::create(&parcel_a::to_boolean__));
		operations.update(sym("to_boolean_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_boolean_or__));
		operations.update(sym("is_number_"), native_extraction_t<parcel_a>::create(&parcel_a::is_number__));
		operations.update(sym("to_number_"), native_extraction_t<parcel_a>::create(&parcel_a::to_number__));
		operations.update(sym("to_number_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_number_or__));
		operations.update(sym("is_int_64_"), native_extraction_t<parcel_a>::create(&parcel_a::is_int_64__));
		operations.update(sym("to_int_64_"), native_extraction_t<parcel_a>::create(&parcel_a::to_int_64__));
		operations.update(sym("to_int_64_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_int_64_or__));
		operations.update(sym("is_float_64_"), native_extraction_t<parcel_a>::create(&parcel_a::is_float_64__));
		operations.update(sym("to_float_64_"), native_extraction_t<parcel_a>::create(&parcel_a::to_float_64__));
		operations.update(sym("to_float_64_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_float_64_or__));
		operations.update(sym("is_symbol_"), native_extraction_t<parcel_a>::create(&parcel_a::is_symbol__));
		operations.update(sym("to_symbol_"), native_extraction_t<parcel_a>::create(&parcel_a::to_symbol__));
		operations.update(sym("to_symbol_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_symbol_or__));
		operations.update(sym("is_flock_"), native_extraction_t<parcel_a>::create(&parcel_a::is_flock__));
		operations.update(sym("to_flock_"), native_extraction_t<parcel_a>::create(&parcel_a::to_flock__));
		operations.update(sym("to_flock_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_flock_or__));
		operations.update(sym("is_lake_"), native_extraction_t<parcel_a>::create(&parcel_a::is_lake__));
		operations.update(sym("to_lake_"), native_extraction_t<parcel_a>::create(&parcel_a::to_lake__));
		operations.update(sym("to_lake_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_lake_or__));
		operations.update(sym("is_ordered_herd_"), native_extraction_t<parcel_a>::create(&parcel_a::is_ordered_herd__));
		operations.update(sym("to_ordered_herd_"), native_extraction_t<parcel_a>::create(&parcel_a::to_ordered_herd__));
		operations.update(sym("to_ordered_herd_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_ordered_herd_or__));
		operations.update(sym("is_ordered_shoal_"), native_extraction_t<parcel_a>::create(&parcel_a::is_ordered_shoal__));
		operations.update(sym("to_ordered_shoal_"), native_extraction_t<parcel_a>::create(&parcel_a::to_ordered_shoal__));
		operations.update(sym("to_ordered_shoal_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_ordered_shoal_or__));
		operations.update(sym("is_squad_"), native_extraction_t<parcel_a>::create(&parcel_a::is_squad__));
		operations.update(sym("to_squad_"), native_extraction_t<parcel_a>::create(&parcel_a::to_squad__));
		operations.update(sym("to_squad_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_squad_or__));
		operations.update(sym("is_unordered_herd_"), native_extraction_t<parcel_a>::create(&parcel_a::is_unordered_herd__));
		operations.update(sym("to_unordered_herd_"), native_extraction_t<parcel_a>::create(&parcel_a::to_unordered_herd__));
		operations.update(sym("to_unordered_herd_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_unordered_herd_or__));
		operations.update(sym("is_unordered_shoal_"), native_extraction_t<parcel_a>::create(&parcel_a::is_unordered_shoal__));
		operations.update(sym("to_unordered_shoal_"), native_extraction_t<parcel_a>::create(&parcel_a::to_unordered_shoal__));
		operations.update(sym("to_unordered_shoal_or_"), native_extraction_t<parcel_a>::create(&parcel_a::to_unordered_shoal_or__));
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
