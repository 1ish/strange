
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
inline any_a<> symbol_a<_1>::to_lake__(range_a<> const& ___arguments___) const
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
inline std :: string symbol_a<_1>::to_string() const
{ assert(any_a<>::___handle___); return ___read___().to_string(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: string symbol_a<_1>::___symbol_a_handle___<___TTT___, ___DHB___>::to_string() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

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
inline any_a<> symbol_a<_1>::add__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("symbol_a::add_ passed short range");
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
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ symbol_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("to_lake_"), native_extraction_t<symbol_a>::create(&symbol_a::to_lake__));
		operations.update(sym("add_"), native_extraction_t<symbol_a>::create(&symbol_a::add__));
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
