
namespace strange
{

template <typename _lake_int8>
inline any_a<> misunderstanding_a<_lake_int8>::to_lake__(range_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _lake_int8>
inline _lake_int8 misunderstanding_a<_lake_int8>::to_lake_() const
{ assert(any_a<>::___handle___); return ___read___().to_lake_(); }

template <typename _lake_int8>
template <typename ___TTT___, typename ___DHB___>
inline _lake_int8 misunderstanding_a<_lake_int8>::___misunderstanding_a_handle___<___TTT___, ___DHB___>::to_lake_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_(); }

template <typename _lake_int8>
inline std :: string misunderstanding_a<_lake_int8>::to_string() const
{ assert(any_a<>::___handle___); return ___read___().to_string(); }

template <typename _lake_int8>
template <typename ___TTT___, typename ___DHB___>
inline std :: string misunderstanding_a<_lake_int8>::___misunderstanding_a_handle___<___TTT___, ___DHB___>::to_string() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

template <typename _lake_int8>
inline any_a<> misunderstanding_a<_lake_int8>::add__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("misunderstanding_a::add_ passed short range");
	}
	auto misunderstanding = cast<misunderstanding_a<>>(*___it___);
	return add_(misunderstanding);
}

template <typename _lake_int8>
inline misunderstanding_a<> misunderstanding_a<_lake_int8>::add_(misunderstanding_a<> const& misunderstanding) const
{ assert(any_a<>::___handle___); return ___read___().add_(misunderstanding); }

template <typename _lake_int8>
inline misunderstanding_a<> misunderstanding_a<_lake_int8>::operator+(misunderstanding_a<> const& misunderstanding) const
{ assert(any_a<>::___handle___); return ___read___().add_(misunderstanding); }

template <typename _lake_int8>
template <typename ___TTT___, typename ___DHB___>
inline misunderstanding_a<> misunderstanding_a<_lake_int8>::___misunderstanding_a_handle___<___TTT___, ___DHB___>::add_(misunderstanding_a<> const& misunderstanding) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(misunderstanding); }

template <typename _lake_int8>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ misunderstanding_a<_lake_int8>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("to_lake_"), native_extraction_t<misunderstanding_a>::create(&misunderstanding_a::to_lake__));
		operations.update(sym("add_"), native_extraction_t<misunderstanding_a>::create(&misunderstanding_a::add__));
		return operations;
	}();
	return OPERATIONS;
}

class ___misunderstanding_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___misunderstanding_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _lake_int8>
inline misunderstanding_d<_lake_int8> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<_lake_int8>{ thing };
}

} // namespace
