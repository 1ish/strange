
namespace strange
{

template <typename _1>
inline bool symbol_a<_1>::operator==(symbol_a < > const & symbol ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::operator==(symbol_a < > const & symbol ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(symbol); }

template <typename _1>
inline bool symbol_a<_1>::operator!=(symbol_a < > const & symbol ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::operator!=(symbol_a < > const & symbol ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(symbol); }

template <typename _1>
inline bool symbol_a<_1>::operator<(symbol_a < > const & symbol ) const
{ assert(any_a<>::___handle___); return ___read___().operator<(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::operator<(symbol_a < > const & symbol ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(symbol); }

template <typename _1>
inline bool symbol_a<_1>::operator>(symbol_a < > const & symbol ) const
{ assert(any_a<>::___handle___); return ___read___().operator>(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::operator>(symbol_a < > const & symbol ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(symbol); }

template <typename _1>
inline bool symbol_a<_1>::operator<=(symbol_a < > const & symbol ) const
{ assert(any_a<>::___handle___); return ___read___().operator<=(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::operator<=(symbol_a < > const & symbol ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(symbol); }

template <typename _1>
inline bool symbol_a<_1>::operator>=(symbol_a < > const & symbol ) const
{ assert(any_a<>::___handle___); return ___read___().operator>=(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::operator>=(symbol_a < > const & symbol ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(symbol); }

template <typename _1>
inline any_a<> symbol_a<_1>::to_lake__(list_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _1>
inline lake_int8_a<> symbol_a<_1>::to_lake_() const
{ assert(any_a<>::___handle___); return ___read___().to_lake_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::to_lake_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_(); }

template <typename _1>
inline std_string symbol_a<_1>::to_string() const
{ assert(any_a<>::___handle___); return ___read___().to_string(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::to_string() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

template <typename _1>
inline char const * symbol_a<_1>::to_c_string() const
{ assert(any_a<>::___handle___); return ___read___().to_c_string(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline char const * symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::to_c_string() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_c_string(); }

template <typename _1>
inline int8_t symbol_a<_1>::first_character() const
{ assert(any_a<>::___handle___); return ___read___().first_character(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int8_t symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::first_character() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.first_character(); }

template <typename _1>
inline int8_t symbol_a<_1>::last_character() const
{ assert(any_a<>::___handle___); return ___read___().last_character(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int8_t symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::last_character() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.last_character(); }

template <typename _1>
inline any_a<> symbol_a<_1>::add__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "symbol_a::add_ passed short range");
	}
	auto symbol = cast<symbol_a<>>(*___it___);
	return add_(symbol);
}

template <typename _1>
inline symbol_a<> symbol_a<_1>::add_(symbol_a<> const& symbol) const
{ assert(any_a<>::___handle___); return ___read___().add_(symbol); }

template <typename _1>
inline symbol_a<> symbol_a<_1>::operator+(symbol_a<> const& symbol) const
{ assert(any_a<>::___handle___); return ___read___().add_(symbol); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline symbol_a<> symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::add_(symbol_a<> const& symbol) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(symbol); }

template <typename _1>
inline cat_a<> symbol_a<_1>::___cat___()
{
	static cat_a<> CAT = cat::create(1, "strange::symbol");
	return CAT;
}

template <typename _1>
inline unordered_herd_a<> symbol_a<_1>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = any_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _1>
inline kind_a<> symbol_a<_1>::___kind___()
{
	static kind_a<> KIND = kind::from_cat(___cat___());
	return KIND;
}

template <typename _1>
inline unordered_herd_a<> symbol_a<_1>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = any_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _1>
inline unordered_shoal_a<> symbol_a<_1>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
		operations.update(sym("to_lake_"), native_extraction::create(&symbol_a::to_lake__));
		operations.update(sym("add_"), native_extraction::create(&symbol_a::add__));
		return operations;
	}();
	return OPERATIONS;
}

class ___symbol_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___symbol_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline symbol_d<_1> ___symbol_dynamic___(any_a<> const& thing)
{
	return symbol_d<_1>{ thing };
}

} // namespace
