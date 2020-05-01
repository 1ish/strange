
namespace strange
{

template <typename _1>
inline any_a<> container_a<_1>::unpack__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::unpack_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	return unpack_(shared_shoal);
}

template <typename _1>
inline any_a<> container_a<_1>::unpack_(shoal_a<> const& shared_shoal) const
{ assert(any_a<>::___handle___); return ___read___().unpack_(shared_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::unpack_(shoal_a<> const& shared_shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unpack_(shared_shoal); }

template <typename _1>
inline any_a<> container_a<_1>::unpack_unique__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::unpack_unique_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::unpack_unique_ passed short range");
	}
	auto unique_shoal = cast_dup<shoal_a<number_data_uint64_a<>, strange::any_a<>>>(*___it___);
	return unpack_unique_(shared_shoal, unique_shoal);
}

template <typename _1>
inline any_a<> container_a<_1>::unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
{ assert(any_a<>::___handle___); return ___read___().unpack_unique_(shared_shoal, unique_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unpack_unique_(shared_shoal, unique_shoal); }

template <typename _1>
inline any_a < > container_a<_1>::unpack(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
{ assert(any_a<>::___handle___); return ___read___().unpack(shared_shoal, unique_shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a < > container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::unpack(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unpack(shared_shoal, unique_shoal); }

template <typename _1>
inline any_a<> container_a<_1>::close__(list_a<> const& ___arguments___)
{
	return close_();
}

template <typename _1>
inline any_a<> container_a<_1>::close_()
{ assert(any_a<>::___handle___); return ___write___().close_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::close_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.close_(); }

template <typename _1>
inline bool container_a<_1>::close()
{ assert(any_a<>::___handle___); return ___write___().close(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::close()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.close(); }

template <typename _1>
inline any_a<> container_a<_1>::closed__(list_a<> const& ___arguments___) const
{
	return closed_();
}

template <typename _1>
inline any_a<> container_a<_1>::closed_() const
{ assert(any_a<>::___handle___); return ___read___().closed_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::closed_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.closed_(); }

template <typename _1>
inline bool container_a<_1>::closed() const
{ assert(any_a<>::___handle___); return ___read___().closed(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::closed() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.closed(); }

template <typename _1>
inline any_a<> container_a<_1>::reopen__(list_a<> const& ___arguments___)
{
	return reopen_();
}

template <typename _1>
inline any_a<> container_a<_1>::reopen_()
{ assert(any_a<>::___handle___); return ___write___().reopen_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::reopen_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.reopen_(); }

template <typename _1>
inline bool container_a<_1>::reopen()
{ assert(any_a<>::___handle___); return ___write___().reopen(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::reopen()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.reopen(); }

template <typename _1>
inline any_a<> container_a<_1>::from_json__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_json_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return from_json_(lake);
}

template <typename _1>
inline container_a<> container_a<_1>::from_json_(lake_int8_a<> const& lake)
{ assert(any_a<>::___handle___); return ___write___().from_json_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_json_(lake_int8_a<> const& lake)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_json_(lake); }

template <typename _1>
inline void container_a<_1>::from_json(std_string const & str )
{ assert(any_a<>::___handle___); ___write___().from_json(str); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_json(std_string const & str )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_json(str); }

template <typename _1>
inline any_a<> container_a<_1>::to_json__(list_a<> const& ___arguments___) const
{
	return to_json_();
}

template <typename _1>
inline lake_int8_a<> container_a<_1>::to_json_() const
{ assert(any_a<>::___handle___); return ___read___().to_json_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_json_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_json_(); }

template <typename _1>
inline std_string container_a<_1>::to_json() const
{ assert(any_a<>::___handle___); return ___read___().to_json(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_json() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_json(); }

template <typename _1>
inline any_a<> container_a<_1>::from_binary__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_binary_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return from_binary_(lake);
}

template <typename _1>
inline container_a<> container_a<_1>::from_binary_(lake_int8_a<> const& lake)
{ assert(any_a<>::___handle___); return ___write___().from_binary_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_binary_(lake_int8_a<> const& lake)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_binary_(lake); }

template <typename _1>
inline void container_a<_1>::from_binary(std_string const & str )
{ assert(any_a<>::___handle___); ___write___().from_binary(str); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_binary(std_string const & str )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_binary(str); }

template <typename _1>
inline any_a<> container_a<_1>::to_binary__(list_a<> const& ___arguments___) const
{
	return to_binary_();
}

template <typename _1>
inline lake_int8_a<> container_a<_1>::to_binary_() const
{ assert(any_a<>::___handle___); return ___read___().to_binary_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_binary_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_binary_(); }

template <typename _1>
inline std_string container_a<_1>::to_binary() const
{ assert(any_a<>::___handle___); return ___read___().to_binary(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_binary() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_binary(); }

template <typename _1>
inline any_a<> container_a<_1>::from_null__(list_a<> const& ___arguments___)
{
	return from_null_();
}

template <typename _1>
inline container_a<> container_a<_1>::from_null_()
{ assert(any_a<>::___handle___); return ___write___().from_null_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_null_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_null_(); }

template <typename _1>
inline void container_a<_1>::from_null()
{ assert(any_a<>::___handle___); ___write___().from_null(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_null()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_null(); }

template <typename _1>
inline any_a<> container_a<_1>::is_null__(list_a<> const& ___arguments___) const
{
	return is_null_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_null_() const
{ assert(any_a<>::___handle___); return ___read___().is_null_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_null_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_null_(); }

template <typename _1>
inline bool container_a<_1>::is_null() const
{ assert(any_a<>::___handle___); return ___read___().is_null(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_null() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_null(); }

template <typename _1>
inline any_a<> container_a<_1>::from_boolean__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_boolean_ passed short range");
	}
	auto boolean = cast<any_a<>>(*___it___);
	return from_boolean_(boolean);
}

template <typename _1>
inline container_a<> container_a<_1>::from_boolean_(any_a<> const& boolean)
{ assert(any_a<>::___handle___); return ___write___().from_boolean_(boolean); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_boolean_(any_a<> const& boolean)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_boolean_(boolean); }

template <typename _1>
inline void container_a<_1>::from_boolean(bool boolean )
{ assert(any_a<>::___handle___); ___write___().from_boolean(boolean); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_boolean(bool boolean )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_boolean(boolean); }

template <typename _1>
inline any_a<> container_a<_1>::is_boolean__(list_a<> const& ___arguments___) const
{
	return is_boolean_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_boolean_() const
{ assert(any_a<>::___handle___); return ___read___().is_boolean_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_boolean_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_boolean_(); }

template <typename _1>
inline bool container_a<_1>::is_boolean() const
{ assert(any_a<>::___handle___); return ___read___().is_boolean(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_boolean() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_boolean(); }

template <typename _1>
inline any_a<> container_a<_1>::to_boolean__(list_a<> const& ___arguments___) const
{
	return to_boolean_();
}

template <typename _1>
inline any_a<> container_a<_1>::to_boolean_() const
{ assert(any_a<>::___handle___); return ___read___().to_boolean_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_boolean_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_boolean_(); }

template <typename _1>
inline bool container_a<_1>::to_boolean() const
{ assert(any_a<>::___handle___); return ___read___().to_boolean(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_boolean() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_boolean(); }

template <typename _1>
inline any_a<> container_a<_1>::from_number__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_number_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return from_number_(number);
}

template <typename _1>
inline container_a<> container_a<_1>::from_number_(number_a<> const& number)
{ assert(any_a<>::___handle___); return ___write___().from_number_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_number_(number_a<> const& number)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_number_(number); }

template <typename _1>
inline void container_a<_1>::from_number(number_a < > const & number )
{ assert(any_a<>::___handle___); ___write___().from_number(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_number(number_a < > const & number )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_number(number); }

template <typename _1>
inline any_a<> container_a<_1>::is_number__(list_a<> const& ___arguments___) const
{
	return is_number_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_number_() const
{ assert(any_a<>::___handle___); return ___read___().is_number_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_number_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_number_(); }

template <typename _1>
inline bool container_a<_1>::is_number() const
{ assert(any_a<>::___handle___); return ___read___().is_number(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_number() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_number(); }

template <typename _1>
inline any_a<> container_a<_1>::to_number__(list_a<> const& ___arguments___) const
{
	return to_number_();
}

template <typename _1>
inline number_a<> container_a<_1>::to_number_() const
{ assert(any_a<>::___handle___); return ___read___().to_number_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_number_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_number_(); }

template <typename _1>
inline any_a<> container_a<_1>::from_int_64__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_int_64_ passed short range");
	}
	auto number = cast<number_data_int64_a<>>(*___it___);
	return from_int_64_(number);
}

template <typename _1>
inline container_a<> container_a<_1>::from_int_64_(number_data_int64_a<> const& number)
{ assert(any_a<>::___handle___); return ___write___().from_int_64_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_int_64_(number_data_int64_a<> const& number)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64_(number); }

template <typename _1>
inline void container_a<_1>::from_int_64(int64_t number )
{ assert(any_a<>::___handle___); ___write___().from_int_64(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_int_64(int64_t number )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64(number); }

template <typename _1>
inline any_a<> container_a<_1>::is_int_64__(list_a<> const& ___arguments___) const
{
	return is_int_64_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_int_64_() const
{ assert(any_a<>::___handle___); return ___read___().is_int_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_int_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int_64_(); }

template <typename _1>
inline bool container_a<_1>::is_int_64() const
{ assert(any_a<>::___handle___); return ___read___().is_int_64(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_int_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int_64(); }

template <typename _1>
inline any_a<> container_a<_1>::to_int_64__(list_a<> const& ___arguments___) const
{
	return to_int_64_();
}

template <typename _1>
inline number_data_int64_a<> container_a<_1>::to_int_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_int_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_int_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64_(); }

template <typename _1>
inline int64_t container_a<_1>::to_int_64() const
{ assert(any_a<>::___handle___); return ___read___().to_int_64(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int64_t container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_int_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64(); }

template <typename _1>
inline any_a<> container_a<_1>::from_float_64__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_float_64_ passed short range");
	}
	auto number = cast<number_data_double_a<>>(*___it___);
	return from_float_64_(number);
}

template <typename _1>
inline container_a<> container_a<_1>::from_float_64_(number_data_double_a<> const& number)
{ assert(any_a<>::___handle___); return ___write___().from_float_64_(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_float_64_(number_data_double_a<> const& number)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64_(number); }

template <typename _1>
inline void container_a<_1>::from_float_64(double number )
{ assert(any_a<>::___handle___); ___write___().from_float_64(number); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_float_64(double number )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64(number); }

template <typename _1>
inline any_a<> container_a<_1>::is_float_64__(list_a<> const& ___arguments___) const
{
	return is_float_64_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_float_64_() const
{ assert(any_a<>::___handle___); return ___read___().is_float_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_float_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_float_64_(); }

template <typename _1>
inline bool container_a<_1>::is_float_64() const
{ assert(any_a<>::___handle___); return ___read___().is_float_64(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_float_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_float_64(); }

template <typename _1>
inline any_a<> container_a<_1>::to_float_64__(list_a<> const& ___arguments___) const
{
	return to_float_64_();
}

template <typename _1>
inline number_data_double_a<> container_a<_1>::to_float_64_() const
{ assert(any_a<>::___handle___); return ___read___().to_float_64_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_double_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_float_64_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64_(); }

template <typename _1>
inline double container_a<_1>::to_float_64() const
{ assert(any_a<>::___handle___); return ___read___().to_float_64(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline double container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_float_64() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64(); }

template <typename _1>
inline any_a<> container_a<_1>::from_symbol__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_symbol_ passed short range");
	}
	auto symbol = cast<symbol_a<>>(*___it___);
	return from_symbol_(symbol);
}

template <typename _1>
inline container_a<> container_a<_1>::from_symbol_(symbol_a<> const& symbol)
{ assert(any_a<>::___handle___); return ___write___().from_symbol_(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_symbol_(symbol_a<> const& symbol)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_symbol_(symbol); }

template <typename _1>
inline void container_a<_1>::from_symbol(symbol_a < > const & symbol )
{ assert(any_a<>::___handle___); ___write___().from_symbol(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_symbol(symbol_a < > const & symbol )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_symbol(symbol); }

template <typename _1>
inline void container_a<_1>::from_string(std_string const & str )
{ assert(any_a<>::___handle___); ___write___().from_string(str); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_string(std_string const & str )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_string(str); }

template <typename _1>
inline any_a<> container_a<_1>::is_symbol__(list_a<> const& ___arguments___) const
{
	return is_symbol_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_symbol_() const
{ assert(any_a<>::___handle___); return ___read___().is_symbol_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_symbol_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_symbol_(); }

template <typename _1>
inline bool container_a<_1>::is_symbol() const
{ assert(any_a<>::___handle___); return ___read___().is_symbol(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_symbol() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_symbol(); }

template <typename _1>
inline any_a<> container_a<_1>::to_symbol__(list_a<> const& ___arguments___) const
{
	return to_symbol_();
}

template <typename _1>
inline symbol_a<> container_a<_1>::to_symbol_() const
{ assert(any_a<>::___handle___); return ___read___().to_symbol_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_symbol_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_symbol_(); }

template <typename _1>
inline std_string container_a<_1>::to_string() const
{ assert(any_a<>::___handle___); return ___read___().to_string(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::to_string() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

template <typename _1>
inline any_a<> container_a<_1>::make_inventory__(list_a<> const& ___arguments___)
{
	return make_inventory_();
}

template <typename _1>
inline container_a<> container_a<_1>::make_inventory_()
{ assert(any_a<>::___handle___); return ___write___().make_inventory_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::make_inventory_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.make_inventory_(); }

template <typename _1>
inline void container_a<_1>::make_inventory()
{ assert(any_a<>::___handle___); ___write___().make_inventory(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::make_inventory()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.make_inventory(); }

template <typename _1>
inline any_a<> container_a<_1>::from_inventory__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_inventory_ passed short range");
	}
	auto inventory = cast<inventory_a<container_a<>>>(*___it___);
	return from_inventory_(inventory);
}

template <typename _1>
inline container_a<> container_a<_1>::from_inventory_(inventory_a<container_a<>> const& inventory)
{ assert(any_a<>::___handle___); return ___write___().from_inventory_(inventory); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_inventory_(inventory_a<container_a<>> const& inventory)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_inventory_(inventory); }

template <typename _1>
inline void container_a<_1>::from_inventory(inventory_a < container_a < > > const & inventory )
{ assert(any_a<>::___handle___); ___write___().from_inventory(inventory); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_inventory(inventory_a < container_a < > > const & inventory )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_inventory(inventory); }

template <typename _1>
inline any_a<> container_a<_1>::is_inventory__(list_a<> const& ___arguments___) const
{
	return is_inventory_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_inventory_() const
{ assert(any_a<>::___handle___); return ___read___().is_inventory_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_inventory_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inventory_(); }

template <typename _1>
inline bool container_a<_1>::is_inventory() const
{ assert(any_a<>::___handle___); return ___read___().is_inventory(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_inventory() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inventory(); }

template <typename _1>
inline any_a<> container_a<_1>::as_inventory__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::as_inventory_ passed short range");
	}
	auto inventory = cast_dup<inventory_a<container_a<>>>(*___it___);
	return as_inventory_(inventory);
}

template <typename _1>
inline any_a<> container_a<_1>::as_inventory_(inventory_a<container_a<>> & inventory) const
{ assert(any_a<>::___handle___); return ___read___().as_inventory_(inventory); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_inventory_(inventory_a<container_a<>> & inventory) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_inventory_(inventory); }

template <typename _1>
inline void container_a<_1>::as_inventory(inventory_a < container_a < > > & inventory ) const
{ assert(any_a<>::___handle___); ___read___().as_inventory(inventory); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_inventory(inventory_a < container_a < > > & inventory ) const
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_inventory(inventory); }

template <typename _1>
inline any_a<> container_a<_1>::make_herd__(list_a<> const& ___arguments___)
{
	return make_herd_();
}

template <typename _1>
inline container_a<> container_a<_1>::make_herd_()
{ assert(any_a<>::___handle___); return ___write___().make_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::make_herd_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.make_herd_(); }

template <typename _1>
inline void container_a<_1>::make_herd()
{ assert(any_a<>::___handle___); ___write___().make_herd(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::make_herd()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.make_herd(); }

template <typename _1>
inline any_a<> container_a<_1>::from_herd__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_herd_ passed short range");
	}
	auto herd = cast<herd_a<symbol_a<>>>(*___it___);
	return from_herd_(herd);
}

template <typename _1>
inline container_a<> container_a<_1>::from_herd_(herd_a<symbol_a<>> const& herd)
{ assert(any_a<>::___handle___); return ___write___().from_herd_(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_herd_(herd_a<symbol_a<>> const& herd)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_herd_(herd); }

template <typename _1>
inline void container_a<_1>::from_herd(herd_a < symbol_a < > > const & herd )
{ assert(any_a<>::___handle___); ___write___().from_herd(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_herd(herd_a < symbol_a < > > const & herd )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_herd(herd); }

template <typename _1>
inline any_a<> container_a<_1>::is_herd__(list_a<> const& ___arguments___) const
{
	return is_herd_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_herd_() const
{ assert(any_a<>::___handle___); return ___read___().is_herd_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_herd_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_herd_(); }

template <typename _1>
inline bool container_a<_1>::is_herd() const
{ assert(any_a<>::___handle___); return ___read___().is_herd(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_herd() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_herd(); }

template <typename _1>
inline any_a<> container_a<_1>::as_herd__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::as_herd_ passed short range");
	}
	auto herd = cast_dup<herd_a<symbol_a<>>>(*___it___);
	return as_herd_(herd);
}

template <typename _1>
inline any_a<> container_a<_1>::as_herd_(herd_a<symbol_a<>> & herd) const
{ assert(any_a<>::___handle___); return ___read___().as_herd_(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_herd_(herd_a<symbol_a<>> & herd) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_herd_(herd); }

template <typename _1>
inline void container_a<_1>::as_herd(herd_a < symbol_a < > > & herd ) const
{ assert(any_a<>::___handle___); ___read___().as_herd(herd); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_herd(herd_a < symbol_a < > > & herd ) const
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_herd(herd); }

template <typename _1>
inline any_a<> container_a<_1>::make_shoal__(list_a<> const& ___arguments___)
{
	return make_shoal_();
}

template <typename _1>
inline container_a<> container_a<_1>::make_shoal_()
{ assert(any_a<>::___handle___); return ___write___().make_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::make_shoal_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.make_shoal_(); }

template <typename _1>
inline void container_a<_1>::make_shoal()
{ assert(any_a<>::___handle___); ___write___().make_shoal(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::make_shoal()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.make_shoal(); }

template <typename _1>
inline any_a<> container_a<_1>::from_shoal__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_shoal_ passed short range");
	}
	auto shoal = cast<shoal_a<symbol_a<>, container_a<>>>(*___it___);
	return from_shoal_(shoal);
}

template <typename _1>
inline container_a<> container_a<_1>::from_shoal_(shoal_a<symbol_a<>, container_a<>> const& shoal)
{ assert(any_a<>::___handle___); return ___write___().from_shoal_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline container_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_shoal_(shoal_a<symbol_a<>, container_a<>> const& shoal)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_shoal_(shoal); }

template <typename _1>
inline void container_a<_1>::from_shoal(shoal_a < symbol_a < > , container_a < > > const & shoal )
{ assert(any_a<>::___handle___); ___write___().from_shoal(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_shoal(shoal_a < symbol_a < > , container_a < > > const & shoal )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_shoal(shoal); }

template <typename _1>
inline any_a<> container_a<_1>::is_shoal__(list_a<> const& ___arguments___) const
{
	return is_shoal_();
}

template <typename _1>
inline any_a<> container_a<_1>::is_shoal_() const
{ assert(any_a<>::___handle___); return ___read___().is_shoal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_shoal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_shoal_(); }

template <typename _1>
inline bool container_a<_1>::is_shoal() const
{ assert(any_a<>::___handle___); return ___read___().is_shoal(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::is_shoal() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.is_shoal(); }

template <typename _1>
inline any_a<> container_a<_1>::as_shoal__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::as_shoal_ passed short range");
	}
	auto shoal = cast_dup<shoal_a<symbol_a<>, container_a<>>>(*___it___);
	return as_shoal_(shoal);
}

template <typename _1>
inline any_a<> container_a<_1>::as_shoal_(shoal_a<symbol_a<>, container_a<>> & shoal) const
{ assert(any_a<>::___handle___); return ___read___().as_shoal_(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_shoal_(shoal_a<symbol_a<>, container_a<>> & shoal) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_shoal_(shoal); }

template <typename _1>
inline void container_a<_1>::as_shoal(shoal_a < symbol_a < > , container_a < > > & shoal ) const
{ assert(any_a<>::___handle___); ___read___().as_shoal(shoal); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_shoal(shoal_a < symbol_a < > , container_a < > > & shoal ) const
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_shoal(shoal); }

template <typename _1>
inline any_a<> container_a<_1>::from_brook__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_brook_ passed short range");
	}
	auto brook = cast<any_a<>>(*___it___);
	return from_brook_(brook);
}

template <typename _1>
inline any_a<> container_a<_1>::from_brook_(any_a<> const& brook)
{ assert(any_a<>::___handle___); return ___write___().from_brook_(brook); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_brook_(any_a<> const& brook)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_brook_(brook); }

template <typename _1>
inline bool container_a<_1>::from_brook(any_a < > const & brook )
{ assert(any_a<>::___handle___); return ___write___().from_brook(brook); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_brook(any_a < > const & brook )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_brook(brook); }

template <typename _1>
inline any_a<> container_a<_1>::as_brook__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::as_brook_ passed short range");
	}
	auto brook = cast_dup<any_a<>>(*___it___);
	return as_brook_(brook);
}

template <typename _1>
inline any_a<> container_a<_1>::as_brook_(any_a<> & brook) const
{ assert(any_a<>::___handle___); return ___read___().as_brook_(brook); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_brook_(any_a<> & brook) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_brook_(brook); }

template <typename _1>
inline bool container_a<_1>::as_brook(any_a < > & brook ) const
{ assert(any_a<>::___handle___); return ___read___().as_brook(brook); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_brook(any_a < > & brook ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_brook(brook); }

template <typename _1>
inline any_a<> container_a<_1>::from_lake__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_lake_ passed short range");
	}
	auto lake = cast<any_a<>>(*___it___);
	return from_lake_(lake);
}

template <typename _1>
inline any_a<> container_a<_1>::from_lake_(any_a<> const& lake)
{ assert(any_a<>::___handle___); return ___write___().from_lake_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_lake_(any_a<> const& lake)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_lake_(lake); }

template <typename _1>
inline bool container_a<_1>::from_lake(any_a < > const & lake )
{ assert(any_a<>::___handle___); return ___write___().from_lake(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_lake(any_a < > const & lake )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_lake(lake); }

template <typename _1>
inline any_a<> container_a<_1>::as_lake__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::as_lake_ passed short range");
	}
	auto lake = cast_dup<any_a<>>(*___it___);
	return as_lake_(lake);
}

template <typename _1>
inline any_a<> container_a<_1>::as_lake_(any_a<> & lake) const
{ assert(any_a<>::___handle___); return ___read___().as_lake_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_lake_(any_a<> & lake) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_lake_(lake); }

template <typename _1>
inline bool container_a<_1>::as_lake(any_a < > & lake ) const
{ assert(any_a<>::___handle___); return ___read___().as_lake(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_lake(any_a < > & lake ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_lake(lake); }

template <typename _1>
inline any_a<> container_a<_1>::from_data__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::from_data_ passed short range");
	}
	auto data = cast<any_a<>>(*___it___);
	return from_data_(data);
}

template <typename _1>
inline any_a<> container_a<_1>::from_data_(any_a<> const& data)
{ assert(any_a<>::___handle___); return ___write___().from_data_(data); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_data_(any_a<> const& data)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_data_(data); }

template <typename _1>
inline bool container_a<_1>::from_data(any_a < > const & data )
{ assert(any_a<>::___handle___); return ___write___().from_data(data); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::from_data(any_a < > const & data )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.from_data(data); }

template <typename _1>
inline any_a<> container_a<_1>::as_data__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "container_a::as_data_ passed short range");
	}
	auto data = cast_dup<any_a<>>(*___it___);
	return as_data_(data);
}

template <typename _1>
inline any_a<> container_a<_1>::as_data_(any_a<> & data) const
{ assert(any_a<>::___handle___); return ___read___().as_data_(data); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_data_(any_a<> & data) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_data_(data); }

template <typename _1>
inline bool container_a<_1>::as_data(any_a < > & data ) const
{ assert(any_a<>::___handle___); return ___read___().as_data(data); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool container_a<_1>::___container_a_handle___<___TTT___, ___DHB___>::as_data(any_a < > & data ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.as_data(data); }

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
inline cat_a<> container_a<_1>::___cat___()
{
	static cat_a<> CAT = cat::create(1, "strange::container");
	return CAT;
}

template <typename _1>
inline unordered_herd_a<> container_a<_1>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = collection_a< any_a<> , container_a<> , container_a<> >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _1>
inline kind_a<> container_a<_1>::___kind___()
{
	static kind_a<> KIND = kind::from_cat(___cat___());
	return KIND;
}

template <typename _1>
inline unordered_herd_a<> container_a<_1>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = collection_a< any_a<> , container_a<> , container_a<> >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _1>
inline unordered_shoal_a<> container_a<_1>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = collection_a< any_a<> , container_a<> , container_a<> >::___operations___();
		operations.update(sym("unpack_"), native_extraction::create(&container_a::unpack__));
		operations.update(sym("unpack_unique_"), native_extraction::create(&container_a::unpack_unique__));
		operations.update(sym("close_"), native_mutation::create(&container_a::close__));
		operations.update(sym("closed_"), native_extraction::create(&container_a::closed__));
		operations.update(sym("reopen_"), native_mutation::create(&container_a::reopen__));
		operations.update(sym("from_json_"), native_mutation::create(&container_a::from_json__));
		operations.update(sym("to_json_"), native_extraction::create(&container_a::to_json__));
		operations.update(sym("from_binary_"), native_mutation::create(&container_a::from_binary__));
		operations.update(sym("to_binary_"), native_extraction::create(&container_a::to_binary__));
		operations.update(sym("from_null_"), native_mutation::create(&container_a::from_null__));
		operations.update(sym("is_null_"), native_extraction::create(&container_a::is_null__));
		operations.update(sym("from_boolean_"), native_mutation::create(&container_a::from_boolean__));
		operations.update(sym("is_boolean_"), native_extraction::create(&container_a::is_boolean__));
		operations.update(sym("to_boolean_"), native_extraction::create(&container_a::to_boolean__));
		operations.update(sym("from_number_"), native_mutation::create(&container_a::from_number__));
		operations.update(sym("is_number_"), native_extraction::create(&container_a::is_number__));
		operations.update(sym("to_number_"), native_extraction::create(&container_a::to_number__));
		operations.update(sym("from_int_64_"), native_mutation::create(&container_a::from_int_64__));
		operations.update(sym("is_int_64_"), native_extraction::create(&container_a::is_int_64__));
		operations.update(sym("to_int_64_"), native_extraction::create(&container_a::to_int_64__));
		operations.update(sym("from_float_64_"), native_mutation::create(&container_a::from_float_64__));
		operations.update(sym("is_float_64_"), native_extraction::create(&container_a::is_float_64__));
		operations.update(sym("to_float_64_"), native_extraction::create(&container_a::to_float_64__));
		operations.update(sym("from_symbol_"), native_mutation::create(&container_a::from_symbol__));
		operations.update(sym("is_symbol_"), native_extraction::create(&container_a::is_symbol__));
		operations.update(sym("to_symbol_"), native_extraction::create(&container_a::to_symbol__));
		operations.update(sym("make_inventory_"), native_mutation::create(&container_a::make_inventory__));
		operations.update(sym("from_inventory_"), native_mutation::create(&container_a::from_inventory__));
		operations.update(sym("is_inventory_"), native_extraction::create(&container_a::is_inventory__));
		operations.update(sym("as_inventory_"), native_extraction::create(&container_a::as_inventory__));
		operations.update(sym("make_herd_"), native_mutation::create(&container_a::make_herd__));
		operations.update(sym("from_herd_"), native_mutation::create(&container_a::from_herd__));
		operations.update(sym("is_herd_"), native_extraction::create(&container_a::is_herd__));
		operations.update(sym("as_herd_"), native_extraction::create(&container_a::as_herd__));
		operations.update(sym("make_shoal_"), native_mutation::create(&container_a::make_shoal__));
		operations.update(sym("from_shoal_"), native_mutation::create(&container_a::from_shoal__));
		operations.update(sym("is_shoal_"), native_extraction::create(&container_a::is_shoal__));
		operations.update(sym("as_shoal_"), native_extraction::create(&container_a::as_shoal__));
		operations.update(sym("from_brook_"), native_mutation::create(&container_a::from_brook__));
		operations.update(sym("as_brook_"), native_extraction::create(&container_a::as_brook__));
		operations.update(sym("from_lake_"), native_mutation::create(&container_a::from_lake__));
		operations.update(sym("as_lake_"), native_extraction::create(&container_a::as_lake__));
		operations.update(sym("from_data_"), native_mutation::create(&container_a::from_data__));
		operations.update(sym("as_data_"), native_extraction::create(&container_a::as_data__));
		operations.update(sym("keys_begin_"), native_extraction::create(&container_a::keys_begin__));
		operations.update(sym("keys_end_"), native_extraction::create(&container_a::keys_end__));
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
