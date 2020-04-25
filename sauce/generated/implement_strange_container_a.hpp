
namespace strange
{

template <typename _1>
inline any_a<> container_a<_1>::unpack__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("container_a::unpack_ passed short range");
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
		throw dis("container_a::unpack_unique_ passed short range");
	}
	auto shared_shoal = cast<shoal_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis("container_a::unpack_unique_ passed short range");
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
inline any_a<> container_a<_1>::from_json__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("container_a::from_json_ passed short range");
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
		throw dis("container_a::from_binary_ passed short range");
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
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::container");
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
	static kind_a<> KIND = kind_from_cat(___cat___());
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
		operations.update(sym("unpack_"), native_extraction_t<container_a>::create(&container_a::unpack__));
		operations.update(sym("unpack_unique_"), native_extraction_t<container_a>::create(&container_a::unpack_unique__));
		operations.update(sym("close_"), native_mutation_t<container_a>::create(&container_a::close__));
		operations.update(sym("closed_"), native_extraction_t<container_a>::create(&container_a::closed__));
		operations.update(sym("reopen_"), native_mutation_t<container_a>::create(&container_a::reopen__));
		operations.update(sym("from_json_"), native_mutation_t<container_a>::create(&container_a::from_json__));
		operations.update(sym("to_json_"), native_extraction_t<container_a>::create(&container_a::to_json__));
		operations.update(sym("from_binary_"), native_mutation_t<container_a>::create(&container_a::from_binary__));
		operations.update(sym("to_binary_"), native_extraction_t<container_a>::create(&container_a::to_binary__));
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
