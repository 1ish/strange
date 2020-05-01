
namespace strange
{

template <typename _1>
inline one_t const & any_a<_1>::extract_thing() const
{ assert(___handle___); return ___read___().extract_thing(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline one_t const & any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::extract_thing() const
{ return ___value___.extract_thing(); }

template <typename _1>
inline one_t & any_a<_1>::mutate_thing()
{ assert(___handle___); return ___write___().mutate_thing(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline one_t & any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::mutate_thing()
{ return ___value___.mutate_thing(); }

template <typename _1>
inline any_a<> any_a<_1>::type__(list_a<> const& ___arguments___) const
{
	return type_();
}

template <typename _1>
inline symbol_a<> any_a<_1>::type_() const
{ assert(___handle___); return ___read___().type_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline symbol_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::type_() const
{ return ___value___.type_(); }

template <typename _1>
inline any_a<> any_a<_1>::cat__(list_a<> const& ___arguments___) const
{
	return cat_();
}

template <typename _1>
inline cat_a<> any_a<_1>::cat_() const
{ assert(___handle___); return ___read___().cat_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline cat_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::cat_() const
{ return ___value___.cat_(); }

template <typename _1>
inline any_a<> any_a<_1>::cats__(list_a<> const& ___arguments___) const
{
	return cats_();
}

template <typename _1>
inline unordered_herd_a<> any_a<_1>::cats_() const
{ assert(___handle___); return ___read___().cats_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline unordered_herd_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::cats_() const
{ return ___value___.cats_(); }

template <typename _1>
inline any_a<> any_a<_1>::kind__(list_a<> const& ___arguments___) const
{
	return kind_();
}

template <typename _1>
inline kind_a<> any_a<_1>::kind_() const
{ assert(___handle___); return ___read___().kind_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline kind_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::kind_() const
{ return ___value___.kind_(); }

template <typename _1>
inline any_a<> any_a<_1>::kinds__(list_a<> const& ___arguments___) const
{
	return kinds_();
}

template <typename _1>
inline unordered_herd_a<> any_a<_1>::kinds_() const
{ assert(___handle___); return ___read___().kinds_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline unordered_herd_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::kinds_() const
{ return ___value___.kinds_(); }

template <typename _1>
inline any_a<> any_a<_1>::operations__(list_a<> const& ___arguments___) const
{
	return operations_();
}

template <typename _1>
inline unordered_shoal_a<> any_a<_1>::operations_() const
{ assert(___handle___); return ___read___().operations_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline unordered_shoal_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::operations_() const
{ return ___value___.operations_(); }

template <typename _1>
inline any_a < > any_a<_1>::invoke(any_a < > & thing , list_a < > const & arguments ) const
{ assert(___handle___); return ___read___().invoke(thing, arguments); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a < > any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::invoke(any_a < > & thing , list_a < > const & arguments ) const
{ return ___value___.invoke(thing, arguments); }

template <typename _1>
inline any_a < > any_a<_1>::operate(any_a < > & thing , list_a < > const & arguments ) const
{ assert(___handle___); return ___read___().operate(thing, arguments); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a < > any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::operate(any_a < > & thing , list_a < > const & arguments ) const
{ return ___value___.operate(thing, arguments); }

template <typename _1>
inline any_a<> any_a<_1>::identity__(list_a<> const& ___arguments___) const
{
	return identity_();
}

template <typename _1>
inline number_data_uint64_a<> any_a<_1>::identity_() const
{ assert(___handle___); return ___read___().identity_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline number_data_uint64_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::identity_() const
{ return ___value___.identity_(); }

template <typename _1>
inline void const * any_a<_1>::identity() const
{ assert(___handle___); return ___read___().identity(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline void const * any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::identity() const
{ return ___value___.identity(); }

template <typename _1>
inline any_a<> any_a<_1>::identical__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::identical_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return identical_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::identical_(any_a<> const& thing) const
{ assert(___handle___); return ___read___().identical_(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::identical_(any_a<> const& thing) const
{ return ___value___.identical_(thing); }

template <typename _1>
inline bool any_a<_1>::identical(any_a < > const & thing ) const
{ assert(___handle___); return ___read___().identical(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::identical(any_a < > const & thing ) const
{ return ___value___.identical(thing); }

template <typename _1>
inline any_a<> any_a<_1>::nothing__(list_a<> const& ___arguments___) const
{
	return nothing_();
}

template <typename _1>
inline any_a<> any_a<_1>::nothing_() const
{ assert(___handle___); return ___read___().nothing_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::nothing_() const
{ return ___value___.nothing_(); }

template <typename _1>
inline bool any_a<_1>::nothing() const
{ assert(___handle___); return ___read___().nothing(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::nothing() const
{ return ___value___.nothing(); }

template <typename _1>
inline any_a<> any_a<_1>::something__(list_a<> const& ___arguments___) const
{
	return something_();
}

template <typename _1>
inline any_a<> any_a<_1>::something_() const
{ assert(___handle___); return ___read___().something_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::something_() const
{ return ___value___.something_(); }

template <typename _1>
inline bool any_a<_1>::something() const
{ assert(___handle___); return ___read___().something(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::something() const
{ return ___value___.something(); }

template <typename _1>
inline any_a<> any_a<_1>::same__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::same_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return same_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::same_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().same_(thing)); }

template <typename _1>
inline bool any_a<_1>::operator==(any_a<> const& thing) const
{ assert(___handle___); return ___read___().same_(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::same_(any_a<> const& thing) const
{ return bool{ ___value___.same_(thing) }; }

template <typename _1>
inline any_a<> any_a<_1>::different__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::different_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return different_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::different_(any_a<> const& thing) const
{ assert(___handle___); return boole(!___read___().same_(thing)); }

template <typename _1>
inline bool any_a<_1>::operator!=(any_a<> const& thing) const
{ assert(___handle___); return !___read___().same_(thing); }

template <typename _1>
inline any_a<> any_a<_1>::less_than__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::less_than_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return less_than_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::less_than_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().less_than_(thing)); }

template <typename _1>
inline bool any_a<_1>::operator<(any_a<> const& thing) const
{ assert(___handle___); return ___read___().less_than_(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::less_than_(any_a<> const& thing) const
{ return bool{ ___value___.less_than_(thing) }; }

template <typename _1>
inline any_a<> any_a<_1>::greater_than__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::greater_than_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return greater_than_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::greater_than_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().greater_than_(thing)); }

template <typename _1>
inline bool any_a<_1>::operator>(any_a<> const& thing) const
{ assert(___handle___); return ___read___().greater_than_(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::greater_than_(any_a<> const& thing) const
{ return bool{ ___value___.greater_than_(thing) }; }

template <typename _1>
inline any_a<> any_a<_1>::less_or_equal__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::less_or_equal_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return less_or_equal_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::less_or_equal_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().less_or_equal_(thing)); }

template <typename _1>
inline bool any_a<_1>::operator<=(any_a<> const& thing) const
{ assert(___handle___); return ___read___().less_or_equal_(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::less_or_equal_(any_a<> const& thing) const
{ return bool{ ___value___.less_or_equal_(thing) }; }

template <typename _1>
inline any_a<> any_a<_1>::greater_or_equal__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::greater_or_equal_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return greater_or_equal_(thing);
}

template <typename _1>
inline any_a<> any_a<_1>::greater_or_equal_(any_a<> const& thing) const
{ assert(___handle___); return boole(___read___().greater_or_equal_(thing)); }

template <typename _1>
inline bool any_a<_1>::operator>=(any_a<> const& thing) const
{ assert(___handle___); return ___read___().greater_or_equal_(thing); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::greater_or_equal_(any_a<> const& thing) const
{ return bool{ ___value___.greater_or_equal_(thing) }; }

template <typename _1>
inline any_a<> any_a<_1>::hash__(list_a<> const& ___arguments___) const
{
	return hash_();
}

template <typename _1>
inline number_data_uint64_a<> any_a<_1>::hash_() const
{ assert(___handle___); return ___read___().hash_(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline number_data_uint64_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::hash_() const
{ return ___value___.hash_(); }

template <typename _1>
inline std_size_t any_a<_1>::hash() const
{ assert(___handle___); return ___read___().hash(); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline std_size_t any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::hash() const
{ return ___value___.hash(); }

template <typename _1>
inline bool any_a<_1>::is(std_string const & s ) const
{ assert(___handle___); return ___read___().is(s); }

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline bool any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::is(std_string const & s ) const
{ return ___value___.is(s); }

template <typename _1>
inline any_a<> any_a<_1>::pack__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::pack_ passed short range");
	}
	auto container = cast_dup<container_a<>>(*___it___);
	return pack_(container);
}

template <typename _1>
inline any_a<> any_a<_1>::pack_(container_a<> & container) const
{
	if (!___handle___)
	{
		container.from_null_();
		return yes();
	}
	return ___read___().pack_(container);
}

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::pack_(container_a<> & container) const
{ return ___value___.pack_(container); }

template <typename _1>
inline any_a<> any_a<_1>::pack_unique__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::pack_unique_ passed short range");
	}
	auto container = cast_dup<container_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "any_a::pack_unique_ passed short range");
	}
	auto unique_herd = cast_dup<herd_a<number_data_uint64_a<>>>(*___it___);
	return pack_unique_(container, unique_herd);
}

template <typename _1>
inline any_a<> any_a<_1>::pack_unique_(container_a<> & container, herd_a<number_data_uint64_a<>> & unique_herd) const
{
	if (!___handle___)
	{
		container.from_null_();
		return yes();
	}
	return ___read___().pack_unique_(container, unique_herd);
}

template <typename _1>
template <typename ___TTT___, typename ___BHB___>
inline any_a<> any_a<_1>::___any_a_handle___<___TTT___, ___BHB___>::pack_unique_(container_a<> & container, herd_a<number_data_uint64_a<>> & unique_herd) const
{ return ___value___.pack_unique_(container, unique_herd); }

template <typename _1>
inline any_a<> any_a<_1>::operation(std_string const& name) const
{
	return ___read___().operations_().at_(sym(name));
}

template <typename _1>
inline cat_a<> any_a<_1>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::any");
	return CAT;
}

template <typename _1>
inline unordered_herd_a<> any_a<_1>::___cats___()
{
	static unordered_herd_a<> CATS = unordered_herd::create_vals(___cat___());
	return CATS;
}

template <typename _1>
inline kind_a<> any_a<_1>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _1>
inline unordered_herd_a<> any_a<_1>::___kinds___()
{
	static unordered_herd_a<> KINDS = unordered_herd::create_vals(___kind___());
	return KINDS;
}

template <typename _1>
inline unordered_shoal_a<> any_a<_1>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = unordered_shoal::create();
		operations.update(sym("call_"), native_mutation::create(&any_a::operator[]));
		operations.update(sym("perform_"), native_mutation::create(&any_a::operator()));
		operations.update(sym("type_"), native_extraction::create(&any_a::type__));
		operations.update(sym("cat_"), native_extraction::create(&any_a::cat__));
		operations.update(sym("cats_"), native_extraction::create(&any_a::cats__));
		operations.update(sym("kind_"), native_extraction::create(&any_a::kind__));
		operations.update(sym("kinds_"), native_extraction::create(&any_a::kinds__));
		operations.update(sym("operations_"), native_extraction::create(&any_a::operations__));
		operations.update(sym("identity_"), native_extraction::create(&any_a::identity__));
		operations.update(sym("identical_"), native_extraction::create(&any_a::identical__));
		operations.update(sym("nothing_"), native_extraction::create(&any_a::nothing__));
		operations.update(sym("something_"), native_extraction::create(&any_a::something__));
		operations.update(sym("same_"), native_extraction::create(&any_a::same__));
		operations.update(sym("different_"), native_extraction::create(&any_a::different__));
		operations.update(sym("less_than_"), native_extraction::create(&any_a::less_than__));
		operations.update(sym("greater_than_"), native_extraction::create(&any_a::greater_than__));
		operations.update(sym("less_or_equal_"), native_extraction::create(&any_a::less_or_equal__));
		operations.update(sym("greater_or_equal_"), native_extraction::create(&any_a::greater_or_equal__));
		operations.update(sym("hash_"), native_extraction::create(&any_a::hash__));
		operations.update(sym("pack_"), native_extraction::create(&any_a::pack__));
		operations.update(sym("pack_unique_"), native_extraction::create(&any_a::pack_unique__));
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
