
namespace strange
{

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline one_t const & any_a<_symbol, _cat, _kind, _number_data_uint64>::extract_thing() const
{ assert(___handle___); return ___read___().extract_thing(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline one_t const & any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::extract_thing() const
{ return ___value___.extract_thing(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline one_t & any_a<_symbol, _cat, _kind, _number_data_uint64>::mutate_thing()
{ assert(___handle___); return ___write___().mutate_thing(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline one_t & any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::mutate_thing()
{ return ___value___.mutate_thing(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::type__(range_a<> const& ___arguments___) const
{
	return type_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline _symbol any_a<_symbol, _cat, _kind, _number_data_uint64>::type_() const
{ assert(___handle___); return ___read___().type_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline _symbol any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::type_() const
{ return ___value___.type_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::cat__(range_a<> const& ___arguments___) const
{
	return cat_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline _cat any_a<_symbol, _cat, _kind, _number_data_uint64>::cat_() const
{ assert(___handle___); return ___read___().cat_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline _cat any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::cat_() const
{ return ___value___.cat_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::cats__(range_a<> const& ___arguments___) const
{
	return cats_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline unordered_herd_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::cats_() const
{ assert(___handle___); return ___read___().cats_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline unordered_herd_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::cats_() const
{ return ___value___.cats_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::kind__(range_a<> const& ___arguments___) const
{
	return kind_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline _kind any_a<_symbol, _cat, _kind, _number_data_uint64>::kind_() const
{ assert(___handle___); return ___read___().kind_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline _kind any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::kind_() const
{ return ___value___.kind_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::kinds__(range_a<> const& ___arguments___) const
{
	return kinds_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline unordered_herd_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::kinds_() const
{ assert(___handle___); return ___read___().kinds_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline unordered_herd_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::kinds_() const
{ return ___value___.kinds_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::operations__(range_a<> const& ___arguments___) const
{
	return operations_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline unordered_shoal_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::operations_() const
{ assert(___handle___); return ___read___().operations_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline unordered_shoal_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::operations_() const
{ return ___value___.operations_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::visit__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::visit_ passed short range");
	}
	auto arguments = cast_dup<inventory_a<>>(*___it___);
	return visit_(arguments);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::visit_(inventory_a<> & arguments) const
{ assert(___handle___); return ___read___().visit_(arguments); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::visit_(inventory_a<> & arguments) const
{ return ___value___.visit_(arguments); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a < > any_a<_symbol, _cat, _kind, _number_data_uint64>::invoke(any_a < > & thing , range_a < > const & arguments ) const
{ assert(___handle___); return ___read___().invoke(thing, arguments); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline any_a < > any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::invoke(any_a < > & thing , range_a < > const & arguments ) const
{ return ___value___.invoke(thing, arguments); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a < > any_a<_symbol, _cat, _kind, _number_data_uint64>::operate(any_a < > & thing , range_a < > const & arguments ) const
{ assert(___handle___); return ___read___().operate(thing, arguments); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline any_a < > any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::operate(any_a < > & thing , range_a < > const & arguments ) const
{ return ___value___.operate(thing, arguments); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::identity__(range_a<> const& ___arguments___) const
{
	return identity_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline _number_data_uint64 any_a<_symbol, _cat, _kind, _number_data_uint64>::identity_() const
{ assert(___handle___); return ___read___().identity_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline _number_data_uint64 any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::identity_() const
{ return ___value___.identity_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline void const * any_a<_symbol, _cat, _kind, _number_data_uint64>::identity() const
{ assert(___handle___); return ___read___().identity(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline void const * any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::identity() const
{ return ___value___.identity(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::identical__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::identical_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return identical_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::identical_(any_a<> const& thing) const
{ assert(___handle___); return ___read___().identical_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::identical_(any_a<> const& thing) const
{ return ___value___.identical_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::identical(any_a < > const & thing ) const
{ assert(___handle___); return ___read___().identical(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::identical(any_a < > const & thing ) const
{ return ___value___.identical(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::nothing__(range_a<> const& ___arguments___) const
{
	return nothing_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::nothing_() const
{ assert(___handle___); return ___read___().nothing_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::nothing_() const
{ return ___value___.nothing_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::nothing() const
{ assert(___handle___); return ___read___().nothing(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::nothing() const
{ return ___value___.nothing(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::something__(range_a<> const& ___arguments___) const
{
	return something_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::something_() const
{ assert(___handle___); return ___read___().something_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::something_() const
{ return ___value___.something_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::something() const
{ assert(___handle___); return ___read___().something(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::something() const
{ return ___value___.something(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::same__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::same_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return same_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::same_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().same_(thing)); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::operator==(any_a<> const& thing) const
{ assert(___handle___); return ___read___().same_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::same_(any_a<> const& thing) const
{ return bool{ ___value___.same_(thing) }; }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::different__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::different_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return different_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::different_(any_a<> const& thing) const
{ assert(___handle___); return boole(!___read___().same_(thing)); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::operator!=(any_a<> const& thing) const
{ assert(___handle___); return !___read___().same_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::less_than__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::less_than_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return less_than_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::less_than_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().less_than_(thing)); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::operator<(any_a<> const& thing) const
{ assert(___handle___); return ___read___().less_than_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::less_than_(any_a<> const& thing) const
{ return bool{ ___value___.less_than_(thing) }; }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::greater_than__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::greater_than_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return greater_than_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::greater_than_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().greater_than_(thing)); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::operator>(any_a<> const& thing) const
{ assert(___handle___); return ___read___().greater_than_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::greater_than_(any_a<> const& thing) const
{ return bool{ ___value___.greater_than_(thing) }; }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::less_or_equal__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::less_or_equal_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return less_or_equal_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::less_or_equal_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().less_or_equal_(thing)); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::operator<=(any_a<> const& thing) const
{ assert(___handle___); return ___read___().less_or_equal_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::less_or_equal_(any_a<> const& thing) const
{ return bool{ ___value___.less_or_equal_(thing) }; }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::greater_or_equal__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::greater_or_equal_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return greater_or_equal_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::greater_or_equal_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().greater_or_equal_(thing)); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::operator>=(any_a<> const& thing) const
{ assert(___handle___); return ___read___().greater_or_equal_(thing); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::greater_or_equal_(any_a<> const& thing) const
{ return bool{ ___value___.greater_or_equal_(thing) }; }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::hash__(range_a<> const& ___arguments___) const
{
	return hash_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline _number_data_uint64 any_a<_symbol, _cat, _kind, _number_data_uint64>::hash_() const
{ assert(___handle___); return ___read___().hash_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline _number_data_uint64 any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::hash_() const
{ return ___value___.hash_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline std :: size_t any_a<_symbol, _cat, _kind, _number_data_uint64>::hash() const
{ assert(___handle___); return ___read___().hash(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline std :: size_t any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::hash() const
{ return ___value___.hash(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::is(std :: string const & s ) const
{ assert(___handle___); return ___read___().is(s); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::is(std :: string const & s ) const
{ return ___value___.is(s); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::to_parcel__(range_a<> const& ___arguments___) const
{
	return to_parcel_();
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline parcel_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::to_parcel_() const
{ assert(___handle___); return ___read___().to_parcel_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline parcel_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::to_parcel_() const
{ return ___value___.to_parcel_(); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::to_parcel_unique__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::to_parcel_unique_ passed short range");
	}
	auto herd = cast_dup< unordered_herd_a< _number_data_uint64 > >(*___it___);
	return to_parcel_unique_(herd);
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline parcel_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::to_parcel_unique_(unordered_herd_a< _number_data_uint64 > & herd) const
{ assert(___handle___); return ___read___().to_parcel_unique_(herd); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___TTT___, typename ___BHB___>
inline parcel_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::___any_a_handle___<___TTT___, ___BHB___>::to_parcel_unique_(unordered_herd_a< _number_data_uint64 > & herd) const
{ return ___value___.to_parcel_unique_(herd); }

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _number_data_uint64>::operation(std::string const& name) const
{
	return ___read___().operations_().at_(sym(name));
}

template <typename _symbol, typename _cat, typename _kind, typename _number_data_uint64>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ any_a<_symbol, _cat, _kind, _number_data_uint64>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = unordered_shoal_create<any_a<>, any_a<>, false, ___unordered_shoal_a___>();
		operations.update(sym("call_"), native_mutation_t<any_a>::create(&any_a::operator[]));
		operations.update(sym("perform_"), native_mutation_t<any_a>::create(&any_a::operator()));
		operations.update(sym("type_"), native_extraction_t<any_a>::create(&any_a::type__));
		operations.update(sym("cat_"), native_extraction_t<any_a>::create(&any_a::cat__));
		operations.update(sym("cats_"), native_extraction_t<any_a>::create(&any_a::cats__));
		operations.update(sym("kind_"), native_extraction_t<any_a>::create(&any_a::kind__));
		operations.update(sym("kinds_"), native_extraction_t<any_a>::create(&any_a::kinds__));
		operations.update(sym("operations_"), native_extraction_t<any_a>::create(&any_a::operations__));
		operations.update(sym("visit_"), native_extraction_t<any_a>::create(&any_a::visit__));
		operations.update(sym("identity_"), native_extraction_t<any_a>::create(&any_a::identity__));
		operations.update(sym("identical_"), native_extraction_t<any_a>::create(&any_a::identical__));
		operations.update(sym("nothing_"), native_extraction_t<any_a>::create(&any_a::nothing__));
		operations.update(sym("something_"), native_extraction_t<any_a>::create(&any_a::something__));
		operations.update(sym("same_"), native_extraction_t<any_a>::create(&any_a::same__));
		operations.update(sym("different_"), native_extraction_t<any_a>::create(&any_a::different__));
		operations.update(sym("less_than_"), native_extraction_t<any_a>::create(&any_a::less_than__));
		operations.update(sym("greater_than_"), native_extraction_t<any_a>::create(&any_a::greater_than__));
		operations.update(sym("less_or_equal_"), native_extraction_t<any_a>::create(&any_a::less_or_equal__));
		operations.update(sym("greater_or_equal_"), native_extraction_t<any_a>::create(&any_a::greater_or_equal__));
		operations.update(sym("hash_"), native_extraction_t<any_a>::create(&any_a::hash__));
		operations.update(sym("to_parcel_"), native_extraction_t<any_a>::create(&any_a::to_parcel__));
		operations.update(sym("to_parcel_unique_"), native_extraction_t<any_a>::create(&any_a::to_parcel_unique__));
		return operations;
	}();
	return OPERATIONS;
}

class ___any_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___any_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

} // namespace
